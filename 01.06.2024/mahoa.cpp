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

const int N = 3e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 109 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

string s ; 
int n ;
void init(void) {
	cin >> s ; 
	n = s.size() ; 
	s = "*" + s ;
}
namespace sub {
	int dp[N] ; 
	int f[N] ;
    void solve(void) {
    	f[0] = 1 ; 
    	rep(i,1,n) {
    		f[i] = (f[i-1] * 2)%MOD ; 
    		dp[i] =(dp[i-1]*10 + ( s[i] - '0' ) * f[i-1] + dp[i-1])%MOD ; 
    	}
    	cout << dp[n]%MOD ; 
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