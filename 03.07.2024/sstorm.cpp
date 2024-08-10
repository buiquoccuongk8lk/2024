/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const int N = 5e2+ 5 ;
const long long inf = 1e18 ;

int n , m , k ,q ;
int a[N][N] ;

struct Storm_Event {
    int w,r1,r2,x,y ;
    void input() {
        cin >> w >> r1 >> r2 >> x >> y ;
    }
} storm[(int)1e5+5] ;
pair<int,int> spec_place[N] ;

void init(void) {
    cin >> n >> m >> q >> k ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin >> a[i][j] ;
        }
    }
    for(int i = 1 ; i <= q ; i++) {
        cin >> spec_place[i].fi >> spec_place[i].se ;
    }
    for(int i = 1 ; i <= k ; i++) storm[i].input() ;
}

namespace sub1 {

    int dist(int x,int y,int u,int v) {
        return abs(x - u) + abs(y - v) ;
    }

    void solve(void) {
        long long ans = 0 ;

        for(int i = 1 ; i <= k ; i++) {
            int w = storm[i].w ;
            int r1 = storm[i].r1 ;
            int r2 = storm[i].r2 ;
            int x = storm[i].x ;
            int y = storm[i].y ;

            for(int u = 1 ; u <= n ; u++) {
                for(int v = 1 ; v <= m ; v++) {
                    if(dist(u,v,x,y) <= r1 and dist(u,v,x,y) >= r2) {
                        ans+= min(w,a[u][v]) ;
                        a[u][v]-=min(w,a[u][v]) ;
                    }
                }
            }

        }

        cout << ans ;
    }

}

namespace sub2 {
    struct BG {
        int w , r1 ,r2 ;
    };
    vector<BG> vec[N][N] ;
    unordered_map<int,int> mp[N] ;
    long long B[7][10005] ;
    int dist(int x,int y,int u,int v) {
        return abs(x - u) + abs(y - v) ;
    }

    void solve(void) {

        long long ans = 0 ;

        for(int i = 1 ; i <= q ; i++) {
            mp[spec_place[i].fi][spec_place[i].se] = i ;
        }

        for(int i = 1 ; i <= k ; i++) {
            auto [w,r1,r2,x,y] = storm[i] ;
            int j = mp[x][y] ;
            B[j][r2]+=w ;
            B[j][r1+1]-=w ;
        }

        for(int i = 1 ; i <= q ; i++) {
            for(int j = 1 ; j <= 1000 ; j++) {
                B[i][j]+= B[i][j-1] ;
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                for(int id = 1 ; id <= q ; id++) {
                    int dis = dist(i,j,spec_place[id].fi,spec_place[id].se) ; 
                    if(a[i][j] >= B[id][dis]) {
                        ans+= B[id][dis] ; 
                        a[i][j]-=B[id][dis] ; 
                    } else {
                        ans+= a[i][j] ; 
                        a[i][j] = 0 ; 
                    }
                }
            }
        }

        cout << ans ; 
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
    //sub1::solve() ;
    sub2::solve() ;

    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0 ;
}
