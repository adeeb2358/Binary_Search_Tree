//
//  _BST.h
//  Binary_Search_Tree
//
//  Created by adeeb mohammed on 08/12/19.
//  Copyright © 2019 adeeb mohammed. All rights reserved.
//

#include <cmath>
#include <float.h>

#ifndef _BST_h
#define _BST_h
/*
    solution for binary search tree without recursion 
 */

class _BST{
    _BST* left ;
    _BST* right ;
    int value ;
    _BST(int val){
        this->left = NULL;
        this->right = NULL;
        this->value = val;
    }
  
    //insert function time complexity O(logn) space o(1)
    _BST &insert(int val){
        _BST *currentNode = this;
        while(true){
            if(val < currentNode->value){
                if (currentNode->left == NULL){
                    currentNode->left = new _BST(val);
                    break;
                }else{
                    currentNode = currentNode->left;
                }
            }else{
                if(currentNode->right == NULL){
                    currentNode->right = new _BST(val);
                    break;
                }else{
                    currentNode = currentNode->right;
                }
            }
        }
        return *this;
    }
    
    // function for checking whether the node exists in the array
    
    bool contains(int val){
        _BST *currentNode = this;
        while(currentNode != NULL){
            if(currentNode->value > val){
                currentNode = currentNode->left;
            }else if(currentNode->value < val){
                currentNode = currentNode->right;
            }else{
                return true;
            }
        }
        return false;
    }
    
    // function for removing a node from the tree space complexity o(1)
    _BST &remove(int val, _BST *parentNode = NULL){
        _BST *currentNode = this;
        while(currentNode != NULL){
            if(currentNode->value > val){
                parentNode = currentNode;
                currentNode = currentNode->left;
            }else if(currentNode->value < val){
                parentNode = currentNode;
                currentNode = currentNode->right;
            }else{
                // we found the node with exact match
                // case the node is having left and right child
                if(currentNode->left != NULL && currentNode->right != NULL){
                    currentNode->value = currentNode->right->getMinValue();
                    currentNode->right->remove(currentNode->value,currentNode);
                }else if(parentNode == NULL){
                    if(currentNode->left != NULL){
                        currentNode->value = currentNode->left->value;
                        currentNode->right = currentNode->left->right;
                        currentNode->left = currentNode->left->left;
                    }else if(currentNode->right != NULL){
                        currentNode->value = currentNode->right->value;
                        currentNode->left  = currentNode->right->left;
                        currentNode->right = currentNode->right->right;
                    }else{
                        currentNode->value = 0;
                    }
                }else if(parentNode->left == currentNode){
                    parentNode->left = (currentNode->left != NULL)? currentNode->left : currentNode->right;
                }else if(parentNode->right == currentNode){
                    parentNode->right = (currentNode->left != NULL)? currentNode->left : currentNode->right;
                }
                break;
            }
        }
        return *this;
    }
    
    int getMinValue(){
        if(this->left == NULL){
            return this->value;
        }else {
            return this->left->getMinValue();
        }
    }
    
    int findClosestValueInBst(_BST *tree, int target){
        return findClosestValueInBstHelper(tree, target, DBL_MAX);
    }
    
    int findClosestValueInBstHelper(_BST *tree, int target, int closest){
        _BST *currentNode = tree;
        while (currentNode != NULL) {
            if(abs(target - closest) > abs(target - currentNode->value)){
                closest = currentNode->value;
            }
            if(target < currentNode->value ){
                currentNode = currentNode->left;
            }else if(target > currentNode->value ){
                currentNode = currentNode->right;
            }else{
                break;
            }
        }
        return (int)closest;
    }
};

#endif /* _BST_h */
