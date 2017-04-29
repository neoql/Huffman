cmake_minimum_required(VERSION 3.6)
project(Huffman)

set(EXE_SRC main.c)
set(HUFF_LIB Huffman.c Huffman.h)
set(BITARRAY_LIB bitarray.c bitarray.h)

add_library(libbitarray SHARED ${BITARRAY_LIB})
set_target_properties(libbitarray PROPERTIES OUTPUT_NAME "libbitarray")

add_library(libhuffman SHARED ${HUFF_LIB})
set_target_properties(libhuffman PROPERTIES OUTPUT_NAME "huffman")
target_link_libraries(libhuffman libbitarray)

add_executable(Huffman ${EXE_SRC})
target_link_libraries(Huffman libhuffman libbitarray)