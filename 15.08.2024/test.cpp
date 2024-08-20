#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN 1000005

int n , m ; 
multiset<int> ms ; 
int dp[MAXN] , ma[MAXN] ;
vii events[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,m) {
		int l , r ; cin >> l >> r ; 
		events[l].pb(ii(0,1)) ; 
		events[r+1].pb(ii(l,-1)) ; 
	}
}

void solve() {
	FOR(i,1,n) {
		for(auto x : events[i]) {
			if(x.se > 0) ms.insert(i) ; 
			else ms.erase(ms.find(x.fi)) ; 
		} 
		if(ms.size()) maxi(dp[i],ma[*ms.begin() - 1] + (int)ms.size()) ; 
		ma[i] = max(ma[i-1],dp[i]) ; 
	}
	cout << *max_element(dp+1,dp+1+n) ;
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