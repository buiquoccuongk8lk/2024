/*[продолжатьипродолжать]*/
/* ---------------------- *
 *   * Code by watbor     *
 *                        *
--------------------------*/

#include <bits/stdc++.h>
using namespace std ; 

#define myClass class WORK,class HARD
#define tct template<myClass>
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
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ; 
struct DL {
	int x , sl ;
	bool operator <(const DL &e) const {
		return x < e.x ; 
	}
} a[N] ; 
ll dp[N] ; 

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,n) cin >> a[i].x >> a[i].sl ;
}

namespace sub1 {
	void solve(void) {
		int max_val = 0 ; 
		FOR(i,1,n) maximize(max_val,a[i].x) ; 

		FOR(i,1,n) a[i].x = max_val - a[i].x ; 
		
		sort(a+1,a+1+n) ;

		FOR(i,1,n) dp[i] = inf ;	
			
		FOR(i,1,n) {
			ll sum = m ; 
			FOR(j,1,n) {
				if(a[j].x <= a[i].x) sum+= abs(a[j].x - a[i].x) * a[j].sl  ;
				else sum+= abs(max_val - a[j].x) * a[j].sl ; 
			}	
			dp[i] = sum ;
			FOR(j,1,i-1) {
				sum = 0 ; 
				FOR(v,j+1,n) if(a[v].x > a[j].x) sum-= ( abs(max_val - a[v].x) * a[v].sl ) ;
				FOR(v,i+1,n) if(a[v].x > a[i].x) sum+= abs(max_val - a[v].x) * a[v].sl ; 	 
				FOR(v,j,i) if(a[v].x > a[j].x) sum+= abs(a[i].x - a[v].x) * a[v].sl ; 
				dp[i] = min(dp[i] , dp[j] + m + sum) ; 
			}	
		} 

		cout << *min_element(dp+1,dp+1+n) ; 
	}
}

namespace sub2 {
	ll pre[N] ;
	ll cost[1005][1005] ; 
	int X[N] ;
	void solve(void) {
		int max_val = 0 ; 
		FOR(i,1,n) maximize(max_val,a[i].x) ;
		FOR(i,1,n) a[i].x = max_val - a[i].x ;
		sort(a+1,a+1+n) ;
		FOR(i,1,n) X[i] = a[i].x ; 

		FOR(i,1,n) pre[i] = pre[i-1] + (max_val - a[i].x) * a[i].sl ;		

		FOR(i,1,n) {		
			FORD(j,i-1,1) {
				cost[j][i] = cost[j+1][i] + abs(a[j].x - a[i].x) * a[j].sl ;
			}
		}	

		FOR(i,1,n) dp[i] = inf ;
		int cur = 1 ; 	
			
		FOR(i,1,n) {
			int v = upper_bound(X+1,X+1+n,a[i].x) - X ;
			dp[i] = m + cost[1][i] + pre[n] - pre[v-1] ; 

			FOR(j,1,i-1) {
				ll sum = 0 ; 
				v = upper_bound(X+1,X+1+n,a[j].x) - X ; 
				sum-= (pre[n] - pre[v-1]) ; 
				v = upper_bound(X+1,X+1+n,a[i].x) - X ; 
				sum+= (pre[n] - pre[v-1]) ; 
				v = upper_bound(X+1,X+1+n,a[j].x) - X ; 
				sum+= cost[v][i] ; 
				if(minimize(dp[i], dp[j] + m + sum)) cur = j ; 
			}	
		} 	

		cout << *min_element(dp+1,dp+1+n) ; 
	}
}

namespace sub3 {
	ll pre[N] , SL[N] , DIFF[N] ;
	int X[N] ;
	void solve(void) {
		int max_val = 0 ; 
		FOR(i,1,n) maximize(max_val,a[i].x) ;
		FOR(i,1,n) a[i].x = max_val - a[i].x ;
		sort(a+1,a+1+n) ;
		FOR(i,1,n) X[i] = a[i].x ; 

		FOR(i,1,n) pre[i] = pre[i-1] + (max_val - a[i].x) * a[i].sl ;

		FOR(i,1,n) SL[i] = SL[i-1] + a[i].sl ; 

		FOR(i,1,n) DIFF[i] = DIFF[i-1] - a[i].sl * a[i].x ; 		

		FOR(i,1,n) dp[i] = inf ;
		int cur = 1 ; 	
			
		FOR(i,1,n) {
			int v = upper_bound(X+1,X+1+n,a[i].x) - X ;
			dp[i] = m + SL[i] * a[i].x + DIFF[i] + pre[n] - pre[v-1] ; 
			int v_cur = v ; 
			FOR(j,cur,i-1) {
				ll sum = 0 ; 
				v = upper_bound(X+1,X+1+n,a[j].x) - X ; 
				sum+= a[i].x * (SL[i] - SL[v-1]) + DIFF[i] - DIFF[v-1] ; 
				sum-= (pre[n] - pre[v-1]) ; 
				sum+= (pre[n] - pre[v_cur-1]) ; 
				if(minimize(dp[i], dp[j] + m + sum)) cur = j ; 
			}	
		} 	

		cout << *min_element(dp+1,dp+1+n) ; 
	}
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; 
    if(n <= 100) sub1::solve() ; 
    else if(n <= 1000) sub2::solve() ;
    else sub3::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}