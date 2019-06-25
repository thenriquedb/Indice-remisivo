//
// Implementação da tabela hash utilizando a refêrencia sugerida (Ziviani, 2011)
//

#include "hashZiviani.h"
#include <iostream>
#include <fstream>

#include "../helps.h"
#include "../external/fort.hpp"
#include "../external/fort.h"

using namespace std;

/*
 * Insere um novo item na tabela hash
 */
void hashZiviani::insert(string key) {
    if (this->searchIndex(key) == -1) {

        int initial = this->h(key);
        int index = initial;
        int i = 0;

        while (table[index].getKey() != -1 && table[index].getValue() != "\0" && i < this->capacity) {
            index = (initial + (++i)) % this->capacity;
        }

        if (i < this->capacity) {
            this->table[index].insertItem(key, index);
        }

    }
}

/*
 * Insere as palavras chave na tabela
 * @param vector<string> keywords: vetor de palavras chaves
 */
void hashZiviani::insertKeyWords(vector<string> keywords) {
    for (auto const &item: keywords) {
        if (item.size() >= 4)
            insert(item);
    }
}

/*
 * Recebe uma palavra e verifica se a palavra existe na hash.
 * Caso existir retorna sua chave, e em caso contrario retorna -1
 */
int hashZiviani::searchIndex(string key) {
    unsigned int i = 0, initial = h(key);
    unsigned index = initial;

    // Verifica se o elemento está presente na tabela

    string a = table[i].getValue();
    int b = table[i].getKey();

    while (table[i].getValue() != "\0" && table[i].getKey() != -1 && i < this->capacity) {
        index = initial + (i++) % this->capacity;
    }

    string c = table[index].getValue();
    int d = table[index].getKey();

    if (table[index].getValue() != "\0" && table[index].getKey() != -1) {
        return index;
    } else {
        return -1;
    }
}

/*
 * Realiza a busca das palavras chaves em um arquivo texto
 * @param ifstream &file arquivo que contém o texto a ser lido
 */
void hashZiviani::searchKeywords(ifstream &file) {
    int numLine = 1;
    string line;
    file.seekg(0);

    while (!file.eof()) {
        getline(file, line);
        std::vector<std::string> words{split(line, ' ')};

        for (auto const &item:words) {
            int index = searchIndex(item);
            if (index >= 0) {
                if (this->table[index].getKey() != -1 && this->table[index].getValue() != "\0") {
                    this->table[index].setNewLine(numLine);
                }
            }
        }
        numLine++;
    }
}

/*
 * Imprime o indice remissivo
 */
void hashZiviani::printIndice() {
    fort::table printTable;
    printTable << fort::header << "Palavra chave" << "Linhas" << fort::endr;

    for (int i = 0; i < capacity; ++i) {
        if (table[i].getKey() != -1 && table[i].getTotalLines() > 0) {
            printTable << table[i].getValue();

            for (int j = 0; j < table[i].getTotalLines(); ++j) {
                printTable << table[i].getExistingLines(j);
            }
            printTable << fort::endr;
        }
    }

    printTable.set_border_style(FT_PLAIN_STYLE);
    printTable.row(0).set_cell_text_align(fort::text_align::center);
    printTable.column(1).set_cell_text_align(fort::text_align::center);
    std::cout << printTable.to_string() << std::endl;
}

/*
 * Retorna o tempo de execução
 */
double hashZiviani::benchmark(vector<string> keyWords, ifstream &file){
    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    start = chrono::system_clock::now();

    insertKeyWords(keyWords);
    searchKeywords(file);

    end = std::chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = runtime(start, end);
    return elapsed_seconds.count();
}
