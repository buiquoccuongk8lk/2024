/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define int long long
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

const int N = 1e6 + 5 ;
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

int n ;
int a[N] , L[N] , R[N] , ans[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

struct {
	int bit[N] ; 
	void reset(void) {
		FOR(i,1,n) bit[i] = 0 ; 
	}
	void up(int u,int val) {
		for(int i = u ; i <= n ; i+=i&-i) bit[i]+=val ; 
	}
	int get(int u) {
		int sum = 0 ;
		for(int i = u ; i ; i-=i&-i) sum+= bit[i] ; 
		return sum ; 
	}
	int get(int l,int r) {
		return get(r) - get(l-1) ; 
	}
} BIT ; 

void pre_calc(void) {
	FOR(i,1,n) {
		L[i] = BIT.get(a[i],n) ;
		BIT.up(a[i],1) ;  
	}
	BIT.reset() ; 
	FORD(i,n,1) {
		R[i] = BIT.get(a[i],n) ; 
		BIT.up(a[i],1) ; 
	}
}

void solve(void) {
	pre_calc() ;
	ll sum = 0 ; 
	FOR(i,1,n) sum+= R[i] ; 
	int k = 1 ;
	vector<int> zip ; 
	FOR(i,1,n) if(a[i]!=n) zip.pb(L[i]-R[i]) ; 
	sort(all(zip)) ;
	ans[1] = sum ; 
	for(auto x : zip) {
		ans[++k] = sum + x ; 
		sum+=x ; 
	}
	FOR(i,1,n) cout << ans[i] << ' ' ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}