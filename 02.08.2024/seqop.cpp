
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/
#define tct template<class MITSURII,class CHANN>
#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair <int, int>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FOD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define file(TASK)  if (fopen(TASK".inp", "r")) { freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout); }
using namespace std ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

const int N = 1e5 + 5 ;

int n , m , k ; 
int p[N] ; 
struct DL {
    int x , y , c ; 
} a[N] ; 

int dist[1005][1005] ; 

void dijkstra(int st,int dist[]) {

}

void solve() {
    
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file("") ; 
    cin >> n >> m >> k ; 
    FOR(i,1,k) cin >> p[i] ; 
    FOR(i,1,m) cin >> a[i].x >> a[i].y >> a[i].c ; 
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s" << endl;
    return 0 ;
}