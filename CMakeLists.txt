cmake_minimum_required(VERSION 3.10)

project(calc CXX)

add_executable(CONTAINER
   vector.h
   list.h
   main.cpp   
)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)
add_executable(
    test_vector
    test/test_vector.cpp
    vector.h
 
    
)

target_link_libraries(
    test_vector
    PRIVATE
    gtest gtest_main -ldl
)

add_executable(
    test_list
    test/test_list.cpp
    list.h 
)

target_link_libraries(
    test_list
    PRIVATE
    gtest gtest_main -ldl
)