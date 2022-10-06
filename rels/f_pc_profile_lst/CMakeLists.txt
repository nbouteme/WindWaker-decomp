file(GLOB_RECURSE libsources CONFIGURE_DEPENDS "src/*.cpp")

add_library(f_pc_profile_lst SHARED ${libsources})
