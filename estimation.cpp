/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 2e3 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , k ;
int a[N] , val[N] ; 
int VAL ; 
ll cost[N][N] ;
ll dp[N][30] ;

void init(void) {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}

struct {
	int bit[N] ; 
	void up(int u,int val) {
		for(int i = u ; i <= VAL ; i+=i&-i) bit[i]+=val ; 
	}
	int get(int u) {
		int ret = 0 ; 
		for(int i = u ; i ; i-=i&-i) ret+= bit[i] ; 
			return ret ; 
	}
	int get(int l,int r) {
		return get(r) - get(l-1) ; 
	}
	int search(int v) {
		int sum = 0;
		int pos = 0;
		int p = __lg(VAL) ; 
		for(int i = p ; i>=0; i--) {
			if(pos + (1 << i) < VAL and sum + bit[pos + (1 << i)] < v) {
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1; 
	}
} bitSL ; 

struct {
	int bit[N] ; 
	void up(int u,int val) {
		for(int i = u ; i <= VAL ; i+=i&-i) bit[i]+=val ; 
	}
	int get(int u) {
		int ret = 0 ; 
		for(int i = u ; i ; i-=i&-i) ret+= bit[i] ; 
			return ret ; 
	}
	int get(int l,int r) {
		return get(r) - get(l-1) ; 
	}
} bitSUM ; 

void nen(void) {
	vi v ; 
	FOR(i,1,n) v.pb(a[i]) ; 
	uni(v) ; 
	FOR(i,1,n) {
		int p = lower_bound(all(v),a[i]) - v.begin() + 1 ; 
		val[p] = a[i] ; 
		a[i] = p ;
	}
	VAL = v.size() ; 
}

void solve(void) {
	nen() ; 
	FOR(i,1,n) {
		FOR(j,i,n) {
			bitSL.up(a[j],1) ; 
			bitSUM.up(a[j],val[a[j]]) ; 
			int p = bitSL.search( (j - i + 2) / 2) ;
			int val_cur = val[p] ; 
			cost[i][j] = 1ll * bitSL.get(p) * val_cur - 1ll *bitSUM.get(p) ; 
			cost[i][j] += 1ll * bitSUM.get(p+1,VAL) - 1ll * val_cur * bitSL.get(p+1,VAL) ; 
		}
		FOR(j,i,n) {
			bitSL.up(a[j],-1) ; 
			bitSUM.up(a[j],-val[a[j]]) ; 
		}
	}
	memset(dp,0x3f,sizeof(dp)) ;
	dp[0][0] = 0 ;
	FOR(i,1,n) FOR(j,1,k) {
		FOR(v,1,i) {
			minimize(dp[i][j],dp[v-1][j-1] + cost[v][i]) ; 
		}
	}
 	cout << dp[n][k] ;
 }

signed main(void) {
    #define TASK "estimation"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}