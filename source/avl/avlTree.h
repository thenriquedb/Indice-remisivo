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
class avlTree : public Tree {
private:
    Leaf *rr_rotation(Leaf *parent);
    Leaf *ll_rotation(Leaf *parent);
    Leaf *lr_rotation(Leaf *parent);
    Leaf *rl_rotation(Leaf *parent);
    int heightDifference(Leaf *n);

public:
    void init(vector<string> keyWords, ifstream& file);
    Leaf *balance(Leaf *n);
    Leaf *insert_avl(Leaf *n, const string &new_key);
};


#endif //INDICE_REMISIVO_AVLTREE_H
