/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}
int n,m,k,q ; 
int a[1005][1005] ; 
map<int,vii> Q ; 
long long dp[N] ;
unordered_map<int,int> ans ;
void input(void) {	
	cin >> n >> m >> q >> k ; 
	for(int i(1) ; i <= n ; i++) for(int j(1) ; j <= m ; j++) cin >> a[i][j] ;
}
int st[4*N];
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return;
	if(l==r) {
		st[id] = val ;
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = max(st[id<<1],st[id<<1|1]);
}
long long get(int id,int l,int r,int u,int v) {
	if( l > v or r < u ) return -inf;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return max(t1,t2);
}
void solve(void) {

	for(int i(1) ; i <= n ; i++) {
		for(int j(1) ; j <= m ; j++) {
			Q[a[i][j]%k].pb({i,j}) ; 
		}
	}

	for(auto x : Q) {
		int module = x.fi ; 
		vector<pair<int,int>>  v ; 
		for(auto p : x.second) {
			update(1,1,m,p.se,get(1,1,m,1,p.se)+1) ;
		}
		ans[module] = st[1] ; 
		for(int i(1) ; i <= 4*m ; i++) st[i] = 0 ;
	}

	while(q--){
		int x ;
		cin >> x ;
		cout << ans[x] << '\n' ; 
	}
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
   	input() ; solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}