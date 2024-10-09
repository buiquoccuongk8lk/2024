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

const int N = 4e5 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , q ; 
int a[N] ; 
struct Queries {
	int L ; 
	int R ; 
	int T ;
	int id ; 
}Q[N] ; 
void init(void) {
	cin >> n >> q ; 
	rep(i,1,n) cin >> a[i] ;
	rep(i,1,q) {
		cin >> Q[i].L >> Q[i].R >> Q[i].T ; 
		Q[i].id = i ; 
	}
}	

namespace sub {
	int cntblock[N] , sumblock[N] ;
	const int B = 330  ; 
	int cnt[B + 2][B + 2] , sum[B + 2][B + 2 ] ; 
	int ans[N] ;
	int S , sz_val , l , r ; 

	void add(int x) {
		cntblock[x/sz_val] ++ ; 
		cnt[x/sz_val][x%sz_val] ++ ;
		sum[x/sz_val][x%sz_val] += x ; 
		sumblock[x/sz_val] += x ; 
	}

	void del(int x) {
		cntblock[x/sz_val]-- ; 
		cnt[x/sz_val][x%sz_val] -- ;
		sum[x/sz_val][x%sz_val] -= x ; 
		sumblock[x/sz_val] -= x ; 
	}

	void MO(int id) {
		while(l > Q[id].L) {
			l-- ;
			add(a[l]) ;
		}
		while(l < Q[id].L) {
			del(a[l]) ;
			l++ ; 
		}
		while(r > Q[id].R) {
			del(a[r]) ; 
			r-- ; 
		}
		while(r < Q[id].R) {
			r++ ;
			add(a[r]) ; 
		}
		int C = 0 ; 
		//cout << Q[id].id << endl ;
		int value = Q[id].T ; 
		rep(j,0,sz_val)
    		if (sumblock[j] <= value) value -= sumblock[j], C += cntblock[j];
    		else {
    			rep(k,0,sz_val-1) {
    				int pos = sz_val*j+k;
    				if (cnt[j][k] >= 1) {
    					int y = min(cnt[j][k],value/pos);
    					C += y;
    					value -= y*pos;
    				}
    			}
    			break;
    		}
		ans[Q[id].id] = C ; 
	}

    void solve(void) {
    	S = sqrt(n) ; 
    	sort(Q+1,Q+1+q,[](Queries u,Queries v) {
    		if(u.L/S==v.L/S) return u.R < v.R ; 
    		else return u.L < v.L ; 
    	}) ;
    	sz_val = B ;
    	l = 1 ;
    	r = 0 ;
    	rep(i,1,q) {
    		MO(i) ; 
    	}
    	rep(i,1,q) {
    		cout << ans[i] << '\n' ; 
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