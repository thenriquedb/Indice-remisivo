////
//// Created by thiago on 24/06/19.
////
//
#include "hash_linkedList.h"



    void hash_linkedList::insert(string value) {
        int index = getHash(value);
        table[index].insert(value, index);
    }

    void hash_linkedList::printIndice() {
        fort::table printTable;
        printTable << fort::header << "Palavra chave" << "Linhas" << fort::endr;
        bool aux = false;

        for (int i = 0; i < capacity; ++i) {
            if (table[i].getKey() != -1) {
                Node *current = table[i].getCollisions().getHead();

                while (current != nullptr) {
                    if (current->existingLines != nullptr) {
                        printTable << current->word;

                        for (int j = 0; j < current->totalLines; ++j) {
                            printTable << current->getExistingLines(j);
                        }
                        printTable << fort::endr;
                    }
                    current = current->next;
                }


            }
        }

        printTable.set_border_style(FT_PLAIN_STYLE);
        printTable.row(0).set_cell_text_align(fort::text_align::center);
        printTable.column(1).set_cell_text_align(fort::text_align::center);
        std::cout << printTable.to_string() << std::endl;
    }

    void hash_linkedList::searchKeywords(ifstream &file) {
        int numLine = 1;
        string line;

        file.seekg(0);
        while (!file.eof()) {
            getline(file, line);
            vector<string> words{split(line, ' ')};

            for (auto const &item : words) {
                if (item.size() >= 4) {
                    int index = getHash(item);

                    // Veriica se table[index] possui algum elemento
                    if (table[index].getKey() != -1) {
                        Node *current = table[index].getCollisions().getHead();
                        string s = s_toLower(item);

                        while (current != nullptr) {
                            if (current->word == s)
                                current->setNewLine(numLine);
                            current = current->next;
                        }
                    }
                }
            }
            numLine++;
        }
    }

    void hash_linkedList::insertKeyWords(vector<string> keywords) {
        for (auto const &item:keywords)
            if (item.size() >= 4)
                insert(item);
    }

    // Retorna um valor entre 0 e 25.
    // Caracter ASCII (97 - 122)
    int hash_linkedList::getHash(string value) {
        return abs((122 - (int) value[0]) - 25);
    }
