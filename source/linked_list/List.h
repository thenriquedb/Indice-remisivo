//
// Created by thiago on 11/06/19.
//

#ifndef INDICE_REMISIVO_LIST_H
#define INDICE_REMISIVO_LIST_H

#include<string>
#include <vector>

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

    int getLenght() { return lenght; };

    Node *getHead() { return head; };

    void display();
};

#endif //INDICE_REMISIVO_LIST_H
