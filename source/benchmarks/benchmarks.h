//
// Created by thiago on 20/06/19.
//

#ifndef INDICE_REMISIVO_BENCHMARKS_H
#define INDICE_REMISIVO_BENCHMARKS_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

#include "../linked_list/indice_list.h"
#include "../bst/tree.h"
#include "../avl/avlTree.h"

void benchmark_BST(vector<string> keyWords, ifstream&file, int totalExecutions);
#endif //INDICE_REMISIVO_BENCHMARKS_H
