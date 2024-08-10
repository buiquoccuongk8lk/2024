/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
#define int long long
const int MAX = 2e5 + 5 ;
int n , m ;
int a[MAX] , b[MAX] ;

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
	cin >> n >> m ; 
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for(int i = 1 ; i <= m ; i++) cin >> b[i] ; 
	int s = 0 ;
	sort(a+1,a+1+n) ;
	for(int i = 1 ; i <= n ; i++) s = __gcd(s,a[i]-a[1]) ; 
	for(int i = 1 ; i <= m ; i++) cout << __gcd(s,a[1]+b[i]) << ' ' ;
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}