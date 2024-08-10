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

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const ll inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n ; 
string s ; 

void init(void) {
	cin >> s ; 
	n = s.size() ; 
	s = "*" + s ; 
	s[1] = '(' ; 
	s[n] = ')' ; 
	//cout << s ;
}

namespace sub1 {
	int ans = 0 ;
	char a[N] ;  
	void backtrack(int pos) {
		if(pos > n) {
			int sum = 0 ;
			rep(i,1,n) {
				sum+= ( a[i] == '(' ? 1 : -1 ) ;
				if(sum < 0) return ;
			}
			//rep(i,1,n) cout << a[i] ; 
			//cout << endl ;
			if(sum==0) ans++ ;
			return ; 
		}else {
			if(s[pos]!='?') {
				a[pos] = s[pos] ; 
				backtrack(pos+1) ; 
			}else {
				rep(j,0,1) {
					a[pos] = (j==0?'(':')') ;
					backtrack(pos+1) ;
				}
			}
		}
	}
    void solve(void) {
    	backtrack(1) ;
    	cout << ans ;
    }
}
namespace sub2 {
	string sum_str(string a, string b) {
	    while(a.size()<b.size()) a = "0" +a;
		while(b.size()<a.size()) b = "0" +b;
	    ll du=0;
	    ll sum ;
	    ll x,y;
	    repd(i,(int)a.size()-1,0){
	    	x = a[i] - '0';
	    	y = b[i] - '0';
	    	sum = x+y +du;
	    	a[i] = sum%10 + '0';
	    	du = sum/10;
		}
	    if(du>0) a= "1"+a;
	    return a;
	}
	string dp[205][205] ;	
	string calc(int pos,int sum) {
		if(sum < 0) return "0" ; 
		if(pos > n) return (sum==0 ? "1" : "0") ; 
		if(dp[pos][sum]!="-1") return dp[pos][sum] ; 
		string &ret = dp[pos][sum] ; 
		ret = "0" ; 
		if(s[pos]=='?') {
			ret = sum_str(ret , calc(pos+1,sum+1) ) ; 
			ret = sum_str(ret , calc(pos+1,sum-1) ) ; 
		}
		else if(s[pos]==')') ret = sum_str(ret , calc(pos+1,sum-1) ) ; 
		else ret = sum_str(ret , calc(pos+1,sum+1) ) ;
		return ret ;
	}
	void solve(void) {
		rep(i,0,n) rep(j,0,n) dp[i][j] = "-1" ;
		cout << calc(1,0) ; 
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
    if(n <= 28) sub1::solve() ;
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}