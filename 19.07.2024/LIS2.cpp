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

const int N = 2e5 + 5 ;
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

int n , d ; 
int a[N] ; 

void init(void) {
	cin >> n >> d ; 
	FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {
	int dp[N] ;
	int b[N] ;
	void solve(void) {	
		int ans = 0 ; 	
		FOR(l,1,n) {
			FOR(j,1,l-1) b[j] = a[j] ;
			FOR(j,l,n) b[j] = a[j] + d ; 
			FOR(i,1,n) dp[i] = 0 ;
			FOR(i,1,n) {
				dp[i] = 1 ; 
				FOR(j,1,i-1) {
					if(b[i] > b[j]) dp[i] = max(dp[i],dp[j] + 1) ; 
				}
			}
			ans = max(ans,*max_element(dp+1,dp+1+n)) ; 
		}
		cout << ans ; 
	}
}

namespace sub2 {
	struct {
		int st[4*N] ; 
		void update(int pos,int val) {
			int i = 1 , l = 0 , r = n ; 
			while(l < r) {
				int mid = (l+r)>>1 ; 
				if(pos <= mid) r = mid , i = i << 1 ; 
				else l = mid + 1 , i = i << 1 | 1 ; 
			}

			st[i] = max(st[i],val) ; 
			while(i) {
				i = i >> 1 ; 
				st[i] = max(st[i<<1],st[i<<1|1]) ; 
			}
		}
		int get(int id,int l,int r,int u,int v) {
			if(l > v || r < u) return 0 ; 
			if(l >= u && r <= v) return st[id] ; 
			int mid = (l+r)>>1 ; 
			return max(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v)) ; 
		}
	} IT ; 
	int dp[N] ; 
	void solve(void) {
		vi v ; 
		FOR(i,1,n) v.pb(a[i]) ; 
		uni(v) ; 
		FOR(i,1,n) a[i] = lower_bound(all(v),a[i]) - v.begin() + 1 ; 

		FOR(i,1,n) {
			dp[i] = 1 ; 
			dp[i] = max(dp[i] , IT.get(1,1,n,1,a[i]-1) + 1) ; 
			IT.update(a[i],dp[i]) ; 
		}
		cout << *max_element(dp+1,dp+1+n) ; 
 	}
}

namespace sub3 {

	int dp[N] ;
	
	void solve(void) {

	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    if(n <= 1e3) sub1::solve() ; 
    else if(d==0) sub2::solve() ;
    else sub3::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}