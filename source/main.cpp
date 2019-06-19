#include <iostream>
#include <fstream>

#include "linked_list/indice_list.h"
#include "bst/tree.h"
#include "avl/avlTree.h"
#include "helps.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fileTxt("../texto.txt");
    ifstream keywordsTXT("../keywords.txt");
    if (!fileTxt.is_open() || !keywordsTXT.is_open()) {
        printf("Erro na leitura dos arquivos. \n");
        exit(EXIT_FAILURE);
    }

    vector<string> keyWords = getKeyWords(keywordsTXT);
    list_index index(keyWords);

    printf("\nLISTA\n\n");
    index.searchWords(fileTxt);
    index.printIndice();

    Tree arvore;

    printf("\nARVORE \n\n");
    arvore.insertKeyWords(keyWords);
    arvore.searchWords(fileTxt);

    arvore.displayInOrden(arvore.getRoot());

    avlTree avl;

    return 0;
}