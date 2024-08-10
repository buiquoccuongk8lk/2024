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
int n , k ; 
string s[N] ; 
void init(void) {
	cin >> n >> k ;
	rep(i,1,n) {
		cin >> s[i] ; 
	}
}

namespace sub {
	int pairs[N], fact[N] , dp[2005][2005] ; 
	int ans = 0 ;
	int sz = 0 ;
	int LT(int x,int y) {
		if(y==0) return 1 ;
		if(y==1) return x ; 
		int c = LT(x,y/2) ;
		if(y&1) return c*c%MOD * x%MOD ;
		else return (c*c)%MOD ; 
	}
	int mul(int a,int b){
		return (a*b)%MOD ; 
	}
	int C(int N,int K) {
		return mul( fact[N] , LT(mul(fact[K],fact[N-K]),MOD-2) ) ; 
	}
	void add(int &x,const int &y) {
		x+=y ; 
		x%=MOD ;
	}
    void solve(void) {
    	fact[0] = 1 ; 
    	rep(i,1,1e6) fact[i] = (fact[i-1] * i)%MOD ; 
    	rep(i,1,n) sort(s[i].begin(),s[i].end()) ; 
    	unordered_map<string,int>mp ; 
    	rep(i,1,n) {
    		mp[s[i]]++ ; 
    	}
    	for(auto x : mp) {
    		pairs[++sz] = x.se  ; 
    	} 
    	dp[0][0] = 1 ; 
    	rep(i,1,sz) {
    		add(dp[i][0],dp[i-1][0]) ;
    		add(dp[i][0],pairs[i] * dp[i-1][0]) ;
    	}    	 
    	rep(i,1,sz) {
    		rep(j,1,k) {
    			rep(t,0,pairs[i]) {
    				if(j >= t*(t-1)/2) add(dp[i][j] , (C(pairs[i],t) * dp[i-1][j - t*(t-1)/2]) %MOD ) ; 
    			}
    		}
    	}
    	cout << dp[sz][k] ; 
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