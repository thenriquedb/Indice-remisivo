//
// Implementação da tabela hash utilizando a refêrencia sugerida (Ziviani, 2011)
//

#include "hashTable.h"


/*
 * Insere um novo item na tabela hash
 */
void hashTable::insert(string key) {
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
void hashTable::insertKeyWords(vector<string> keywords) {
    for (auto const &item: keywords)
        insert(item);
}

/*
 * Realiza a busca de uma palavra especifica no hash
 * @param string key chave a ser buscada
 */
string hashTable::searchWord(string key) {
    unsigned int index = this->searchIndex(key);

    if (index < this->capacity)
        return table[index].getValue();
    else
        return "\0";
}

/*
 * Recebe uma palavra e verifica se a palavra existe na hash.
 * Caso existir retorna sua chave, e em caso contrario retorna -1
 */
int hashTable::searchIndex(string key) {
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

// Temporario
void hashTable::printElemnto() {
    for (int i = 0; i < capacity; ++i) {
        if (table[i].getKey() != -1)
            std::cout << "Palavra: " << table[i].getValue() << "  Chave: " << table[i].getKey() << endl;
    }
}