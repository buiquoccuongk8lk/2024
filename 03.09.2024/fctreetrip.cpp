// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
typedef pair<int,ll> pil ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 2e5 + 5 ;

int n ;
ll A , B ;
vector<pil> g[MAXN] ;

void init() {
	cin >> n >> A >> B ; 
	FOR(i,1,n-1) {
		int u , v , w ; cin >> u >> v >> w ; 
		g[u].pb(pil(v,w)) ; g[v].pb(pil(u,w)) ;
	}
}

ll dp[MAXN][3] ;

/*
	Ta có nhận xét về cách đi trên đồ thị cũng như là cách giải
	ta sẽ tô màu đỏ cho những cạnh di chuyển bình thường
	còn những cạnh còn lại thì dịch chuyển

	Và đặc biệt 1 đỉnh chỉ cớ nhiều nhất 2 cạnh đc tô màu đỏ nối với nó
	vì > 2 sẽ không tồn tại cách di chuyển thỏa đề bài

	Khi đó ta chuyển bài toán về dạng tìm tập P sao cho

	wNot * A (những cạnh thuộc P) + B * số cách không thuộc P
	DP ON TREE 
*/
	
void dfs(int u,int par) {
	int nc = 0 ; 
	pair<ll,ll> best = {1e18,1e18} ;
	ll totalCost = 0 ; 

	for(auto x : g[u]) {
		int v = x.fi ; ll w = x.se ;
		if(v==par) continue ; 
		nc++ ; 
		dfs(v,u) ;

		ll delta = dp[v][1] + A * w - B - min(dp[v][1],dp[v][0]) ;

		if(delta < best.fi) {
			best.se = best.fi ; 
			best.fi = delta ; 
		} else if(delta < best.se) best.se = delta ;

		totalCost+= min(dp[v][0],dp[v][1]) + B ;
	}
	dp[u][1] = min(totalCost,totalCost + best.fi) ;
	if(nc > 1) dp[u][0] = totalCost + best.fi + best.se ;
	else dp[u][0] = 1e18 ;
}

void solve() {
	if(n==2) {
		ll w1 = 0; 
		for(auto x : g[1]) {
			w1 = x.se ; 
		}
		cout << 2 * min(w1 * A, B) ;
	} else {
		dfs(1,-1) ;
		cout << min(dp[1][1],dp[1][0]) + B ;
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */