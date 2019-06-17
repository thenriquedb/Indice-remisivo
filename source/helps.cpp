//
// Created by thiago on 11/06/19.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<algorithm>

#include "helps.h"

using namespace std;

/*
 * Recebe um string e a separa em pedaços de acordo com o token.
 * Retorna um vetor contendo as partes
 *
 */
const vector<string> split(const string &string, const char &token) {
    std::string buff = {};
    vector<std::string> vetor;

    for (auto n:string) {
        if (n != token) {
            buff += n;
        } else if (n == token && !buff.empty()) {
            vetor.push_back(buff);
            buff = "";
        }
    }

    if (!buff.empty()) {
        vetor.push_back(buff);
    }

    return vetor;
}

/*
 * Armazena todos as palavras chaves em um vetor e o retorna ordenado
 * @param
 *      ifstream &file: arquivo que contem as palavrass chaves
 * */
const vector<string> getKeyWords(ifstream &file) {
    string line, current;
    getline(file, line);
    std::vector<std::string> keyWords = split(line, ' ');

    return sortKeywordsAlphabetical(keyWords);
}



const vector<string> sortKeywordsAlphabetical(vector<string> keyWords) {
    int lenght = keyWords.size();
    for (int i = 0; i < lenght; i++) {
        string current = keyWords[i];
        std::transform(current.begin(), current.end(), current.begin(), ::tolower); // Converte string para minuscula

        int j = i - 1;
        while (j >= 0 && keyWords[j] > current) {
            keyWords[j + 1] = keyWords[j];
            j = j - 1;
        }
        keyWords[j + 1] = current;
    }
    return keyWords;
}