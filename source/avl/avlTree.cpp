//
// Created by thiago on 18/06/19.
//

#include "avlTree.h"

/*
 * Insere as palavras chaves nos nós da arvore e realiza a busca no arquivo de texto
 * @param
 *       vector<string> keyWords: Vetor de palavras chaves
 *       ifstream& file: arquivo que contém o texto que será lido
 */
void avlTree::init(vector<string> keyWords, ifstream& file){
    insertKeyWords(keyWords);
    searchWords(file);
}

Leaf* avlTree::insert_avl(Leaf*n, const string &new_key){
    if (n == NULL) {
        n = new Leaf(new_key);
        return n;
    } else if (new_key < n->getKey()) {
        n->setLeft(insert_avl(n->getLeft(), new_key));
        n = balance(n);
    } else if (new_key >= n->getKey()) {
        n->setRight(insert_avl(n->getRight(), new_key));
        n = balance(n);
    } return n;
}

/*
 * Realiza o balanceamento da arvore
 */
Leaf *avlTree::balance(Leaf *n) {
    int bal_factor = heightDifference(n);

    if (bal_factor > 1) {
        if (heightDifference(n->getLeft()) > 0)
            n = ll_rotation(n);
        else
            n = lr_rotation(n);
    } else if (bal_factor < -1) {
        if (heightDifference(n->getRight()) > 0)
            n = rl_rotation(n);
        else
            n = rr_rotation(n);
    }
    return n;
}

/*
 * Retorna o fator de balanceamento que é a diferença da altura entre
 * dois nós
 */
int avlTree::heightDifference(Leaf *n) {
    int r_height = n->getRight()->getHeight();
    int l_height = n->getLeft()->getHeight();

    return l_height - r_height;
}

/*
 * Realiza a rotação direita-direita
 */
Leaf *avlTree::rr_rotation(Leaf *parent) {
    Leaf *temp;
    temp = parent->getRight();
    parent->setLeft(temp->getLeft());
    temp->setLeft(parent);
    return temp;
}

/*
 * Realiza a rotação esquerda-esquerda
 */
Leaf *avlTree::ll_rotation(Leaf *parent) {
    Leaf *temp;
    temp = parent->getLeft();
    parent->setLeft(temp->getRight());
    temp->setRight(parent);
    return temp;
}

/*
 *Realiza a rotação esquerda-direita
 */
Leaf *avlTree::lr_rotation(Leaf *parent) {
    Leaf *temp;
    temp = parent->getLeft();
    parent->setLeft(rr_rotation(temp));
    return ll_rotation(parent);
}

/*
 * Realiza a rotação direita-esquerda
 */
Leaf *avlTree::rl_rotation(Leaf *parent) {
    Leaf *temp;
    temp = parent->getRight();
    parent->setRight(ll_rotation(temp));
    return rr_rotation(parent);
}

