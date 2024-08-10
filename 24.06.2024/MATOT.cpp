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

 int dx_ma[] = {-2, -2, -1, -1, 1, 1, 2, 2};
 int dy_ma[] = {-1, 1, -2, 2, -2, 2, -1, 1};

 int dx_tot[] = {0 , -1 , -1 , -1 , 0 , 1 , 1 , 1  } ;
 int dy_tot[] = {-1, -1 , 0  , 1 , 1 , 1  , 0  , -1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ;
char a[1005][1005] ; 
ii Ma , Tot ;

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,n) {
		FOR(j,1,m) {
			cin >> a[i][j] ; 
			if(a[i][j]=='T') Tot = ii(i,j) ; 
			if(a[i][j]=='M') Ma = ii(i,j) ;
		}
	}
}

ll dist_ma[105][105][2] , dist_tot[105][105][2] ;
bool ok_ma[105][105],ok_tot[105][105] ;
struct bg {
	int u ;
	int v ; 
	int t ; 
}; 

void BFS(ll dist[105][105][2],ii st,int dx[],int dy[],bool ok[105][105]) {
	FOR(i,1,n) FOR(j,1,m) FOR(t,0,1) dist[i][j][t] = inf ; 
	dist[st.fi][st.se][0] = 0 ; 
	deque<bg> dq ; 
	dq.pb({st.fi,st.se,0}) ;
	while(!dq.empty()) {
		int u = dq.front().u ; 
		int v = dq.front().v ;
		int t = dq.front().t ; 
		dq.pop_front() ; 
		FOR(s,0,7) {
			int x = u + dx[s] ; 
			int y = v + dy[s] ;
			int new_t = (t + 1)%2 ; 
			if(x < 1 || x > n || y < 1 || y > m) continue ; 
			if(a[x][y]=='#') continue ;
			ok[u][v] = 1 ;
			if(minimize(dist[x][y][new_t] , dist[u][v][t] + 1)) {
				dq.pb({x,y,new_t}) ;
			}
		}
	}

}

void process(void) {

	BFS(dist_ma,Ma,dx_ma,dy_ma,ok_ma) ;
	BFS(dist_tot,Tot,dx_tot,dy_tot,ok_tot) ;

	ll ans = inf ; 
	FOR(i,1,n) FOR(j,1,m) {
		if(a[i][j]=='#') continue ;
		FOR(t1,0,1) FOR(t2,0,1) {
			if(dist_ma[i][j][t1]==dist_tot[i][j][t2]) {
				minimize(ans,dist_ma[i][j][t1]) ; 
			}
			else if(t1==t2) {
				if(ok_ma[i][j] and ok_tot[i][j]) {
					minimize(ans , max(dist_ma[i][j][t1] , dist_tot[i][j][t2]) ) ; 
				}
			}
		}
	}

	cout << (ans == inf ? -1 : ans) ;
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
    return 0;
}