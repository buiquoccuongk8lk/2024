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
const int M = 2e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ;
char a[M][M] ;
ii st , ed ;
int dist[M][M],distMIN[M][M] ;

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,n)FOR(j,1,m) cin>>a[i][j] ; 
	FOR(i,1,n)FOR(j,1,m) {
		if(a[i][j]=='P') st = ii(i,j) ; 
		if(a[i][j]=='C') ed = ii(i,j) ; 
	}
}

void build(void) {
	FOR(i,1,n)FOR(j,1,m)distMIN[i][j] = oo ; 
	queue<ii> q ; 
	FOR(i,1,n)FOR(j,1,m) if(a[i][j]=='+') {
		distMIN[i][j] = 0 ;
		q.push(ii(i,j)) ; 
	}
	while(!q.empty()) {
		int u = q.front().fi ; 
		int v = q.front().se ;
		q.pop() ; 
		FOR(s,0,3) {
			int x = u + dx[s] ; 
			int y = v + dy[s] ; 
			if(x<1||x>n||y<1||y>m) continue ; 
			if(minimize(distMIN[x][y],distMIN[u][v]+1)) {
				q.push(ii(x,y)) ; 
				//cout << x << ' ' << y << ' ' << u << ' ' << v << endl ; 
			}
		}
	}
}

bool check(int mid) {
	FOR(i,1,n)FOR(j,1,m)dist[i][j] = oo ;
	if(distMIN[st.fi][st.se] < mid) return 0 ; 
	dist[st.fi][st.se] = 0 ; 
	queue<ii>q ; 
	q.push(st) ; 
	while(!q.empty()) {
		int u = q.front().fi ; 
		int v = q.front().se ;
		q.pop() ; 
		FOR(s,0,3) {
			int x = u + dx[s] ; 
			int y = v + dy[s] ; 
			if(x<1||x>n||y<1||y>m) continue ; 
			if(distMIN[x][y] >= mid && minimize(dist[x][y],dist[u][v]+1)) {
				q.push(ii(x,y)) ; 
			}
		}
	}
	return (dist[ed.fi][ed.se] < oo) ; 
}

void solve(void) {
	build() ; 
	int l = 0 , r = distMIN[ed.fi][ed.se] , ans = -1 ; 
	while(l <= r) {
		int mid = (l+r)/2 ; 
		if(check(mid)) ans = mid , l = mid + 1 ; 
		else r = mid - 1 ; 
	}
	cout << ans ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}