#include<bits/stdc++.h>
using namespace std ;
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
const int N = 1e5 + 5 ; 
typedef long long ll ;

int n , a[N] ; 
ll pre[N] ; 

int tknp(int l,int r) {
	int ret = -1 ; 
	int d = l , c = r ;
	while(l <= r) {
		int mid = (l+r)/2 ; 
		if( (pre[mid] - pre[d-1]) >= (pre[c] - pre[mid]) ) ret = mid , r = mid - 1 ; 
		else l = mid + 1 ; 
	}
	return ret ; 
}
int calc(int l,int r) {
	if(l==r) return 0 ; 
	if((pre[r]-pre[l-1])%2==1) return 0 ; 
	int p = tknp(l,r) ;
	//cout << l << ' ' << r << ' ' << p << endl ;
	if( (pre[p] - pre[l-1]) != (pre[r] - pre[p]) ) return 0 ; 
	int ma = 0 ; 
	//cout << l << ' ' << r << ' ' << p << endl ;
	ma = max(calc(l,p) + 1 , calc(p+1,r) + 1) ;
	return ma ; 
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ; 
	//freopen(".inp","r",stdin) ; 
	//freopen(".out","w",stdout) ;
	int t ; cin >> t ;
	while(t--) {
		cin >> n ; 
		FOR(i,1,n)cin>>a[i] ;
		FOR(i,1,n)pre[i]=pre[i-1]+a[i] ;
		cout << calc(1,n) << '\n' ; 
	}
	return 0 ; 
}