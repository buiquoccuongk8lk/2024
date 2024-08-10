/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

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
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 50 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ; 
string s[N] ; 
int diff[N][N] ; 
bool ok[N][N] ;
int dp[N][N] , dd[N][N] ;

void init(void) {
	cin >> n ; 
	m = 3 ; 
	FOR(i,1,n) cin >> s[i] , s[i] = "*" + s[i] ; 
}

void pre_calc(void) {
	FOR(i,1,n) FOR(j,1,n) {
		int npc = 0 ; 
		FOR(t1,1,3) FOR(t2,1,3) if(s[i][t1]==s[j][t2]) npc++ ; 
		diff[i][j] = npc ; 
	}
}

int calc(int l,int r) {
	if(l > r) return 0 ; 
	if(dd[l][r]) return dp[l][r] ; 
	dd[l][r] = 1 ;

	FOR(k,l+1,r-1) {
		dp[l][r] = max(dp[l][r] , calc(l,k) + calc(k,r) ) ; 
		if(ok[l][k] && ok[k][r] && diff[l][r] >= 2) {
			dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + 1) ; 
			ok[l][r] = 1 ; 
		}
	} 
	
	return dp[l][r] ; 
}

void solve(void) {
	pre_calc() ;

	FOR(i,1,n) dp[i][i] = 0 ; 
	FOR(i,1,n) ok[i][i+1] = 1 ; 

	FOR(i,1,n) {
		if(diff[i][i+2] >= 2) {
			dp[i][i+2] = 1 ;
			ok[i][i+2] = 1 ; 
		}
	} 	

	cout << calc(1,n); 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}