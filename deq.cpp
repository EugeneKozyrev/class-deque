#include<iostream>
#include "deq.h"
 
using namespace std;

// Конструктор 
Deque::Deque() {
    size = 0;
    first = last = NULL;
}
 
// Деструктор
Deque::~Deque() {
    this->Clear();
}
 
// Вывести голову дека
int Deque::Head() const {
    return first->item;
}
 
// Вывести хвост дека
int Deque::Tail() const {
    return last->item;
}

// Добавить элемент в начало дека
void Deque::push_front(int item) {
    Node *newNode = new Node(item, first);
    if(first == NULL){
        last = newNode;
    } else {
        first->prev = newNode;
        newNode->next = first;
    }
    first = newNode;
    size++;
}
 
// Добавить элемент в конец дека
void Deque::push_back(int item) {
    Node *newNode = new Node(item, NULL, last);
    if(last){
        first = newNode;
    }
    else{
        last->next = newNode;
        newNode->prev = last;
    }
    last = newNode;
    size++;
}
 
// Удалить элемент из начала дека
int Deque::pop_front() {
    Node *current = first;
    int res = first->item;
    first = first->next;
    if(first){
        first->prev = NULL;
    }
    delete current;
    size--;
    return res;
}
 
// Удалить элемент из конца дека
int Deque::pop_back() {
    Node *current = last;
    int res = last->item;
    last = last->prev;
    if(last){
        last->next = NULL;
    }
    delete current;
    size--;
    return res;
}
 
// Вывести колличество узлов дека
void Deque::printCount() {
    cout << size << endl;
}
 
// Вывести дек с начала до хвоста
void Deque::printFront() {
    Node *current = first;
    while(current){
        cout << current->item << ' ';
        current = current ->next;
    }
}

// Вывести дек с конца до начала
void Deque::printBack() {
    Node *current = last;
    while(current){
        cout << current->item << ' ';
        current = current->prev;
    }
}

// Удаление всех элементов - сброс дека
void Deque::Clear() {
    Node *current = NULL;
    Node *next = first;
    while (next) {
        current = next;
        next = next->next;
        delete current;
    }
    size = 0;
    first = NULL;
    last = NULL;
}
