if(NOT DEFINED ENV{CXXFLAGS})
  if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
    # Discover C++11 support
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE CXX_COMPILER_VERSION)
    if(CXX_COMPILER_VERSION VERSION_LESS 14.0.0)
      message(STATUS "Buggy compiler support for C++11. Using older standard.")
      set(ENABLE_CXX11_SUPPORT OFF)
    endif()

    set(CXX_STANDARD_FLAG "-std=gnu++98")
    if(ENABLE_CXX11_SUPPORT)
      include(CheckCXX11)
      discover_cxx11_support(CXX_STANDARD_FLAG)
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_STANDARD_FLAG}")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -debug -DDEBUG -Wall -Wuninitialized -Wno-unknown-pragmas -Wno-sign-compare")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    # FIXME not sure this is actually needed...
    set(CMAKE_CXX_LINK_FLAGS    "-shared-intel")
  endif()
endif()
