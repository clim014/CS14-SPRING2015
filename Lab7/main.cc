// Name: Crystal Lim
// SID: 861041326
// Date: 5/18/15
// Lab 7
// Section 21

#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include "test.h"


using namespace std;


int main() {
    srand(333);
    
    clock_t t;
    t = clock();
    
    cout << "testing..." << endl;
    dictionary myDict("words.txt");
    
    cout << myDict.at(0) << endl;
    
    hashtable myHT;
    myHT.insertWords(5,myDict);
    myHT.findWords(5,myDict);
    
    t = clock() - t;
    
    printf("It took me %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    
    cout << ((float)t)/CLOCKS_PER_SEC << endl;
    cout << endl;
    
    
    cout << "testing scramble" << endl;
    dictionary d("w.txt");
    d.scramble();
    for (int i = 0; i < d.size(); ++i) {
        cout << d.at(i) << " ";
    }
    cout << endl;
    
    
    cout << "testing add..." << endl;
    
    vector<float> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    vector<float> r;
    r.push_back(1);
    r.push_back(2);
    r.push_back(3);
    
    vector<float> result;
    result = add(r,v);
    
    for (unsigned i = 0; i < result.size(); ++i) {
        cout << result.at(i) << " ";
    }
    cout << endl;
    
    cout << "testing record..." << endl;
    record();
    
    
    
    return 0;
}