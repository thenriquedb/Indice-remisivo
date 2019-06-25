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

#include "../helps.h"

using namespace std;

class hashNode {
private:
    string word;
    int key, totalLines;
    int *existingLines;

public:
    void insertItem(string value, int k) {
        word = std::move(value);
        key = k;
        totalLines = 0;
        existingLines = nullptr;
    };

    string getValue() { return word; };

    void setNewLine(unsigned int n) {
        existingLines = allocateIntVector(n, existingLines, totalLines);
        totalLines++;
    }

    int getExistingLines(int i) { return existingLines[i]; };

    int getTotalLines() { return totalLines; };

    int getKey() { return key; };

};

class hashZiviani {
private:
    hashNode *table;
    int capacity;
    vector<int> weights;

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

    hashNode getTable(int index) { return table[index]; };

public:
    explicit hashZiviani(unsigned int capacity) {
        this->capacity = capacity; // Tamanho maximo da tabela
        this->table = new hashNode[this->capacity];

        // Inicia as celulas
        for (int i = 0; i < this->capacity; ++i)
            table[i].insertItem("\0", -1);

        generateWeights();
    }

    void insert(string key);

    void searchKeywords(ifstream &file);

    void insertKeyWords(vector<string> keywords);

    double benchmark(vector<string> keyWords, ifstream &file);

    void printIndice();

};


#endif //INDICE_REMISIVO_HASHTABLE_H
