
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

int n,a,x,b,y ;

void init(void) {
    cin >> n >> a >> x >> b >> y ;
}

void process(void) {
   int ax = (x - a + n)%n ;
   int by = (b - y + n)%n ;
   int ab = (b - a + n)%n ;
   if(ab % 2 == 0) {
        if(2*ax >= ab and 2*by >= ab) {
            cout << "YES" ;
        } else cout << "NO" ;
   } else if( (ab + n) % 2 == 0 ) {
        if(2*ax >= (ab+n) and 2*by >= (ab+n) ) {
            cout << "YES" ;
        } else cout << "NO" ;
   } else cout << "NO" ;
   cout << endl ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int t ;
    cin >> t ;
    while(t--) {
        init() ; process() ;
    }
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ;
}
