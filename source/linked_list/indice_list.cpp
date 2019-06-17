//
// Created by thiago on 11/06/19.
//

#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include <cstdio>

#include "indice_list.h"
#include "List.h"
#include "../helps.h"

using namespace std;

/*
 * Recebe o vetor de palavras chaves ja ordenado e o adciona em uma lista encadeada
 * @param:
 *      keyWordsArray: vetor que contem as palavras chaves
 */
void list_index::setKeyWords(vector<string> keyWordsArray) {
    string word;
    int i = 1;

    for (const auto &item: keyWordsArray)
        keyWords.push(item);
}

/*
 * Realiza a busca das palavras chaves no arquivo TXTX
 * #param
 *      ifstream file: Arquivo txt que contém o texto
 */
void list_index::searchWords(ifstream &file) {
    if (this->keyWords.getHead() != nullptr) {
        Node *current = keyWords.getHead();
        string line;
        int numLine = 1;


        while (current != nullptr) {
            while (!file.eof()) {
                getline(file, line);
                std::vector<std::string> words{split(line, ' ')};

                for (const auto &item : words) {
                    if (current->word == item) {
                        push(item, numLine);
                    }
                }
                numLine++;
            }

            numLine = 1;
            file.seekg(0); // Retorna ponteiro do arquivo para o inicio
            current = current->next;
        }
    }
}

/*
 * Adciona um novo item a lista encadeada
 * @param:
 *       string content: palavra chave
 *       unsigned int line: linha que aparece
 */
bool list_index::push(string content, unsigned int line) {
    if (head == nullptr) {
        head = new word;
        head->content = content;
        head->existingLines = new int;
        head->existingLines[0] = line;
        head->contLines++;
    } else {
        /*
         * Verifica se a palavra ja existe na lista
         */
        word *current = this->head;
        while (current != nullptr) {
            if (current->content == content) {
                current->existingLines = (int *) realloc(current->existingLines, (current->contLines++) * sizeof(int));
                current->existingLines[current->contLines++] = line;
                return true;
            }
            current = current->next;
        }

        // Caso não exista, será adcionado um novo item
        word *new_word = new word;
        new_word->content = content;
        new_word->existingLines = new int;
        new_word->existingLines[0] = line;
        new_word->next = this->head;
        new_word->contLines++;

        this->head = new_word;
//        this->lenght++;
    }
}


/*
 * Imprime o indice remissivo
 */
void list_index::printIndice() {
    if (this->head == nullptr) {
        cout << "Nenhuma palavra chave foi encontrada no texto." << endl;
    } else {
        word *current = this->head;

        cout << "PALAVRA" << "\t\t\t" << "LINHAS" << endl;
        while (current != nullptr) {
            cout << current->content << "\t\t";

            for (int i = 0; i < current->contLines; i++) {
                if (current->existingLines[i] != 0 &&
                    current->existingLines[i] < 100000) // Gambiara temporaria (ou não)
                    cout << current->existingLines[i] << "\t";
            }

            cout << endl;
            current = current->next;
        }
    }
}