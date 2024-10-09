/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int n , L , B ; 
int a[N] ; 

void init(void) {
	cin >> n >> L >> B ;
	FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {

	ll pre[N] ;

	ll calc(int i,int j) {
		int mid = (i+j)>>1 ; 
		int s1 = a [mid] * (mid - i) - pre[mid - 1] + pre[i - 1];
		int s2 = pre[j] - pre[mid] - a[mid] * (j - mid);
		return s1 + s2 ;
	}

	void solve(void) {
		
		sort(a+1,a+1+n) ; 

		FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 

		int ans = 0 ;

		FOR(i,1,n) {
			int l = i ; 
			int r = n ;
			int pos = -1 ; 
			while(l <= r) {
				int mid = (l+r)>>1 ; 
				if(calc(i,mid) <= B) {
					pos = mid ; 
					l = mid + 1 ; 
				}else r = mid - 1 ; 
			}
			maximize(ans,pos-i+1) ; 
		}

		cout << ans ;
	}

}

signed main(void) {
    #define TASK "fields"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int sub_task ; cin >> sub_task ; 
    init() ; 
    sub1::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}