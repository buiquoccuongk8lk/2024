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

const int N = 2e5 + 5 , LO = 17 , base = 29 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , q ; 
pair<string,int> S[N] ; 
void init(void) {
    cin >> n >> q ; 
    rep(i,1,n) {
        string x ;
        cin >> x ; 
        S[i].fi = x ; 
        S[i].se = i ;
    }
}

namespace sub {
    vi Hash[N] ;  
    int fir[N] ;
    int LCP(int a,int b) {
        int l = 0 ; 
        int r = min((int)S[a].fi.size(),(int)S[b].fi.size()) ;
        int ret = 0 ; 
        while(l <= r) {
            int mid = (l+r)>>1 ; 
            if(Hash[a][mid]==Hash[b][mid]) ret = mid , l = mid + 1 ; 
            else r = mid - 1 ; 
        }
        return ret ; 
    } 
    void solve(void) {
        /*rep(i,1,n) {
            S[i].fi = "*" + S[i].fi ; 
        }*/
        sort(S+1,S+1+n) ;    
        rep(i,1,n) {
            int cur = 1 ; 
            Hash[i].push_back(cur) ; 
            for(auto c : S[i].fi) {
                cur = (cur*base + c - 'a' + 1)%MOD ; 
                Hash[i].pb(cur) ; 
            }
        }
        int sz = 0 ; 
        rep(i,1,n) {
            fir[S[i].se] = ++sz ; 
        }
        while(q--) {
            int K , L ; 
            cin >> K >> L ;
            vi vec ;  
            rep(i,1,K) {
                int idx ; 
                cin >> idx ; 
                vec.pb(fir[idx]) ; 
            }
            vec.pb(0) ; 
            sort(vec.begin(),vec.end()) ; 
            int ans = 0 ;
            rep(i,1,K-L+1) {
                int tot = LCP(vec[i],vec[i+L-1]) ; 
                int diffA = 0 , diffB = 0 ; 
                if(i + L <= K) diffA = LCP(vec[i],vec[i+L]) ; 
                if(i >= 2) diffB = LCP(vec[i-1],vec[i]) ; 
                ans+= tot - min(max(diffA,diffB) , tot) ; 
            }
            cout << ans << '\n' ; 
        }
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
    return 0;
}