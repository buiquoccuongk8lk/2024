#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 1000005

int n , k ;
int a[MAXN] ; 
long long pre[MAXN] ;

void init() {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void solve() {	
	FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;
	vector<pair<int,int>> v ; 
	long long ans = 0 ;
	FOR(i,1,n) {
		for(auto &x : v) x.second = __gcd(x.second,a[i]) ; 
		v.push_back({i,a[i]}) ;
 		vector<pair<int,int>> tmp ; 
 		tmp.push_back(v[0]) ; 
 		FOR(j,0,(int)v.size()-1) if(v[j-1].second!=v[j].second) tmp.push_back(v[j]) ; 
 		v = tmp ; 
 		for(auto x : v) if(i - x.first + 1 >= k) maxi(ans, (pre[i] - pre[x.first-1]) * x.second) ; 
	}
	cout << ans ; 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}