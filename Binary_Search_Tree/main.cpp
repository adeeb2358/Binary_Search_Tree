//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by adeeb mohammed on 01/12/19.
//  Copyright © 2019 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
#include "BST.h"
#include "_BST.h"


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
