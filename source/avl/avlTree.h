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
    int height, totalNodes;


public:

    avlTree() {
        root = nullptr;
        height = totalNodes = 0;
    }

    double benchmarkAVL(vector<string> keyWords, ifstream &file);

    Leaf *search(Leaf *l, string s);

    int heightDifference(Leaf *n);

    void insertKeyWords_avl(vector<string> keyWords);

    Leaf *rightRotate(Leaf *y);

    Leaf *leftRotate(Leaf *y);

    Leaf *getRoot() { return root; };

    void displayInOrden(Leaf *n);

    void searchWords(ifstream &file);


    Leaf *insert_avl(Leaf *n, const string &new_key);
};


#endif //INDICE_REMISIVO_AVLTREE_H
