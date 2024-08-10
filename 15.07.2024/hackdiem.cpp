#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;

int n ; 
int a[maxn] ;

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	priority_queue<int,vector<int>,greater<int>>pq ;
	int ans = 0 ; 
	int sum = 0 ; 
	FOR(i,1,n) sum+=a[i] ;
	if((double)sum/n >= 4.5) cout << 0 ;
	else {
		FOR(i,1,n) pq.push(a[i]) ; 
		FOR(i,1,n) {
			sum = sum - pq.top() + 5 ; 
			pq.pop() ; 
			//cout << sum << endl
			ans++ ; 
			if((double)sum/n >= 4.5) {
				cout << ans ; 
				return 0 ;
			}
		}
	} 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}