// Name: Crystal Lim
// SID: 861041326
// Date: 4/27/15
// Lab 4
// Section 21

#include <iostream>
#include <vector>

#include "lab4.h"

using namespace std;

int main() {
    
    cout << "___pre-order___" << endl;
    preorder(9);
    
    cout << "___post-order___" << endl;
    postorder(9);
    
    cout << "___sorted___" << endl;
    sorted(9);
    
    
    return 0;
}