/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

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

class closedHash {
private:
    hashNode *table;
    int capacity, hashUsed;     // Capacidade maxima e  Capacidade maxima

    int generateIndex_1(string key);

    // Hash Ziviani
    int generateIndex_2(string key);
    int generateWeights();
    vector<int> weights;

    int generateIndex_3(string key);
    int searchIndex(string key);

    void exportIndexTxt(string table);
    void insert(string key);
    void printIndice();

public:
    // Constructor
    explicit closedHash(unsigned int capacity, int hash) {
        this->capacity = capacity; // Tamanho maximo da tabela
        this->table = new hashNode[this->capacity];
        this->hashUsed = hash;

        // Inicia as celulas
        for (int i = 0; i < this->capacity; ++i)
            table[i].insertItem("\0", -1);

        if (this->hashUsed == 2)
            generateWeights();
    }

    void searchKeywords(ifstream &file);
    void insertKeyWords(vector<string> keywords);

    void run(vector<string> keyWords,ifstream &file);

    double benchmark(vector<string> keyWords, ifstream &file);
};


#endif //INDICE_REMISIVO_HASHTABLE_H
