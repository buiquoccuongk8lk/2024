#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAX 100005
int n , k ;
int a[MAX] ;
int cnt[MAX] ;
int pre[MAX] , suf[MAX] ; 
signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> k ;
    FOR(i,1,k) cin >> a[i] ;
    FOR(i,1,k) cnt[a[i]]++ ; 
    FOR(i,1,n) {
    	if(cnt[i]) {
    		pre[i] = pre[i-1] + 1 ; 
    	} else {		
    		pre[i] = 0 ; 
    	}
    }
    FORD(i,n,1) {
    	if(cnt[i]) {
    		suf[i] = suf[i+1] + 1 ; 
    	} else {
    		suf[i] = 0 ; 
    	}
    }
    set<int> mex ; 
    int ans = 0 ;
    FOR(i,1,n) maxi(ans,pre[i]) ; 
    FOR(i,1,n) if(!cnt[i]) mex.insert(i) ;
    for(auto x : mex) maxi(ans,pre[x-1] + 1 + suf[x+1]) ;
    cout << ans ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}