/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e5 + 5 ;

int n ; 
char a[5005][5005] ; 

void init(void) {
	cin >> n ; 
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) cin >> a[i][j] ; 
	}
}

void solve(void) {

}

signed main(void) {
    #define watbor ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(watbor".inp","r") ) {
        freopen(watbor".inp","r",stdin) ; freopen(watbor".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "WatborLAT : " << clock() << "ms" << endl;
    return 0 ;
}