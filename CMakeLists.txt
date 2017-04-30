cmake_minimum_required(VERSION 3.6)
project(Huffman)

set(EXE_SRC main.c)
set(LIB_SRC Huffman.c Huffman.h sortlist.c sortlist.h)

add_library(libhuffman SHARED ${LIB_SRC})
set_target_properties(libhuffman PROPERTIES OUTPUT_NAME "huffman")

add_executable(Huffman ${EXE_SRC})
target_link_libraries(Huffman libhuffman)