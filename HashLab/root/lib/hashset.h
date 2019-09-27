//
//  hashset.hpp
//  
//
//  Created by Chris  Munoz on 4/4/19.
//
#include "linked_list.h"
#include <string>

using namespace std;
class Hashset {
public:
    Hashset(int size);
    ~Hashset();
    bool contains(int value);
    bool insert(int value);
    bool remove(int value);
    int hash(int prehash);
    int hash_str(string str);
    //void print();
private:
    LinkedList* table;
    int size;
    
    
};
