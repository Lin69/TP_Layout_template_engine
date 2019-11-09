project(TP_Layout_template_engine)

file(GLOB ${PROJECT_NAME}_SOURCE_FILES "./*.cpp")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        COMPILE_FLAGS "-Wall -Wextra -Werror -Wpedantic")
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(Tests)