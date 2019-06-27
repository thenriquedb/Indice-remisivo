//
// Implementação da tabela hash utilizando a refêrencia sugerida (Ziviani, 2011)
//

#include "closedHash.h"
#include <iostream>
#include <fstream>

#include "../helps.h"
#include "../external/fort.hpp"
#include "../external/fort.h"

using namespace std;


void closedHash::run(vector<string> keyWords,ifstream &file){
    this->insertKeyWords(keyWords);
    this->searchKeywords(file);
    this->printIndice();
}
/*
 * Insere um novo item na tabela hash
 */
void closedHash::insert(string key) {
    if (this->searchIndex(key) == -1) {
        int initial;

        if (this->hashUsed == 1)
            initial = this->generateIndex_1(key);
        if (this->hashUsed == 2)
            initial = this->generateIndex_2(key);
        if (this->hashUsed == 3)
            initial = this->generateIndex_3(key);

        int index = initial, i = 0;

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
void closedHash::insertKeyWords(vector<string> keywords) {
    for (auto const &item: keywords) {
        if (item.size() >= 4)
            insert(item);
    }
}

/*
 * Recebe uma palavra e verifica se a palavra existe na hash.
 * Caso existir retorna sua chave, e em caso contrario retorna -1
 */
int closedHash::searchIndex(string key) {
    unsigned int i = 0, index, initial;

    if (this->hashUsed == 1)
        initial = this->generateIndex_1(key);
    if (this->hashUsed == 2)
        initial = this->generateIndex_2(key);
    if (this->hashUsed == 3)
        initial = this->generateIndex_3(key);

    index = initial;

    while (table[i].getValue() != "\0" && table[i].getKey() != -1 && i < this->capacity) {
        index = initial + (i++) % this->capacity;
    }

    // Verifica se o elemento está presente na tabela
    if (table[index].getValue() != "\0" && table[index].getKey() != -1)
        return index;
    else
        return -1;
}

/*
 * Realiza a busca das palavras chaves em um arquivo texto
 * @param ifstream &file arquivo que contém o texto a ser lido
 */
void closedHash::searchKeywords(ifstream &file) {
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
void closedHash::printIndice() {
    fort::table printTable;

    printf("ÍNDICE REMISSIVO \n");
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
double closedHash::benchmark(vector<string> keyWords, ifstream &file) {
    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    start = chrono::system_clock::now();

    insertKeyWords(keyWords);
    searchKeywords(file);

    end = std::chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = runtime(start, end);
    return elapsed_seconds.count();
}

int closedHash::generateIndex_1(string key) {
    return abs((122 - (int) key[0]) - 25);
}

// Hash Ziviani
int closedHash::generateIndex_2(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + (int) key[i] * weights[i];
    }

    return sum % this->capacity;
}


/*
 * Vetor de pesos utilizado para o calculo do hash utilizando o método de Ziviani.
 * Os pesos são armazenados no vetor Weightsdentro da propria classe
 */
int closedHash::generateWeights() {
    std::srand(time(nullptr));
    for (int i = 0; i < this->capacity; i++)
        this->weights.push_back(rand() % this->capacity);
}

/*
 * Método da Multiplicação ou Congruencia Linear Multiplicativo
 *
 * -Usa um valor sendo este "0 < A < 1" entre 0 e 1 para multiplicar o valor da chave
 *  que representa o elemento.
 *
 *  -Em seguida, a parte fracionária resultante é multiplicada pelo tamanho da tabela
 *  para calcular a posição do elemento;
*/
int closedHash::generateIndex_3(string key) {
    std::srand(time(nullptr));
    float val = (int) key[0] * (float) ((rand() % this->capacity) / RAND_MAX);
    val = val - (int) val;
    return (int) (this->capacity * val);
}
