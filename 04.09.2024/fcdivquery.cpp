#include<bits/stdc++.h>
using namespace std ;

const int MAXN = 3e5 + 5 , oo = 2e9 ;
const long long inf = 1e18 , mod = 1e9 + 7 ;
const int MAXVAL = 1e7 ;

int n , q , sqrtN , MAXV , l , r ;
int a[MAXN] ;
int prime[2 * MAXVAL + 5] , cnt[2 * MAXVAL + 5] ;
struct Queries {
	int L , R , id ; 
} Q[MAXN] ;
int ans[MAXN] ;

void init() {
	cin >> n >> q ; 
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 
	for(int i = 1 ; i <= n ; i++) cin >> Q[i].L >> Q[i].R , Q[i].id = i ; 
}

void Sieve() {
	for(int i = 1 ; i <= n ; i++) MAXV = max(MAXV,abs(a[i])) ; 
	for(int i = 2 ; i <= MAXV ; i++) prime[i] = i ;
	for(int i = 2 ; i * i <= MAXV ; i++) {
		for(int j = i * i ; j <= MAXV ; j+=i) if(prime[j]==j) prime[j] = i ;
	}
	int cur , res , cnt , p ;
	for(int i = 1 ; i <= n ; i++) { 
		if(a[i] == 0) continue ;	
		cur = abs(a[i]) , res = 1 ;
		while(cur > 1) {
			p = prime[cur] , cnt = 0 ; 
			while(cur % p == 0) {
				cur/= p ; 
				cnt++ ; 
			}
			if(cnt & 1) res*= p ;
		}
		a[i] = (a[i] < 0 ? - res : res) ;
	}
	for(int i = 1 ; i <= n ; i++) a[i]+= MAXV ;
}

int res ;

void MO(int id) {
	while(l < Q[id].L) {
		cnt[a[l]]-- ; 
		if(cnt[a[l]]==0 && a[l]!=MAXV) res-- ; 
		l++ ; 
	}
	while(l > Q[id].L) {
		l-- ;
		cnt[a[l]]++ ; 
		if(cnt[a[l]]==1 && a[l]!=MAXV) res++ ; 
	}
	while(r < Q[id].R) {
		r++ ; 
		cnt[a[r]]++ ; 
		if(cnt[a[r]]==1 && a[r]!=MAXV) res++ ; 
	}
	while(r > Q[id].R) {
		cnt[a[r]]-- ;
		if(cnt[a[r]]==0 && a[r]!=MAXV) res-- ; 
		r-- ;
	}
	ans[Q[id].id] = max(res,(int)(cnt[MAXV] > 0)) ;
}

void solve() {
	Sieve() ;
	sqrtN = sqrt(n) ;
	sort(Q+1,Q+1+q,[](Queries u,Queries v) {
		if(u.L/sqrtN == v.L/sqrtN) return u.R < v.R ; 
		else return u.L/sqrtN < v.L/sqrtN ;
	}) ; 
	l = 1 , r = 0 ;
	for(int i = 1 ; i <= q ; i++) MO(i) ; 
	for(int i = 1 ; i <= q ; i++) cout << ans[i] << '\n' ; 
}

signed main() {
	#define task ""
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	if(fopen(task".inp","r")) {
		freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
	}
	init() ; 
	solve() ;
	cerr << "\nTIME : " << clock() * 0.001 << "s" << endl ;
	return 0 ;
}