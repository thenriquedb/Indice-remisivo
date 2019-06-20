//
// Created by thiago on 13/06/19.
//

#include <iostream>
#include <fstream>
#include <chrono>
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
    Leaf *left;
    Leaf *right;

    int *lines;
    int totalLines, height;

public:
    Leaf(string k) {
        this->key = k;
        height = 1;
        totalLines = 0;
        lines = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    string getKey() { return key; };

    Leaf *getLeft() { return left; };

    Leaf *getRight() { return right; };

    int getTotalLines() { return totalLines; };

    int getHeight() { return height; };

    void setLeft(Leaf *n) { left = n; };

    void setRight(Leaf *n) { right = n; };

    void setHeight(int h) { height = h; }

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
    Leaf *leaf;
    int height, totalNodes;

    static void insertAux(Leaf *n, const string &newKey);

public:
    Tree() { // Construtor
        totalNodes = height = 0;
        leaf = nullptr;
    }


    double benchmark(vector<string> keyWords, ifstream &file);

    Leaf *getRoot() { return leaf; };

    void setRoot(Leaf *n) { n = n; };

    void displayInOrden(Leaf *n);

    void insertNode(const string &new_key);

    void insertKeyWords(vector<string> keyWords);

    void searchWords(ifstream &file);

    int getTreeHeight(Leaf *n);

    int getTotalNodes() { return totalNodes; };

    Leaf *search(Leaf *l, string s);



    // Libera os nós da arvóre
//    void freeTreeNodes(Leaf *leaf);
};

#endif //INDICE_REMISIVO_TREE_H
