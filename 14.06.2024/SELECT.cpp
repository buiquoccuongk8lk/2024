/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
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

const int N = 2e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m , q ;
ii edge[N] ;
int a[N] ,del_flag[N] ;
ll f[N] , L[N] ;
multiset<ll> ms ; 
ll ans[N] ;
vi dq[N] ;// nhan cua dinh u sau truy van loai C 
// f[i] < 0 ; f[i] = sum dinh cay goc i
// f[i] > 0 : fi la to tien cua i tren duong di ve goc
struct Queries {
	char ch ; 
	int x1 ;
	int x2 ; 
}Q[N] ; 
void init(void) {
	cin >> n >> m >> q ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) dq[i].pb(a[i]) ; 
	FOR(i,1,m) {
		cin >> edge[i].fi >> edge[i].se ;
	}
	FOR(i,1,q) {
		char ch ; 
		cin >> ch ;
		if(ch=='D') {
			int id ;
			cin >>id ; 
			del_flag[id] = 1 ; 
			Q[i] = {ch , id, 0} ;
		}else{
			int u,val ;
			cin>> u >> val ;
			Q[i] = {ch , u , val} ; 
			dq[u].pb(val) ;
		}
	}
}

ll goc(ll x){
	while(f[x]>0){
		x = f[x];
	}
	return x;
}
void joint(int r1,int r2) {
	ll t = f[r1] + f[r2] ; 
	ll sum = L[r1] + L[r2] ; 
	ms.erase(ms.find(L[r1])) ;
	ms.erase(ms.find(L[r2])) ; 
	ms.insert(sum) ; 
	if(abs(f[r1]) > abs(f[r2])) {
		f[r1] = t ;
		f[r2] = r1 ; 
		L[r1] = sum ; 
	}else {
		f[r2] = t ; 
		f[r1] = r2 ; 
		L[r2] = sum ; 
	}
}

void process(void) {
	FOR(i,1,n) {
		f[i] = -1 ; 
		L[i] = dq[i].back() ; 
		ms.insert(L[i]) ; 
	}
	FOR(i,1,m) {
		if(del_flag[i]==0) {
			int r1 = goc(edge[i].fi) ;
			int r2 = goc(edge[i].se) ; 
			if(r1!=r2) {
				joint(r1,r2) ; 
			}
		}
	}
	ans[q] = *ms.rbegin() ;
	FORD(i,q,2) {
		if(Q[i].ch=='D') {
			int j = Q[i].x1 ; 
			int r1 = goc(edge[j].fi) ;
			int r2 = goc(edge[j].se) ;
			if(r1!=r2) {
				joint(r1,r2) ; 
			}
			ans[i-1] = *ms.rbegin() ; 
		}else {
			int u = Q[i].x1 ; 
			ll r = goc(u) ; 
			int value = dq[u].back();
			dq[u].pop_back() ;
			ms.erase(ms.find(L[r])) ; 
			L[r] = L[r] - value + dq[u].back() ; 
			ms.insert(L[r]) ; 
			ans[i-1] = *ms.rbegin() ;
		}	
	}
	FOR(i,1,q){
		cout << ans[i] << endl ;
	}
}

signed main(void) {
    #define TASK "SELECT"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}