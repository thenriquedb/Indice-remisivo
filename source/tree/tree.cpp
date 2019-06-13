//
// Created by thiago on 13/06/19.
//
#include <iostream>
#include "tree.h"


using namespace std;

void Tree::insertNode(string new_key) {
    if (root == nullptr) { // Caso a raiz for nula
        root = new Leaf(new_key);
    } else {
        insertAux(this->root, new_key);

        totalNodes++;
    }
}

void Tree::insertAux(Leaf *n, string newKey) {
    // Insere no esquerdo

    if (newKey > n->getKey()) {
        if (n->getRight() == nullptr) {
            Leaf *temp = new Leaf(newKey);
            n->setRight(temp);
        } else
            insertAux(n->getRight(), newKey);
    }

        // Insere no direito
    else if (newKey <  n->getKey()) {
        if ( n->getLeft() == nullptr) {
            Leaf *temp = new Leaf(newKey);
            n->setLeft(temp);
        } else {
            insertAux(n->getLeft(), newKey);
        }
    }
}
