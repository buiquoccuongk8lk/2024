/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds ;
using namespace std ; 
const int MAX = 1e5 + 5 ;

int n , m , q ;
void init(void) {
	cin >> n >> m >> q ; 
}
int mp_col[50 * MAX] , mp_row[50 * MAX] ; 
void solve(void) {
	while(q--) {
		char t ; int x ; 
		cin >> t >> x ; 
		if(t=='R') mp_row[x]++ ;
		else mp_col[x]++ ; 
	}
	int ans = 0 ; 
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			if( (mp_col[j] + mp_row[i])%2==1 ) {
				ans++ ; 
				
				//cout << i << ' ' << j << endl ;
			}
		}
	}
	cout << ans ; 
}

signed main(void) {
    #define NAME ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(NAME".inp","r") ) {
        freopen(NAME".inp","r",stdin) ; freopen(NAME".out","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}