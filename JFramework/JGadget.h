#pragma once

template <class P, class M>
unsigned my_offsetof(const M P::*member) {
	return (unsigned)&(reinterpret_cast<P *>(0)->*member);
}

template <class P, class M>
P *my_container_of_impl(M *ptr, const M P::*member) {
	return (P *)((char *)ptr - my_offsetof(member));
}

#define my_container_of(ptr, type, member) \
	my_container_of_impl(ptr, &type::member)

namespace JGadget {

	// doubly linked, circular
	struct TLinkListNode {
		TLinkListNode *next = nullptr;
		TLinkListNode *prev = nullptr;
	};

	struct TNodeLinkList {
		TLinkListNode head{&head, &head};
		int count = 0;
		struct iterator {
			TLinkListNode *node;
		};

		iterator Erase(TLinkListNode *param_3);
		iterator Insert(iterator where, TLinkListNode *newel);
		iterator erase(iterator it);
		iterator erase(iterator start, iterator end);

		// infinite loop if param_3 not in the list (as it is circular), this makes
		// checks in JUTConsoleManager useless
		iterator Find(TLinkListNode *param_3);

		void splice(iterator myIt, TNodeLinkList *otherList, iterator otherIt);
		void Remove(TLinkListNode *node);
	};
}
