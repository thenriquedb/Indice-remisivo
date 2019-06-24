//
//
//
#include <iostream>
#include <fstream>
#include<string>
#include<vector>

#include "../helps.h"
#include "benchmarks.h"
#include "../external/fort.h"
#include "../external/fort.hpp"
#include "../bst/tree.h"
#include "../avl/avlTree.h"
#include "../linked_list/indice_list.h"

using namespace std;

void benchmark_BST(vector<string> keyWords,  vector<double> *times, ifstream &file, int totalExecutions) {
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

    times->push_back(sumTimes / totalExecutions);
    exportBenchmark_txt("BST", table.to_string(), table2.to_string());
}

void benchmark_AVL(vector<string> keyWords,  vector<double> *times, ifstream &file, int totalExecutions) {
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

    times->push_back(sumTimes / totalExecutions);
    exportBenchmark_txt("AVL", table.to_string(), table2.to_string());
}

void benchmark_LinkedList(vector<string> keyWords, vector<double> *times, ifstream &file, int totalExecutions) {
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

    times->push_back(sumTimes / totalExecutions);
    exportBenchmark_txt("Lista_encadeada", table.to_string(), table2.to_string());
}

void exportBenchmark_txt(string type, string table1, string table2) {
    ofstream file, fileAll;
    string path = "../outputs/benchmarks/benchmark_" + type + ".txt";
    file.open(path, ios::app);
    fileAll.open("../outputs/benchmarks/benchmarks_ALL.txt", ios::app);

    file << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;
    file << type << endl;
    file << table1 << endl;
    file << "RESULTADOS" << endl;
    file << table2 << endl;
    file << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;

    // Armazena todos os benchmaks realizados em um unico arquivo
    fileAll << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;
    fileAll << type << endl;
    fileAll << table1 << endl;
    fileAll << "RESULTADOS" << endl;
    fileAll << table2 << endl;
    fileAll << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;

    file.close();
    fileAll.close();
}