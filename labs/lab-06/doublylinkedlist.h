#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    
        Node(int v) {
            data = v;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int n_nodes;
    
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        
        void push_back(int v);
        void push_front(int v);
        void push_at(int idx, int v);

        void pop_back();
        void pop_front();
        void pop_at(int idx);

        int back();
        int front();
        int at(int idx);

        int size();
        bool empty();
        void clear();
        void print();
        bool contains(int v);
};

#endif // __DOUBLYLINKEDLIST_H__