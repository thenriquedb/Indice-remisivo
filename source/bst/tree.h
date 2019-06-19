//
// Created by thiago on 13/06/19.
//

#include <iostream>
#include <fstream>
#include "../helps.h"


using namespace std;

#ifndef INDICE_REMISIVO_TREE_H
#define INDICE_REMISIVO_TREE_H

/*
 * Classe nó da arvore
 */
class Leaf {
private:
    string key;
    int *lines;
    int totalLines;
    Leaf *left;
    Leaf *right;

public:
    Leaf(string k) {
        this->key = k;
        lines = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    string getKey() { return key; };

    Leaf *getLeft() { return left; };
    Leaf *getRight() { return right; };

    void setLeft(Leaf *n) { left = n; };
    void setRight(Leaf *n) { right = n; };

    int getTotalLines() { return totalLines; };

    void setNewLine(int n) {
        lines = allocateIntVector(n, lines, totalLines);
        totalLines++;
    }
    void displayTotalLines() {
        for (int i = 0; i < totalLines; i++)
            cout << lines[i] << ' ';
    }
};

class Tree {
private:
    Leaf *root;
    int height, totalNodes;

    static void insertAux(Leaf *n, const string &newKey);

public:
    Tree() { // Construtor
        totalNodes = height = 0;
        root = nullptr;
    }

    // Retorna raiz
    Leaf *getRoot() { return root; };


    void setRoot(Leaf *n) { root = n; };

    void displayInOrden(Leaf *n);

    // Insere um novo elemento na arvore
    void insertNode(const string &new_key);

    void insertKeyWords(vector<string> keyWords);

    void searchWords(ifstream &file);

    // Verifica se a arvore possui determinado elemento e retorna um valor booleano
//    Leaf *searchElement(Leaf *n, unsigned int k);

    // Retorna a altura da arvore
    int getHeight(Leaf *n);

    int getTotalNodes() { return totalNodes; };


    // Imprime todos os elementos de determinado level
    void printElementsByLevel(Leaf *n, unsigned int level);

    Leaf *search(Leaf *l, string s);

    // Libera os nós da arvóre
    void freeTreeNodes(Leaf *n);
};

#endif //INDICE_REMISIVO_TREE_H
