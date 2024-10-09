/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
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

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n,k ;
struct DL {
	string xau ; 
	int id ;
	int ts ;
}s[N] , a[N] ;
unordered_map<string,int> mp ;
string pos[N] ;
unordered_map<string,int> ID ;

void init(void) {
	cin >> n >> k ;
	getline(cin,s[1].xau) ;
	FOR(i,1,3*n) {
		getline(cin,s[i].xau) ;
		s[i].id = i ;
	} 
}

void process(void) {
	FOR(i,1,3*n) mp[s[i].xau]++ ; 
	FOR(i,1,3*n) {
		ID[s[i].xau] = i ;
	}
	int sz = 0 ;
	FOR(i,1,3*n) {
		if(ID[s[i].xau]==i) {
			a[++sz]= { s[i].xau , i , mp[s[i].xau] } ; 
		}
	}
	sort(a+1,a+1+sz,[](DL u,DL v) {
		if(u.ts==v.ts) return u.id > v.id ;
		else return u.ts > v.ts; 
	}) ; 
	FOR(i,1,k) cout << a[i].xau << endl ;
}

signed main(void) {
    #define TASK "gratitude"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}