#include<bits/stdc++.h>
using namespace std ;
#define int long long

const int MAXN = 1e6 + 10005 ;
const int mod = 1e9 + 7 ;

int prime[MAXN+5] ;
int sumT[MAXN+5] , sum[MAXN+5] , stt[MAXN+5] ; 

signed main() {
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	//freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 	
	for(int i = 2 ; i <= MAXN ; i++) prime[i] = 1 ;
	for(int i = 2 ; i * i <= MAXN ; i++) {
		for(int j = i * i ; j <= MAXN ; j+=i) prime[j] = 0 ;
	}	
	for(int i = 2 ; i <= MAXN ; i++) {
		stt[i] = ( stt[i-1] + prime[i] ) % mod ;
		sumT[i] = ( sumT[i-1] + prime[i] * (i * stt[i]) %mod ) % mod ;
		sum[i] = (sum[i-1] + prime[i] * i%mod)%mod ;
	} 
	vector<int> V ; 
	for(int i = 2 ; i <= MAXN ; i++) if(prime[i]) V.push_back(i) ; 
	int test ; cin >> test ; 
	while(test--) {
		int l , r ; cin >> l >> r ;
		if(l > r) swap(l,r) ;
		int pos = lower_bound(V.begin(),V.end(),l) - V.begin() ; 
		l = V[pos] ; 
		int ans = sumT[r] - sumT[l-1] ;
		if(ans < 0) ans+= mod ;
		ans+= - stt[l] * (sum[r] - sum[l-1])%mod ;
		if(ans < 0) ans+= mod ;
		ans+= sum[r] - sum[l-1] ;
		if(ans < 0) ans+= mod ;
		while(ans <= 0) ans+= mod ;
		cout << ans % mod << '\n' ;
	}
	cerr << endl << "TIME : " << clock() * 0.001 << "s " << endl ;
	return 0 ;
}