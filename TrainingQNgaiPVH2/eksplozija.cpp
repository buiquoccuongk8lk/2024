
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

const int N = 3e6 + 5 ;
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

string s , t ;
int n , m ;
ll pw[N] , hashS[N] , hashT[N] ;
bool mark[N] ;

void init(void) {
	cin >> s ; 
	cin >> t ; 
	n = sz(s) ; m = sz(t) ; 
	s = "*" + s ; 
	t = "*" + t ; 
}
ll get_hash(int i,int j,ll Hash[]) {
	return (Hash[j] - Hash[i-1]*pw[j-i+1] + MOD*MOD)%MOD ;
}
void process(void) {
	pw[0] = 1 ; 

	FOR(i,1,3e6) pw[i] = (pw[i-1] * base)%MOD ;
	FOR(i,1,m) hashT[i] = (hashT[i-1]*base + t[i] - 'a' + 1)%MOD ;

	int pos_cur = 0 ; 
	deque<char> dq ;

	FOR(i,1,n) {
		++pos_cur ; 
		dq.pb(s[i]) ; 	
		hashS[pos_cur] = (hashS[pos_cur-1]*base + s[i] - 'a' + 1)%MOD ;
		if( get_hash(pos_cur-m+1,pos_cur,hashS) == get_hash(1,m,hashT) ) {
			int cnt = 0 ; 
			while(!dq.empty()) {
				dq.pop_back() ; 
				cnt++ ;
				if(cnt==m) break;
			}
			pos_cur-=m ; 
		} 
	}
	if(dq.empty()) {
		cout <<  "miss you baby" ; 
	}
	while(!dq.empty()) {
		cout << dq.front() ;
		dq.pop_front() ;
	}
}

signed main(void) {
    #define TASK "eksplozija"
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