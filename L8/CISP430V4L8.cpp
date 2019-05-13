// AUTHOR     : Cynthia Carrillo
// FILE       : CISP430V4L8.cpp 
// DESCRIPTION: This program allows the user to enter as many integers as 
//              they'd like. It then displays the nodes in inorder, preorder,
//              and postorder. It also shows the tree height, node count, and 
//              leaves count. 

#include <iostream>
#include "binarySearchTree.h"

int main()
{
    bSearchTreeType<int> b;                             // declare an int of bSearchTree type
    int num;                                            // local variale hold user input 

    std::cout << "Enter numbers ending with -999\n";    // prompt the user 
    std::cin >> num;                                    // store user data 

    while (num != -999)                                 // loop until user enters -999
    {
        b.insert(num);
        std::cin >> num;
    }

    std::cout << "Nodes inorder: ";                     // display the nodes in inorder 
    b.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Nodes preorder: ";                    // display the nodes in preorder
    b.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Nodes postorder: ";                   // display the nodes in postorder 
    b.postorderTraversal();
    std::cout << std::endl;

    // display the tree height, node count, and leaves count 
    std::cout << "Height: " << b.treeHeight() << std::endl;
    std::cout << "Number of Nodes: " << b.treeNodeCount() << std::endl;
    std::cout << "Number of leaves: " << b.treeLeavesCount() << std::endl;

    system("PAUSE");
    return 0;
}
