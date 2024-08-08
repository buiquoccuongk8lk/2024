#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 32800

int n ;
int a[MAXN] , b[MAXN] ;
int pos[MAXN] , ok[MAXN] ; 
multiset<int> set_mex ; 
unordered_map<int,int> flag ; 
vector<pair<int,int>> ans ;

void update(int i,int j) {
	ans.push_back({a[i] , a[i] ^ (1 << j)}) ; 
	pos[a[i]] = 0 ;
	if(ok[a[i]]) set_mex.insert(i) ; 
	a[i] = a[i] ^ (1 << j) ;
	pos[a[i]] = i ;
	if(ok[a[i]]) set_mex.erase(set_mex.find(i)) ; 
}

void xuly(int x,int y,int j) {
	for(; j <= 14 ; j++) {
		if( (a[x] & (1 << j)) ^ (y & (1 << j)) )  {
			if(pos[a[x] ^ (1 << j)]) {
				xuly(pos[a[x] ^ (1 << j)] , y , j+1) ; 
				update(x,j) ;
				break ; 
			} else update(x,j) ; 
		}
	}
}

void solve() {
	FOR(i,1,n) {
		ok[b[i]] = 1 ; 
		pos[a[i]] = i ; 
	}
	FOR(i,1,n) if(!ok[a[i]]) set_mex.insert(i) ; 		
	FOR(i,1,n) {
		if(!pos[b[i]]) {
			xuly(*set_mex.begin(),b[i],0) ; 
		}
	}	
	cout << ans.size() << '\n' ;
	for(auto x : ans) cout << x.first << ' ' << x.second << '\n' ; 
}	

signed main() {
    #define task "cloud"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n ;
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,n) cin >> b[i] ;
    solve() ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}