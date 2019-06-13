//
// Created by thiago on 11/06/19.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>

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