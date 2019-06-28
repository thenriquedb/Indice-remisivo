/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

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

/*
 * Realiza o teste de desemenho da estrutura BST.
 * O calculo do tempo é feito levando em consideração o tempo de inserção das palavras na estrutura e o tempo gasto para
 * a pesquisa das mesmas no arquivo TXT.
 *
 * @param
 *      vector<string> keyWords -  vetor que contém as palavras chaves
 *      vector<averageTimes> *times - vetor da classe "averageTimes" que armazena as informações sobre o benchmark
 *      ifstream &file - arquivo de texto que será lido
 *      int totalExecutions - número de vezes que o benchmark será rodado
 */
void benchmark_BST(vector<string> keyWords, vector<averageTimes> *times, ifstream &file, int totalExecutions) {
    double time, sumTimes = 0, min, max;

    fort::table table;
    table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;

    cout << "\nBENCHMARK" << endl;
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

    // Exportando o tempos de execução
    averageTimes temp;
    temp.setTimes("BST", sumTimes, sumTimes / totalExecutions, min, max);
    times->push_back(temp);
    exportBenchmark_txt("BST", table.to_string(), table2.to_string());
}

/*
 * Realiza o teste de desemenho da estrutura AVL.
 * O calculo do tempo é feito levando em consideração o tempo de inserção das palavras na estrutura e o tempo gasto para
 * a pesquisa das mesmas no arquivo TXT.
 *
 * @param
 *      vector<string> keyWords -  vetor que contém as palavras chaves
 *      vector<averageTimes> *times - vetor da classe "averageTimes" que armazena as informações sobre o benchmark
 *      ifstream &file - arquivo de texto que será lido
 *      int totalExecutions - número de vezes que o benchmark será rodado
 */
void benchmark_AVL(vector<string> keyWords, vector<averageTimes> *times, ifstream &file, int totalExecutions) {
    double time, sumTimes = 0, min, max;

    fort::table table;
    table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;

    cout << "\nBENCHMARK" << endl;
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

    // Exportando o tempos de execução
    averageTimes temp;
    temp.setTimes("AVL", sumTimes, sumTimes / totalExecutions, min, max);
    times->push_back(temp);
    exportBenchmark_txt("AVL", table.to_string(), table2.to_string());
}

/*
 * Realiza o teste de desemenho da estrutura de lista encadeada.
 * O calculo do tempo é feito levando em consideração o tempo de inserção das palavras na estrutura e o tempo gasto para
 * a pesquisa das mesmas no arquivo TXT.
 *
 * @param
 *      vector<string> keyWords -  vetor que contém as palavras chaves
 *      vector<averageTimes> *times - vetor da classe "averageTimes" que armazena as informações sobre o benchmark
 *      ifstream &file - arquivo de texto que será lido
 *      int totalExecutions - número de vezes que o benchmark será rodado
 */
void benchmark_LinkedList(vector<string> keyWords, vector<averageTimes> *times, ifstream &file, int totalExecutions) {
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

    // Exportando o tempos de execução
    averageTimes temp;
    temp.setTimes("Lista encadeada", sumTimes, sumTimes / totalExecutions, min, max);
    times->push_back(temp);

    exportBenchmark_txt("Lista_encadeada", table.to_string(), table2.to_string());
}

/*
 * Realiza o teste de desemenho das estruturas open e closed hash.
 * O calculo do tempo é feito levando em consideração o tempo de inserção das palavras na estrutura e o tempo gasto para
 * a pesquisa das mesmas no arquivo TXT.
 *
 * @param
 *      vector<string> keyWords -  vetor que contém as palavras chaves
 *      vector<averageTimes> *times - vetor da classe "averageTimes" que armazena as informações sobre o benchmark
 *      ifstream &file - arquivo de texto que será lido
 *      int totalExecutions - número de vezes que o benchmark será rodado
 */
void benchmarkHash(string type, vector<string> keyWords, int CAPACITY, vector<averageTimes> *times,
                   ifstream &file, int totalExecutions) {

    // Executa todas as três funções de calculo de hash
    for (int hashFunction = 1; hashFunction <= 3; ++hashFunction) {
        double time, sumTimes = 0, min, max;

        string s_hashFunction = (type + " hash ") + to_string(hashFunction);
        closedHash temp_closedHash(CAPACITY, hashFunction);
        openHash temp_openHash(CAPACITY, hashFunction);

        fort::table table;
        table << fort::header << "N" << "Estrutura" << "Tempo" << fort::endr;

        cout << "\nBENCHMARK UTILIZANDO O A FUNÇÃO HASH " << hashFunction << endl;
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

        // Exportando o tempos de execução
        averageTimes temp;
        temp.setTimes(type + " hash - Metodo " + to_string(hashFunction), sumTimes, sumTimes / totalExecutions, min,
                      max);
        times->push_back(temp);
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

void checkBenchmarkResults(vector<averageTimes> times) {
    double min, max, average, total;
    string dataStruct_min, dataStruct_max, dataStruct_average, dataStruct_total;

    min = times[0].getMinTime();
    max = times[0].getMaxTime();
    average = times[0].getAverageTime();
    total = times[0].getTotalTime();

    for (int i = 0; i < times.size(); i++) {
        if (times[i].getMinTime() < min) {
            dataStruct_min = times[i].getDataStruct();
            min = times[i].getMinTime();
        }
        if (times[i].getMaxTime() > max) {
            dataStruct_max = times[i].getDataStruct();
            max = times[i].getMaxTime();
        }
        if (times[i].getAverageTime() < average) {
            dataStruct_average= times[i].getDataStruct();
            average = times[i].getAverageTime();
        }
        if (times[i].getTotalTime() < total) {
            dataStruct_total = times[i].getDataStruct();
            total = times[i].getTotalTime();
        }
    }

    cout << "Menor tempo registrado foi de " << min << " utilizando a estrutura " << dataStruct_min << endl;
    cout << "Maior tempo registrado foi de " << max << " utilizando a estrutura " << dataStruct_max << endl;
    cout << "Menor tempo medio registrado foi de " << average << " utilizando a estrutura " << dataStruct_average << endl;
    cout << "Menor tempo total de execução registrado foi de " << total << " utilizando a estrutura " << dataStruct_total<< endl;
}