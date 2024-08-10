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
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

string s , t ; 
int n , m , k ;
void init(void) {
	cin >> n >> m >> k ; 
	cin >> s ;
	cin >> t ; 
	s = "*" + s ;
	t = "*" + t ;
}

namespace sub {
	long long hashS[N] , hashT[N] , pw[N] ; 
	void build_HASH(void) {
		pw[0] = 1 ;
		rep(i,1,1e6) pw[i] = (pw[i-1] * base)%MOD ; 
		rep(i,1,n) {
			hashS[i] = (hashS[i-1] * base + s[i] - 'a' + 1)%MOD ;
		}
		rep(i,1,m) {
			hashT[i] = (hashT[i-1] * base + t[i] - 'a' + 1)%MOD ; 
		}
	}
	int get_hash(int i,int j,long long hash[]) {
		return (hash[j] - hash[i-1]*pw[j-i+1] + MOD*MOD)%MOD ;
	}
	bool Check(int mid) {
		unordered_map<long long,int> mp ; 
		rep(i,1,m - mid + 1) {
			mp[get_hash(i,i+mid-1,hashT)]++ ;
		}
		rep(i,1,n-mid+1) {
			if(mp[get_hash(i,i+mid-1,hashS)]>=k) return 1; 
		}
		return 0 ;
	}
    void solve(void) {
    	build_HASH() ;
    	int l = 0 ; 
    	int r = n ; 
    	int ans = -1 ; 
    	while(l <= r) {
    		int mid = (l+r)>>1 ; 
    		if(Check(mid)) {
    			ans = mid ; 
    			l = mid + 1 ; 
    		}else r = mid - 1 ;
    	}
    	string ans_str = "" ;
    	bool ok = 0 ; 
    	unordered_map<long long,int>mp ; 
    	rep(i,1,m-ans+1) {
    		mp[get_hash(i,i+ans-1,hashT)]++ ;
    	}
    	rep(i,1,n-ans+1) {
    		if( mp[get_hash(i,i+ans-1,hashS)] >= k ) {
    			if(!ok) {
    				string tmp = "" ;
    				rep(j,i,i+ans-1) tmp.pb(s[j]) ;
    				ans_str = tmp ; 
    				ok = 1 ; 
    			}else {
    				string tmp = "" ;
    				rep(j,i,i+ans-1) tmp.pb(s[j]) ;
    				ans_str = min(ans_str,tmp) ;
    			}
    		}
    	}
    	cout << ans_str ;
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