#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
const int dx[] = {0,1,0,-1} ;
const int dy[] = {1,0,-1,0} ;
int n , m ;
int a[1005][1005] ; 
int f[1005][1005] ;

int calc(int i,int j) {
	if(i < 1 || i > n || j < 1 || j > m) return 0 ;
	if(f[i][j]!=-1) return f[i][j] ; 
	f[i][j] = 1 ; 
	FOR(s,0,3) {
		int x = i + dx[s] ; 
		int y = j + dy[s] ; 
		if(a[x][y] == a[i][j] + 1) maxi(f[i][j],1+calc(x,y)) ; 
	}
	return f[i][j] ; 
} 

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> m ; 
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
    memset(f,-1,sizeof f) ; 
    int ans = 0 ; 
    FOR(i,1,n)FOR(j,1,m)maxi(ans,calc(i,j)) ;
    cout << ans ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}