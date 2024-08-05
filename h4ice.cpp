/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

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

const int N = 1e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 5e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
char a[M][M] ; 
int dist[M][M] ;

void init() {
	cin >> n ;
	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j] ;
}

bool inside(int x,int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n ;
}

void solve() {
	FOR(i,1,n)FOR(j,1,n)dist[i][j]=oo ; 
	queue<ii>q ; 
	FOR(i,1,n)FOR(j,1,n)if(a[i][j]=='0') {
	 	dist[i][j] = 0 ; 
	 	q.push(ii(i,j)) ; 
	}
	while(!q.empty()) {
		int u = q.front().fi ; 
		int v = q.front().se ; 
		q.pop() ; 
		FOR(s,0,3) {
			int xx = u + dx[s] ; 
			int yy = v + dy[s] ; 
			if(inside(xx,yy)) {
				FOR(t,0,3) {
					int x = xx + dx[t] ; 
					int y = yy + dy[t] ; 
					if(x == u && y == v) continue ; 
					if(inside(x,y)) {
						if(minimize(dist[xx][yy],max(dist[u][v],dist[x][y])+1)) {
							q.push(ii(xx,yy)) ; 
						}
					}
				}
			}
		}
	}
	int ans = 0 ; 
	FOR(i,1,n)FOR(j,1,n) ans=max(ans,dist[i][j]) ;
	cout << ans ; 
}


signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}