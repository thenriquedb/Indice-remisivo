//
// Created by thiago on 11/06/19.
//

#ifndef INDICE_REMISIVO_INDICE_LIST_H
#define INDICE_REMISIVO_INDICE_LIST_H

#include<string>
#include<iostream>

#include "List.h"

using namespace std;


class word {
public:
    string content;
    int contLines; // Variavel para controle do vetor
    int *existingLines; // Vetor para armazenar em quais linhas a palavra é encontrada
    word *next;

    word() {
        contLines = 0;
        next = nullptr;
        existingLines = nullptr;
    }
};

/*
 * Implementação do indice remissivo utilizando a estrutura de lista encadeada
 */
class list_index {
private:
    List keyWords; // Lista das palavras chaves
    word *head;
    int lenght;

public:
    list_index() {
        head = nullptr;
        lenght = 0;
    }
    void setKeyWords();

    bool push(string word, unsigned int line);

    void searchWords(ifstream &file);

    void printIndice();
};

#endif //INDICE_REMISIVO_INDICE_LIST_H
