//
// Created by thiago on 11/06/19.
//

#ifndef INDICE_REMISIVO_INDICE_LIST_H
#define INDICE_REMISIVO_INDICE_LIST_H

#include<string>
#include<vector>
#include<iostream>

#include "List.h"

using namespace std;

/*
 * Implementação do indice remissivo utilizando a estrutura de lista encadeada
 */
class list_index {
private:
    List keyWords; // Lista das palavras chaves
    int lenght;

public:
    explicit list_index(vector<string> keyWordsArray) {
        for (int i = keyWordsArray.size() - 1; i > 0; i--) {
                keyWords.push(keyWordsArray[i]);
        }
        lenght = keyWordsArray.size();
    }

    void searchWords(ifstream &file);

    void printIndice();
};

#endif //INDICE_REMISIVO_INDICE_LIST_H
