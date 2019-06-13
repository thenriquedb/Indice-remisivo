//
// Created by thiago on 11/06/19.
//

#include "list.h"
#include<string>
#include<iostream>

using namespace std;

/*
 * Adciona um novo elemento no final da lista
 */
void list::push(string content) {
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
void list::display() {
    if (this->head == nullptr)
        cout << "Lista vazia" << endl;
    else {
        Node* temp = this->head;
        while (temp != nullptr) {
            cout << "\t" << temp->word << endl;
            temp = temp->next;
        }
    }
}

