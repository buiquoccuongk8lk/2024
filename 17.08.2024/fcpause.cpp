#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()

#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 1e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n ; 
int a[MAXN] , q[MAXN] , par[MAXN] , sum[MAXN] ; 
int ans ;
int dd[MAXN] ; 
int res[MAXN] ;

int acs(int u) {
	if(u==par[u]) return u ; 
	else return par[u] = acs(par[u]) ; 
}

void join(int u,int v) {
	int x = acs(u) , y = acs(v) ; 
	if(x!=y) {
		par[y] = x ; 
		sum[x]+= sum[y] ; 
		maxi(ans,sum[x]) ; 
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ;
    FOR(i,1,n) cin >> q[i] ; 
   	FOR(i,1,n) par[i] = i , sum[i] = a[i] ; 
   	FORD(i,n,1) {
   		res[i] = ans ;
  		maxi(ans,sum[q[i]]) ; 
   		if(dd[q[i]-1]) join(q[i],q[i]-1) ; 
   		if(dd[q[i]+1]) join(q[i],q[i]+1) ; 
   		dd[q[i]] = 1 ; 
   	}
   	FOR(i,1,n) cout << res[i] << endl ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}