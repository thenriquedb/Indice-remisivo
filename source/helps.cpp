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
 * Retorna o total de linhas do arquivo de texto
 */
int totalLinesFile(ifstream &file) {
    int cont = 0;
    string line;

    while (!file.eof()) {
        getline(file, line);
        cont++;
    }
    return cont;
}


chrono::duration<double> runtime(chrono::time_point<std::chrono::system_clock> startTime,
                                 chrono::time_point<std::chrono::system_clock> endTime) {
    return endTime - startTime;
}

/*
 * Retorna o tempo medio de execução
 * @param:
 *       long float sumTimes: a soma do tempo de todas as execuções
 *       int c: quantidade de execuções
 */
double averageRunningTime(double sumTimes, int c) {
    return sumTimes / c;
}


/*
 * Recebe um string e a separa em pedaços de acordo com o token.
 * Retorna um vetor cuja cada posição contém um pedaço da string
 * @param
 *      const string &string: frase que será divida
 *      const char &token: token que ira separar os pedaços. EX: ',' '.' ' ' ';'
 */
const vector<string> split(const string &string, const char &token) {
    std::string buff = {};
    vector<std::string> vetor;

    for (auto n:string) {
        if (n != token) {
            buff += n;
        } else if (n == token && !buff.empty()) {
//            cout << "Buff: " << buff << "   Final: " << buff[buff.size() - 1] << endl;
            vetor.push_back(s_toLower(buff));
            buff = "";
        }
    }

    if (!buff.empty()) {
        vetor.push_back(buff);
    }

    return vetor;
}

/*
 * Armazena todos as palavras chaves em um vetor
 *      ifstream &file: arquivo que contem as palavrass chaves
 * */
const vector<string> getKeyWords(ifstream &file) {
    string line, current;
    getline(file, line);
    std::vector<std::string> keyWords = split(line, ' ');

    return keyWords;
}

/*
 * Recebe uma string e a retorna minuscula
 * @apram string s
 */
string s_toLower(string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower); // Converte string para minuscula
    return s;
}

/*
 * Realiza o armazenamento das linhas
 */
int *allocateIntVector(int numLine, int *p, int n) {
    if (p == nullptr) {
        p = static_cast<int *>(malloc(sizeof(int)));
        p[0] = numLine;
        return p;
    } else {
        p = static_cast<int *> (realloc(p, (n + 1) * sizeof(int)));
        p[n] = numLine;
        return p;
    }
}



/*
 * Recebe dois números e retorna o maior
 */
int maxNumber(int a, int b) { return (a > b) ? a : b; }


