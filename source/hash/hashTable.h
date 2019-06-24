//
// Implementação doe.
//

#ifndef INDICE_REMISIVO_HASH_H
#define INDICE_REMISIVO_HASH_H

#include <string>
#include <ctime>

using namespace std;

class hashNode {
private:
    string word;
    int key;

    int generateWeights(){
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
        return std::rand();
    }
};

class hash {
hashNode table;
};


#endif //INDICE_REMISIVO_HASH_H
