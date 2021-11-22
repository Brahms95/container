#include <iostream>
using namespace std;

template <typename T>
struct Node {

    T val;
    Node* next;

    Node() :next(nullptr){ }; 
    Node(T _val) : val(_val), next(nullptr) {}
    Node(T _val, Node* _next) : val(_val), next(_next) {}
};
 
template <typename T>
struct list {
    Node<T>* first;
    Node<T> second;
    Node<T>* last;
    int  size_list ;
 
    list() : first(nullptr), last(nullptr), size_list(0) {}
    
    bool is_empty() {
        return first == nullptr;
    }

    public:
    class iterator
    {
        friend class list;
        
        private:
        iterator(Node<T>* node) : m_node(node) {}

        public:
        iterator() : m_node(0) {}

        private:
        Node<T>* m_node;
    };

public:

    Node<T>* iterator_begin(){
        return first->next;
    }
    Node<T>* iterator_end(){
        return first->next;
    }
    void push_back(T _val) {
        Node<T>* p = new Node<T>(_val);
        if (first == nullptr) {
            first = p;
            last = p;
            size_list++;
            return;
        }
        last->next = p;
        last = p;
        size_list++;
    }
 
    void print() {
        if (first == nullptr) return;
        Node<T>* p = first;
        while (p) {
           cout << p->val << " " ;
         // cout << p->val << " " << "(" << p->next << ")" << " " ;
            p = p->next;
        }
        cout << endl;
    }
 
    int size_print(){
        return size_list;
    }
 
    void remove_first() {
        if (first == nullptr) return;
        Node<T>* p = first;
        first = p->next;
        delete p;
    }
 
    void insert(T _value){
        if (_value == 0){
            push_back(_value);
        }
        Node<T>* p = this ->first;
         Node<T>* p1 = this ->first;
        for (int i =1 ; i<size_list/2; i++){

            p1= p1->next;
           
        }
    
        Node<T>* pow = new Node<T>(_value ,p1->next);
        p1->next= pow;
        size_list++;
 
    }
 
    void remove_last() {
        if (first == nullptr) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node<T>* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
         size_list--;
    }
 
    void push_frond(T _val){
        Node<T>* p = new Node<T>(_val);
        if (first == nullptr) {
            first = p;
            last = p;
            size_list++;
            return;
        }
  
        p->next=first ;
        first=p;
        size_list ++;
    }
 
    void erase(T _val) {
 
        if (first == nullptr) return;
 
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node<T>* slow = first;
        Node<T>* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        size_list--;
        delete fast;
    }
 
    Node<T>* operator[] (const int index) {
        if (first == nullptr) return nullptr;
        Node<T>* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};
 
