cmake_minimum_required(VERSION 3.14)
project(Indice_Remisivo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Indice_Remisivo source/main.cpp source/helps.cpp source/linked_list/List.cpp source/linked_list/List.h source/helps.h source/linked_list/indice_list.cpp source/linked_list/indice_list.h source/bst/tree.cpp source/bst/tree.h source/avl/avlTree.cpp source/avl/avlTree.h source/hash/hash.cpp source/hash/hash.h source/hash/hash.cpp source/external/fort.h source/external/fort.c source/external/fort.hpp source/benchmarks/benchmarks.cpp source/benchmarks/benchmarks.h)