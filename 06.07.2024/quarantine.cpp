#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 
#define fi first
#define se second

const int maxn = 1e5 + 5 ;

int n , m , k ; 
pair<int,int> a[maxn] ;
int b[maxn] ;

void init(void) {
	cin >> n >> m >> k ; 
	FOR(i,1,m) cin >> a[i].fi >> a[i].se ; 
}
void process(void) {
	sort(a+1,a+1+m) ;
	int ans = 0 ;
	int x ;
	while(k--) {
		ans = 0 ; 
		cin >> x ;
		int j = 1 ;  
		FOR(i,1,x) cin >> b[i] ; 
		FOR(i,1,x) {
			while(j <= m and a[j].fi <= b[i]) {
				ans+= (a[j].se >= b[i]) ;
				j++ ; 
			}
		}
		cout << m - ans << '\n' ;
	}
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ;
    process() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}