#include <utility>

//
// Implementação do método de Nivio Ziviani
//

#ifndef INDICE_REMISIVO_HASHTABLE_H
#define INDICE_REMISIVO_HASHTABLE_H

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class hashNode {
private:
    string word;
    int key;

public:
    void insertItem(string value, int k) {
        word = std::move(value);
        key = k;
    };

    string getValue() { return word; };

    int getKey() { return key; };

};

class hashTable {
    hashNode *table;
    int capacity;
    vector<int> weights;

private:
    // Gera os valores dos pesos aleatoriamente
    int generateWeights() {
        std::srand(time(nullptr));
        for (int i = 0; i < this->capacity; i++)
            this->weights.push_back(rand() % this->capacity);
    }

    int h(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum = sum + (int) key[i] * weights[i];
        }

        return sum % this->capacity;
    }

    int searchIndex(string key);


public:
    explicit hashTable(unsigned int capacity) {
        this->capacity = capacity; // Tamanho maximo da tabela
        this->table = new hashNode[this->capacity];

        // Inicia as celulas
        for (int i = 0; i < this->capacity; ++i)
            table[i].insertItem("\0", -1);

        generateWeights();
    }

    void insert(string key);

    string searchWord(string key);

    void insertKeyWords(vector<string> keywords);

    // Temporario
    void printElemnto();

};


#endif //INDICE_REMISIVO_HASHTABLE_H
