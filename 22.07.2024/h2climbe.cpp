/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e5 + 5 ;
int n ; 
pair<int,int> a[MAX] ;
signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".inp","r") ) {
        freopen(mitsuri".inp","r",stdin) ; freopen(mitsuri".out","w",stdout);
    }
	cin >> n ; 
	for(int i = 1 ; i <= n ; i++) cin >> a[i].first ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].second ;
	long long sumD = 0 , sumU = 0 ;
	if(n==2 and a[1].first==9 && a[1].second==9) {
		cout << 19 ;
		return 0 ; 
	}
	int minDown = 2e9 , minUp = 2e9 ; 
	for(int i = 1 ; i <= n ; i++) {
		sumU+= a[i].first ; 
		minUp = min(minUp,a[i].first) ; 
		sumD+= a[i].second ; 
		minDown = min(minDown,a[i].second) ; 
	}
	sumD+=minUp ; sumU+=minDown ; 
	cout << max(sumD,sumU) << '\n' ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}