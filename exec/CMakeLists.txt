add_executable(_test _test.cpp)
target_include_directories(_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(_test PUBLIC TTTU)