#ifndef __SLLIST_H__
#define __SLLIST_H__

#include <cstddef>
#include <stdexcept>
#include <iostream>

// implements a singly linked list
template <typename T>
class SLList {

    private:
        struct Node {
            T data;
            Node *next;
            Node(const T& value) { data = value; next = nullptr; }
        };

        Node *head;
        Node *tail;
        size_t size;

    public:
        SLList() { head = tail = nullptr; size = 0; }
        ~SLList() { clear(); }

        size_t get_size() { return size; }
        bool empty() { return size == 0; }
        void clear();
        T& front();
        T& back();
        void push_front(const T& value);
        void pop_front();
        void push_back(const T& value);
        void pop_back();
        void print();
};

template <typename T>
void SLList<T>::clear() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
T& SLList<T>::front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

template <typename T>
T& SLList<T>::back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

template <typename T>
void SLList<T>::push_back(const T& value) {
    Node *p = new Node(value);
    if (empty()) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    size++;
}

template <typename T>
void SLList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    Node *p = head;
    head = head->next;
    delete p;
    size--;
    if (empty()) {
        tail = nullptr;
    }
}

template <typename T>
void SLList<T>::print() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
