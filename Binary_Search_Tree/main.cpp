//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by adeeb mohammed on 01/12/19.
//  Copyright © 2019 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
/*
    implementation of bianry search tree using
 */

class BST{
    public :
    
    int value;
    BST *left;
    BST *right;
    
    /*
        function initializes the new binary search tree.
    */
    BST(int val){
        this->value = val;
        this->left  = NULL;
        this->right = NULL;
    }
    
    /*
        function for inserting a new node into the binary search tree
     */
    
    BST &insert(int val){
        if(val < this->value){
            if(this->left == NULL){
                this->left = new BST(val);
            }else{
                this->left->insert(val);
            }
        }else{
            if(this->right == NULL){
                this->right = new BST(val);
            }else{
                this->right->insert(val);
            }
        }
        return *this;
    }
    
    /*
        check whether the value exists in the bst
        fully using recursion
     */
    
    bool contains(int val){
        if(val < this->value){
            if(this->left == NULL){
                return false;
            }else{
                return this->left->contains(val);
            }
        }else if(val > this->value){
            if(this->right == NULL){
                return false;
            }else{
                return this->right->contains(val);
            }
        }else{
            return true;
        }
    }
    // remove a node from a binary search tree
    // solution using recursion
    BST &remove(int val,BST *parent=NULL){
        if(val < this->value){
            if(this->left != NULL){
                this->left->remove(val,this);
           }
        }else if(val > this->value){
            if(this->right != NULL){
                this->right->remove(val,this);
            }
        }else{
            // here in this case we have found the value to remove
            // case 1 :- the left and right node are present
            // case 2 :- parent node is empty and either of the left or right node is empty
            // case 3 :- parent node is non empty, but either of the left or right child is empty
            
            // case 1
            if((this->left != NULL) && (this->right != NULL)){
                this->value = this->right->getMinValue();
                this->right->remove(this->value,this);
            }
            // case 2
            else if(parent == NULL){
                if(this->left != NULL){
                    // the order is very important, for left subtree assign right node first and then left node
                    this->value = this->left->value;
                    this->right = this->left->right;
                    this->left  = this->left->left;
                }else if(this->right != NULL){
                    // assignt the left node first then assign the right node
                    this->value = this->right->value;
                    this->left  = this->right->left;
                    this->right = this->right->right;
                }else{
                    value = 0;
                }
            }
            // case 3 left
            else if(parent->left == this){
                parent->left = (this->left != NULL)? this->left : this->right;
            }
            // case 3 right
            else if(parent->right == this){
                parent->right = (this->left != NULL)? this->left : this->right;
            }
        
        }
        return *this;
    }
    // function for getting the minimum value from the binary search tree
    int getMinValue(){
        if(this->left == NULL){
            return this->value;
        }else{
            return this->left->getMinValue();
        }
    }
};


int main(int argc, const char * argv[]) {
    BST *pBST = new BST(5);
    pBST->insert(5);
    pBST->insert(6);
    pBST->insert(4);
    pBST->insert(1);
    int result = pBST->contains(1);
    std::cout << "Result :"<< result;
    delete pBST;
    return 0;
}
