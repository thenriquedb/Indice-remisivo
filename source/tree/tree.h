//
// Created by thiago on 13/06/19.
//

#include <iostream>
#include <fstream>

using namespace std;

#ifndef INDICE_REMISIVO_TREE_H
#define INDICE_REMISIVO_TREE_H

class Leaf {
private:
    string key;
    Leaf *left;
    Leaf *right;

public:
    Leaf(string k) {
        this->key = k;
        this->left = nullptr;
        this->right = nullptr;
    }

    string getKey() { return key; };

    Leaf *getLeft() { return left; };

    Leaf *getRight() { return right; };

    void setLeft(Leaf *n) { left = n; };

    void setRight(Leaf *n) { right = n; };
};

class Tree {
private:
    Leaf *root;
    int totalNodes;
    int elements[30]; // Vetor de elementos
    int indice; // Utilizado para o controle do vetor de elementos

    static void insertAux(Leaf *n, const string& newKey);

public:
    Tree() { // Construtor
        totalNodes = indice = 0;
        root = nullptr;
    }

    // Retorna raiz
    Leaf *getRoot() { return root; };

    void setRoot(Leaf *n) { root = n; };

    void displayInOrden(Leaf* n);

    // Insere um novo elemento na arvore
    void insertNode(const string& new_key);

    Leaf *balancedTree(vector<string> keyWords, unsigned int start, unsigned int final);


        // Verifica se a arvore possui determinado elemento e retorna um valor booleano
//    Leaf *searchElement(Leaf *n, unsigned int k);

    // Retorna a altura da arvore
    int getHeight(Leaf *n);

    int getTotalNodes() { return totalNodes; };

    // Imprime por level
    void printLevel(Leaf *n);

    // Imprime todos os elementos de determinado level
    void printElementsByLevel(Leaf *n, unsigned int level);


    // Libera os nós da arvóre
    void freeTreeNodes(Leaf *n);
};

class indexTree{
private:
    Tree* root;

};

#endif //INDICE_REMISIVO_TREE_H
