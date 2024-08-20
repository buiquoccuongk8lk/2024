#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

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

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 1e6 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n , k ; 
int a[MAXN] ;
int prime[MAXN+5] ;
int L[MAXN] , R[MAXN] ;  

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> k ;
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,2,MAXN) prime[i] = 1 ; 
    FOR(i,2,sqrt(MAXN)) {
    	for(int j = i * i ; j <= MAXN ; j+=i) prime[j] = 0 ; 
    } 
	FOR(i,1,n) {
		if(a[i]!=1) L[i] = 0 ; 
		else {
			if(i < k) L[i] = 1 ; 
			else L[i] = L[i-k] + 1 ;
		} 
	}
	FORD(i,n,1) {
		if(a[i]!=1) R[i] = 0 ; 
		else {
			if(i + k > n) R[i] = 1 ; 
			else R[i] = R[i+k] + 1 ;  
		}
	}
	int ans = 0 ; 
	FOR(i,1,n) if(prime[a[i]]) ans+= ( L[max(1ll*0,i-k)] + 1)  * ( R[min(i+k,n+1)] + 1) - 1 ; 
	cout << ans ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}