file(GLOB_RECURSE SOURCES ./*.cc)
add_library(lib-cocoatweet ${SOURCES})


target_link_libraries(lib-cocoatweet PUBLIC
  ${OPENSSL_LIBRARIES}
  ${CURL_LIBRARIES}
)

if(ENABLE_TEST)
  target_link_libraries(lib-cocoatweet PUBLIC Boost::boost)
endif()

target_include_directories(lib-cocoatweet PUBLIC ${PROJECT_SOURCE_DIR}/src)
set_target_properties(lib-cocoatweet PROPERTIES OUTPUT_NAME cocoatweet)
