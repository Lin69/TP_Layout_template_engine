cmake_minimum_required(VERSION 3.12.4)
project(TP_Layout_template_engine)

enable_testing()

add_subdirectory(external)

add_subdirectory(block_model)
add_subdirectory(html_generator)
add_subdirectory(presenter)
add_subdirectory(layout_template_engine)