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

const int N = 1e5 + 5 ;
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

int n ; 
int a[N] , wa[N] , b[N] , wb[N] , c[N] , wc[N] ;

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) cin >> wa[i] ;
	FOR(i,1,n) cin >> b[i] ; 
	FOR(i,1,n) cin >> wb[i] ; 
	FOR(i,1,n) cin >> c[i] ; 
	FOR(i,1,n) cin >> wc[i] ;
}

namespace sub1 {
	const int mod1 = pow(2,21) ; 
	const int mod2 = pow(2,20) ; 
	int dd[20 * N] ; 
	int e , s ;
	void solve(void) {	
		ll ans = 0 ; 
		FOR(x,0,n) FOR(y,0,n) FOR(z,0,n) {
			ll sum = 0 ;
			bool ok = true ; 
			FOR(i,1,x) {
				if(!dd[a[i]]) {
					dd[a[i]] = 1 ; 
					sum+= wa[i] ; 
				} else {
					ok = false ; 
					break ;
				}
			}
			if(ok) {
				FOR(i,1,y) {
					if(!dd[b[i]]) {
						dd[b[i]] = 1 ; 
						sum+= wb[i] ; 
					} else {
						ok = false ; 
						break ; 
					} 
				}
			}
			if(ok) {
				FOR(i,1,z) {
					if(!dd[c[i]]) {
						dd[c[i]] = 1 ; 
						sum+= wc[i] ;
					} else {
						ok = false ; 
						break ;
					} 
				}
			}
			FOR(i,1,n) dd[a[i]] = dd[b[i]] = dd[c[i]] = 0 ;
			if(ok) ans = max(ans,sum) ;
		}
		cout << ans << '\n' ; 
		cin >> e >> s ; 
		FOR(i,1,n) { 
			wa[i] = ((((wa[i]+mod2) xor e)+s) %mod1) - mod2 ; 
			wb[i] = ((((wb[i]+mod2) xor e)+s) %mod1) - mod2 ;
			wc[i] = ((((wc[i]+mod2) xor e)+s) %mod1) - mod2 ;  
 		}
	}	
}

namespace sub2 {
	const int mod1 = pow(2,21) ; 
	const int mod2 = pow(2,20) ;	

	ll preA[5005] , preB[5005] , preC[5005] , maC[5005] ; 
	int mark[4][(int)1e6 + 5] , dd[10 * N] ; 

	void solve(void) {
		ll ans = 0 ; 

		FOR(i,1,n) {
			preA[i] = preA[i-1] + wa[i] ; 
			preB[i] = preB[i-1] + wb[i] ; 
			preC[i] = preC[i-1] + wc[i] ; 
		}

		FOR(i,1,n) maC[i] = max(maC[i-1],preC[i]) ; 

		int max_x = n , max_y = n , max_z = n ; 

		FOR(i,1,n) dd[a[i]] = 0 ; 
		FOR(i,1,n) {
			if(!dd[a[i]]) {
				dd[a[i]] = 1 ; 
			} else {
				max_x = i - 1 ; 
				break ; 
			} 
		}
		FOR(i,1,n) dd[b[i]] = 0 ;
		FOR(i,1,n) {
			if(!dd[b[i]]) {
				dd[b[i]] = 1 ; 
			} else {
				max_y = i - 1;
				break ; 
			}
		}
		FOR(i,1,n) dd[c[i]] = 0 ;
		memset(dd,0,sizeof dd) ; 
		FOR(i,1,n) {
			if(!dd[c[i]]) {
				dd[c[i]] = 1 ; 
			} else {
				max_z = i - 1 ; 
				break ; 
			}
		}
		
 		FOR(i,0,max_x) {
			int z = max_z ; 
			FOR(it,1,z) mark[3][c[it]] = 1 ; 		
			FOR(it,1,i) mark[1][a[it]] = 1 ; 
			FOR(it,1,i) {
				while(z && mark[3][a[it]]) {
					mark[3][c[z]] = 0 ; 
					z-- ; 
				}
			}
			FOR(j,0,max_y) {
				if(mark[1][b[j]]) break ; 
				mark[2][b[j]] = 1 ; 
				while(z && mark[3][b[j]]) {
					mark[3][c[z]] = 0 ; 
					z-- ; 
				}
				ans = max(ans,preA[i] + preB[j] + maC[z]) ; 
			}
			FOR(j,1,max({max_x,max_y,max_z})) mark[1][a[j]] = mark[2][b[j]] = mark[3][c[j]] = 0 ; 
		}

		cout << ans << '\n' ; 
		int e , s ;
		cin >> e >> s ; 
		FOR(i,1,n) { 
			wa[i] = ((((wa[i]+mod2) xor e)+s) %mod1) - mod2 ; 
			wb[i] = ((((wb[i]+mod2) xor e)+s) %mod1) - mod2 ;
			wc[i] = ((((wc[i]+mod2) xor e)+s) %mod1) - mod2 ;  
 		}
	}

}

namespace sub3 {

	int dd[10 * N] ; 

	void solve(void) {
		int ans = 0 ; 		

		FOR(i,1,n) {
			if(!dd[])
		}

	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    int TEST ; cin >> TEST ;
    init() ;
    while(TEST--) {
    	//sub1::solve() ;
    	//sub2::solve() ; 
    	sub3::solve() ; 
    } 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}