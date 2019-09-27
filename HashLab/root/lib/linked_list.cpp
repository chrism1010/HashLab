//
//  linked_list.cpp
//  
//
//  Created by Chris  Munoz on 3/29/19.
//

#include<iostream>
#include "linked_list.h"

using namespace std;

Node* head;
Node* tail;

Node::Node(int data) {
    this->data = data;
    next = NULL;
}
Node::~Node() {
    if (next != NULL) {
        delete next;
    }
}

LinkedList::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList() {
    delete head;
}

int LinkedList::len() {
    return length;
}

bool LinkedList::insert_head(int data) {
    if (head == NULL) {
        head = new Node(data);
        tail = head;
    } else {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    length++;
    return true;
}

bool LinkedList::insert_tail(int data) {
    if (head == NULL) {
        head = new Node(data);
        tail = head;
    } else {
        Node* new_node = new Node(data);
        tail->next = new_node;
        tail = tail->next;
    }
    length++;
    return true;
}

bool LinkedList::insert_at_index(int index, int data) {
    int pos = 0;
    Node* curr = head;
    Node* new_node = new Node(data);
    if (index == 0) {
        insert_head(data);
        tail = head;
    } else {
        while (index != pos + 1) {
            curr = curr->next;
            pos++;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
    length++;
    return true;
}

bool LinkedList::remove_head() {
    if (head->next == NULL) {
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
    
    length--;
    return true;
}

bool LinkedList::remove_tail() {
    if (head->next == NULL) {
        head = NULL;
        tail = NULL;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = NULL;
        delete curr->next;
        tail = curr;
    }
    length--;
    return true;
}

bool LinkedList::remove_at_index(int index) {
    Node* curr = head;
    if (index == 0) {
        remove_head();
    }
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    Node* temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
    length--;
    return true;
}

int LinkedList::find(int data) {
    Node* curr = head;
    int pos = 0;
    if (head == NULL) {
        return -1;
    } else {
        while (curr != NULL) {
            if(curr->data == data) {
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        
    }
    return -1;
}

