file(GLOB_RECURSE SOURCES ./*.cc)
add_library(lib-cocoatweet ${SOURCES})
target_include_directories(lib-cocoatweet PUBLIC ${PROJECT_SOURCE_DIR}/src)
set_target_properties(lib-cocoatweet PROPERTIES OUTPUT_NAME cocoatweet)
