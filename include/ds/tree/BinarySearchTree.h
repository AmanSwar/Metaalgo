#include "Tree.h"


namespace Tree{
    template <typename type>
    class BinarySearchTree{
    private:
        struct Node{
            type data;
            struct Node* left;
            struct Node* right;
            Node(type value) : data(value), left(nullptr), right(nullptr){}

        }

        


    }
}