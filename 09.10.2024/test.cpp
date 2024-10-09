// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef pair<int,int> ii ;
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
template<class T> bool maxi(T &x,T y) { if(x < y) { x = y ; return 1 ;} return 0 ;}
template<class T> bool mini(T &x,T y) { if(x > y) { x = y ; return 1 ;} return 0 ;}

const int MAXN = 1e5 + 5 ;

int n , k ;
int a[MAXN] ;
ll pre[MAXN] ;

void init() {
	cin >> n >> k ;
	FOR(i,1,n) cin >> a[i] ;
	FOR(i,1,n) pre[i] = pre[i-1] ^ a[i] ;
}

int node = 1 ;
int f[MAXN * 32] ;
int trie[MAXN * 32][3] ;

void add(int x) {
	int root = 1 ;
	FORD(i,32,0) {
		int val = (x >> i) & 1 ; 
		if(trie[root][val]==-1) trie[root][val] = ++node ;
		root = trie[root][val] ; 
		f[root]++ ; 
	}
}

int get(int x) {
	int root = 1 , ans = 0 ;
	FORD(i,32,0) {
		int bit_x = (x >> i) & 1 , bit_k = (k >> i) & 1 ; 
		if(bit_k) {
			if(trie[root][1 ^ bit_x]==-1) break ;
			root = trie[root][1 ^ bit_x] ;  
		} else {
			if(trie[root][1 ^ bit_x]!=-1) ans+= f[trie[root][1 ^ bit_x]] ;
			if(trie[root][bit_x]==-1) break ; 
			root = trie[root][bit_x] ;
		}
		if(i==0) ans+= f[root] ;
	}
	return ans ;
}

void solve() {
	memset(trie,-1,sizeof trie) ;

	ll ans = 0 ;
	FOR(i,1,n) {
		ans+= get(a[i]) ;
		add(a[i]) ;
	}
	cout << n * (n - 1) / 2 - ans ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */