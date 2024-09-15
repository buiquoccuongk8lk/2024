// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 20 ; 
const int oo = 2e9 ;

int test , n ;
string s , t ;
int dp[1 << 10][1 << 10] ; 
int a[MAXN] , b[MAXN] ;

void init() {
	cin >> test >> n ; 
}

void solve() {
	while(test--) {
		cin >> s ;
		cin >> t ;
		s = "*" + s , t = "*" + t ; 

		FOR(i,1,n) a[i] = s[i] - '0' ;
		FOR(i,1,n) b[i] = t[i] - '0' ;

		FOR(mask1,0,(1<<n)-1) {
			FOR(mask2,0,(1<<n)-1) dp[mask1][mask2] = oo ;
		}

		int mask_st = 0 ;  
		FORD(i,n,1) {
			if(a[i]) mask_st = mask_st | (1 << (n - i)) ;  
		}

		int mask_sw = 0 ; 
		FORD(i,n,1) {
			if(b[i]) mask_sw = mask_sw | (1 << (n - i)) ; 
		}
		
		queue<ii> q ; 
		q.push(ii({mask_sw , mask_st})) ; 	
		dp[mask_sw][mask_st] = 0 ;

		while(!q.empty()) {
			int mask_sw = q.front().fi ;	
			int mask_li = q.front().se ; 
			q.pop() ; 

			cout << mask_sw << ' ' << mask_li << '\n' ; 

			FOR(i,0,n-1) {
				int curmask_sw = mask_sw ; 
				int curmask_li = mask_li ; 

				curmask_sw^= i ; 
				int newmask_li = curmask_li ; 

				FOR(j,0,n-1) {
					if(BIT(curmask_sw,j)) {
						newmask_li^= j ;
					}
				}

				vi tmp ;  
				FOR(j,0,n-1) tmp.pb(BIT(curmask_sw,j)) ; 

				int newmask_sw = 0 ; 
				FOR(j,0,n-1) {
					if(tmp[j]) {
						newmask_sw = newmask_sw | (1 << ((j + 1) % n)) ; 
					}
				}

				if(mini(dp[newmask_sw][newmask_li],dp[mask_sw][mask_li]+1)) {
					q.push(ii(newmask_sw,newmask_li)) ; 
				}
			}
		}

		
	}

}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 