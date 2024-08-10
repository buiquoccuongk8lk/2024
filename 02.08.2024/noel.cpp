#include<bits/stdc++.h>
using namespace std ;
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

const int N = 1e5 + 5 ; 

int n , m ; 
int a[N] , b[N] ; 

bool check(int mid) {
	int j = 0 ; 	
	FOR(i,1,n) if(a[i] < mid) {
		while(j <= m && a[i] + b[j] < mid) j++ ; 
		if(a[i] + b[j] < mid) return 0 ; 
		if(a[i] + b[j] >= mid) j++ ; 
	}
	return 1 ; 
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ; 
	freopen(".inp","r",stdin) ; 
	freopen(".out","w",stdout) ; 
	cin >> n ;
	FOR(i,1,n)cin>>a[i] ; 
	cin >> m ; 
	FOR(i,1,m)cin>>b[i] ; 
	int l = 0 , r = 2e9 , ans = 0 ;
	while(l <= r) {
		int mid = (l+r)/2 ; 
		if(check(mid)) ans = mid , l = mid + 1 ; 
		else r = mid - 1 ;
	}
	cout << ans ; 
	return 0 ; 
}