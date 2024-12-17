// #include "BinarySearchTree.h"
#include <initializer_list>
#include <iostream>
#include <memory>
// #include "include/ds/tree/BinarySearchTree.h"
/*
main prop
    - left subtree root < root <= right subtree root

layout ->
BinarySearchTree<int> bst = {1,2,3,4,1,4,2}

- insert , O(log n)
- remove , O(log n)
- traversal O(n)
    - inorder 
    - preorder
    - postorder
    - bfs
    - dfs

- search
- sort
- max
- min
- len
- height
- lowest common ancestor
- sum


*/




template <typename type>
class BinarySearchTree : public BinarySearchTree{
private:
    // defination of a single node of a tree
    struct Node{
        type data;
        struct Node* left;
        struct Node* right;
        Node(type value) : data(value) , left(nullptr) , right(nullptr){}
    };
    // ptr to root node
    std::unique_ptr<Node> root = nullptr;
    
    // insert function
    void insert(type value){
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        // if root is null
        if(root == nullptr){
            root = newNode;
            return;
        }
        // pointer for traversal
        std::unique_ptr<Node> ptr = root;

        while(true){
            if(value < ptr->data){
                if(ptr->left == nullptr){
                    ptr->left = newNode;
                    break;
                }
                ptr = ptr->left;
            }

            else if(value > ptr->data){
                if(ptr->right == nullptr){
                    ptr->right = newNode;
                    break;
                }
                ptr = ptr->right;
            }
            else{
                // delete newNode;
                break;
            }
        }
    }

    void inorderTraverse(std::unique_ptr<Node> node){
        if(!node) return;
        inorderTraverse(node->left);
        std::cout << node->data << " ";
        inorderTraverse(node->right);
    }

    
    // void destroyTree(std::unique_ptr<Node> node) {
    //     if (!node) return;
    //     destroyTree(node->left);
    //     destroyTree(node->right);
    //     delete node;
    // }

public:
    // constructure if no values are given
    BinarySearchTree() : root(nullptr){}

    // init values are given
    BinarySearchTree(std::initializer_list<type> elements) : root(nullptr){
        for(const type value : elements){
            insert(value);
        }
    }
    // ~BinarySearchTree() {
    //     destroyTree(root);
    // }

    void inorderTraverse(){
        inorderTraverse(root);
        std::cout << "\n";
    }
};



int main(){

    BinarySearchTree<int> bt = {1,4,2,3,6,3};
    bt.inorderTraverse();

    
}