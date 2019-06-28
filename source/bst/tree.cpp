/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

#include <iostream>
#include <vector>
#include <chrono>

#include "tree.h"
#include "../helps.h"
#include "../external/fort.h"
#include "../external/fort.hpp"

using namespace std;

void Tree::run(vector<string> keyWords, ifstream &file) {
    this->insertKeyWords(keyWords);
    this->searchWords(file);
    this->displayInOrden(this->root);
    this->exportIndexTxt(sortKeywordsAlphabetical(keyWords));
}


double Tree::benchmark(vector<string> keyWords, ifstream &file) {
    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    insertKeyWords(std::move(keyWords));
    searchWords(file);

    end = std::chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = runtime(start, end);
    return elapsed_seconds.count();
}

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
    }
    totalNodes++;
}

/*
 * Função que adciona na arvore de forma recursiva
 * @param:
 *      Leaf *leaf: leaf; string newKey: palavra que será adcionada
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
 * Insere todas as palavras chaves na arvore
 * @param
 *      vector<string> keyWords: vetor de palavras chaves
 */
void Tree::insertKeyWords(vector<string> keyWords) {
    for (const auto &item : keyWords)
        if (item.size() >= 4)
            this->insertNode(item);
}

/*
 * Imprime a arvóre na seguinte ordem: ESQUERDA - RAIZ - DIREITA.
 * Recebe como parámetro inicial a raiz da arvóre
 * @param Leaf *n
 */
void Tree::displayInOrden(Leaf *n) {
    if (n != nullptr) {
        if (n->getExistingLines() != nullptr) {
            displayInOrden(n->getLeft());
            cout << "\t" << n->getKey() << "\t";
            n->displayTotalLines();
            cout << endl;
            displayInOrden(n->getRight());
        }
    }
}

/*
 * Realiza a busca das palavras chaves em um arquivo texto
 * @param ifstream &file arquivo que contém o texto a ser lido
 */
void Tree::searchWords(ifstream &file) {
    if (this->root != nullptr) {
        string line;
        int numLine = 1;

        // Retorna o ponteiro de leitura para o inicio do arquivo
        file.seekg(0);
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
 * Retorna o nó que contem a string pesquisada. Recebe como parametro incial a raiz da arvoré.
 * @param Leaf *l, string s
 */
Leaf *Tree::search(Leaf *l, string s) {
    if (l == nullptr || l->getKey() == s)
        return l;

    if (s > this->root->getKey())
        return search(l->getRight(), s);

    if (s < this->root->getKey())
        return search(l->getLeft(), s);
};


/*
 * Exporta o indice remissivo em um arquivo txt
 * @param
 *      vector<string> sort_keywords Palavras chaves em ordem alfabetica
 */
void Tree::exportIndexTxt(vector<string> sort_keywords) {
    // Definição da tabela
    fort::table table;
    table.set_border_style(FT_PLAIN_STYLE);
    table.row(0).set_cell_text_align(fort::text_align::center);
    table.column(1).set_cell_text_align(fort::text_align::center);
    std::cout << table.to_string() << std::endl;

    printf("ÍNDICE REMISSIVO \n");
    table << fort::header << "Palavra chave" << "Linhas" << fort::endr;

    std::string content;

    for (const auto &keyword : sort_keywords) {
        Leaf *node = this->search(this->root, keyword);
        if (node != nullptr) {
            int *existingLines = node->getExistingLines();
            table << node->getKey();

            for (int i = 0; i < node->getTotalLines(); ++i)
                table << existingLines[i];

            table << fort::endr;
        }
    }
    ofstream file;
    string path = "../outputs/indices_remisivo/index_bst.txt";
    file.open(path, ios::app);
    file << "Indice remissivo - BST" <<endl;
    file << table.to_string() <<endl;
}

