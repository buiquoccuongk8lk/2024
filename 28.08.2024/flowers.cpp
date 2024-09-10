// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1e6 + 5 ;

int T , mod ; 
int n[MAXN] , k[MAXN] , m[MAXN] ; 

namespace subtask_12 {

	bool check() {
		FOR(i,1,T) if(n[i] > 1e6) return 0 ; 
		return (mod == 998244353) ; 
	}

	int fact[MAXN] , inv_fact[MAXN] ;

	int LT(int x,int y) {
		if(y==0) return 1 ; 
		if(y==1) return x ; 
		int c = LT(x,y/2) ; 
		if(y&1) return 1ll * c * c % mod * x % mod ; 
		else return 1ll * c * c % mod ; 
	}

	int C(int n,int k) {
		if(k > n) return 0 ; 
		return 1ll * fact[n] * inv_fact[n-k] % mod * inv_fact[k] % mod ; 
	}

	void solve() {	
		int mxn = 0 ;
		FOR(i,1,T) maxi(mxn,n[i]) ; 
		fact[0] = 1 ; 
		FOR(i,1,mxn) fact[i] = 1ll * (fact[i-1] * i) % mod ; 
		inv_fact[mxn] = LT(fact[mxn],mod-2) % mod ; 	
		FORD(i,mxn-1,0) inv_fact[i] = 1ll * inv_fact[i+1] * (i+1) % mod ; 
		FOR(i,1,T) cout << 1ll * C(n[i]-1,k[i]) * LT(m[i]-1,k[i]) % mod * m[i] % mod << '\n' ;  
	}
}

namespace subtask_4 {
	bool check() {
		return mod == 220797 ; 
	}

	int prime[MAXN + 5] , primeID[MAXN + 5] , exp[MAXN + 5] ;
	int VAL , mxn ;

	void Sieve() {
		FOR(i,2,MAXN) prime[i] = i ; 
		FOR(i,2,sqrt(MAXN)) {
			for(int j=i*i;j<=MAXN;j+=i) if(prime[j]==j)prime[j] = i ; 
		}
		FOR(i,2,MAXN) if(prime[i]==i) {
			primeID[i] = ++VAL ; 
		}
	}

	void capnhat(int x,int d) {
		while(x!=1) {
			int tmp = prime[x] ; 
			if(x%tmp==0) {
				exp[tmp]+= d ; 
				x/=tmp ; 
			}
		}
	}

	int LT(int x,int y) {
		if(y==0) return 1 ; 
		if(y==1) return x ; 
		int c = LT(x,y/2) ; 
		if(y&1) return 1ll * c * c % mod * x % mod ; 
		else return 1ll * c * c % mod ; 
	}

	int C(int n,int k) {
		FOR(i,1,MAXN) exp[i] = 0 ;  
		int ret = 1 ; 
		FOR(i,1,k) {
			capnhat(i,-1) ; 
			capnhat(n-i+1,1) ; 
		}
		FOR(i,2,MAXN) if(prime[i]==i && exp[i] > 0) 
			ret = 1ll * ret * LT(i,exp[i]) % mod ; 
		return ret ; 
	}

	void solve() {
		FOR(i,1,T) maxi(mxn,n[i]) ; 
		Sieve() ; 	
		FOR(i,1,T) cout << 1ll * C(n[i]-1,k[i]) * LT(m[i]-1,k[i]) % mod * m[i] % mod << '\n' ; 
	}
}

namespace subtask_3 {

	int LT(int x,int y) {
		if(y==0) return 1 ; 
		if(y==1) return x ; 
		int c = LT(x,y/2) ; 
		if(y&1) return 1ll * c * c % mod * x % mod ; 
		else return 1ll * c * c % mod ; 
	}

	int inv_fact[MAXN + 5] , fact[MAXN + 5] ;

	int C(int n,int k) {
		int ret = 1 ; 
		FOR(i,1,k) {
			ret = 1ll *  ret * (n - i + 1) % mod ; 
		}
		ret = 1ll * ret * inv_fact[k] % mod ;
		return ret ; 
	}

	void solve() {
		int mxn = 0 ;
		FOR(i,1,T) maxi(mxn,k[i]) ; 
		fact[0] = 1 ; 
		FOR(i,1,mxn) fact[i] = 1ll * (fact[i-1] * i) % mod ; 
		inv_fact[mxn] = LT(fact[mxn],mod-2) % mod ; 	
		FORD(i,mxn-1,0) inv_fact[i] = 1ll * inv_fact[i+1] * (i+1) % mod ; 
		FOR(i,1,T) cout << 1ll * C(n[i]-1,k[i]) * LT(m[i]-1,k[i]) % mod * m[i] % mod << '\n' ; 
	}
}

signed main() {
    #define task "flowers"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> T >> mod ;
    FOR(i,1,T) cin >> n[i] >> m[i] >> k[i] ;
    if(subtask_12::check()) subtask_12::solve() ;
    else if(subtask_4::check()) subtask_4::solve() ; 
    else subtask_3::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */