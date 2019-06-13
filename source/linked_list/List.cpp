//
// Created by thiago on 11/06/19.
//

#include "List.h"
#include<string>
#include<iostream>
#include "../external/fort.hpp"

using namespace std;

/*
 * Adciona um novo elemento no final da lista
 */
void List::push(string content) {
    if (head == nullptr)
        head = new Node(content);
    else {
        Node *new_node = new Node(content);
        new_node->next = this->head;
        this->head = new_node;
    }
    this->lenght++;
}

/*
 * Imprime os elementos da lista
 */
void List::display() {
    int cont = 1;
    if (this->head == nullptr)
        cout << "Lista vazia" << endl;
    else {
        Node *temp = this->head;
        while (temp != nullptr) {
            cout << "\t" << cont << "º: " << temp->word << endl;
            temp = temp->next;
            cont++;
        }
    }
}