//
//
//
#include <iostream>
#include <fstream>
#include<string>
#include<vector>

#include "benchmarks.h"
#include "../helps.h"

// External
#include "../external/fort.h"
#include "../external/fort.hpp"
// Estruturas
#include "../bst/tree.h"
#include "../avl/avlTree.h"
#include "../linked_list/indice_list.h"
#include "../hash/closedHash.h"
#include "../hash/openHash.h"

using namespace std;

void benchmark_BST(vector<string> keyWords, vector<double> *times, ifstream &file, int totalExecutions) {
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

void benchmark_AVL(vector<string> keyWords, vector<double> *times, ifstream &file, int totalExecutions) {
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

void benchmarkHash(string type, vector<string> keyWords, int CAPACITY, vector<double> *times,
                   ifstream &file, int totalExecutions) {

    // Executa todas as três funções de calculo de hash
    for (int hashFunction = 1; hashFunction <= 3; ++hashFunction) {
        fort::table table;
        double time, sumTimes = 0, min, max;
        string s_hashFunction = (type + " hash ") + to_string(hashFunction);

        closedHash temp_closedHash(CAPACITY, hashFunction);
        openHash temp_openHash(CAPACITY, hashFunction);


        cout << "\nBENCHMARK UTILIZANDO O A FUNÇÃO HASH " << hashFunction << endl;
        table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;

        for (int i = 0; i < totalExecutions; i++) {
            // Caso deseja realziar o benchmark da estrutura closed hash
            if (type == "closed") {
                temp_closedHash.insertKeyWords(keyWords);
                temp_closedHash.searchKeywords(file);
                time = temp_closedHash.benchmark(keyWords, file);

                if (i == 0)
                    min = max = time;
                if (time < min)
                    min = time;
                if (time > max)
                    max = time;
            }

            // Caso deseja realziar o benchmark da estrutura open hash
            if (type == "open") {
                temp_openHash.insertKeyWords(keyWords);
                temp_openHash.searchKeywords(file);
                time = temp_openHash.benchmark(keyWords, file);

                if (i == 0)
                    min = max = time;
                if (time < min)
                    min = time;
                if (time > max)
                    max = time;
            }

            sumTimes += time;
            table << i << s_hashFunction << time << fort::endr;
        }

        std::cout << table.to_string() << std::endl;

        cout << "RESULTADOS UTILIZANDO A ESTRUTURA " << s_toUpper(type) << " HASH" << endl;
        fort::table table2;
        table2 << fort::header << "Menor tempo" << "Maior tempo" << "Tempo total" << "Tempo médio" << fort::endr;
        table2 << min << max << sumTimes << sumTimes / totalExecutions << fort::endr;

        std::cout << table2.to_string() << std::endl;
        times->push_back(sumTimes / totalExecutions);
        exportBenchmark_txt("closedHash", table.to_string(), table2.to_string());
    }
}


/*
 * Exporta o resultado dos benchmarks em um arquivo TXT.
 *
 * @param string type Estrutura utilizada
 *        string table1 Tabela que contém o tempo dos benchmarks
 *        string table2 Tabela que contém o resultado final
 */
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