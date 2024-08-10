/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n' 
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define REP(i,n) for(int i(0) ; i < n ; i++) 
#define all(a) a.begin(),a.end() 
#define __builtin_popcount __builtin_popcountll

template<class X,class Y> bool maximize(X &x,const Y &y) {
    if(x < y) {
        x = y ; 
        return 1 ; 
    } else return 0 ; 
}

template<class X,class Y> bool minimize(X &x ,const Y &y) {
    if(x > y) {
        x = y ;
        return 1 ; 
    } else return 0 ;
}

const int N = 1e5 + 5 ;
const ll inf = 1e18 ;
const int MOD = 1e9 + 7 ; 

int n , m ;
string s , t ;
ll fact[N] , inv_fact[N] ; 
int pre[35][35] ;
ll dp[N][35] ; 

struct BG { 
	int x ;
	ll val ; 
} a[N] , b[N] ; 

void init(void) {
    cin >> n >> m ; 
    cin >> s ; 
    cin >> t ; 
}

ll LT(int x,int y) {
	if(y==0) return 1 ; 
	if(y==1) return x ; 
	ll c = LT(x,y/2) ; 
	if(y&1) return 1LL * c * c %MOD * x %MOD ; 
	else return 1LL * c * c %MOD ; 
}

void build_fact(void) {
	fact[0] = 1 ; 	
	FOR(i,1,1e5) {
		fact[i] = (fact[i-1] * i)%MOD ; 
	}
	inv_fact[(int)1e5] = LT(fact[(int)1e5],MOD-2) ; 
	FOR(i,0,1e5-1) {
		inv_fact[i] = LT(fact[i],MOD-2) ; 
	}
	FORD(i,1e5-1,0) {
		inv_fact[i] = 1LL * inv_fact[i+1] * (i+1)%MOD ; 
	}
}

int C(int n,int k) {
	return 1LL * fact[n] * inv_fact[n-k] % MOD * inv_fact[k]%MOD ; 
}

void process(void) {

	n = 0 ;
	m = 0 ;

	REP(i,(int)s.size()) {
		if(s[i] >= 'a' and s[i] <= 'z') {
			a[++n].x = s[i] - 'a' + 1 ; 
		} else {
			a[n].val = a[n].val * 10 + (s[i] - '0') ; 
			a[n].val%=MOD ; 
		}
	}

	REP(i,(int)t.size()) {
		m++ ; 
		b[m].x = t[i] - 'a' + 1 ; 
		b[m].val = 1 ; 
	}

	build_fact() ; 	

	FOR(i,1,m) {
		FOR(j,1,27) {
			pre[i][j] = pre[i-1][j] +  (b[i].x == j) ; 
		}
	}

	//cout << 'i' - 'a' + 1 ; 
	//cout << pre[1][9] - pre[0][9] ; 

	dp[0][0] = 1 ; 
	FOR(i,0,n-1) FOR(j,0,m) if(dp[i][j] > 0) {
		FOR(t,0,m) {
			if(j + t > m) continue ; 
			if(pre[j+t][a[i+1].x] - pre[j][a[i+1].x] < t ) continue ; 
			dp[i+1][j+t]+= dp[i][j] * C(a[i+1].val,t)%MOD ;
			dp[i+1][j+t]%=MOD ;  	
		}
	}

	cout << dp[n][m] ; 
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
    return 0 ; 
}