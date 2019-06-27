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

/*
 * Classe responsavel por armazenar os dados da execução do benchmark de cada estrutura
 */
class averageTimes {
private:
    string dataStruct;
    double averageTime, totalTime, minTime, maxTime;

public:
    void setTimes(string type, double total_t, double average_t, double min_t, double max_t) {
        dataStruct = type;
        totalTime = total_t;
        averageTime = average_t;
        minTime = min_t;
        maxTime = max_t;
    }

    void display() {
        cout << "\tEstrutura: " << dataStruct << endl;
        cout << "\tTempo total: " << totalTime << endl;
        cout << "\tMenor tempo: " << minTime << endl;
        cout << "\tMaior tempo: " << maxTime << endl;
        cout << "\tTempo médio: " << averageTime << endl << endl;
    }

    string getDataStruct(){return dataStruct; };
    double getAverageTime() { return averageTime; };
    double getTotalTime() { return totalTime; };
    double getMinTime() { return minTime; };
    double getMaxTime() { return maxTime; };
};

int totalLinesFile(ifstream &file);

const vector<string> split(const string &string, const char &token);

const vector<string> getKeyWords(ifstream &file);

int *allocateIntVector(int numLine, int *p, int n);

string s_toLower(string s);

string s_toUpper(string s);

string clear_string(string word);

chrono::duration<double> runtime(chrono::time_point<std::chrono::system_clock> startTime,
                                 chrono::time_point<std::chrono::system_clock> endTime);

int maxNumber(int a, int b);

#endif //INDICE_REMISIVO_HELPS_H
