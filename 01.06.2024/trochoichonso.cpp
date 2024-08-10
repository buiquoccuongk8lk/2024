/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n ; 
int f[N][2] ;
int a[N][2] ;
signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ;
    rep(i,1,n) {
    	rep(j,0,1) cin >> a[i][j] ;
    }
    memset(f,-0x3f3f3f3f,sizeof(f)) ;
    int ans = -inf ;
    rep(i,1,n) {
    	ans = max({ans , a[i][0] , a[i][1]}) ;
    }
    f[1][0] = a[1][0] ; 
    f[1][1] = a[1][1] ;
    rep(i,2,n) {
    	f[i][0] = max( { f[i-1][0] , a[i][0] }) ; 
    	f[i][0] = max(f[i][0] , f[i-1][1] + a[i][0]) ; 
    	f[i][1] = max( { f[i-1][1] , a[i][1] }) ;  
    	f[i][1] = max(f[i][1] , f[i-1][0] + a[i][1]) ;
    	ans = max({ans , f[i][1] , f[i][0] }) ;
    }
    cout << ans ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}