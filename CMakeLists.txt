cmake_minimum_required(VERSION 3.15)
project(FileLib)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/FileLib/resources)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/FileLib/resources)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/FileLib/resources)

add_library(FileLib STATIC src/FileLib.cpp include/FileLib.h)
target_link_libraries(FileLib stdc++fs)

add_library(FileLibShared SHARED src/FileLib.cpp include/FileLib.h)
target_link_libraries(FileLibShared stdc++fs)

set_target_properties(FileLibShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/FileLib/resources)
set_target_properties(FileLibShared PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/FileLib/resources)