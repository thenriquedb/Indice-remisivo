/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

#ifndef INDICE_REMISIVO_LIST_H
#define INDICE_REMISIVO_LIST_H

#include<string>
#include <vector>
#include <iostream>

#include "../helps.h"

using namespace std;

class Node {
public:
    string word;
    Node *next;
    int *existingLines;
    int totalLines;

    Node(string content) {
        this->totalLines = 0;
        this->existingLines = nullptr;
        this->word = content;
        this->next = nullptr;
    }

    void setNewLine(unsigned int n) {
        existingLines = allocateIntVector(n, existingLines, totalLines);
        totalLines++;
    }
    int getExistingLines(int i) { return existingLines[i]; };
};

class List {
private:
    Node *head;
    int lenght;

public:
    List() { // Construtor
        head = nullptr;
        lenght = 0;
    }

    void push(string content);
    Node* sortList();
    Node *getHead() { return head; };
};

#endif //INDICE_REMISIVO_LIST_H
