//
// Created by thiago on 13/06/19.
//
#include <iostream>
#include <vector>

#include "tree.h"
#include "../helps.h"


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

void Tree::insertKeyWords(vector<string> keyWords) {
    for (const auto &item : keyWords)
        if (item.size() >= 4)
            this->insertNode(item);
}

/*
 * Imprime a arvore utilizando o método In Order
 * @param
 *      Leaf *n: raiz
 */
void Tree::displayInOrden(Leaf *n) {
    if (n != nullptr) {
        displayInOrden(n->getLeft());
        cout << n->getKey() << "\t";
        n->displayTotalLines();
        cout << endl;
        displayInOrden(n->getRight());
    }
}

void Tree::searchWords(ifstream &file) {
    if (this->root != nullptr) {
        string line;
        int numLine = 1;

        while (!file.eof()) {
            getline(file, line);
            std::vector<std::string> words{split(line, ' ')};

            for (const auto &item : words) {
                Leaf *temp = search(this->root, item);
                if (temp != nullptr && item.size() >= 4 && temp->getKey() == item) {
                    temp->setNewLine(numLine);
                }
                temp = nullptr;
            }
            numLine++;
        }
    }
}

/*
 * Retorna o nó que contem a string pesquisada
 */
Leaf *Tree::search(Leaf *l, string s) {
    if (l == nullptr || l->getKey() == s)
        return l;

    if (s > this->root->getKey())
        return search(l->getRight(), s);

    if (s < this->root->getKey())
        return search(l->getLeft(), s);
};