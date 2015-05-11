// Name: Crystal Lim
// SID: 861041326
// Date: 5/11/15
// Lab 5
// Section 21

#ifndef BST_H
#define BST_H


#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>


#include <stdlib.h> // for the exit(-1)
#include <list> // to print findSumPath in order

using namespace std;

#define nil 0
//#define Vallue int // restore for testing.
template <typename Value>
class BST {
    
    class Node { // binary tree node
    public:
        Node* left;
        Node* right;
        Value value;
        bool visited;
        bool selected;
        
        Node( const Value v = Value() )
            : left(nil), right(nil), value(v), visited(false), selected(false)
        {}
        
        Value& content() { return value; }
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }
        int height() {
            // returns the height of the subtree rooted at this node
            // FILL IN
            
            // height - length of its longest root-to-leaf path
            //          root in this case being the current node
            
            
            if (left == nil && right == nil) {
                return 0;
            }
            else if (left == nil) {
                return 1 + right->height();
            }
            else if (right == nil) {
                return 1 + left->height();
            }
            else {    
                if ( left->height() >= right->height() ) {
                    return 1 + left->height();
                }
                else {
                    return 1 + right->height();
                }
                
            }
            
        }
        
        int size() {
            // returns the size of the subtree rooted at this node
            // FILL IN
            
            // if you call size on an empty node
            if (this == nil) {
                return 0;
            }
            if (left == nil && right == nil) {
                return 1; // 0 or 1 depending on if we count initial node
            }
            else if (left == nil) {
                return 1 + right->size();
            }
            else if (right == nil) {
                return 1 + left->size();
            }
            else {
                return 1 + left->size() + right->size();
            }
            
        }
    }; // Node
    
    
    // const Node* nil; later nil will point to a sentinel node.
    Node* root;
    int count;
    
    public:
    
        int size() {
            // size of the overall tree.
            // FILL IN
            return root->size();
        }
        
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) const {
            // Print the node's value
            // FILL IN
            cout << n->value;
        }
        
        bool search ( Value x ) {
            // search for a Value in the BST and return true iff it was found.
            // FILL IN
            int h = root->height();
            Node* temp;
            temp = root;
            
            count = 0;
            while ( count <= h ) {
                if (x == temp->value) {
                    return true; // found value
                }
                else if (x < temp->value) {
                    temp = temp->left; // search left branch
                }
                else if (x > temp->value) {
                    temp = temp->right; // search right branch
                }
                if (temp == nil) {
                    return false; // not in tree
                }
                ++count;
            }
            
            return false;
        }
        
        
        void preorder() const {
            //Traverse and print the tree one Value per line in preorder.
            // FILL IN
            print_node(root); // print current
            cout << endl;
            
            if (root->left == nil && root->right == nil) {
                return;
            }
            else if (root->left == nil) {
                BST temp;
                temp.root = root->right;
                
                temp.preorder();  // go right
            }
            else if (root->right == nil) {
                BST temp;
                temp.root = root->left;
                
                temp.preorder();  // go left
            }
            else {
                BST tempLeft;
                BST tempRight;
                
                tempLeft.root = root->left;
                tempRight.root = root->right;
                
                tempLeft.preorder(); // go left
                tempRight.preorder(); // then go right
            }
            
            
            
            return;
        }
        
        void postorder() const {
            // Traverse and print the tree one Value per line in postorder.
            // FILL IN
            
            if (root->left == nil && root->right == nil) {
                print_node(root); // print current only
                cout << endl;
                return;
            }
            else if (root->left == nil) {
                BST temp;
                temp.root = root->right;
                
                temp.postorder(); // go right
            }
            else if (root->right == nil) {
                BST temp;
                temp.root = root->left;
                
                temp.postorder(); // go left
            }
            else {
                BST tempLeft;
                BST tempRight;
                
                tempLeft.root = root->left;
                tempRight.root = root->right;
                
                tempLeft.postorder(); // go left
                tempRight.postorder(); // go right
            }
            
            print_node(root); // then print current
            cout << endl;
            
            return;
        }
        
        
        void inorder() const {
            // Traverse nad print the tree one Value per line in inorder.
            // FILL IN
            
            // print leaf
            if (root->left == nil && root->right == nil) {
                print_node(root);
                cout << endl;
                return;
            }
            
            else if (root->left == nil) {
                BST temp;
                temp.root = root->right;
                
                print_node(root);  // print current
                cout << endl;
                temp.inorder(); // then go right
            }
            else if (root->right == nil) {
                BST temp;
                temp.root = root->left;
                
                temp.inorder(); // go left first
                print_node(root); // then print current
                cout << endl;
            }
            else {
                BST tempLeft;
                BST tempRight;
                
                tempLeft.root = root->left;
                tempRight.root = root->right;
                
                tempLeft.inorder(); // go left
                print_node(root); // print current
                cout << endl;
                tempRight.inorder(); // then go right
            }
            
            
            
            return;
        }
        
        
        
        // THIS IS A NEW INORDER SPECIFICALLY FOR MINCOVER
        void inorder(Node* x) {
            // Traverse nad print the tree one Value per line in inorder.
            // FILL IN
            
            // print leaf
            if (x->left == nil && x->right == nil) {
                if (x->selected){
                    print_node(x);
                    cout << " ";
                    
                    ++count;
                }
                return;
            }
            else if (x->left == nil) {
                
                if (x->selected) {
                    print_node(x);  // print current
                    cout << " ";
                    
                    ++count;
                }
                
                inorder(x->right); // then go right
            }
            else if (x->right == nil) {
                
                inorder(x->left); // go left first
                
                if (x->selected) {
                    print_node(x); // then print current
                    cout << " ";
                    
                    ++count;
                }
            }
            else {
                
                inorder(x->left); // go left
                
                if (x->selected) {
                    print_node(x); // print current
                    cout << " ";
                    
                    ++count;
                }
                
                inorder(x->right); // then go right
            }
            
            
            
            return;
        }
        
        
        // operator[] helper
        Node* findIndex (int n, int counted) {
            
            int current = root->left->size() + counted; // current index
            
            if ( n == current ) {
                return root;
            }
            else if (n < current) {   // looking for lower index than root
                BST temp;
                temp.root = root->left;
                return temp.findIndex( n, counted );
            }
            else if (n > current) {   // looking for higher index
                BST temp;
                temp.root = root->right;
                
                counted = current + 1;
                return temp.findIndex( n, counted );
            }
            else {
                return root;  // to avoid the return warning when compiling
            }
            
        }
        
        
        Value& operator[] (int n) {
            // returns reference to the value field of the n-th Node.
            // FILL IN
            if (n < 0 || n >= size()){
                cout << "not a valid node ID" << endl;
                exit(-1);
            }
            
            Node* temp = findIndex( n, 0 );
            
            return temp->value;
            
        }
        
        
        
        
        BST() : root(nil), count(0) {}
        
        
        
        void insert( Value X) { root = insert( X, root ); }
        Node* insert( Value X, Node* T) {
            // The normal binary-tree insertion procedure ...
            if (T == nil) {
                T = new Node( X );   // the only place that T gets updated.
            }
            else if ( X < T->value ) {
                T->left = insert( X, T->left );
            }
            else if (X > T->value ) {
                T->right = insert( X, T->right );
            }
            else {
                T->value = X;
            }
            
            // later, rebalancing code will be installed here
            
            return T;
        }
        
        
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) {
            // The normal binary-tree removal procedure ...
            // Weiss's code is faster but way more intricate.
            if ( T != nil ) {
                if ( X > T->value ) {
                    T->right = remove( X, T->right );
                }
                else if ( X < T->value ) {
                    T->left = remove( X, T->left );
                }
                else {                                // X == T->value
                    if ( T->right != nil ) {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value;       // successor's value
                        T->right = remove( T->value, T->right );
                    }
                    else if ( T->left != nil ) {
                        Node* x = T-> left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value;       // predecessor's value
                        T->left = remove( T->value, T->left );
                    }
                    else {            // *T is external
                        delete T;
                        T = nil;    // the only updating of T
                    }
                }
            }
            
            // later, rebalancing code will be installed here
            
            return T;
        }
        
        void okay( ) { okay( root ); }
        void okay( Node* T ) {
            // diagnostic code can be installed here
            return;
        }
        
        
        
        
        
        //////////////////////////////////
        //           LAB5               //
        //////////////////////////////////
        
        
        //////////////// PART 1 ///////////////////
        
        void DFS(Node* x) {
            //mark x as visited
            x->visited = true;
            
            
            if (!x->isLeaf()) {
                
                if (x->left != nil && !x->left->visited) {
                    
                    DFS(x->left);
                    // if child not selected as vertex for minimum
                    // seleccted cover then select parent
                    if (!x->left->selected) {
                        x->selected = true;
                    }
                    
                }
                
                if (x->right != nil && !x->right->visited) {
                    
                    DFS(x->right);
                    
                    if (!x->right->selected) {
                        x->selected = true;
                    }
                    
                }
                
            }
            
        }
        
        
        void minCover() {
            // finds smallest cover of the tree such that
            // root is not part of vertex cover
            // makes them selected using DFS
            this->DFS(root);
        }
        
        
        
        void displayMincover() {
            // display smallest cover and size of vertex cover
            // Traverse nad print the tree one Value per line in inorder.
            // FILL IN
            
            count = 0;
            inorder(root);
            cout << endl;
            cout << count << endl;
            
            // reset to 0
            count = 0;
            
            
            return;
        }
        
        
        //////////////// PART 2 ///////////////////
        
        void displaySumPath(int path[]) {
            list<int> temp;
            
            int i = 0;
            while (path[i] != 0) {
                temp.push_back(path[i]);
                ++i;
            }
            
            temp.sort();
            for (list<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
            
            return;
        }
        
        int numberOfSumPath(Node* n, int sum, int buffer[]) {
            // finds and display all paths root to leaf for which sum
            // of node values on path is equal to particular 'sum' taken
            // as input
            
            // we are assuming buffer is large size
            
            // calculate original buffer sum
            // if buffer sum > sum, return 0;
            int buffSum = 0;
            int i = 0;
            while (buffer[i] != 0) {
                buffSum += buffer[i];
                ++i;
            }
            
            // put n into buffer and calculate new current buffer
            buffer[i] = n->value;
            buffSum += n->value;
            
            // reach goal
            if (buffSum == sum) {
                displaySumPath(buffer);
                return 1;
            }
            // went over
            else if (buffSum > sum) {
                return 0;
            }
            
            
            // go left
            if (n->left != nil) {
                return numberOfSumPath(n->left, sum, buffer);
            }
            
            // go right
            if (n->right != nil) {
                return numberOfSumPath(n->right, sum, buffer);
            }
            
            
            return 0;
        }
        
        void findSumPath(Node* n, int sum, int buffer[]) {
            // int x = findSumPath;
            // if x = 0, display 0;
            int x;
            x = numberOfSumPath(n, sum, buffer);
            if (x == 0) {
                cout << 0 << endl;
            }
            
        }
        
        void findSumPath(int sum) {
            // for testing from main, because can't access root in main
            // as it is a private data member
            
            int buffer[1000] = {0};
            findSumPath(root, sum, buffer);
        }
        
        
        
        //////////////// PART 3 ///////////////////
        
        void findVertSum(Node* n, int hd, std::map<int,int>& m) {
            // fills map in 
            
            // put n in the map
            m[hd] += n->value;
            
            // left child
            if (n->left != nil){
                findVertSum(n->left, hd-1, m);
            }
            
            // right child
            if (n->right != nil) {
                findVertSum(n->right, hd+1, m);
            }
            
            return;
        }
        
        void vertSum(Node* node, int hd, std::map<int,int>& m) {
            
            // updates map
            findVertSum(node, hd, m);
            
            // print
            for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it) {
                cout << it->second << " ";
            }
            cout << endl;
            
            return;
        }
        
        
        void vertSum() {
            // for testing in main
            
            map<int, int> m;
            vertSum(root, 0, m);
            return;
        }
        
        
}; // BST

#endif