#include <bits/stdc++.h>
using namespace std ; 
#define int long long
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;

int n,m ;
int a[maxn],b[maxn] ; 
ll pre[maxn] ;

void process1(void) {
	FOR(i,1,n-m+1) {
   		FOR(j,1,m) a[i+j-1]+=b[j] ; 
   	}
   	FOR(i,1,n) cout << a[i] << ' ' ;
}

void process2(void) {
	FOR(i,1,m) pre[i] = pre[i-1] + b[i] ; 
	FOR(i,1,n-m+1) a[i]+=pre[min(m,i)] ; 
	FOR(i,n-m+2,n) a[i]+=pre[min(i,m)] - pre[i-(n-m+1)] ;  
	FOR(i,1,n) cout << a[i] << ' ' ;
}

signed main(void) {
    #define mitsurichannn "congmang"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    cin >> n >> m ; 
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,m) cin >> b[i] ;
   	//process1() ; 
   //	cout << endl ;
   	process2() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}