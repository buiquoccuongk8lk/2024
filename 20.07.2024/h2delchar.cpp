/// никогда не сдавайся

#include <bits/stdc++.h>
using namespace std ; 
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int N = 3e2 + 5 ;
const int oo = 2e9 ; 

string s ; 
int n ; 
int dp[N][N] , dd[N][N] ;

void init(void) {
	cin >> s ; 
	n = s.size() ; 
	s = "*" + s ; 
}

bool CheckSame(int i,int j) {
	if(s[i]=='(') return s[j] == ')' ; 
	else if(s[i]=='[') return s[j] == ']' ; 
	else if(s[i]=='{') return s[j] == '}' ; 
	return 0 ; 
 }

int calc(int i,int j) {	

	if(i > j) return 0 ; 

	if(i + 1 == j) if(CheckSame(i,j)) return 0 ; 

	if(dd[i][j]) return dp[i][j] ; 

	dd[i][j] = 1 ;

	if(CheckSame(i,j)) dp[i][j] = min( dp[i][j] , calc(i+1,j-1) ) ; 

	FOR(k,i,j-1) {
		dp[i][j] = min( dp[i][j] , calc(i,k) + calc(k+1,j) ) ; 	
	}

	return dp[i][j] ; 
}

void solve(void) {
	
	FOR(i,1,n) FOR(j,1,n) dp[i][j] = oo ;

	FOR(i,1,n) dp[i][i] = 1 ; 

	FOR(i,1,n) if(CheckSame(i,i+1)) dp[i][i+1] = 0 ; 

	FOR(i,1,n) FOR(j,1,n) if(j < i) dp[i][j] = 0 ; 

	cout << calc(1,n) ; 
}

signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}