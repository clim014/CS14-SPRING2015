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
#include <map>
#include <stdlib.h>
#include "dictionary.h"


using namespace std;

vector<float> add(vector<float>& v1, vector<float>& v2) {
    
    int s = v1.size();
    for (int i = 0; i < s; ++i) {
        v1.at(i) += v2.at(i);
    }
    return v1;
}

vector<float> divide(vector<float>& v, float n) {
    
    int s = v.size();
    for (int i = 0; i < s; ++i) {
        v.at(i) = v.at(i) / n;
    }
    return v;
}




map< int, vector<float> > run() {
    map<int, vector<float>> myMap;
    vector<float> v;
    
    // make dictionary
    dictionary myDict("words.txt");
    
    int counter = 0;
    
    while (counter < 10) {
        for (int n = 5000; n <= 50000; n = n + 5000){
            // make tree and hashtable
            SBtree myTree;
            hashtable myHT;
            
            
            // <tree-insert-time>
            clock_t t;
            t = clock();
            myTree.insertWords(n,myDict);
            t = clock() - t;
            v.push_back( ((float) t) / (n * CLOCKS_PER_SEC) );
            
            // <hash-insert-time>
            t = clock();
            myHT.insertWords(n,myDict);
            t = clock() - t;
            v.push_back( ((float) t) / (n * CLOCKS_PER_SEC) );
            
            // <tree-query-time>
            t = clock();
            myTree.findWords(n,myDict);
            t = clock() - t;
            v.push_back( ((float) t) / (n * CLOCKS_PER_SEC) );
            
            // <hash-query-time>
            t = clock();
            myHT.findWords(n,myDict);
            t = clock() - t;
            v.push_back( ((float) t) / (n * CLOCKS_PER_SEC) );
            
            // first run
            if (counter == 0) {
                myMap[n] = v;
            }
            // then add times for each run
            else {
                myMap[n] = add(v,myMap[n]);
            }
            
            
            v.clear();
        }
        
        myDict.scramble();
        ++counter;
    }
    
    // divide everything by 10 to get the average
    for (int n = 5000; n <= 50000; n = n + 5000) {
        myMap[n] = divide(myMap[n],10);
    }
    
    
    
    return myMap;
}

void record() {
    ofstream outFS;
    outFS.open("data.txt");
    
    // check if open
    if (!outFS.is_open()) {
        cout << "Could not open file " << endl;
        return;
    }
    
    map< int, vector<float> > data;
    data = run();
    
    for (int i = 5000; i <= 50000; i = i + 5000) {
        vector<float> v;
        v = data.find(i)->second;
        
        outFS << i << "\t";
        for (int j = 0; j < v.size(); ++j) {
            outFS << v.at(j) << "\t";
        }
        outFS << "\n";
    }
    
    
    outFS.close();
    return;
}
