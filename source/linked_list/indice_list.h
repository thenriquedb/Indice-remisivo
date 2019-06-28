/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

#ifndef INDICE_REMISIVO_INDICE_LIST_H
#define INDICE_REMISIVO_INDICE_LIST_H

#include<string>
#include<vector>
#include<iostream>

#include "List.h"

using namespace std;

/*
 * Implementação do indice remissivo utilizando a estrutura de lista encadeada
 */
class list_index {
private:
    List keyWords; // Lista das palavras chaves
    int lenght;
    void insertKeyWords(vector<string> keyWordsArray);
    void searchWords(ifstream &file);
    void printIndice();
    void exportIndexTxt(string table);

public:
    void run(vector<string>keyWordsArray, ifstream&file);
    double benchmark(vector<string> keyWords, ifstream &file);

};

#endif //INDICE_REMISIVO_INDICE_LIST_H
