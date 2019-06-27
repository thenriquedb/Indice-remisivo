#include <iostream>
#include <fstream>
#include <vector>

#include "linked_list/indice_list.h"
#include "bst/tree.h"
#include "avl/avlTree.h"

#include "hash/closedHash.h"
#include "hash/openHash.h"

#include "benchmarks/benchmarks.h"

#define HASH_SIZE 100000
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

    /* Vetor onde será armazendado o menor tempo de cada benchmark, sendo respectivamente:
    * [0] - Lista encadeada; [1] - BST; [2] - AVL; [3] - Open Hash */
    vector<double> times;

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

    /*
     * Impressão do menor desempenho - TEMPORARIO
     */
    int temp;
    double bestResult = times[0];
    for (int i = 1; i < times.size(); i++)
        if (times[i] < bestResult) {
            temp = i;
            bestResult = times[i];
        }

    string str;
    if (temp == 0)
        str = "Lista encadeada.";
    else if (temp == 1)
        str = "BST";
    else if (temp == 2)
        str = "AVL";
    else if (temp == 4)
        str = "Open Hash";
    cout << "De acordo com resultado dos benchmarks realizados, a estrutura que possui o melhor desempenho foi a " <<
         str << ". Com o tempo médio de " << bestResult << ". " << endl;


    // Fechar os arquivos
    keywordsTXT.close();
    fileTxt.close();

    return 0;
}
