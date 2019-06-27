//
// Created by thiago on 11/06/19.
//

#ifndef INDICE_REMISIVO_HELPS_H
#define INDICE_REMISIVO_HELPS_H

#include<iostream>
#include <vector>
#include <chrono>
#include "external/fort.hpp"
#include "external/fort.h"

using namespace std;

int totalLinesFile(ifstream &file);

//void displayTimes(fort::table table,int leaf, int totalLines, int totalKeyWords, string structure, double time);

const vector<string> split(const string &string, const char &token);

const vector<string> getKeyWords(ifstream &file);

const vector<string> sortKeywordsAlphabetical(vector<string> keyWords);

int *allocateIntVector(int numLine, int *p, int n);

string s_toLower(string s);

string s_toUpper(string s);
chrono::duration<double> runtime(chrono::time_point<std::chrono::system_clock> startTime,
                                 chrono::time_point<std::chrono::system_clock> endTime);

double averageRunningTime(double sumTimes, int c);

int maxNumber(int a, int b);
#endif //INDICE_REMISIVO_HELPS_H
