#include <iostream>
#include <fstream>
#include <vector>

#include "linked_list/indice_list.h"
#include "bst/tree.h"
#include "avl/avlTree.h"
#include "hash/closedHash.h"
#include "hash/openHash.h"
#include "benchmarks/benchmarks.h"

#define HASH_SIZE 10000
#define EXECUTIONS 10

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fileTxt("../texto.txt");

//    ifstream fileTxt("../datasets/words_alpha.txt");
    ifstream keywordsTXT("../keywords.txt");
    if (!fileTxt.is_open() || !keywordsTXT.is_open()) {
        printf("Erro na leitura dos arquivos. \n");
        exit(EXIT_FAILURE);
    }

    vector<string> keyWords = getKeyWords(keywordsTXT);
    vector<averageTimes> times;


    cout << "Informações sobre os aruqivos" << endl;
    cout << "\tTotal de linhas do arquivo: " << totalLinesFile(fileTxt) << endl;
    cout << "\tTotal de palavras chaves: " << keyWords.size() << endl;
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "\t\tLISTA ENCADEADA\n" << endl;
    list_index LinkedList;
    printf("ÍNDICE REMISSIVO \n");
    LinkedList.run(keyWords, fileTxt);
    benchmark_LinkedList(keyWords, &times, fileTxt, EXECUTIONS);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "\t\tÁRVORE BINÁRIA DE BUSCA (BST)\n" << endl;
    Tree BST;
    printf("ÍNDICE REMISSIVO \n");
    BST.run(keyWords, fileTxt);
    benchmark_BST(keyWords, &times, fileTxt, EXECUTIONS);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "AVL\n" << endl;
    avlTree AVL;
    AVL.run(keyWords, fileTxt);
    benchmark_AVL(keyWords, &times, fileTxt, EXECUTIONS);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "\t\t\tCLOSED HASH\n" << endl;
    closedHash ClosedHash(HASH_SIZE, 1);
    ClosedHash.run(keyWords, fileTxt);
    benchmarkHash("closed", keyWords, 10000, &times, fileTxt, EXECUTIONS);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "\t\t\tOPEN HASH \n" << endl;
    openHash OpenHash(26, 1);
    OpenHash.run(keyWords, fileTxt);
    benchmarkHash("open", keyWords, 10000, &times, fileTxt, EXECUTIONS);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;

    checkBenchmarkResults(times);

    // Fechar os arquivos
    keywordsTXT.close();
    fileTxt.close();

    return 0;
}
