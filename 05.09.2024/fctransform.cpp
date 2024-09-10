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

const int mod = 1e9 + 9 ;
const int MAXN = 1e2 + 5 ;

int n , k , m ;
string s , t ;
ll dp[MAXN][MAXN] ;
ll C[MAXN][MAXN] ;

// dp[i][j] là số cách biến đổi để i lượt đầu có j thằng giống nhau
// khi xét đến (i,j)
// ta có thể chọn x trong số các phần tử đã giống trc đó hoặc không
// nên công thức như ở dưới

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
   	C[0][0] = 1 ;
   	FOR(i,1,100) {
   		C[i][0] = 1 ;
   		FOR(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod ;
   	}
   	while(cin >> n >> k >> m) {
   		cin >> s ;
   		cin >> t ; 
   		s = "*" + s ; 
   		t = "*" + t ;
   		int cnt = 0 ;
   		FOR(i,1,n) cnt+= (s[i] == t[i]) ; 
   		dp[0][cnt] = 1 ;		
   		FOR(i,0,k-1) {
   			FOR(j,0,n) {
   				FOR(x,0,min(j,m)) {
   					int new_j = j - x + m - x ; 
   					dp[i+1][new_j] = (dp[i+1][new_j] + 1LL * dp[i][j] * C[j][x] % mod * C[n-j][m-x]) % mod ;
   				}
   			}
   		}
   		cout << dp[k][n] << '\n' ;
   		FOR(i,0,k) FOR(j,0,n) dp[i][j] = 0 ;
   	}
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */