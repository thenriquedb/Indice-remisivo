//
// Created by thiago on 24/06/19.
//

#ifndef INDICE_REMISIVO_HASH_LINKEDLIST_H
#define INDICE_REMISIVO_HASH_LINKEDLIST_H

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

#include "../helps.h"
#include "../linked_list/List.h"


class hashNode_ll {
private:
//    string content;
    List collisions;
    int key;

public:

    void setKey(int k) { key = k; };

    int getKey() { return key; };

    void insert(string value, int k) {
        collisions.push(value);
        key = k;
    };

};

class hash_linkedList {
private:
    hashNode_ll *table;
    int capacity;

public:
    hash_linkedList(int capacity) {
        this->capacity = capacity; // Tamanho maximo da tabela
        this->table = new hashNode_ll[this->capacity];
    }

    void insert(string value) {
        int index = getHash(value);
        table->insert(value, index);
    }

    // Retorna um valor entre 0 e 25.
    // Caracter ASCII (97 - 122)
    int getHash(string value) {
        return (122 - (int) value[0]);
    }
};


#endif //INDICE_REMISIVO_HASH_LINKEDLIST_H
