/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 2e3 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}
int n ; 
vi G[N] ;
ii a[N] ;

void init(void) {
	cin >> n ; 
	rep(i,1,n) cin >> a[i].fi ; 
	rep(i,1,n) cin >> a[i].se ; 
	rep(i,1,n) {
		rep(j,1,n) {
			if(i!=j and a[i].fi > a[j].fi and a[i].se < a[j].se) {
				G[i].pb(j) ;
			}
		}
	}
}

namespace sub1 {
	int ans[N] ; 
	void dfs(int st,int en,int cnt,int u,int par) {
		if(u==en) {
			ans[cnt]++ ;
			ans[cnt]%=MOD ;
			return ; 
		}
		for(auto v : G[u]) {
			if(v==par) continue ; 
			dfs(st,en,cnt+1,v,u) ;
		}
	}
    void solve(void) {
   		rep(i,1,n) {
   			rep(j,1,n) {
   				dfs(i,j,1,i,i) ;
   			}
   		}
   		rep(i,1,n) cout << ans[i] << ' ';
   	}
}
namespace sub2 {
	int ans[N] ;
	int dp[2005][2005] ; 
	void solve(void) {
		sort(a+1,a+1+n,[](ii u,ii v) {
			if(u.fi==v.fi) return u.se > v.se ; 
			else return u.fi > v.fi ; 
		}) ;
		rep(i,1,n) {
			dp[i][1] = 1 ;
			rep(j,2,n) {
				rep(k,1,i-1) {
					if(a[k].se < a[i].se) {
						dp[i][j] += dp[k][j-1] ;
						dp[i][j]%=MOD ;
					}
				}
			}
		}	
		rep(i,1,n) {
			rep(j,0,n) {
				ans[j]+=dp[i][j] ; 
				ans[j]%=MOD ;
			}
		}
		rep(i,1,n) cout << ans[i] << ' ';
	}
}
namespace sub3 {
	int st[4*2002][2002] ; 
	int ans[N] ; 
	int dp[2005][2005] ;
	void update(int id,int l,int r,int pos,int val,int j) {
		if(pos < l or pos > r ) return ; 
		if(l==r) {
			st[id][j] += val ;
			st[id][j]%=MOD ;
			return ;
		}
		int mid = (l+r)>>1 ;
		update(id<<1,l,mid,pos,val,j) ;
		update(id<<1|1,mid+1,r,pos,val,j) ; 
		st[id][j] = (st[id<<1][j] + st[id<<1|1][j])%MOD ;
	}
	int get(int id,int l,int r,int u,int v,int j) {
		if(l > v or r < u) return 0 ; 
		if(l >= u and r <= v) return st[id][j] ; 
		int mid = (l+r)>>1 ; 
		return ( get(id<<1,l,mid,u,v,j) + get(id<<1|1,mid+1,r,u,v,j) )%MOD ;
	}
	void solve(void) {
		sort(a+1,a+1+n,[](ii u,ii v) {
			if(u.fi==v.fi) return u.se < v.se ; 
			else return u.fi < v.fi ; 
		}) ;
		vi v ; 
		unordered_map<int,int> mp ;
		rep(i,1,n) v.pb(a[i].se) ; 
		sort(v.begin(),v.end()) ; 
		v.resize(unique(v.begin(),v.end()) - v.begin()) ; 
		rep(i,0,(int)v.size()-1) mp[v[i]] = i + 1 ;
		int VAL = v.size() ; 
		rep(i,1,n) {
			dp[i][1] = 1 ; 
			update(1,1,VAL,mp[a[i].se],1,1) ; 
			rep(j,2,n) {
				dp[i][j] = get(1,1,VAL,mp[a[i].se]+1,VAL,j-1) ; 
				update(1,1,VAL,mp[a[i].se],dp[i][j],j) ; 
			}
		}
		rep(i,1,n) {
			rep(j,0,i) {
				ans[j]+=dp[i][j] ; 
				ans[j]%=MOD ;
			}
		}
		rep(i,1,n) cout << ans[i] << ' ';
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
    if(n <= 50) sub1::solve() ;
    else if(n <= 500) sub2::solve() ;
    else sub3::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}