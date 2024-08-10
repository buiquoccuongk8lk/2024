/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

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
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int dx[] = { -1 , 1 , 0 , 0 } ;
int dy[] = { 0  , 0 , -1 , 1 } ; 

int n ;
int a[M][M] ; 
ii st ,en ; 
int dist1[M][M][4] ;
int dist2[M][M][4] ; 

struct DL {
	int u ;
	int v ; 
	int dir_t ; 
	//int cost ; 
} ;

/*struct cmp {
	bool operator()(DL u,DL v) {
		return u.cost > v.cost ;
	}
};*/

void init(void) {
	cin >> n ;
	FOR(i,1,n) FOR(j,1,n) cin >> a[i][j] ; 
	cin >> st.fi >> st.se >> en.fi >> en.se ; 
}

bool isValid(int x,int y) {
	return (x>=1 and x<=n and y>=1 and y<=n) ; 
}

void BFS(ii start , int dist[M][M][4] ) {
	FOR(i,1,n) FOR(j,1,n) FOR(dir,0,3) dist[i][j][dir] = 2e9 ; 
	FOR(dir,0,3) dist[start.fi][start.se][dir] = 0 ; 
	deque<DL>dq ; 
	FOR(dir,0,3) dq.push_back({start.fi,start.se,dir}) ;  
	while(!dq.empty()) {
		auto tmp = dq.front() ; dq.pop_front() ; 
		int u = tmp.u ; 
		int v = tmp.v ; 
		int dir_prev = tmp.dir_t ; 
		FOR(s,0,3) {
			int x = u + dx[s] ; 
			int y = v + dy[s] ; 
			int new_dir = s ; 
			int w = 0 + (dir_prev!=new_dir) ; 
			if(isValid(x,y)) {
				if(a[x][y]) {
					minimize(dist[x][y][new_dir] ,dist[u][v][dir_prev] + w) ; 
				}else if(minimize(dist[x][y][new_dir] ,dist[u][v][dir_prev] + w)) {
					if(w==0) dq.push_front({x,y,new_dir}) ; 
					else dq.push_back({x,y,new_dir}) ;
				}
			}	
		}
	}
}
int calc(int dir1,int dir2) {
	if(dir1==0) return (dir2!=1) ; 
	else if(dir1==1) return (dir2!=0) ; 
	else if(dir1==2) return (dir2!=3) ; 
	else if(dir1==3) return (dir2!=2) ; 
	else return 0 ; 
}
void process(void) {
	BFS(st,dist1) ; 
	BFS(en,dist2) ; 
	int ans1 = 2e9 ;
	FOR(dir,0,3) minimize(ans1,dist1[en.fi][en.se][dir]) ; 
   	int ans2 = ans1 ; 
   	bool ok = 0 ;
   	int ans3 = 0 ; 
   	int cnt = 0 ; 
   	FOR(i,1,n) FOR(j,1,n) cnt+=a[i][j] ;
   	FOR(i,1,n) {
   		FOR(j,1,n) {
   			if(a[i][j]) {
   				FOR(s1,0,3) FOR(s2,0,3) {
   					if(dist1[i][j][s1]==2e9 || dist2[i][j][s2]==2e9) continue ; 
   					int cost = dist1[i][j][s1] + dist2[i][j][s2] + calc(s1,s2)  ; 
   					if(ans2 == cost) ans3++ ; 
   					if( minimize(ans2,cost) ) {
   						ok = 1 ; 
   						ans3 = 1 ; 
   					} 
   				}
   			}
   		}
   	}
   	cout << ans1 << ' ' ; 
   	cout << ans2 << ' ' ;
  	cout << (ok ? ans3 : cnt) ; 
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