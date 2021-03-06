if(NOT DEFINED ENV{CFLAGS})
    if(CMAKE_C_COMPILER_ID MATCHES Intel)
        set(CMAKE_C_FLAGS         "${CMAKE_C_FLAGS} -restrict -DRESTRICT=restrict -std=c99 -fPIC")
        set(CMAKE_C_FLAGS_DEBUG   "-O0 -DDEBUG -g -w3 -Wall -Wuninitialized -Wno-sign-compare")
        set(CMAKE_C_FLAGS_RELEASE "-O3 -ip -DNDEBUG")
        # FIXME Not sure this is really needed
        set(CMAKE_C_LINK_FLAGS    "-shared-intel -fPIC")
    endif()
endif()
