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
char* Deque::Head() const {
    return first->item;
}
 
// Вывести хвост дека
char* Deque::Tail() const {
    return last->item;
}

// Добавить элемент в начало дека
void Deque::push_front(char* item) {
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
void Deque::push_back(char* item) {
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
char* Deque::pop_front() {
    Node *current = first;
    char* res = first->item;
    first = first->next;
    if(first){
        first->prev = NULL;
    }
    delete current;
    size--;
    return res;
}
 
// Удалить элемент из конца дека
char* Deque::pop_back() {
    Node *current = last;
    char* res = last->item;
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
