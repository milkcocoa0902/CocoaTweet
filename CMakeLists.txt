cmake_minimum_required(VERSION 3.10)

project(CocoaTweet CXX C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Disable in-source build
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set compiler flags
set(CMAKE_CXX_EXTENSIONS  OFF)
set(CMAKE_CXX_STANDARD    17)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -march=native -DNDEBUG")


if(UNIX AND (NOT APPLE))
	message(STATUS "afiejanfonw")
  set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}  -Wl,-O1,--sort-common,--as-needed,-z,relro")
elseif(WIN32 OR APPLE)
 #set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}  -Wl,-O1,--sort-common,--as-needed")
endif()

if(CMAKE_GENERATOR STREQUAL "Ninja")
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")
  endif()
endif()

# Sanitizers
if(ENABLE_SANITIZERS)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Enabling GCC's address sanitizer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Enabling Clang's address sanitizer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
  endif()
endif()

# Code coverage
if(ENABLE_CODE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# Required libraries
if(ENABLE_TEST)
  if(NOT (UNIX OR APPLE))
    message(FAITAL_ERROR "unit test is NOT supported on Windows")
  endif()
  find_package(Boost 1.71.0 COMPONENTS unit_test_framework REQUIRED)
  # Enable CTest
  enable_testing()
  add_subdirectory(test)
endif()


# Search OpenSSL
if (APPLE)
  # This is a bug in CMake that causes it to prefer the system version over
  # the one in the specified ROOT folder.
  find_package(PkgConfig REQUIRED)
  find_package(OpenSSL REQUIRED)
  set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libcrypto.dylib CACHE FILEPATH "" FORCE)
  set(OPENSSL_SSL_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libssl.dylib CACHE FILEPATH "" FORCE)
  set(OPENSSL_LIBRARIES ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY})
elseif(UNIX)
  find_package(PkgConfig REQUIRED)
  find_package(OpenSSL REQUIRED)
  if(NOT OPENSSL_FOUND)
    message(FATAL_ERROR "Fail to find OpenSSL") # exit
  endif()
  set(OPENSSL_LIBRARIES OpenSSL::SSL OpenSSL::Crypto)
elseif(WIN32)
  if(NOT OPENSSL_ROOT_DIR)
    message(FATAL_ERROR "Fail to find OpenSSL") # exit
  endif()
  set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
  set(OPENSSL_LIBRARIES "${OPENSSL_ROOT_DIR}/lib/libssl.dll.a" "${OPENSSL_ROOT_DIR}/lib/libcrypto.dll.a" )
  file(GLOB DLL ${OPENSSL_ROOT_DIR}/*.dll)
  file(COPY ${DLL} DESTINATION ${CMAKE_BINARY_DIR})
endif()
message(STATUS "OPENSSL_INCLUDE_DIR: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "OpenSSL Libraries : ${OPENSSL_LIBRARIES}")
include_directories(${OPENSSL_INCLUDE_DIR})


# Search cURL library
if(UNIX OR APPLE)
  find_package(CURL REQUIRED)
  if(NOT CURL_FOUND)
    message(FATAL_ERROR "Fail to find cURL library") # exit
  endif()
elseif(WIN32)
	if(NOT CURL_ROOT_DIR)
    message(FATAL_ERROR "Fail to find cURL library") # exit
  endif()
  add_definitions(-DCURL_STATICLIB)
	set(CURL_INCLUDE_DIRS "${CURL_ROOT_DIR}/include")
	set(CURL_LIBRARIES "${CURL_ROOT_DIR}/lib/libcurl.dll.a")
  file(GLOB DLL ${CURL_ROOT_DIR}/bin/*.dll)
  file(COPY ${DLL} DESTINATION ${CMAKE_BINARY_DIR})
endif()
message(STATUS "CURL_INCLUDE_DIR: ${CURL_INCLUDE_DIRS}")
message(STATUS "CURL_LIBRARIES: ${CURL_LIBRARIES}")
include_directories(${CURL_INCLUDE_DIRS})


include_directories(
		${CMAKE_SOURCE_DIR}/src
		${CMAKE_SOURCE_DIR}/third
)


add_subdirectory(src)
