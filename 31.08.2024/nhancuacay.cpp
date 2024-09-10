// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1e5 + 5 ;
const int LO = __lg(MAXN) + 1 ;

int n , m ;
int a[MAXN] ;
int rmq[MAXN][LO] ;

void init() {
    cin >> n >> m ; 
    FOR(i,1,n) cin >> a[i] ;
}

int get(int l,int r) {
    if(l > r) return 2e9 ; 
    int k = __lg(r-l+1) ; 
    return min(rmq[l][k],rmq[r-(1<<k)+1][k]) ;
}

int d , lim ; 

void solve() {
    FOR(i,1,n)rmq[i][0]=a[i] ;
    for(int j(1) ; (1<<j) - 1 <= n ; j++) {
        for(int i(1) ; i + (1<<j) - 1 <= n ; i++) 
            rmq[i][j] = min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
    }
    while(m--) {
        cin >> lim >> d ; 
        int pos = 1 ;
        bool ok = true ; 
        while(pos < n) {
            int tmp_r = min(n,pos+d) ;
            int l = pos , r = min(n,pos+d) , nxt_pos = -1 ; 
            while(l <= r) {
                int mid = (l+r)/2 ; 
                if(get(mid,tmp_r) <= lim) nxt_pos = mid , l = mid + 1 ; 
                else r = mid - 1 ; 
            }
            if(nxt_pos==-1 || nxt_pos <= pos) {
                ok = false ;
                break ; 
            }
           // cout << pos << ' ' << nxt_pos << endl ;
            pos = nxt_pos ; 
        }
      //  cout << ok << ' ' << pos << endl ;
        if(ok || pos >= n) cout << 1 << '\n' ; 
        else cout << '0' << '\n' ; 
    }
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */