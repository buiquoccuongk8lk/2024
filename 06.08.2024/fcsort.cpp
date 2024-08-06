#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
using namespace std ; 
#define int long long
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 
const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

const int N = 1e5 + 5 , M = 1e3 + 3 , base = 311 , LO = __lg(N) + 1 ;
const long long inf = 1e18 ; 
const int mod = 1e9 + 7 ;

tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ;
int a[N] ;

void process() {
	
	
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
	cin >> n ;
	FOR(i,1,n) cin >> a[i] ;
	process() ;     
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}