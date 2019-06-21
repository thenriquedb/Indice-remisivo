#include <iostream>
#include <fstream>
#include <vector>

#include "linked_list/indice_list.h"
#include "bst/tree.h"
#include "avl/avlTree.h"
#include "benchmarks/benchmarks.h"

using namespace std;

int main(int argc, char *argv[]) {
//    ifstream fileTxt("../texto.txt");
    ifstream fileTxt("../datasets/file3.txt");
    ifstream keywordsTXT("../keywords2.txt");
    if (!fileTxt.is_open() || !keywordsTXT.is_open()) {
        printf("Erro na leitura dos arquivos. \n");
        exit(EXIT_FAILURE);
    }

    vector<string> keyWords = getKeyWords(keywordsTXT);
    cout << "Informações sobre os aruqivos" << endl;
    cout << "\tTotal de linhas do arquivo: " << totalLinesFile(fileTxt)  << endl;
    cout << "\tTotal de palavras chaves: " << keyWords.size() << endl;
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "\t\tLISTA ENCADEADA\n" << endl;
    printf("ÍNDICE REMISSIVO \n");
    list_index linkedList;
    linkedList.insertKeyWords(keyWords);
    linkedList.searchWords(fileTxt);
    linkedList.printIndice();
    benchmark_LinkedList(keyWords, fileTxt, 10);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "\t\tÁRVORE BINÁRIA DE BUSCA (BST)\n" << endl;
    Tree BST;
    BST.insertKeyWords(keyWords);
    BST.searchWords(fileTxt);
    printf("ÍNDICE REMISSIVO \n");
    BST.displayInOrden(BST.getRoot());
    benchmark_BST(keyWords, fileTxt, 10);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;


    cout << "AVL\n" << endl;
    printf("ÍNDICE REMISSIVO \n");
    avlTree AVL;
    AVL.insertKeyWords_avl(keyWords);
    AVL.searchWords(fileTxt);
    AVL.displayInOrden(AVL.getRoot());
    benchmark_AVL(keyWords, fileTxt, 10);
    cout << ":.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.::.:.:.:.:.:" << endl;

    // Fechar os arquivos
    keywordsTXT.close();
    fileTxt.close();

    return 0;
}