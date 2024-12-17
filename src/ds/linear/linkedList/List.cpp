#include "/home/aman/code/metaalgo/include/ds/linear/linkedList/List.h"
#include <iostream>
#include <memory>


template <typename type>
List<type>::List() : head_ptr(nullptr) , tail_ptr(nullptr){};

template <typename type>
List<type>::List(std::initializer_list<type> init) : List(){
    for(const type& value : init){
        push_back(value);
    }
}

template <typename type>
List<type>::List(const List& other): List(){    
    copy_from(other);
}

template <typename type>
List<type>& List<type>::operator=(const List& other){
    if(this != &other){
        clear();
        copy_from(other);
    }
    return *this;
}

template <typename type>
List<type>::List(List&& other) noexcept : head_ptr(other.head_ptr) , tail_ptr(other.tail_ptr){
    other.tail_ptr = nullptr;
}

template <typename type>
List<type>& List<type>::operator=(List&& other) noexcept {
    if (this != other){
        clear();
        head_ptr = other.head_ptr;
        tail_ptr = other.tail_ptr;
        other.tail_ptr = nullptr;

    }
    return *this;
}

template <typename type>
void List<type>::push_front(type value){
    /*
    updates the head pointer.
    new element in front of the array

    general algo
        head->prev = newNode
        newNode->next = head
        head = newNode
        size ++;
    base case
        head == null
    */
    auto newNode = std::make_shared<Node>(value);

    if(head_ptr == nullptr){
        head_ptr = newNode;
        tail_ptr = newNode;
    }
    else{
        head_ptr->PREV = newNode;
        newNode->NEXT = head_ptr;
        head_ptr = newNode;
    }
    size++;
}

template <typename type>
void List<type>::push_back(type value){

    /*
    updates the tail pointer
    new element in back of the array

    general algo
        newNode->prev = tail
        tail->next = newNode
        tail = newNode
    
    base case
        head == null

    
    */
   auto newNode = std::make_shared<Node>(value);
    if(head_ptr == nullptr){
        head_ptr = newNode;
        tail_ptr = newNode;
    }
    else{
        newNode->PREV = tail_ptr;
        tail_ptr->NEXT = newNode;
        tail_ptr = newNode;
    }
    size++;

}

template <typename type>
void List<type>::insert_at(type value , int position){

    /*
    new element at any position

    general algo
        newNode->prev = ptr
        newNode->next = ptr->next
        ptr->next->prev = newNode
        ptr->next = newnode

    base case
        head = null
        index out of range
        head = tail
        insert at last position

    */
   try{
        auto newNode = std::make_shared<Node>(value);

        if (head_ptr == nullptr){
            head_ptr = newNode;
            tail_ptr = newNode;

        }
        else if(position < 0){
            throw "not a valid index";
        }
        else if(position > size){
            std::cout << "error";
            throw "index out of range";
            return;
        }

        else if(position == size-1){
            push_back(value);

        }

        else if(position == 0){
            push_front(value);
        }

        else{
            auto ptr = head_ptr;

            for(int i = 0 ; i < position - 1 ;i++){
                ptr = ptr->NEXT;
            }

            newNode->PREV = ptr;
            newNode->NEXT = ptr->NEXT;
            ptr->NEXT->PREV = newNode;
            ptr->NEXT = newNode;

        }
        size++;
   }
   catch(const char* e){
    std::cout << e << std::endl;
    std::exit(EXIT_FAILURE);
   }
}

template <typename type>
type List<type>::pop_front(){
    /*
    removes the front element and prints it

    general algo
        ptr = head
        head->next->prev = null
        head = head->next;
        delete ptr
        print(ptr->value)
    
    base case
        head = null

    */
   try{
        if(head_ptr == nullptr){
            throw "List is empty";
        }
        else if(head_ptr == tail_ptr){
            auto ptr = head_ptr;
            type data = ptr->value;
            head_ptr = nullptr;
            tail_ptr = nullptr;
            return data;
        }
        else{
            auto ptr = head_ptr;
            head_ptr->NEXT->PREV = nullptr;
            head_ptr = head_ptr->NEXT;
            type data = ptr->value;
            size--;
            return data;
        }
   }
   catch(const char* e){
    std::cout << e << std::endl;
    std::exit(EXIT_FAILURE);
   }
    
}

template <typename type>
type List<type>::pop_back(){
    try{
        if(head_ptr == nullptr){
            throw "List is empty";
        }

        else if(head_ptr == tail_ptr){
            auto ptr = tail_ptr;
            type data = tail_ptr->value;
            head_ptr = nullptr;
            tail_ptr = nullptr;
            size--;
            ptr.reset();
            return data;
        }
        else{
            auto ptr = tail_ptr;
            type data = tail_ptr->value;
            tail_ptr = tail_ptr->PREV;
            tail_ptr->NEXT = nullptr;
            size--;
            ptr.reset();
            return data;
        }
    }
    catch(const char* e){
    std::cout << e << std::endl;
    std::exit(EXIT_FAILURE);
   }
    
}

template <typename type>
void List<type>::remove(type value){
    /*
    searches for value and removes it

    base case 
    - if the value doesn't exist
    - head_ptr == null -> O(1)
    - head_ptr == tail_ptr -> O(1)
    - value -> tail_ptr -> O(1)
    - value -> head_ptr -> O(1)


    */

   try{
    if(head_ptr == nullptr){
        throw "list is empty";

    }

    else if(head_ptr == tail_ptr){
        if(head_ptr->value == value){
            auto ptr = head_ptr;
            head_ptr = nullptr;
            tail_ptr = nullptr;
            ptr.reset();
        }
        else{
            throw "value not present";
        }

    }
    else if(head_ptr->value == value){
        pop_front();
    }
    else if(tail_ptr->value == value){
        pop_back();
    }
    else{
        auto ptr = head_ptr;
        while(ptr->value != value && ptr != tail_ptr){
            ptr = ptr->NEXT;
        }
        if(ptr == tail_ptr){
            throw "value not found";
        }
        else{
            ptr->PREV->NEXT = ptr->NEXT;
            ptr->NEXT->PREV = ptr->PREV;
            ptr.reset();
        }
    }
    size--;
   }
   catch(const char* e){
    std::cout << e << std::endl;
    std::exit(EXIT_FAILURE);
   }
   
}

template <typename type>
void List<type>::erase(int position){
    /*
    erase the element on position 'position'

    base case-
    head_ptr == null
    position > size
    position = -ve
    position = size
    position = 0


    */
   try{

   
    if(head_ptr == nullptr){
        throw "list is empty";
    }

    else if(position >= size || position < 0){
        throw "invalid index";
    }

    else if(position == size-1){
        pop_back();
        
    }

    else if(position == 0){
        pop_front();
    }

    else{
        auto ptr = head_ptr;
        for(int i = 0 ; i <= position ; i++){
            ptr = ptr->NEXT;

        }
        ptr->PREV->NEXT = ptr->NEXT;
        ptr->NEXT->PREV = ptr->PREV;
        ptr.reset();
    
    }
    size--;


   }
   catch(const char* e){
    std::cout << e << std::endl;
    std::exit(EXIT_FAILURE);
   }

}

template <typename type>
void List<type>::clear(){
    head_ptr = nullptr;
    tail_ptr = nullptr;
    size = 0;
}


template <typename type>
int List<type>::isEmpty(){
    return (size == 0) ? 1 : 0;
}

template <typename type>
type List<type>::front(){
    return head_ptr->value;
}

template <typename type>
type List<type>::back(){
    return tail_ptr->value;
}

template <typename type>
List<type>::Node* List<type>::end(){
    Node* ptr = (Node*)tail_ptr;
    return ptr;
}

template <typename type>
List<type>::Node* List<type>::end(){
    Node* ptr = (Node*)tail_ptr;
    return ptr;
}


template <typename type>
void List<type>::sort(){
    void merged_sort = [](std::shared_ptr<Node>head){
        if(head == nullptr || head->NEXT == nullptr){
            return head;
        }
        std::shared_ptr<Node> middle = find_middle(head);
        std::shared_ptr<Node> middle_next = middle->NEXT;
        middle->NEXT = nullptr;

        std::shared_ptr<Node> left = merged_sort(head);
        std::shared_ptr<Node> right = merged_sort(middle_next);
        return merge(left , right)
    }

    void find_middle = [](std::shared_ptr<Node>head){
        auto slow = head;
        auto fast = head;
        while(fast->NEXT != nullptr and fast->NEXT->NEXT != nullptr){
            slow = slow->NEXT;
            fast = fast->NEXT->NEXT;
        }

        return slow;
    }

    void merge(std::shared_ptr<Node> left ,std::shared_ptr<Node> right){
        if(left == nullptr){
            return right;
        }
        else if(righ == nullptr){
            return right;

        }

        if(left->value <= right->value){
            auto res = left;
            res->NEXT = merge(left->NEXT , right)
            res->NEXT->PREV = res;
        }
        else{
            auto res = right;
            res->NEXT = merge(left , right->NEXT);
            res->NEXT->PREV = res;


        }
        return res
        
    }
    merged_sort(head_ptr);

}

template <typename type>
void List<type>::print(){
    std::shared_ptr<Node> ptr;
    ptr = head_ptr;

    while (ptr != nullptr){
        std::cout << ptr->value << " ";
        ptr = ptr->NEXT;
        
    }
    std::cout << "\n" << "Size: " << size << "\n"; 
}



