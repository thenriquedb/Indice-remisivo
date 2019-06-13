#include <iostream>
#include <fstream>

#include "indice_list.h"
#include "tree/tree.h"

using namespace std;

int main() {
    ifstream file("../texto.txt");
    if (!file.is_open()) {
        printf("Impossivel abrir o arquivo. \n");
        exit(EXIT_FAILURE);
    }

//    list_index index;
    Tree arvore;

    arvore.insertNode("Arroz");
    arvore.insertNode("Beterraba");
    arvore.insertNode("Caixeta");
    arvore.insertNode("Donkey");

//    index.setKeyWords();
//    index.searchWords(file);
//    index.displayWords();
    return 0;
}