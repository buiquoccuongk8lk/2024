/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 2e5 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}

int n , q ; 
ii a[N] , b[N] ; 
int f[N] , rmq[N][19] , m ; 
void init(void) { 
	cin >> n ;
	rep(i,1,n) cin >> b[i].fi >> b[i].se ; 
	cin >> q ; 
}
int tknp(int x) { 
	int d = 1 ; 
	int c = n ;
	int pos = -1 ; 
	while(d <= c) { 
		int mid = (d+c) >> 1 ; 
		if(a[mid].fi <= x) {
			pos = mid ; 
			d = mid + 1 ; 
		}else c = mid - 1 ; 
	}
	return pos ; 
}

int calc(int l,int r) {
	int ans = 1 ; 

	int u = tknp(l) ; 

	if(u==-1) return u ; 
	if(a[u].second >= r) return 1 ; 

	repd(k,log2(n),0) {
		int nxt_index = rmq[u][k] ; 
		if(a[nxt_index].se < r) {
			u = nxt_index ; 
			ans+= (1<<k) ;
		}
	}

	rep(k,0,log2(n)) {
		int nxt_index = rmq[u][k] ; 
		if(a[nxt_index].se >= r) return ans + (1<<k) ;
	}

	return -1 ;
}

void process(void) {
	sort(b+1,b+1+n,[](ii u,ii v){
		if(u.fi==v.fi) return u.se < v.se ; 
		else return u.fi < v.fi ;
	}) ;

	vii good_seg ; 

	good_seg.pb(b[1]) ; 

	rep(i,2,n) {
		if(b[i].second > good_seg.back().second) {
			good_seg.push_back(b[i]) ; 
		}
	}

	
	n = good_seg.size()  ; 

	rep(i,0,n-1) {
		a[i+1] = good_seg[i] ; 
	}
	// ok 

	int j = 1 ; 
	rep(i,1,n) { 
		while(j <= n and a[j].fi <= a[i].second + 1) { 
			++j ;
		}
		f[i] = j - 1 ; 
	}

	rep(i,1,n) {
		rmq[i][0] = f[i] ; 
	}
	int MASK = log2(n) ; 
	for(int j(1) ; j <= MASK ; j++) {
		for(int i(1) ; i  <= n ; i++) {
			rmq[i][j] = rmq[rmq[i][j-1]][j-1] ; 
		}
	}
	while(q--) {
		int l , r ; 
		cin >> l >> r ; 
		cout << calc(l,r) << '\n' ; 
	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; process() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}