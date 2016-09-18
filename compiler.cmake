include(CheckCXXCompilerFlag)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpointer-arith -Wnon-virtual-dtor")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall ")
endif()

if (NOT RCT_RTTI_ENABLED)
    if(NOT MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-")
    endif()
endif ()

if(NOT MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpointer-arith")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Wall")
endif()

if (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
else ()
    if(NOT MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
    endif()
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  add_definitions(-D_DARWIN_UNLIMITED_SELECT)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else ()
  if (NOT CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
    # Use pic instead of PIC, which produces faster and smaller code,
    # but could eventully lead to linker problems.
    set(CMAKE_CXX_COMPILE_OPTIONS_PIC  "-fpic")
    set(CMAKE_C_COMPILE_OPTIONS_PIC  "-fpic")
  endif ()
  if (RCT_USE_LIBCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi")
    string(STRIP "${CMAKE_EXE_LINKER_FLAGS}" CMAKE_EXE_LINKER_FLAGS)
  endif ()
endif ()
