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
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}
int n , k ;
void init(void) {
	cin >> n >> k ;
}
string dp[2][1001][1001] ;  
string sum_str(string a, string b) {
	while(a.size()<b.size()) a = "0" +a;
	while(b.size()<a.size()) b = "0" +b;
	ll du=0;
	ll sum ;
	ll x,y;
	FORD(i,(int)a.size()-1,0){
		x = a[i] - '0';
		y = b[i] - '0';
		sum = x+y +du;
		a[i] = sum%10 + '0';
		du = sum/10;
	}
	if(du>0) a= "1"+a;
	return a;
}
void process(void) {
    dp[0][0][0] = "1" ; 
    string ans = "0" ;
    FOR(i,1,n) {
    	int cur = i&1 ; 
    	int prev = (i-1)&1 ;
    	FOR(t1,0,k) FOR(t2,0,k) dp[cur][t1][t2] = "0" ;
    	FOR(t1,0,k) FOR(t2,1,k) {
    		dp[cur][0][t2] = sum_str(dp[cur][0][t2],dp[prev][t1][t2-1]) ; 
    	}
    	FOR(t1,1,k) FOR(t2,0,k) {
    		dp[cur][t1][0] = sum_str(dp[cur][t1][0],dp[prev][t1-1][t2]) ; 
    	} 
    	if(i==n) {
    		FOR(t1,0,k) FOR(t2,0,k) {
    			ans = sum_str(ans,dp[cur][t1][t2]) ; 
    		}
    	}
    	FOR(t1,0,k) FOR(t2,0,k) {
    		dp[prev][t1][t2] = dp[cur][t1][t2] ; 
    	}
    }
    cout << ans; 
}
signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}