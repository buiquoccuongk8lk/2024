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

const int MAXN = 2e5 + 5 ;

int n ;
int a[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ;
}

int deCompress[MAXN] , VAL ;

void Compress() {
	vi V ;
	FOR(i,1,n) V.pb(a[i]) ;
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ;
	FOR(i,1,n) {
		int p = lower_bound(all(V),a[i]) - V.begin() + 1 ; 
		deCompress[p] = a[i] ; 
		a[i] = p ;
	}
	VAL = V.size() ;
}

int bit[MAXN] ;

void up(int u,int val) {
	for(int i(u) ; i <= VAL ; i+=i&-i) bit[i]+= val ; 
}

int get(int u) {
	int sum = 0 ; 
	for(int i(u) ; i ; i-=i&-i) sum+= bit[i] ; 
	return sum ;
}

void solve() {
	Compress() ;
	FOR(i,1,n) up(a[i],1) ;
	FOR(i,1,n) {
		up(a[i],-1) ;
		int l = 1 , r = VAL , p = -1 ; 
		while(l <= r) {
			int mid = (l+r)/2 ; 
			if(get(mid) >= ( (n) / 2) ) p = mid , r = mid - 1 ; 
			else l = mid + 1 ;
		}
		cout << deCompress[p] << ' ' ;
		up(a[i],1) ;
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