// Name: Crystal Lim
// SID: 861041326
// Date: 4/27/15
// Lab 4
// Section 21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/////////////////////////////////////////////
// PART 1

// recursive function helper
// (m,n) specifies the node
void cptreePre(int k, int m, int n) {
    if (m + n < k) {
        cout << m << " " << n << endl;
        
        cptreePre( k, 2*m-n, m ); // left
        cptreePre( k, 2*m+n, m ); // middle
        cptreePre( k, m+2*n, n ); // right
        
    }
    
    return;
}


void preorder(int k) {
    if (k < 4) {
        cout << "None" << endl;
    }
    else if (k == 4) {
        cptreePre( k, 2, 1 );
    }
    else if ( k >= 5 ) {     
        cptreePre( k, 2, 1);
        cptreePre( k, 3, 1);
    }
    
    return;
}

///////////////////////////////////////////////
// PART 2

void cptreePost(int k, int m, int n) {
    if (m + n < k) {
        cptreePost( k, 2*m-n, m ); // left
        cptreePost( k, 2*m+n, m ); // middle
        cptreePost( k, m+2*n, n ); // right
        
        cout << m << " " << n << endl;
    }
    
    return;
}

void postorder(int k) {
    if (k < 4) {
        cout << "None" << endl;
    }
    else if (k == 4) {
        cptreePost( k, 2, 1 );
    }
    else if ( k >= 5 ) {     
        cptreePost( k, 2, 1);
        cptreePost( k, 3, 1);
    }
    
    return;
}

///////////////////////////////////////////////
// PART 3
struct coprimePair {
    int first;
    int second;
};


class compareSum {
    public:
    bool operator()(coprimePair& pair1, coprimePair& pair2) {
        
        if ( (pair1.first + pair1.second) > (pair2.first + pair2.second) ) {
            return true;
        }
        else if ((pair1.first + pair1.second) == (pair2.first + pair2.second)) {
            if (pair1.first > pair2.first) {
                return true;
            }
            
            return false;
        }
        
        
        return false;
    }
};




void cptreeSorted(int k, 
    priority_queue< coprimePair, vector<coprimePair>, compareSum >& myQ, 
    //queue<coprimePair>& myQ,
    int m, int n) {
    
    if (m + n < k) {
        // make pair
        coprimePair myPair;
        myPair.first = m;
        myPair.second = n;
        
        
        // children
        cptreeSorted( k, myQ, 2*m-n, m ); // left
        cptreeSorted( k, myQ, 2*m+n, m ); // middle
        cptreeSorted( k, myQ, m+2*n, n ); // right
        
        // insert created pair
        myQ.push(myPair);
    }
    
    return;
}

void sorted(int k) {
    // make queue to keep track
    
    priority_queue< coprimePair, vector<coprimePair>, compareSum > myQ;
    //queue<coprimePair> myQ;
    
    
    if (k < 4) {
        cout << "None" << endl;
    }
    else if (k == 4) {
        cptreeSorted( k, myQ, 2, 1 );
    }
    else if ( k >= 5 ) {
        cptreeSorted( k, myQ, 2, 1);
        cptreeSorted( k, myQ, 3, 1);
        
    }
    
    while (!myQ.empty()) {
        cout << myQ.top().first << " " << myQ.top().second << endl;
        myQ.pop();
    }
    cout << endl;
    
    
    return;
}
