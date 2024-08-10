/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
#define int long long
const int MAX = 1e5 + 5 ; 

int n ;
bool prime[MAX + 5] ; 

void sieve(void) {
	for(int i = 2 ; i <= n ; i++) prime[i] = 1 ; 

	for(int i = 2 ; i * i <= n ; i++) {
		for(int j = i * i ; j <= n ; j+=i) {
			prime[j] = 0 ; 
		}
	}
}

int LT(int x,int y) {
	if(y==0) return 1 ; 
	if(y==1) return x ; 
	int c = LT(x,y/2) ; 
	if(y&1) return c * c * x ; 
	else return c * c ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n ; 
    vector<int> vec ;
    int s = 1 ;
    for(int i = 1 ; i <= n - 1 ; i++) if(__gcd(n,i)==1) {
    	s*= i ;
    	s%= n ;
    }
    if(s%n==1) {
    	for(int i = 1 ; i <= n - 1 ; i++) if(__gcd(n,i)==1) {
    		vec.push_back(i) ; 
    	}
    	cout << vec.size() << endl ;
    	for(auto x : vec) cout << x << ' ' ;
    	return 0 ;
    }
   
    for(int i = 1 ; i <= n - 1 ; i++) if(__gcd(n,i)==1 && s!=i) {
    	vec.push_back(i) ; 
    }
    cout << vec.size() << endl ; 
    for(auto x : vec) cout << x << ' ' ;
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}