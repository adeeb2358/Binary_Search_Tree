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
    
    BST &insert(int val){
        return *this;
    }
    
    bool contains(int val){
        bool result = false;
        return result;
    }
    
    BST &Remove(){
        return *this;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "This is good";
    std::cout << "Hello, World!\n";
    return 0;
}
