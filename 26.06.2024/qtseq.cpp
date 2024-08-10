/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

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

const int N = 1e6 + 5 ;
const int LO = __lg(N) + 1;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
int a[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

ll suf[N] ;
gp_hash_table <long long,int >mp_max , mp_min ; 
ll pre[N] ; 
ll maxiM[N] , miniM[N] ; 


void process(void) {
	suf[n+1] = 0 ; 
	FORD(i,n,1) {
		suf[i] = suf[i+1] + a[i] ; 
	}
	maxiM[n+1] = -inf ; 
	miniM[n+1] = inf ;
	FORD(i,n,1) {
		maxiM[i] = max(maxiM[i+1] , suf[i]) ; 
		miniM[i] = min(miniM[i+1] , suf[i]) ; 
	}
	
	ll ans = 0 ; 

	FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 

	FOR(i,1,n - 1) {
		ll sum = pre[i] ; 
		ll maxi = maxiM[i+1] ; 
		ll mini = miniM[i+1] ; 
		maximize(ans , abs(sum - maxi)) ; 
		maximize(ans , abs(sum - mini)) ; 
	}

	mp_max[suf[n]]++ ; 
	mp_min[suf[n]]++ ; 
	ll ans2 = 0 ;

	FORD(i,n - 1,1) {
		ll sum = pre[i] ; 

		ll maxi =  maxiM[i+1] ; 
		ll mini =  miniM[i+1] ; 

		if(maxi==mini) {
			if(abs(maxi - sum) == ans || abs(mini - sum) == ans) {
				ans2+= mp_max[maxi] ; 
			}
		} else {
			if(abs(maxi - sum) == ans) {
				ans2+= mp_max[maxi] ; 
			} else if(abs(mini - sum) == ans) {
				ans2+= mp_min[mini] ; 
			}
		}
		mp_max[suf[i]]++ ; 
		mp_min[suf[i]]++ ; 
	}
	cout << ans << ' ' << ans2 ; 

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