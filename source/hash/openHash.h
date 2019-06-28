/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

#ifndef INDICE_REMISIVO_OPENHASH_H
#define INDICE_REMISIVO_OPENHASH_H

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

class openHash {
private:
    hashNode_ll *table;
    int capacity, hashUsed;  // Capacidade maxima e capacidade maxima

    int generateIndex_1(string key);

    // Hash Ziviani
    int generateIndex_2(string key);
    int generateWeights();
    vector<int> weights;  // Vetor de pesos utilizado para o calculo do hash utilizando o método de Ziviani

    int generateIndex_3(string key);
    void insert(string key);
    void exportIndexTxt(string table);
public:
    explicit openHash(int capacity, int hash) {
        this->capacity = capacity; // Tamanho maximo da tabela
        this->table = new hashNode_ll[this->capacity];
        this->hashUsed = hash;

        // Inicia as celulas
        for (int i = 0; i < capacity; ++i) {
            table[i].insert("\0", -1);
        }

        if (this->hashUsed == 2)
            generateWeights();
    }

    void run(vector<string> keyWords,ifstream &file);
    void insertKeyWords(vector<string> keywords);
    void searchKeywords(ifstream &file);
    void printIndice();
    double benchmark(vector<string> keyWords, ifstream &file);
};

#endif //INDICE_REMISIVO_OPENHASH_H
