/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5 ;
const long long inf = 1e18 ;
const int MOD = 1e9 + 7 ;

string s ; 
int n ; 

void init(void) {
   	cin >> s ; 
   	n = s.size() ; 
   	s = "*" + s ; 
}

namespace sub {
	
	long long dp[505][505] ; 

	int check(int i,int j) {
		if(s[i] == '?' and s[j] == '?') return 3 ; 
		else if(s[j] == '?') return (s[i]=='(' or s[i] == '{' or s[i] == '[') ; 
		else if(s[i] == '?') return (s[j]==')' or s[j] == '}' or s[j] == ']')  ; 
		else if(s[i] == '(' and s[j] == ')') return 1 ; 
		else if(s[i] == '{' and s[j] == '}') return 1 ; 
		else if(s[i] == '[' and s[j] == ']') return 1 ; 
		return 0 ; 
	}

	long long calc(int i,int j) {
		if(i > j) return 1 ; 

		if( ( j - i + 1) % 2 == 1 ) return 0 ; 

		if(i + 1 == j) return check(i,j) ;

		if(dp[i][j]!=-1) return dp[i][j] ; 

		long long &val = dp[i][j] ; 

		val = check(i,j) * calc(i+1,j-1)%MOD ; 

		for(int k = i + 1 ; k <= j - 1 ; k+=2 ) {
			if(check(i,k)) val = (val + check(i,k) * calc(i+1,k-1) * calc(k+1,j)%MOD )%MOD ; 
		}

		return val ; 
	}

	void solve(void) {
		for(int i(1) ; i <= n + 1 ; i++) for(int j(1) ; j <= n  ; j++) dp[i][j] = -1 ; 
		cout << calc(1,n) ; 
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
    return 0 ; 
}