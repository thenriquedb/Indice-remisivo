////
//// Created by thiago on 24/06/19.
////
//
#include "openHash.h"

void openHash::run(vector<string> keyWords,ifstream &file){
    this->insertKeyWords(keyWords);
    this->searchKeywords(file);
    this->printIndice();
}

void openHash::insert(string key) {
    int index;

    if (this->hashUsed == 1)
        index = this->generateIndex_1(key);
    if (this->hashUsed == 2)
        index = this->generateIndex_2(key);
    if (this->hashUsed == 3)
        index = this->generateIndex_3(key);

    table[index].insert(key, index);
}

void openHash::printIndice() {
    fort::table printTable;

    printf("ÍNDICE REMISSIVO \n");
    printTable << fort::header << "Palavra chave" << "Linhas" << fort::endr;

    for (int i = 0; i < capacity; ++i) {
        if (table[i].getKey() != -1) {
            Node *current = table[i].getCollisions().getHead();

            while (current != nullptr) {
                if (current->existingLines != nullptr) {
                    printTable << current->word;

                    for (int j = 0; j < current->totalLines; ++j) {
                        printTable << current->getExistingLines(j);
                    }
                    printTable << fort::endr;
                }
                current = current->next;
            }


        }
    }

    printTable.set_border_style(FT_PLAIN_STYLE);
    printTable.row(0).set_cell_text_align(fort::text_align::center);
    printTable.column(1).set_cell_text_align(fort::text_align::center);
    std::cout << printTable.to_string() << std::endl;
}

void openHash::searchKeywords(ifstream &file) {
    int numLine = 1;
    string line;

    file.seekg(0);
    while (!file.eof()) {
        getline(file, line);
        vector<string> words{split(line, ' ')};

        for (auto const &item : words) {
            if (item.size() >= 4) {
                int index = generateIndex_1(item);

                // Veriica se table[index] possui algum elemento
                if (table[index].getKey() != -1) {
                    Node *current = table[index].getCollisions().getHead();
                    string s = s_toLower(item);

                    while (current != nullptr) {
                        if (current->word == s)
                            current->setNewLine(numLine);
                        current = current->next;
                    }
                }
            }
        }
        numLine++;
    }
}

void openHash::insertKeyWords(vector<string> keywords) {
    for (auto const &item:keywords)
        if (item.size() >= 4)
            insert(item);
}

/*
 * Vetor de pesos utilizado para o calculo do hash utilizando o método de Ziviani.
 * Os pesos são armazenados no vetor Weightsdentro da propria classe
 */
int openHash::generateWeights() {
    std::srand(time(nullptr));
    for (int i = 0; i < this->capacity; i++)
        this->weights.push_back(rand() % this->capacity);
}

/*
 * Recebe como parametro um string no qual é pego o valor ASCII do primeiro caracter.
 * Atráves disto é retornado um valor entre 0 e 25 correspondente a letra do alphabeto.
 *
 * Caracter ASCII (97 - 122)
    @param string value
 */
int openHash::generateIndex_1(string key) {
    return abs((122 - (int) key[0]) - 25);
}

// Hash Ziviani
int openHash::generateIndex_2(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + (int) key[i] * weights[i];
    }

    return sum % this->capacity;
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
int openHash::generateIndex_3(string key) {
    std::srand(time(nullptr));
        float val = (int)key[0] * (float)((rand() % this->capacity) / RAND_MAX);
        val = val - (int)val;
        return (int) (this->capacity * val);
}

double openHash::benchmark(vector<string> keyWords, ifstream &file) {
    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    start = chrono::system_clock::now();

    insertKeyWords(keyWords);
    searchKeywords(file);

    end = std::chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = runtime(start, end);
    return elapsed_seconds.count();
}