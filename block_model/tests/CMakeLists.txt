set(NAME_OF_THE_TESTED_PROJECT block_model)

include(GoogleTest)

set(PROJECT_NAME ${NAME_OF_THE_TESTED_PROJECT}_tests)

file(GLOB ${PROJECT_NAME}_SOURCE_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${NAME_OF_THE_TESTED_PROJECT}_lib gtest)

gtest_discover_tests(${PROJECT_NAME})