//
// Created by thiago on 13/06/19.
//
#include <iostream>
#include <vector>
#include "tree.h"


using namespace std;

/*
 * Insere um novo nó na arvore
 * @param
 *      new_string: palavra que será adcionada a arvore
 */
void Tree::insertNode(const string &new_key) {
    if (root == nullptr) { // Caso a raiz for nula
        root = new Leaf(new_key);
    } else {
        insertAux(this->root, new_key);

        totalNodes++;
    }
}

/*
 * Função que adciona na arvore de forma recursiva
 * @param:
 *      Leaf *n: Folha; string newKey: palavra que será adcionada
 */
void Tree::insertAux(Leaf *n, const string &newKey) {
    // Insere no direito
    if (newKey > n->getKey()) {
        if (n->getRight() == nullptr) {
            Leaf *temp = new Leaf(newKey);
            n->setRight(temp);
        } else
            insertAux(n->getRight(), newKey);
    }

        // Insere no esquerdo
    else if (newKey < n->getKey()) {
        if (n->getLeft() == nullptr) {
            Leaf *temp = new Leaf(newKey);
            n->setLeft(temp);
        } else {
            insertAux(n->getLeft(), newKey);
        }
    }
}

/*
 * Imprime a arvore utilizando o método In Order
 * @param
 *      Leaf *n: raiz
 */
void Tree::displayInOrden(Leaf *n) {
    if (n != nullptr) {
        displayInOrden(n->getLeft());
        cout << n->getKey() << endl;
        displayInOrden(n->getRight());

    }
}
// Function to insert nodes in level order

Leaf *Tree::insertLevelOrder(vector<string> keyWords, int start, int final) {
    // Base case for recursion
    if (start < final) {
        Leaf *temp = new Leaf(keyWords[start]);
        this->root = temp;

        // insert left child
        this->getRoot()->setLeft(insertLevelOrder(keyWords, 2 * start + 1, final));
        this->getRoot()->setRight(insertLevelOrder(keyWords, 2 * start + 2, final));
    }
//    return root;
}


Leaf *Tree::balancedTree(vector<string> keyWords, unsigned int start, unsigned int final) {
    if (start > final)
        return nullptr;

    int middle = (start + final) / 2;

    insertNode(keyWords[middle]);
    balancedTree(keyWords, start, middle - 1);
    balancedTree(keyWords, middle + 1, final);

}