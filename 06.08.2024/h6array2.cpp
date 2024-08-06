#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
using namespace std ; 

const int N = 1e5 + 5 ;

int n ;
int a[N] ;

void init() {
	cin >> n ; 
	for(int i(1) ; i <= n ; i++) cin >> a[i] ; 
}

void process() {
	
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    int test ; cin >> test ;
    while(test--) {
    	init() ; process() ; 
    }
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}