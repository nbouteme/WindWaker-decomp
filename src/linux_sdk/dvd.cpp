#include <dirent.h>
#include <dolphin/dvd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include <limits>

const char rootdir[] = "/home/lillie/rev/ww.iso-ext/files";
const char* cwd;

template <typename T>
class UntrackedAllocator {
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

public:
	template <typename U>
	struct rebind {
		typedef UntrackedAllocator<U> other;
	};

public:
	inline explicit UntrackedAllocator() {}
	inline ~UntrackedAllocator() {}
	inline UntrackedAllocator(UntrackedAllocator const&) {}
	template <typename U>
	inline explicit UntrackedAllocator(UntrackedAllocator<U> const&) {}

	//    address
	inline pointer address(reference r) {
		return &r;
	}

	inline const_pointer address(const_reference r) {
		return &r;
	}

	//    memory allocation
	inline pointer allocate(size_type cnt,
							typename std::allocator<void>::const_pointer = 0) {
		T* ptr = (T*)malloc(cnt * sizeof(T));
		return ptr;
	}

	inline void deallocate(pointer p, size_type cnt) {
		free(p);
	}

	//   size
	inline size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(T);
	}

	// construction/destruction
	inline void construct(pointer p, const T& t) {
		new (p) T(t);
	}

	inline void destroy(pointer p) {
		p->~T();
	}

	inline bool operator==(UntrackedAllocator const& a) { return this == &a; }
	inline bool operator!=(UntrackedAllocator const& a) { return !operator==(a); }
};

using string = std::basic_string<char, std::char_traits<char>, UntrackedAllocator<char>>;

static string replace(const string& a, const string& b, const string& c) {
	auto s = a;
	auto i = s.find(b);
	if (i != string::npos)
		s.replace(i, b.size(), c);
	return s;
}

namespace dvd {

	bool DVDChangeDir(char const* a) {
		chdir(a);
		free((void*)cwd);
		cwd = strdup(a);
		return true;
	}

	bool DVDCheckDisk() {
		return true;
	}

	bool DVDFastOpen(int uid, dvd::DVDFileInfo* info) {
		struct stat s;
		info->startAddr = uid;
		fstat(uid, &s);
		info->length = s.st_size;
		return true;
	}

	DVDDiskID* DVDGetCurrentDiskID() {
		static DVDDiskID data = {
			{'G', 'Z', 'L', 'E'},
			{'0', '1'},
			0,
			99,
			0,
			0};
		return &data;
	}

	void DVDInit() {
		puts("Initializing DVD");
		cwd = strdup("/");
	}

	bool DVDReadAsyncPrio(dvd::DVDFileInfo* info, void* dest, int len, int offset, void (*cb)(int, dvd::DVDFileInfo*), int) {
		lseek(info->startAddr, offset, SEEK_SET);
		int l = read(info->startAddr, dest, len);
		cb(l, info);
		return true;
	}

	bool DVDClose(dvd::DVDFileInfo* info) {
		// We can't really close the fd because the game expects to be able
		// to reuse the same handle to refer to the same file
		// In short, we can only close it if we know it won't be used in a call to DVDFastOpen later
		// So to fix this we need some mapping between entry ids and file handles
		//close(info->startAddr);
		return true;
	}

	int DVDConvertPathToEntrynum(char const* path) {
		// hack: what's known as the "files" folder seems to be internally refered as "/dvd"? but sometimes it's omitted?
		if (path[0] == '/' && path[1] == 'd' && path[2] == 'v' && path[3] == 'd')
			path += 4;

		string fdir = rootdir;
		if (path[0] == '/')
			fdir += (path);
		else
			fdir = fdir + cwd + "/" + (path);
		// The filesystem is expected to be case insensitive, but not the case on linux
		// hopefully there aren't many of these cases
		fdir = replace(fdir, "AudioRes", "Audiores");
		return open(fdir.c_str(), O_RDONLY);
	}

	int DVDGetCommandBlockStatus(dvd::DVDCommandBlock const*) {
		return 0;
	}

	bool DVDOpen(char const* str, dvd::DVDFileInfo* info) {
		struct stat s;
		int uid = DVDConvertPathToEntrynum(str);
		info->startAddr = uid;
		fstat(uid, &s);
		info->length = s.st_size;
		return info->startAddr != ~0u;
	}

	bool DVDCloseDir(dvd::DVDDir* dir) {
		close(dir->entryNum);
		return true;
	}

	int DVDGetDriveStatus() {
		return 0;
	}

	bool DVDOpenDir(char const* path, dvd::DVDDir* dir) {
		*(void**)dir = (void*)opendir(path);
		return true;
	}

	bool DVDReadDir(dvd::DVDDir* dir, dvd::DVDDirEntry* entries) {
		DIR* dirp = *(DIR**)dir;
		auto ent = readdir(dirp);
		if (!ent)
			return false;
		entries->isDir = (ent->d_type & DT_DIR) != 0;
		entries->entryNum = ent->d_ino;
		entries->name = ent->d_name;
		return true;
	}

	int DVDReadPrio(dvd::DVDFileInfo* info, void* dest, int len, int offset, int) {
		lseek(info->startAddr, offset, SEEK_SET);
		int l = read(info->startAddr, dest, len);
		return l;
	}
}