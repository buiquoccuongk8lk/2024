// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}
const int MAXN = 2e5 + 5 ;

int n ;
ll S ;
int a[MAXN] ; 
ll pre[MAXN] ;
int nxt[MAXN] ;
int nxt_pos , cnt , pos ; 

void init() {
	cin >> n >> S ; 
	FOR(i,1,n) cin >> a[i] ;
	FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;
}

void solve() {
	ll ans = 0 ; 
	FOR(i,1,n) {
		nxt_pos = upper_bound(pre+i,pre+n+1,S+pre[i-1]) - pre ; 
		nxt[i] = nxt_pos ;
	}
	FOR(i,1,n) {
		cnt = 0  ,pos = i ;
		while(pos <= n) {
			nxt_pos = nxt[pos] ;
			cnt++ ; 
			ans+= 1ll * cnt * (nxt_pos - pos) ; 
			pos = nxt_pos ;
		}
	}
	cout << ans ;
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