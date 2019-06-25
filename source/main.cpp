#include <iostream>
#include <fstream>
#include <vector>

#include "linked_list/indice_list.h"
#include "bst/tree.h"
#include "avl/avlTree.h"

#include "hash/hashZiviani.h"
#include "hash/hash_linkedList.h"

#include "benchmarks/benchmarks.h"

#define ZIVIANI_HASH_SIZE 1007
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

    //Vetor onde será armazendado o menor tempo de cada benchmark, sendo respectivamente:
    vector<double> times; // [0] - Lista encadeada; [1] - BST; [2] - AVL; [3] - Open Hash

    cout << "Informações sobre os aruqivos" << endl;
    cout << "\tTotal de linhas do arquivo: " << totalLinesFile(fileTxt) << endl;
    cout << "\tTotal de palavras chaves: " << keyWords.size() << endl;
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


//
//    cout << "\t\tLISTA ENCADEADA\n" << endl;
//    printf("ÍNDICE REMISSIVO \n");
//    list_index linkedList;
//    linkedList.insertKeyWords(keyWords);
//    linkedList.searchWords(fileTxt);
//    linkedList.printIndice();
//    benchmark_LinkedList(keyWords, &times, fileTxt, EXECUTIONS);
//    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;

//
//    cout << "\t\tÁRVORE BINÁRIA DE BUSCA (BST)\n" << endl;
//    Tree BST;
//    BST.insertKeyWords(keyWords);
//    BST.searchWords(fileTxt);
//    printf("ÍNDICE REMISSIVO \n");
//    BST.displayInOrden(BST.getRoot());
//    benchmark_BST(keyWords, &times, fileTxt, EXECUTIONS);
//    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;
//
//
//    cout << "AVL\n" << endl;
//    printf("ÍNDICE REMISSIVO \n");
//    avlTree AVL;
//    AVL.insertKeyWords_avl(keyWords);
//    AVL.searchWords(fileTxt);
//    AVL.displayInOrden(AVL.getRoot());
//    benchmark_AVL(keyWords, &times, fileTxt, EXECUTIONS);
//    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;
//


//    cout << "\t\tHASH ZIVIANIn" << endl;
//    printf("ÍNDICE REMISSIVO \n");
//    hashZiviani tabela(ZIVIANI_HASH_SIZE);
//    tabela.insertKeyWords(keyWords);
//    tabela.searchKeywords(fileTxt);
//    tabela.printIndice();
//    benchmark_ZivianiHash(keyWords, ZIVIANI_HASH_SIZE, &times, fileTxt, EXECUTIONS);

    cout << "\t\tHASH UTILIZANDO LISTA ENCADEADA" << endl;
    printf("ÍNDICE REMISSIVO \n");
    hash_linkedList hash_ll(26);
    hash_ll.insert("bacaxi");
    hash_ll.insert("bacate");


//    /*
//     * Impressão do menor desempenho - TEMPORARIO
//     */
//    int temp;
//    double bestResult = times[0];
//    for (int i = 1; i < times.size(); i++)
//        if (times[i] < bestResult) {
//            temp = i;
//            bestResult = times[i];
//        }
//
//    string str;
//    if (temp == 0)
//        str = "Lista encadeada.";
//    else if (temp == 1)
//        str = "BST";
//    else if (temp == 2)
//        str = "AVL";
//    else if (temp == 4)
//        str = "Open Hash";
//    cout << "De acordo com resultado dos benchmarks realizados, a estrutura que possui o melhor desempenho foi  a " <<
//         str << ". Com o tempo médio de " << bestResult << ". " << endl;




    // Fechar os arquivos
    keywordsTXT.close();

    fileTxt.close();

    return 0;
}
