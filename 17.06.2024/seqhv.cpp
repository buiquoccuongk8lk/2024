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

const int N = 1e6 + 5 ;
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
int a[N] ;

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {

 	ll dp[505][10005] ;

	void solve(void) {
	
		int max_val = *max_element(a+1,a+1+n) ; 

		FOR(i,1,n) {
			FOR(j,0,max_val) dp[i][j] = inf ; 
		}

		dp[0][0] = 0 ; 

		FOR(j,0,max_val) dp[1][j] = abs(a[1] - j) ;

		FOR(i,2,n) {
			FOR(j,0,max_val) {
				FOR(k,j,max_val) minimize(dp[i][k],dp[i-1][j] + abs(a[i] - k) ) ;
			}
		}
		ll ans = inf ; 
		FOR(j,0,max_val) minimize(ans,dp[n][j]) ; 
		cout << ans ;
	}

}

namespace sub2 {

	ll dp[1005][10005] ; 

	struct seg {
			int n ; 
			vector<ll> st ; 
		private:
			void up(int id,int l,int r,int u,int v,ll val) {
				if(l>v or r<u) return ;
				if(l >= u and r <= v) {
					st[id] = (r-l+1)*val ; 
					return ;
				}
				int mid = (l+r)>>1 ;
				up(id<<1,l,mid,u,v,val) ; up(id<<1|1,mid+1,r,u,v,val) ; 
				st[id] = min( st[id<<1] , st[id<<1|1] ); 
			}
			ll get(int id,int l,int r,int u,int v) {
				if(l>v or r<u) return inf ; 
				if(l >= u and r <= v) return st[id] ; 
				int mid = (l+r)>>1 ; 
				return min( get(id<<1,l,mid,u,v) , get(id<<1|1,mid+1,r,u,v) ) ; 
			}
		public:
			seg(int n) : n(n) { st.assign(4*n+1,0) ; }
			void up(int l,int r,ll val) { up(1,1,n,l,r,val) ; }
			ll get(int l,int r) {return get(1,1,n,l,r) ; }  
	} ; 


	void solve(void) {

		int max_val = *max_element(a+1,a+1+n) ; 

		seg st(max_val) ;

		FOR(i,1,n) {
			FOR(j,0,max_val) dp[i][j] = inf ; 
		}

		dp[0][0] = 0 ; 

		FOR(j,0,max_val) {
			dp[1][j] = abs(a[1] - j) ;
			st.up(j,j,dp[1][j]) ;
		}

		FOR(i,2,n) {
			FOR(k,0,max_val) {
				minimize(dp[i][k] , st.get(0,k) + abs(a[i] - k) ) ; 
			}
			FOR(k,0,max_val) {
				st.up(k,k,dp[i][k]) ;
			}
		}

		ll ans = inf ; 
		FOR(j,0,max_val) minimize(ans,dp[n][j]) ; 
		cout << ans ;

	}

}

namespace sub3 {

	ll dp[3][10005] , mini[3][10005] ; 

	void solve(void) {

		int max_val = *max_element(a+1,a+1+n) ; 

		FOR(i,0,1) {
			FOR(j,0,max_val) dp[i][j] = inf ; 
		}

		dp[0][0] = 0 ; 

		FOR(j,0,max_val) {
			dp[1&1][j] = abs(a[1] - j) ;
			if(j==0) {
				mini[1&1][j] = dp[1&1][j] ; 
			}else mini[1&1][j] = min(dp[1&1][j],mini[1&1][j-1]) ; 
		}

		FOR(i,2,n) {
			int cur = i&1 ;
			int prev = (i-1)&1 ; 
			FOR(k,0,max_val) dp[cur][k] = inf ;
			FOR(k,0,max_val) {
				minimize(dp[cur][k],mini[prev][k] + abs(a[i] - k) ) ; 
			}
			FOR(k,0,max_val) dp[prev][k] = dp[cur][k] ; 
			FOR(k,0,max_val) {
				if(k==0) mini[cur][k] = dp[cur][k] ;
				else mini[cur][k] = min(dp[cur][k],mini[cur][k-1]) ; 
			}
		}

		ll ans = inf ;
		FOR(j,0,max_val) minimize(ans,dp[n&1][j]) ; 
		cout << ans ;

	}

}

namespace sub4 {

	void solve(void) {

		ll ans = 0 ;
		priority_queue<int,vi>pq ;
		FOR(i,1,n) {
			pq.push(a[i]) ; 
			ans+= pq.top() - a[i] ; 
			pq.pop() ; 
			pq.push(a[i]) ; 
		}
		cout << ans ;

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
    if(n <= 500 ) sub1::solve() ; 
    else if( n <= 1000 ) sub2::solve() ;
    else if(n <= 2000) sub3::solve() ;
    else sub4::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}