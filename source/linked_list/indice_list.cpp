//
// Created by thiago on 11/06/19.
//

#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include<algorithm>

#include "indice_list.h"
#include "List.h"
#include "../helps.h"

using namespace std;

/*
 * Realiza a busca das palavras chaves no arquivo TXT
 * #param
 *      ifstream file: Arquivo txt que contém o texto
 */
void list_index::searchWords(ifstream &file) {
    if (this->keyWords.getHead() != nullptr) {
        string line;
        int numLine = 1;

        while (!file.eof()) {
            getline(file, line);
            std::vector<std::string> words{split(line, ' ')};
            Node *current = keyWords.getHead();

            /* Percorre a lista verificando se a palavra esta presente */
            while (current != nullptr) {
                for (const auto &item : words) {
                    string s = s_toLower(item);
                    if (current->word == s && s.size() >= 4) {
                        current->existingLines = allocateIntVector(numLine, current->existingLines,
                                                                   current->totalLines);
                        current->totalLines++;
                    }
                }
                current = current->next;
            }

            numLine++;
        }
    }
}


/*
 * Imprime o indice remissivo
 */
void list_index::printIndice() {
    if (this->keyWords.getHead() == nullptr) {
        cout << "Nenhuma palavra chave foi encontrada no texto." << endl;
    } else {
        Node *current = this->keyWords.getHead();

        cout << "PALAVRA" << "\t\t\t" << "LINHAS" << endl;
        while (current != nullptr) {
            if (current->existingLines != nullptr) {
                cout << current->word << "\t\t";
                for (int i = 0; i < current->totalLines; i++) {
                    cout << current->existingLines[i] << "\t";
                }
                cout << endl;
            }
            current = current->next;
        }
    }
}
