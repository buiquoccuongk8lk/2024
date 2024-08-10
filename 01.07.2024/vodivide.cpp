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

const int N = 5e3 + 5 ;
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

struct bg {
	int val ; 
	int id ; 
	bool operator < (const bg &x) const {
		return val < x.val ; 
	}
}a[N] , b[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].val , a[i].id = i ;  
	FOR(i,1,n) cin >> b[i].val , b[i].id = i ;
}

namespace sub1 {

	void solve(void) {

		sort(a+1,a+1+n) ; 
		sort(b+1,b+1+n) ; 

		ll ans = 0 ;

		FORD(i,n,n/2) {
			ans+= a[i].val ;  
		}

		cout << ans << endl ; 
		FORD(i,n,n/2) {
			cout << a[i].id << ' ' << b[i].id << endl ; 
		}

	}

}

namespace sub2 {

	ll dp[(int)1<<20 + 2] ; 

	void solve(void) {
		//memset(dp,-0x3f,sizeof(dp)) ; 

		dp[0] = 0 ; 

		FOR(mask,0,(1<<n)-1) {
			if(__builtin_popcountll(mask)%2==1) continue ;
			vector<int> ones ; 
			FOR(j,0,n-1) {
				if( (mask >> j ) & 1 ) ones.pb(j) ; 
			}
			for(auto u : ones) {
				for(auto v : ones) {
					if(u!=v) {
						int prev_mask = mask ^ ( 1 << u ) ; 
						prev_mask = prev_mask ^ ( 1 << v ) ;
						if(a[u + 1].val > a[v + 1].val) {
							maximize(dp[mask] , dp[prev_mask] + b[v + 1].val ) ; 
						} else {
							maximize(dp[mask] , dp[prev_mask] + b[u + 1].val ) ; 
						}
					}
				}
			}
		}

		ll ans = 0  ;

		FOR(mask,0,(1<<n)-1) {
			if(__builtin_popcountll(mask) % 2 == 0 ) maximize(ans,dp[mask]) ; 
		}

		cout << ans; 

	}

}

namespace sub3 {

	ll L[N] , R[N] ;
	bool mark[N] ;

	struct DL {
		int Vinh , Son , id ; 
	} val[N] ;

	struct cmp {
		bool operator() ( bg u , bg v ) {
			return u.val > v.val ; 
		}
	} ; 

	void solve(void) {

		FOR(i,1,n) {
			val[i].Vinh = a[i].val ; 
			val[i].Son = b[i].val ; 
			val[i].id = i ; 
		}

		sort(val+1,val+1+n,[](DL u,DL v) {
			return u.Vinh > v.Vinh ; 
		}) ; 

	
		ll ans = 0 ;	 

		priority_queue<bg,vector<bg>,cmp>pq ; 

		FOR(i,2,2) {
			pq.push({val[i].Son , val[i].id}) ; 
		}

		FOR(i,3,n) {
			pq.push({val[i].Son , val[i].id}) ; 
			if(i%2==1) {
				pq.pop() ; 
			}
		}

		while(!pq.empty()) {
			ans+= pq.top().val ;
			int j =  pq.top().id ; 
			pq.pop() ; 
			mark[j] = 1 ; 
		}

		cout << ans << endl ;

		int m = 0 ;
		int v = 0 ;

		FOR(i,1,n) {
			if(mark[val[i].id]) {
				m++ ; 
				L[m] = val[i].id ; 
			} else {
				v++ ; 
				R[v] = val[i].id ; 
			}
		}

		FOR(i,1,n/2) {
			cout << L[i] << " " << R[i] << endl ;
		}

	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
   	//sub1::solve() ; 
   	//sub2::solve() ;
   	sub3::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}