#include <iostream>
#include <fstream>

#include "linked_list/indice_list.h"
#include "tree/tree.h"
#include "helps.h"

using namespace std;

int main() {
    ifstream fileTxt("../texto.txt");
    ifstream keywordsTXT("../keywords.txt");
    if (!fileTxt.is_open() && !keywordsTXT.is_open()) {
        printf("Erro na leitura dos arquivos. \n");
        exit(EXIT_FAILURE);
    }

    vector<string> keyWords = getKeyWords(keywordsTXT);
    for (int i=0; i< keyWords.size(); i++)
        cout << keyWords[i] << endl;

    //    list_index index;
    Tree arvore;

//    arvore.insertNode("Arroz");
//    arvore.insertNode("Beterraba");
//    arvore.insertNode("Caixeta");
//    arvore.insertNode("Donkey");


//    index.setKeyWords();
//    index.searchWords(fileTxt);
//    index.printIndice();
    return 0;
}