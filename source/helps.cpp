/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<algorithm>

#include "helps.h"

using namespace std;

/*
 * Realiza o recebimento dos parametros via terminal
 *
 * @param
 *  int argc
 *  char **argv
 */
string *input_parse(int argc, char **argv) {

    auto tmp = new std::string[2];
    if (argc > 3 || argc < 2) {
        std::cout << "Argumentos invalidos" << std::endl;
        std::cout << "Exemplo de execucao: user@machine:~$ remissive-index <arquivo com o texto> <arquivo com as palavras chaves>" << std::endl;
        exit(EXIT_FAILURE);
    }

    tmp[0] = argv[1];
    tmp[1] = argv[2];

    return tmp;
}

/*
 * Retorna o total de linhas do arquivo de texto
 * @param
 *      ifstream &file arquivo txt que contém o texto
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
            vetor.push_back(s_toLower(clear_string(buff)));
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
 * @param
 *     ifstream &file: arquivo que contem as palavrass chaves
 * */
const vector<string> getKeyWords(ifstream &file) {
    string line, current;
    getline(file, line);
    vector<string> temp = split(line, ' ');
    vector<string> keyWords;

    for (const auto &item: temp)
        if (item.size() >= 4)
            keyWords.push_back(item);

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
 * Recebe uma string e a retorna maiscula
 * @apram string s
 */
string s_toUpper(string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::toupper); // Converte string para minuscula
    return s;
}

/*
 * Remove caracteres da string
 *
 */
string clear_string(string word) {
    std::string output;

    for (auto n:word)
        if (n != '.' && n != ',' && n != ':' && n != ';')
            output += n;

    return output;
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
        if (p[n] == numLine)
            return p;

        p = static_cast<int *> (realloc(p, (n + 1) * sizeof(int)));
        p[n] = numLine;
        return p;
    }
}


/*
 * Recebe dois números e retorna o maior
 */
int maxNumber(int a, int b) { return (a > b) ? a : b; }

vector<string> sortKeywordsAlphabetical(vector<string> keyWords) {
    int lenght = keyWords.size();
    for (int i = 0; i < lenght; i++) {
        string current = keyWords[i];
        current = s_toLower(clear_string(current));

        int j = i - 1;
        while (j >= 0 && keyWords[j] > current) {
            keyWords[j + 1] = keyWords[j];
            j = j - 1;
        }
        keyWords[j + 1] = current;
    }
    return keyWords;
}