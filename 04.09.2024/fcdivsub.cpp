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

const int MAXN = 2e5 + 5 ;

int n , P ;
string s ;
int pre[MAXN] ;
int cnt[MAXN] ;

void init() {
	cin >> n >> P ;
	cin >> s ; s = '*' + s ;
}

int LT(int x,int y) {
	if(y==0) return 1 ; 
	if(y==1) return x ; 
	int c = LT(x,y/2) ; 
	if(y&1) return 1LL * c * c % P * x % P ;
	else return 1LL * c * c % P ;
}

void solve() {
	int ans = 0 ; 
	if(P == 2 || P == 5) {
		FOR(i,1,n) if( (s[i] - '0') % P == 0) ans = (ans + i) ; 
		cout << ans ; 
		exit(0) ;
	}
	cnt[0] = 1 ;
	FOR(i,1,n) {
		pre[i] = pre[i-1] + ( (s[i] - '0' ) * LT(10,n-i) % P) % P; 
		ans+= cnt[pre[i]%P] ;
		cnt[pre[i]%P]++ ;  
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