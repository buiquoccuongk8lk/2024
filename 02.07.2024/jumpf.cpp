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

int n ;
int a[N] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> a[i] ; 
}

struct bg {
	int i , j ; 
	ll sum ; 
} ; 
struct cmp {
	bool operator()(bg u,bg v) {
		return u.sum > v.sum ; 
	}
} ; 

priority_queue<bg,vector<bg>,cmp> pq ;
ll dist[1005][1005] ; 

void process(void) {

	FOR(i,1,n) FOR(j,1,n) dist[i][j] = inf ; 

	dist[2][1] = a[2] ; 
	pq.push({ 2 , 1 , dist[2][1] } )  ;	

	while(!pq.empty()) {
		int i = pq.top().i ; 
		int j = pq.top().j ; 
		ll val = pq.top().sum ;
		if(i==n) {
			cout << val ;
			return ; 
		} 
		//cout << i << ' ' << j << ' ' << val << endl ;
		pq.pop() ; 
		if(val > dist[i][j]) continue ; 
		if(i - j >=1) {
			if(minimize(dist[i-j][j], dist[i][j] + a[i-j]) ) {
				pq.push({i - j , j , dist[i-j][j] }) ; 
			}
		}
		if(i + j + 1<= n) {
			if( minimize(dist[i+j+1][j+1] , dist[i][j] + a[i+j+1]) ) {
				pq.push({i + j + 1 , j + 1 , dist[i+1+j][j+1] }) ; 
			}
		}
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
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}