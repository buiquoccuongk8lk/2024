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
   	int ans = 0 ; 
   	FOR(mask,0,(1<<n)-1) {
   		vector<int> ones ; 
   		FOR(j,0,n-1) if((mask>>j)&1) ones.pb(j+1) ; 
   		ll sum = 0 ;
   		for(auto x : ones) sum+=a[x] ; 
   		int sl = __builtin_popcountll(mask) ; 
   		for(auto x : ones) {
   			if(sl*a[x] == sum) ans = max(ans,sl) ; 
   		}
   	}
   	cout << ans ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
