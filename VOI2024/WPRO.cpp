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

const int N = 1e4 + 5 ;
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

int n , L1 , L2 , C , D ;
int a[N] ;

namespace sub1 {

	bool check() {return L1==L2 ;}

	void solve(void) {
		int L = L1 ;
		vector<int> cur ; 
		long long ans = 0 ;
		while(1) {
			int i = n ;
			for(int j = 1 ; j <= n ; j++) {
				if(a[j]!=L) {
					i = j ; 
					break ; 
				}
			}
			if(i==n && a[i]==L) {
				break ; 
			}
			if(a[i] > L) {
				n++ ; 
				for(int j = n ; j >= i + 2 ; j--) a[j] = a[j-1] ; 
				a[i+1] = a[i] - L ; a[i] = L ; 
				ans+= C ;
			} else if(a[i] < L) {
				a[i]+= a[i+1] ; 
				for(int j = i + 1 ; j <= n ; j++) a[j] = a[j+1] ; 
				n-- ;
				ans+= D ; 
			}
		}
		cout << ans ; 
	}

}

namespace sub3 {
	bool check() {
		ll S = 0 ;
		FOR(i,1,n) S+= a[i] ;
		return S <= 3e7 ;  
	}
	int dp[(int)3e7 + 5] ;
	int best[(int)3e7 + 5] ; 
	void solve(void) {
		ll S = 0 ; 
		FOR(i,1,n) S+= a[i] ; 
		FOR(i,0,S) best[i] = oo ; 
		best[0] = 0 ; 
		FOR (i,min(L1,L2),S) {
			if (i >= L1) minimize(best[i],best[i-L1] + 1) ; 
			if (i >= L2) minimize(best[i],best[i-L2] + 1) ; 
		}
		FOR(i,1,n) dp[i] = oo ;
		dp[0] = 0 ;
		FOR (i,1,n) {
			int sum = 0 ; 
			FORD (j,i,1) {
				sum+= a[j] ; 
				if(best[sum] != oo) {
					minimize(dp[i], dp[j-1] + (i-j)*D + (best[sum] - 1) * C) ; 
				}
			}
		}
		cout << dp[n] ;
	}
}

namespace sub4 {

	void solve(void) {
		
	}

}

signed main(void) {
    #define TASK "WPRO"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n >> L1 >> L2 >> C >> D ; 
    FOR(i,1,n) cin >> a[i] ; 
    /*if(sub1::check()) sub1::solve() ;
    else if(sub3::check()) sub3::solve() ;  
    else*/ sub4::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}