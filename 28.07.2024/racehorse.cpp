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

const int N = 1e5 + 5 ;
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

int n , m , k ; 
int a[N] ;
int win[N] ; 
vi v ;

void init(void) {
	cin >> n >> m >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) v.pb(a[i]) ; 
	uni(v) ; 
}

bool check(int mid) {

	priority_queue<int,vector<int>> pq ; 

	FOR(i,1,n) win[i] = 0 ;
	FOR(i,1,n) win[a[i]]++ ;

	//for(auto x : v) cout << x << ' ' ; 

	for(auto x : v) {
		if(x <= m && win[x] >= mid) {
			pq.push({win[x] - mid}) ; 
		} 
		if(x > m) {
			pq.push({win[x]}) ; 
		}
	}	

	int cnt = 0 ; 
	vi vec ; 

	FOR(i,1,m) {
		if(i <= m && win[i] < mid) {
			vec.pb(i) ; 
		}
	}

	sort(all(vec),[](int u,int v) {
		return win[u] < win[v] ; 
	}) ;

	for(auto x : vec) {
		while(!pq.empty()) {
			if(win[x] >= mid) break ; 
			int ma = pq.top();			
			pq.pop() ; 
			if(ma >= mid - win[x]) {
				cnt+= mid - win[x] ;
				pq.push({ ma - (mid - win[x])}) ; 
				win[x] = mid ;
			} else if(ma < mid - win[x]) {
				win[x] += ma ; 
				cnt+= ma ; 
			}
		}
	}	

	for(auto x : vec) if(win[x] < mid) return 0 ;

	return (cnt <= k) ;
}	

void solve(void) {
	int lim = 1e5 ;
	FOR(i,1,n) win[a[i]]++  ;
	FOR(i,1,m) lim = min(lim,win[i]) ; 
	int l = 1 ; 
	int r = min((int)1e5 , lim + k) ; 
	int ans = 0 ; 
	while(l <= r) {
		int mid = (l+r)>>1 ; 
		if(check(mid)) {
			ans = mid , l = mid + 1 ;
		}
		else r = mid - 1 ; 
	}
	cout << ans << '\n' ; 
	v.clear() ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    int T ; cin >> T ;
    while(T--) {
    	init() ; solve() ;
    }
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}