#include <iostream>
#include <fstream>
#include <vector>

#include "linked_list/indice_list.h"
#include "bst/tree.h"
#include "avl/avlTree.h"
#include "benchmarks/benchmarks.h"
#include "external/fort.h"
#include "external/fort.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fileTxt("../texto.txt");
    ifstream keywordsTXT("../keywords.txt");
    if (!fileTxt.is_open() || !keywordsTXT.is_open()) {
        printf("Erro na leitura dos arquivos. \n");
        exit(EXIT_FAILURE);
    }

    vector<string> keyWords = getKeyWords(keywordsTXT);
    cout << "Informações sobre os aruqivos" << endl;
    cout << "\tTotal de linhas do arquivo: " << totalLinesFile(fileTxt) << endl;
    cout << "\tTotal de palavras chaves: " << keyWords.size() << endl << endl;


    cout << "---------------------------------------------------" << endl;
    cout << "ÁRVORE BINÁRIA DE BUSCA (BST)\n" << endl ;
    printf("ÍNDICE REMISSIVO \n");
    Tree BST;
    BST.insertKeyWords(keyWords);
    BST.searchWords(fileTxt);
    BST.displayInOrden(BST.getRoot());

    benchmark_BST(keyWords, fileTxt, 10);


//    list_index index(keyWords);
//
//    printf("\nLISTA\leaf\leaf");
//    index.searchWords(fileTxt);
//    index.printIndice();



    avlTree avl;
//    avl.init(keyWords,fileTxt);

//    printf("\nAVL\leaf\leaf");
//    avl.displayInOrden(avl.getRoot());

    return 0;
}