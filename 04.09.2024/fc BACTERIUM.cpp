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

int n ; 
pair<ll,ll> a[MAXN] ;
vi idB[MAXN] ; 
ll deCompress[MAXN] ;
int VAL ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ;
	FOR(i,1,n) idB[a[i].se].pb(i) ;
}

void Compress() {
	vi V ; 
	FOR(i,1,n) V.pb(a[i].fi) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ;
	FOR(i,1,n) {
		int p = lower_bound(all(V),a[i].fi) - V.begin() + 1 ; 
		deCompress[p] = a[i].fi ; 
		a[i].fi = p ;
	}
	VAL = V.size() ;
}

ll bit[MAXN] ;
int sl[MAXN] ;

void up(int u,ll val) {
	for(int i(u) ; i <= n ; i+=i&-i) bit[i]+= val , sl[i]++ ;
}

pair<ll,int> get(int u) {
	ll sum = 0 , sum1 = 0 ;
	for(int i(u) ; i ; i-=i&-i) sum+= bit[i] , sum1+= sl[i] ;
	return {sum , sum1} ;
}

namespace subtask_1 {

	void solve() {
		sort(a+1,a+1+n,[](ii u,ii v) {
			return u.se > v.se ; 
		}) ; 
		int ans = 0 ; 
		FOR(i,1,n) FOR(j,i,n) {
			int sum = 0 , cnt = 0 ;  
			vi V ;
			FOR(v,i,j) V.pb(a[v].fi) ;
			sort(all(V)) ; 
			for(auto x : V) {
				sum+=x ; 
				cnt++ ; 
				if(a[j].se * cnt >= sum) maxi(ans,cnt) ;
			}
		}		
		cout << ans ;
	}
}

namespace subtask_2 {
	vi V ;
	void solve() {
		Compress() ;
		FOR(i,1,n) V.pb(a[i].se) ; 
		sort(all(V)) ; 
		V.resize(unique(all(V))-V.begin()) ;
		reverse(all(V)) ; 
		int ans = 0 ; 
		int lim = 2e9 ;
		FOR(i,0,V.size()-1) {
			int b = V[i] ;
			for(auto id : idB[b]) {
				up(a[id].fi,deCompress[a[id].fi]) ; 
				lim = min(lim,a[id].fi) ;
			}
			int l = lim , r = n , p = -1 ; 
			while(l <= r) {
				int mid = (l+r)/2 ; 
				pair<ll,int> cur = get(mid) ; 
				ll sum = cur.fi ;
				int sl = cur.se ; 
				if(b * sl >= sum) p = sl , l = mid + 1 ; 
				else r = mid - 1 ; 
			}
			maxi(ans,p) ; 
		}
		cout << ans ;
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    subtask_2::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */