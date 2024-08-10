/* 
    Code by Watbor :>>
*/
#include <bits/stdc++.h>
using namespace std ; 

const int MAX = 1e5 + 5 ;
const int NUM_BIT = 50 ;

long long x, k ;
int comb[NUM_BIT+5][NUM_BIT+5] ;

void prepare(void) {
	
	for(int i(1) ; i <= NUM_BIT ; i++) {
		comb[0][i] = 1 ; 
		comb[i][0] = 0 ; 
	}	

	for(int i(1) ; i <= NUM_BIT ; i++) {
		for(int j(1) ; j <= NUM_BIT ; j++) {
			if(i < j) comb[i][j] = comb[i][j-1] + comb[i-1][j-1] ; 
			if(i == j) comb[i][j] = 1 ; 
			if(i > j) comb[i][j] = 0 ; 
		}
	}

}

long long get_rank(long long x,int numOne) {

	int cntOne = 0 ; 
	long long ret = 0 ; 	

	for(int i(NUM_BIT - 1) ; i ; i--) {
		if((x>>i)&1) {
			int need = numOne - cntOne ; 
			if(need >= 0 && need <= i) {
				ret+= comb[need][i] ; 
			}
			cntOne++ ; 
 		}
	}

	return ret ; 
}

void process(void) {
	prepare() ;
	long long rankX = get_rank(x,__builtin_popcountll(x)) ; 
	cout << rankX ; 

	cout << '\n' ; 
}

signed main(void) {
    #define mitsuri "NEXT"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }

    int T ; 
    cin >> T ;
    while(T--) {
    	cin >> x >> k ;
    	prepare() ; 
    	process() ; 
    }
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ; 
}