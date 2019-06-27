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
 * @param
 *      string content Palavra  a ser inserida
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
 * Re-organiza as palavras em ordem alfabética
*/
Node *List::sortList() {
    Node *sorted = nullptr;
    while (this->head) {
        // Pop
        Node *head = this->head;
        this->head = this->head->next;

        // Find the place to insert.
        Node *lead = sorted;
        Node *trail = nullptr;
        while (lead && lead->word <= head->word) {
            trail = lead;
            lead = lead->next;
        }

        // Insert either within the list or at the head.
        head->next = lead;
        if (trail)
            trail->next = head;
        else
            sorted = head;
    }
    this->head = sorted;

}