//
// Created by thiago on 11/06/19.
//

#ifndef INDICE_REMISIVO_HELPS_H
#define INDICE_REMISIVO_HELPS_H

#include<iostream>
#include <vector>
using namespace std;

const vector<string> split(const string &string, const char &token);

const vector<string> getKeyWords(ifstream &file);

const vector<string> sortKeywordsAlphabetical(vector<string> keyWords);

#endif //INDICE_REMISIVO_HELPS_H
