//
//  main.cpp
//  
//
//  Created by Chris  Munoz on 3/29/19.
//

#include "hashset.h"
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream inFile;
    clock_t start;
    string name;
    int x = 0;
    float avgTime = -1;
    int hashed_names[1000];
    string names[1000];
    Hashset* table110 = new Hashset(10);
    Hashset* table210 = new Hashset(10);
    Hashset* table310 = new Hashset(10);
    Hashset* table1100 = new Hashset(100);
    Hashset* table2100 = new Hashset(100);
    Hashset* table3100 = new Hashset(100);
    Hashset* table11000 = new Hashset(1000);
    Hashset* table21000 = new Hashset(1000);
    Hashset* table31000 = new Hashset(1000);
    LinkedList* list10 = new LinkedList();
    LinkedList* list100 = new LinkedList();
    LinkedList* list1000 = new LinkedList();
    
    inFile.open("names.txt");
    while (!inFile.eof()) {
        getline(inFile, name);
        hashed_names[x] = table110->hash_str(name);
        x++;
    }
    inFile.close();
    
    
    
    //Linked List 10
    cout << "Linked list 10" << endl;
    start = clock();
    for (int i = 0; i < 10; i++) {
        list10->insert_tail(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to insert: " << avgTime << "s" << endl;
    
    start = clock();
    for (int i = 0; i < 10; i++) {
        list10->find(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Linked List 100
    cout << "Linked list 100" << endl;
    start = clock();
    for (int i = 0; i < 100; i++) {
        list100->insert_tail(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 100; i++) {
        list100->find(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Linked List 1000
    cout << "Linked list 1000" << endl;
    start = clock();
    for (int i = 0; i < 1000; i++) {
        list1000->insert_tail(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        list1000->find(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(10) 10
    cout << "Hashset(10) 10" << endl;
    start = clock();
    for (int i = 0; i < 10; i++) {
        table110->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 10; i++) {
        table110->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(10) 100
    cout << "Hashset(10) 100" << endl;
    start = clock();
    for (int i = 0; i < 100; i++) {
        table1100->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 100; i++) {
        table1100->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(10) 1000
    cout << "Hashset(10) 1000" << endl;
    start = clock();
    for (int i = 0; i < 1000; i++) {
        table11000->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        table1100->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(100) 10
    cout << "Hashset(100) 10" << endl;
    start = clock();
    for (int i = 0; i < 10; i++) {
        table210->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 10; i++) {
        table210->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(100) 100
    cout << "Hashset(100) 100" << endl;
    start = clock();
    for (int i = 0; i < 100; i++) {
        table2100->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 100; i++) {
        table2100->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(100) 1000
    cout << "Hashset(100) 1000" << endl;
    start = clock();
    for (int i = 0; i < 1000; i++) {
        table21000->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        table21000->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(1000) 10
    cout << "Hashset(1000) 10" << endl;
    start = clock();
    for (int i = 0; i < 10; i++) {
        table310->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 10; i++) {
        table310->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 10);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(1000) 100
    cout << "Hashset(1000) 100" << endl;
    start = clock();
    for (int i = 0; i < 100; i++) {
        table3100->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 100; i++) {
        table3100->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 100);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;

    //Hashset(1000) 1000
    cout << "Hashset(1000) 1000" << endl;
    start = clock();
    for (int i = 0; i < 1000; i++) {
        table31000->insert(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to insert: " << avgTime << "s" << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        table31000->contains(hashed_names[i]);
    }
    start = clock() - start;
    avgTime = ((float)start)/(CLOCKS_PER_SEC * 1000);
    cout << "Avg time to find: " << avgTime << "s" << endl;
    cout << endl;
}
