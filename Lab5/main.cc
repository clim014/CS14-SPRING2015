// Name: Crystal Lim
// SID: 861041326
// Date: 5/11/15
// Lab 5
// Section 21


#include <iostream>
#include "lab5.h"


using namespace std;





int main() {
    
    
    
    
    cout << "------------------" << endl;
    cout << "LAB 5" << endl;
    cout << "------------------" << endl;
    cout << endl;
    
    BST<int> myBST2;
    myBST2.insert(50);
    myBST2.insert(20);
    myBST2.insert(60);
    myBST2.insert(10);
    myBST2.insert(40);
    myBST2.insert(70);
    myBST2.insert(35);
    myBST2.insert(45);
    
    cout << "Part 1" << endl;
    myBST2.minCover();
    myBST2.displayMincover();
    
    
    cout << "Part 2" << endl;
    myBST2.findSumPath(80);
    
    
    cout << "Part 3" << endl;
    myBST2.vertSum();
    
    return 0;
}