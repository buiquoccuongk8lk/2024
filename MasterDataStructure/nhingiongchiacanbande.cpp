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

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count()) ; 
int Rand(int l,int r) {
	return l + rd()%(r-l+1) ;
}

int n, k ; 
int a[N] ;
int x[N] ;
void init(void) {
	cin >> n >> k ;
}

namespace sub {

    void solve(void) {
    	int sum = 0 ;
    	rep(i,1,k-1) {
    		x[i] = Rand(1,1e13) ; 
    		sum+= x[i] ;
    	}
    	x[k] -= sum ;
    	sum = 0 ;
    	int ans = 0 ;
    	unordered_map<int,int> mp ;
    	mp[0] = 0 ;
    	rep(i,1,n) {
    		int y ;
    		cin >> y  ;
    		y = x[y] ;
    		sum+= y ;
    		if(mp.find(sum)!=mp.end()) {
    			maximize(ans , i - mp[sum] ) ; 
    		}else {
    			mp[sum] = i ; 
    		}
    	}
    	cout << ans ; 
    }
    
}

signed main(void) {
    #define TASK ""
    srand(time(NULL)) ; 
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