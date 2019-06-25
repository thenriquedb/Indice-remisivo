//
// Created by thiago on 24/06/19.
//

#ifndef INDICE_REMISIVO_HASH_LINKEDLIST_H
#define INDICE_REMISIVO_HASH_LINKEDLIST_H

#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

#include "../helps.h"
#include "../linked_list/List.h"


class hashNode_ll {
private:
    List collisions;
    int key;

public:
    void setKey(int k) { key = k; };

    int getKey() { return key; };

    List getCollisions() { return collisions; };

    void insert(string value, int k) {
        collisions.push(value);
        key = k;
    };


    Node *findElement(string value) {
        Node *current = collisions.getHead();

        while (current != nullptr) {
            if (current->word == value)
                return current;
            current = current->next;
        }

        return nullptr;
    }
};

class hash_linkedList {
private:
    hashNode_ll *table;
    int capacity;

public:
    hash_linkedList(int capacity) {
        this->capacity = capacity; // Tamanho maximo da tabela
        this->table = new hashNode_ll[this->capacity];

        for (int i = 0; i < capacity; ++i) {
            table[i].insert("\0", -1);
        }
    }

    void insert(string value);

    void printIndice();

    void searchKeywords(ifstream &file);

    void insertKeyWords(vector<string> keywords);

    // Retorna um valor entre 0 e 25.
    // Caracter ASCII (97 - 122)
    int getHash(string value);
};


#endif //INDICE_REMISIVO_HASH_LINKEDLIST_H
