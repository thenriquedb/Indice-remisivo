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
    void insertKeyWords(vector<string> keyWordsArray) {
        for (int i = keyWordsArray.size() - 1; i > 0; i--) {
            if (keyWordsArray[i].size() >= 4)
                keyWords.push(keyWordsArray[i]);
        }
        lenght = keyWordsArray.size();
    }

    void searchWords(ifstream &file);

    double benchmark(vector<string> keyWords, ifstream &file);

    void printIndice();
};

#endif //INDICE_REMISIVO_INDICE_LIST_H
