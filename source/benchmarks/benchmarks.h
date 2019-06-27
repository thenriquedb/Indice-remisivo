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

void benchmark_AVL(vector<string> keyWords, vector<averageTimes> *times, ifstream &file, int totalExecutions);

void benchmark_BST(vector<string> keyWords, vector<averageTimes> *times, ifstream &file, int totalExecutions);

void benchmark_LinkedList(vector<string> keyWords, vector<averageTimes> *times, ifstream &file, int totalExecutions);

void benchmarkHash(string type, vector<string> keyWords, int CAPACITY, vector<averageTimes> *times,
                   ifstream &file, int totalExecutions);

void exportBenchmark_txt(string type, string table1, string table2);

void checkBenchmarkResults(vector<averageTimes> times);
#endif //INDICE_REMISIVO_BENCHMARKS_H
