// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
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

const int MAXN = 1e5 + 5 ;

int n , q ;
int a[MAXN] ; 
int prime[MAXN + 5] ;
vi pr ;
vi VAL[MAXN] , pos[MAXN] , ind[MAXN] ;

void init() {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void Sieve() {
	FOR(i,2,MAXN) prime[i] = i ;
	FOR(i,2,sqrt(MAXN)) {
		for(int j = i * i ; j <= MAXN ; j+=i) if(prime[j] == j) prime[j] = i ;
	}
	FOR(i,2,MAXN) if(prime[i]==i) {
		VAL[i].pb(-1) ;
		pr.pb(i) ; 
		pos[i].pb(-1) ; 
	}
}

vi FactX(int x) {
	vi ans ; 
	while(x > 1) {
		int p = prime[x] ; 
		while(x % p == 0) {
			x/= p ;
		}
		ans.pb(p) ; 
	}
	return ans ; 
}

vi st[MAXN] ; 

void build(int id,int l,int r,int t) {
	if(l==r) {
		st[t][id] = VAL[t][l] ; 
		return ; 
	}
	int mid = (l+r)/2 ; 
	build(id<<1,l,mid,t) ; 
	build(id<<1|1,mid+1,r,t) ; 
	st[t][id] = max(st[t][id<<1],st[t][id<<1|1]) ; 
}

int get(int id,int l,int r,int u,int v,int t) {
	if(l > v || r < u) return -1 ; 
	if(l >= u && r <= v) return st[t][id] ; 
	int mid = (l+r)/2 ; 
	return max(get(id<<1,l,mid,u,v,t),get(id<<1|1,mid+1,r,u,v,t)) ;
}

void solve() {
	Sieve() ; 
	FOR(i,1,n) {
		vi cur = FactX(a[i]) ; 
		ind[a[i]].pb(i) ;
		for(auto x : cur) {
			pos[x].pb(i) ; 
			VAL[x].pb(a[i]) ; 
		}			
	}	
	for(auto x : pr) {	
		if(x > 1e5) continue ;
		int sz = VAL[x].size() - 1 ; 
		if(sz == 0) continue ;
		st[x].resize(4 * sz + 2) ;
		build(1,1,sz,x) ;
	}
	while(q--) {
		int l , r , x ;
		cin >> x >> l >> r ; 
		vi cur = FactX(x) ;
		int num = -1 , cnt = -1 ;
		FOR(i,0,cur.size()-1) {
			int val = cur[i] ; 
			int L = lower_bound(all(pos[val]),l) - pos[val].begin() ;
			int R = upper_bound(all(pos[val]),r) - pos[val].begin() - 1 ; 
			int sz = VAL[val].size() - 1 ;
			int res = get(1,1,sz,L,R,val) ; 
			if(res > num) {
				num = res ;
				int u = lower_bound(all(ind[res]),l) - ind[res].begin() ;
				int v = upper_bound(all(ind[res]),r) - ind[res].begin() - 1 ;
				cnt = v - u + 1 ; 
			}
		}
		if(num == -1) cout << num << ' ' << num << '\n' ; 
		else cout << num << ' ' << cnt << '\n' ;
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */