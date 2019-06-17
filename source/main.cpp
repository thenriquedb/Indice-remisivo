#include <iostream>
#include <fstream>

#include "linked_list/indice_list.h"
#include "tree/tree.h"
#include "helps.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fileTxt("../texto.txt");
    ifstream keywordsTXT("../keywords.txt");
    if (!fileTxt.is_open() && !keywordsTXT.is_open()) {
        printf("Erro na leitura dos arquivos. \n");
        exit(EXIT_FAILURE);
    }
    vector<string> keyWords = getKeyWords(keywordsTXT);

    list_index index(keyWords);
    index.searchWords(fileTxt);
    index.printIndice();

    Tree arvore;
//    arvore.insertNode("Mario");
//    arvore.insertNode("Mano Walter");
//    arvore.insertNode("Thiago");
//    arvore.insertNode("Ana");
//arvore.insertLevelOrder(keyWords, 0,keyWords.size());
//    arvore.balancedTree(keyWords, 0, keyWords.size() - 1);
    arvore.displayInOrden(arvore.getRoot());
    return 0;
}