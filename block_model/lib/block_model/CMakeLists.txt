project(block_model_block_model)

file(GLOB ${PROJECT_NAME}_SOURCE_FILES "src/*.cpp")

add_library(${PROJECT_NAME}_lib STATIC ${${PROJECT_NAME}_SOURCE_FILES})
set_target_properties(${PROJECT_NAME}_lib PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)
#        COMPILE_FLAGS "-Wall -Wextra -Werror -Wpedantic")
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)

add_subdirectory(tests)