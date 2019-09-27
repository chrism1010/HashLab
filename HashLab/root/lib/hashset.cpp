//
//  hashset.cpp
//  
//
//  Created by Chris  Munoz on 4/4/19.
//

#include "hashset.h"
#include <iostream>
#include <string>
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */

using namespace std;

LinkedList** table;
int size = 0;

Hashset::Hashset(int size) {
    table = new LinkedList[size];
    this->size = size;
}

Hashset::~Hashset() {
    for (int i = 0; i < size; i++) {
        delete &table[i];
    }
}

int Hashset::hash_str(string str) {
    char* s = new char[str.length() + 1];
    strcpy(s, str.c_str());
    int h = FIRSTH;
    while (*s) {
        h = (h * A) ^ (s[0] * B);
        s++;
    }
    return h;
}

int Hashset::hash(int prehash) {
    if (prehash < 0) {
        prehash *= -1;
    }
    return prehash % size;
}

bool Hashset::contains(int value) {
    int index = hash(value);
    LinkedList* list = &table[index];
    if (list->find(value) >= 0) {
        return true;
    }
    return false;
}

bool Hashset::insert(int value) {
    int index = hash(value);
    LinkedList* list = &table[index];
    list->insert_tail(value);
    return true;
}

bool Hashset::remove(int value) {
    int index = hash(value);
    LinkedList* list = &table[index];
    list->remove_at_index(list->find(value));
    return true;
}

