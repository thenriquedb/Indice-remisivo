//
// Created by thiago on 11/06/19.
//

#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include<algorithm>
#include <chrono>

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
        file.seekg(0);

        while (!file.eof()) {
            getline(file, line);
            std::vector<std::string> words{split(line, ' ')};
            Node *current = keyWords.getHead();

            /* Percorre a lista verificando se a palavra esta presente */
            while (current != nullptr) {
                for (const auto &item : words) {
                    string s = s_toLower(item);
                    if (current->word == s) {
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
        fort::table table;
        table << fort::header << "Palavra chave" << "Linhas" << fort::endr;
        Node *current = this->keyWords.getHead();

//        cout << "PALAVRA" << "\t\t\t" << "LINHAS" << endl;
        while (current != nullptr) {
            if (current->existingLines != nullptr) {
                table << current->word;
//                cout << current->word << "\t\t";
                for (int i = 0; i < current->totalLines; i++) {
                    table << current->existingLines[i];
//                    cout << current->existingLines[i] << "\t";
                }
                table << fort::endr;
//                cout << endl;
            }
            current = current->next;
        }

        table.set_border_style(FT_PLAIN_STYLE);
        table.row(0).set_cell_text_align(fort::text_align::center);
        table.column(1).set_cell_text_align(fort::text_align::center);
        std::cout << table.to_string() << std::endl;
    }
}

double list_index::benchmark(vector<string> keyWords, ifstream &file) {
    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    start = chrono::system_clock::now();

    insertKeyWords(std::move(keyWords));
    searchWords(file);

    end = std::chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = runtime(start, end);
    return elapsed_seconds.count();
}
