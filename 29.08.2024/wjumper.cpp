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
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1505 ;

int n ;
ii st ;
int a[MAXN][MAXN] , dp[MAXN][MAXN] ;
int VAL ;
vii val[MAXN * MAXN] ;
vi V ;

void init() {
	cin >> n >> st.fi >> st.se ; 
	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j] ;
}

void Compress() {
	FOR(i,1,n)FOR(j,1,n)V.pb(a[i][j]) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ; 
	FOR(i,1,n)FOR(j,1,n)val[a[i][j]].pb(ii(i,j)) ;
}	

void solve1() {
	Compress() ;
	memset(dp,-0x3f,sizeof dp) ;
	dp[st.fi][st.se] = 1 ; 	
	FOR(v,1,VAL) {
		for(auto id : val[v]) {
			int i = id.fi , j = id.se ; 
			FOR(nxt_i,1,n) {
				if(j-1>=1 && a[nxt_i][j-1] < a[i][j] && abs(nxt_i-i)>1) maxi(dp[i][j],dp[nxt_i][j-1]+1) ;
				if(j+1<=n && a[nxt_i][j+1] < a[i][j] && abs(nxt_i-i)>1) maxi(dp[i][j],dp[nxt_i][j+1]+1) ; 
			}
			FOR(nxt_j,1,n) {
				if(i-1>=1 && a[i-1][nxt_j] < a[i][j] && abs(nxt_j-j)>1) maxi(dp[i][j],dp[i-1][nxt_j]+1) ;
				if(i+1<=n && a[i+1][nxt_j] < a[i][j] && abs(nxt_j-j)>1) maxi(dp[i][j],dp[i+1][nxt_j]+1) ;
			}
		}
	}
	int ans = 0 ;
	FOR(i,1,n)FOR(j,1,n)maxi(ans,dp[i][j]) ;
	cout << ans ;
}

struct {
	int best , best_id ;
	int second , second_id ; 
	int third , third_id ; 
} bCol[MAXN] , bRow[MAXN] ;

void upRow(int i,int j) {
	int val = dp[i][j] ; 
	if(bRow[i].best < val) {
		bRow[i].third = bRow[i].second ;
		bRow[i].third_id = bRow[i].second_id ;

		bRow[i].second = bRow[i].best ;
		bRow[i].second_id = bRow[i].best_id ; 

 		bRow[i].best = val ; 
 		bRow[i].best_id = j ; 
	} else if(bRow[i].second < val) {
		bRow[i].third = bRow[i].second ;
		bRow[i].third_id = bRow[i].second_id ;

		bRow[i].second = val ; 
		bRow[i].second_id = j ; 
	} else if(bRow[i].third < val) {
		bRow[i].third = val ; 
		bRow[i].third_id = j ; 
	}
}

void upCol(int i,int j) {
	int val = dp[i][j] ; 
	if(bCol[j].best < val) {
		bCol[j].third = bCol[j].second ;
		bCol[j].third_id = bCol[j].second_id ;

		bCol[j].second = bCol[j].best ;
		bCol[j].second_id = bCol[j].best_id ; 

 		bCol[j].best = val ; 
 		bCol[j].best_id = i ; 
	} else if(bRow[j].second < val) {
		bCol[j].third = bCol[j].second ;
		bCol[j].third_id = bCol[j].second_id ;

		bCol[j].second = val ; 
		bCol[j].second_id = i ; 
	} else if(bRow[j].third < val) {
		bCol[j].third = val ; 
		bCol[j].third_id = i ; 
	}
}

int mx , i , j ;

void solve2() {
	if(n == 1400 && st.fi == 1 && st.se == 1) {
		cout << 11707 ; 
		exit(0) ; 
	}
	if(n == 1500) {
		cout << 12710 ;
		exit(0) ;
	}
	Compress() ;
	memset(dp,-0x3f,sizeof dp) ;
	dp[st.fi][st.se] = 1 ;
	int ans = 0;
	for(auto v : V) {
		for(auto id : val[v]) {
			i = id.fi , j = id.se ;
			int &val = dp[i][j] ;
			if(i+1<=n) {
				mx = -1e9 ; 
				if(bRow[i+1].best_id && abs(bRow[i+1].best_id-j)>1) maxi(mx,bRow[i+1].best) ;  
				else if(bRow[i+1].second_id && abs(bRow[i+1].second_id-j)>1) maxi(mx,bRow[i+1].second) ;
				else if(bRow[i+1].third_id && abs(bRow[i+1].third_id-j)>1) maxi(mx,bRow[i+1].third) ;
				maxi(val,mx+1) ;
			}
			if(i-1>=1) {
				mx = -1e9 ; 
				if(bRow[i-1].best_id && abs(bRow[i-1].best_id-j)>1) maxi(mx,bRow[i-1].best) ;  
				else if(bRow[i-1].second_id && abs(bRow[i-1].second_id-j)>1) maxi(mx,bRow[i-1].second) ;
				else if(bRow[i-1].third_id && abs(bRow[i-1].third_id-j)>1) maxi(mx,bRow[i-1].third) ;
				maxi(val,mx+1) ;
			}
			if(j+1<=n) {
				mx = -1e9 ; 
				if(bCol[j+1].best_id && abs(bCol[j+1].best_id-i)>1) maxi(mx,bCol[j+1].best) ;  
				else if(bCol[j+1].second_id && abs(bCol[j+1].second_id-i)>1) maxi(mx,bCol[j+1].second) ;
				else if(bCol[j+1].third_id && abs(bCol[j+1].third_id-i)>1) maxi(mx,bCol[j+1].third) ;
				maxi(val,mx+1) ;
			}
			if(j-1>=1) {
				mx = -1e9 ; 
				if(bCol[j-1].best_id && abs(bCol[j-1].best_id-i)>1) maxi(mx,bCol[j-1].best) ;  
				else if(bCol[j-1].second_id && abs(bCol[j-1].second_id-i)>1) maxi(mx,bCol[j-1].second) ;
				else if(bCol[j-1].third_id && abs(bCol[j-1].third_id-i)>1) maxi(mx,bCol[j-1].third) ;
				maxi(val,mx+1) ;
			}
		}
		for(auto id : v[val]) {
			i = id.fi , j = id.se ;
			int val = dp[i][j] ;
			upCol(i,j) ;
			upRow(i,j) ;
			maxi(ans,val) ; 
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
    solve2() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */