#ifndef LIST_H
#define LIST_H

#include <initializer_list>

/*
default implementation -> double linked list 
*/


template <typename type>
class List{
private:
    struct Node{
        type value;
        Node* NEXT;
        Node* PREV;

        Node(type data) : value(data) , NEXT(nullptr);
    };

    Node* head_ptr;
    Node* tail_ptr;

public:
    //initlize list empty
    List();
    // init list with array of values
    List(std::initializer_list<type> init);
    // copy constructor
    List(const List& other);
    List& operator=(const List& other);

    List(List&& other) noexcept;
    List& operator=(const List&& other) noexcept; 

    ~List() = default;

    // ADDING ELEMENT
    void push_front(type value);
    void push_back(type value);
    void insert_at(type value , int position);

    // DELETION OF ELEMENT
    type pop_front();
    type pop_back();
    void remove(type value);
    void erase(int position);
    Node* clear();

    // HELPER FUNCTION
    int isEmpty();
    type front();
    type back();
    Node* begin();
    Node* end();

    // FUNCTIONAL
    void sort();
    void reverse();
    void swap();
    void merge();
    void unqiue();
    void copy_from();

};


#endif