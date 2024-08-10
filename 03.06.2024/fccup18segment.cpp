/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 2e5 + 5 , LO = 17 , base = 311 ;
const ll inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n ; 
ii seg[N] ;
int q ;
void init(void) {
	cin >> n ; 
	rep(i,1,n) cin >> seg[i].fi >> seg[i].se ;  
	cin >> q ;
}

namespace sub {
	ii a[N] ; 
	int far[N] ; 
	int rmq[N][LO] ; 
	int calc(int L,int R) {
		int l = 1 ; 
		int r = n ; 
		int pos = -1 ; 
		while(l <= r) {
			int mid = (l+r)>>1 ;
			if( a[mid].fi <= L ) pos = mid , l = mid + 1 ; 
			else r = mid - 1 ;
		}
		if(pos==-1) return -1 ; 
		if(a[pos].se >= R) return 1 ; 
		int ret = 1 ;
		int jump = pos ; 
		repd(k,log2(n),0) {
			int nxt = rmq[jump][k] ; 
			if(a[nxt].se < R) {
				ret += (1<<k) ; 
				jump = nxt ; 
			}
		}
		rep(k,0,log2(n)) {
			int nxt = rmq[jump][k] ; 
			if(a[nxt].se >= R) return ret + (1<<k) ;
		}
		return -1 ;
	}
    void solve(void) {
     	sort(seg+1,seg+1+n,[](ii u,ii v) {
     		if(u.fi==v.fi) return u.se < v.se ; 
     		else return u.fi < v.fi ;
     	}) ;
    	// chỉ chọn đoạn L[i] <= L[j] <= R[i] <= R[j]
    	vii last_seg ; 
    	last_seg.pb(seg[1]) ; 
    	rep(i,2,n) {
    		if(last_seg.back().se < seg[i].se) last_seg.pb(seg[i]) ; 
    	}
    	rep(i,0,(int)last_seg.size()-1) {
    		a[i+1] = last_seg[i] ; 
    	}
    	n = last_seg.size() ; 
    	int j = 1 ;
    	// gọi far[i] là điểm gần nhất kết thúc 1 đoạn khi a[i].se <= a[j].se
    	rep(i,1,n) {
    		while(j <= n and a[j].fi <= a[i].second + 1) ++j ; 
    		far[i] = j - 1 ; 
    	}
    	rep(i,1,n) rmq[i][0] = far[i] ; 
    	for(int j(1) ; (1<<j) <= n ; j++) {
    		for(int i(1) ; i <= n ; i++) {
    			rmq[i][j] = rmq[rmq[i][j-1]][j-1] ; 
    		}
    	}
    	while(q--) {
    		int l , r ; 
    		cin >> l >> r ;
    		cout << calc(l,r) << '\n' ; 
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
    sub::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}