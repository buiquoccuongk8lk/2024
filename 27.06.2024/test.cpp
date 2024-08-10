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

const int N = 1e5 + 5 ;
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

int n ;
ii a[N] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ; 
}
struct bg {
	int id ; 
	int t ; 
	bool operator < (const bg &x) const {
		return t > x.t ; 
	}
} ; 
priority_queue<bg,vector<bg>> pq ;
vii vec_start[N] ; 
int ans[N] ; 
int fi[N] ;

void process(void) {
	vi vec ; 
	FOR(i,1,n) {
		vec.pb(a[i].fi) ; 
	}	
	uni(vec) ; 
	FOR(i,1,n) {
		int pos = lower_bound(all(vec),a[i].fi) - vec.begin() + 1 ; 
		fi[pos] = a[i].fi ;
		a[i].fi = lower_bound(all(vec),a[i].fi) - vec.begin() + 1 ; 
		vec_start[a[i].fi].push_back({i , a[i].se}) ; 
	}
	int sz = sz(vec) ;
	FOR(i,1,sz) {
		ll pre = vec[i-1] ; 
		while(!pq.empty()) {
			int id = pq.top().id ; 
			int t = pq.top().t ; 
			pq.pop() ; 
			if(pre + t <= vec[i]) {
				pre+=t ; 
				ans[id] = pre ; 
			} else {
				pq.push({id , t - (vec[i] - pre) } ) ;  
				break ; 
			}
		}
		for(auto x : vec_start[i]) pq.push({x.fi , x.se}) ; 
	}	
	ll res = 0 ; 
	FOR(i,1,n) res+= ans[i] - fi[a[i].fi] ; 
	cout << res ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}