//
//  linked_list.hpp
//  
//
//  Created by Chris  Munoz on 3/29/19.
//

class Node {
public:
    Node(int data);
    ~Node();
    int data;
    Node* next;
    Node* find_tail();
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int len();
    bool insert_head(int data);
    bool insert_tail(int data);
    bool insert_at_index(int index, int data);
    bool remove_head();
    bool remove_tail();
    bool remove_at_index(int index);
    int find(int data);
    
protected:
    int length;
    Node* head;
    Node* tail;
};
