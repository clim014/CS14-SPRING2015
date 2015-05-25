// Name: Crystal Lim
// SID: 861041326
// Date: 5/18/15
// Lab 7
// Section 21

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <set>
#include <stdlib.h>


using namespace std;

// making a vector of strings read in from file
struct dictionary {
    vector<string> myDict;
        
    dictionary( const string& listFile ) {
        string word;
        
        ifstream inFS;
        inFS.open(listFile.c_str());
        
        if (!inFS.is_open()) {
            cout << "Could not open file." << endl;
            return; // indicates error
        }
        
        while (inFS >> word) {
            myDict.push_back(word);
        }
        
        inFS.close();
    }
    
    // returns string at position loc
    // for testing purposes
    string& at (int loc) {
        return myDict.at(loc);
    }
    
    // returns size of dictionary
    int size() {
        return myDict.size();
    }
    
    // scramble
    void scramble() {
        int s = size();
        for (int i = 0; i < s; ++i) {
            swap( myDict.at(i), myDict.at(rand() % s) );
        }
    }
    
};



// hashtable
class hashtable {
    private:
        unordered_set<string> HT;
    public:
        hashtable() {
            unordered_set<string> HT;
        }
        
        void insertWords (int numWords, dictionary& dict) {
            for (int i = 0; i < numWords; ++i) {
                HT.insert(dict.at(i));
            }
        }
        
        void findWords (int numWords, dictionary& dict) {
            unordered_set<string>::const_iterator g;
            for (int i = 0; i < numWords; ++i) {
                g = HT.find(dict.at(i));
            }
        }
};

// tree
class SBtree {
    private:
        set<string> tree;
    public:
        SBtree() {
            set<string> tree;
        }
        
        void insertWords (int numWords, dictionary& dict) {
            for (int i = 0; i < numWords; ++i) {
                tree.insert(dict.at(i));
            }
        }
        
        void findWords (int numWords, dictionary& dict) {
            set<string>::iterator it;
            for (int i = 0; i < numWords; ++i) {
                it = tree.find(dict.at(i));
            }
        }
};