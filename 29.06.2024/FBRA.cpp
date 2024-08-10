/* ---------------------- *
 *   * Code by watbor     *
 *   :>  🐧🐧             *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n' 
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)

const int N = 1e6 + 5 ;
const int MOD = 1e9 + 7 ; 

template <class X,class Y> void add(X &x , const Y &y) {
	x+=y ; 
	if(x>=MOD) x-=MOD ; 
}


int n ; 
string s ; 

void init(void) {
	cin >> s ; 
	n = s.size() ;  
	s = "*" + s ; 
}
	
ll dp[65][65][65][65] ;

ll calc(int i,int sumt,int sumv,int sumk) {
	//cout << i << ' ' << sumt << ' ' << sumv << ' ' << sumk << endl ;

	if(sumt < 0 || sumv < 0 || sumk < 0) return 0 ;

	if(i > n) return (sumt == 0 and sumv == 0 and sumk == 0) ;

	if(dp[i][sumt][sumv][sumk]!=-1) return dp[i][sumt][sumv][sumk] ;

	ll &val = dp[i][sumt][sumv][sumk] ; 
	val = 0 ; 

	if(s[i] == '(') add(val , calc(i+1,sumt + 1,sumv , sumk) ) ; 
	if(s[i] == ')') add(val , calc(i+1,sumt - 1,sumv , sumk) ) ; 

	if(s[i] == '[') add(val , calc(i+1,sumt , sumv + 1 , sumk) ) ; 
	if(s[i] == ']') add(val , calc(i+1,sumt , sumv - 1 , sumk) ) ; 

	if(s[i] == '{') add(val , calc(i+1,sumt , sumv , sumk + 1) ) ; 
	if(s[i] == '}') add(val , calc(i+1,sumt , sumv , sumk - 1) ) ; 

	if(s[i] == '?') {
		add(val , calc(i+1,sumt + 1,sumv , sumk) ) ;
		add(val , calc(i+1,sumt - 1,sumv , sumk) ) ;  
		add(val , calc(i+1,sumt , sumv + 1 , sumk) ) ; 
		add(val , calc(i+1,sumt , sumv - 1 , sumk) ) ; 
		add(val , calc(i+1,sumt , sumv , sumk + 1) ) ; 
		add(val , calc(i+1,sumt , sumv , sumk - 1) ) ; 
	}

	return val ;
}


void process(void) {
	FOR(i,0,n) FOR(j,0,n) FOR(t,0,n) FOR(k,0,n) dp[i][j][t][k] = -1 ; 
    cout << calc(1,0,0,0) ; 
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
    return (0 ^ 0) ; 
}