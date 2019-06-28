/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

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
    explicit Leaf(string k) {
        this->key = k;
        height = 0;
        totalLines = 0;

        lines = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    string getKey() { return key; };
    Leaf *getLeft() { return left; };
    Leaf *getRight() { return right; };
    int getHeight() {return height; };
    int getTotalLines() {return totalLines; };
    void setLeft(Leaf *n) { left = n; };
    void setRight(Leaf *n) { right = n; };
    void setHeight(int h) { height = h; }
    void setNewLine(int n) {
        lines = allocateIntVector(n, lines, totalLines);
        totalLines++;

    }
    int* getExistingLines() { return lines; };
    void displayTotalLines() { for (int i = 0; i < totalLines; i++) cout << lines[i] << ' '; }
};

class Tree {
private:
    Leaf *root;
    int height, totalNodes;
    static void insertAux(Leaf *n, const string &newKey);

protected:
    void setRoot(Leaf* n){ root = n;}
    Leaf *getRoot() { return root; };
    void displayInOrden(Leaf *n);
    void insertNode(const string &new_key);
    void insertKeyWords(vector<string> keyWords);
    void searchWords(ifstream &file);
    Leaf *search(Leaf *l, string s);
    void exportIndexTxt(vector<string> sort_keywords);
public:
    Tree() { // Construtor
        totalNodes = height = 0;
        root = nullptr;
    }
    void run(vector<string> keyWords,  ifstream &file);
    double benchmark(vector<string> keyWords, ifstream &file);
};

#endif //INDICE_REMISIVO_TREE_H
