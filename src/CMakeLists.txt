add_subdirectory(cocoatweet)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME}
  lib-cocoatweet
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  OpenSSL::SSL
  OpenSSL::Crypto
  ${CURL_LIBRARIES}
)
