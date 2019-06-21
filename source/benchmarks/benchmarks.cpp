//
// Created by thiago on 20/06/19.
//


#include <iostream>
#include <fstream>
#include<string>
#include<vector>

#include "../helps.h"
#include "../external/fort.h"
#include "../external/fort.hpp"
#include "../bst/tree.h"
#include "../avl/avlTree.h"
#include "../linked_list/indice_list.h"

using namespace std;

void benchmark_BST(vector<string> keyWords, ifstream &file, int totalExecutions) {
    fort::table table;
    double time, sumTimes = 0, min, max;

    cout << "\nBENCHMARK" << endl;
    table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;
    for (int i = 0; i < totalExecutions; i++) {
        Tree temp;
        time = temp.benchmark(keyWords, file);
        if (i == 0)
            min = max = time;
        if (time < min)
            min = time;
        if (time > max)
            max = time;

        sumTimes += time;
        table << i << "BST" << time << fort::endr;
    }
    std::cout << table.to_string() << std::endl;


    cout << "RESULTADOS" << endl;
    fort::table table2;
    table2 << fort::header << "Menor tempo" << "Maior tempo" << "Tempo total" << "Tempo médio" << fort::endr;
    table2 << min << max << sumTimes << sumTimes / totalExecutions << fort::endr;
    std::cout << table2.to_string() << std::endl;
}

void benchmark_AVL(vector<string> keyWords, ifstream &file, int totalExecutions) {
    fort::table table;
    double time, sumTimes = 0, min, max;

    cout << "\nBENCHMARK" << endl;
    table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;
    for (int i = 0; i < totalExecutions; i++) {
        avlTree temp;
        time = temp.benchmarkAVL(keyWords, file);
        if (i == 0)
            min = max = time;
        if (time < min)
            min = time;
        if (time > max)
            max = time;

        sumTimes += time;
        table << i << "AVL" << time << fort::endr;
    }
    std::cout << table.to_string() << std::endl;


    cout << "RESULTADOS" << endl;
    fort::table table2;
    table2 << fort::header << "Menor tempo" << "Maior tempo" << "Tempo total" << "Tempo médio" << fort::endr;
    table2 << min << max << sumTimes << sumTimes / totalExecutions << fort::endr;
    std::cout << table2.to_string() << std::endl;
}

void benchmark_LinkedList(vector<string> keyWords, ifstream &file, int totalExecutions) {
    fort::table table;
    double time, sumTimes = 0, min, max;

    cout << "\nBENCHMARK" << endl;
    table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;
    for (int i = 0; i < totalExecutions; i++) {
        list_index temp;
        time = temp.benchmark(keyWords, file);
        if (i == 0)
            min = max = time;
        if (time < min)
            min = time;
        if (time > max)
            max = time;

        sumTimes += time;
        table << i << "Lista encadeada" << time << fort::endr;
    }
    std::cout << table.to_string() << std::endl;


    cout << "RESULTADOS" << endl;
    fort::table table2;
    table2 << fort::header << "Menor tempo" << "Maior tempo" << "Tempo total" << "Tempo médio" << fort::endr;
    table2 << min << max << sumTimes << sumTimes / totalExecutions << fort::endr;
    std::cout << table2.to_string() << std::endl;
}