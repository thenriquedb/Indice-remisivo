#include <iostream>
#include <fstream>

#include "indice_list.h"

using namespace std;

int main() {
    list_index index;
    ifstream file("../texto.txt");
    if (!file.is_open()) {
        printf("Impossivel abrir o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    index.setKeyWords();
    index.searchWords(file);
    index.displayWords();
    return 0;
}