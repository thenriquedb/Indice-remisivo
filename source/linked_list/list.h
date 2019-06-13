//
// Created by thiago on 11/06/19.
//

#ifndef INDICE_REMISIVO_LIST_H
#define INDICE_REMISIVO_LIST_H

#include<string>

using namespace std;

class Node {
public:
    string word;
    Node *next;

    Node(string content) {
        this->word = content;
        this->next = nullptr;
    }
};

class list {
private:
    Node *head;
    int lenght;

public:
    list() { // Construtor
        head = nullptr;
        lenght = 0;
    }

    void push(string content);

    int getLenght() { return lenght; };
    Node *getHead() { return head; };

    void display();

//    void alphabetical_order();
};

#endif //INDICE_REMISIVO_LIST_H
