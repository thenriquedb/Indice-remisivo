//
// Created by thiago on 18/06/19.
//

#ifndef INDICE_REMISIVO_AVLTREE_H
#define INDICE_REMISIVO_AVLTREE_H

#include "../bst/tree.h"
#include "../bst/tree.h"
#include "../helps.h"

/*
 * Classe avlTree é uma classe filha de Tree
 */
class avlTree {
private:
    Leaf *root;
    int height;

    int heightDifference(Leaf *n);
    Leaf *search(Leaf *l, string s);
    Leaf *rightRotate(Leaf *y);
    Leaf *leftRotate(Leaf *y);
    Leaf *getRoot() { return root; };
    Leaf *insert_avl(Leaf *n, const string &new_key);
    void insertKeyWords_avl(vector<string> keyWords);
    void displayInOrden(Leaf *n);
    void searchWords(ifstream &file);

public:
    explicit avlTree() {
        root = nullptr;
        height = 0;
    }
    void run(vector<string> keyWords,ifstream &file);
    double benchmarkAVL(vector<string> keyWords, ifstream &file);

};


#endif //INDICE_REMISIVO_AVLTREE_H
