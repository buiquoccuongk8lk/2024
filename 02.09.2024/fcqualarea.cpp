// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 505 ;

int n ;
struct point {
	int x , y ; 
} P[MAXN] , H[MAXN] ;

void init() {
	cin >> n ;
	FOR(i,1,n) cin >> P[i].x >> P[i].y ; 
}

int ccw(point a,point b,point c) {
	return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x) ; 
}

int dist(point a,point b) {
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) ; 
}

int dtri(point a,point b,point c) {
	return abs( (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) ) ; 
}

void solve() {
	sort(P+1,P+1+n,[](point a,point b) {
		if(a.y==b.y) return a.x < b.x ; 
		else return a.y < b.y ; 
	}) ; 
	sort(P+2,P+1+n,[](point a,point b) {
		if(ccw(a,b,P[1])==0) return dist(P[1],a) < dist(P[1],b) ; 
		else return ccw(P[1],a,b) > 0 ;
	}) ; 
	P[n+1] = P[1] ; 
	int m = 2 ; 
	H[1] = P[1] ; 
	H[2] = P[2] ;
	FOR(i,3,n+1) {
		while(m >= 2 && ccw(H[m-1],H[m],P[i]) <= 0) m-- ; 
		m++ ; 
		H[m] = P[i] ; 
	}
	m-- ;
	FOR(i,1,m) cout << H[i].x << " " << H[i].y << endl ;
	int ans = 0 ; 
	FOR(i,1,m-1) {
		int l = i + 1 , r = i + 3 ;
		FOR(j,i+2,m-1) {
			while(l <= j - 1 && dtri(H[i],H[j],H[l]) <= dtri(H[i],H[j],H[l+1]) ) l++ ; 
			while(r <= m && dtri(H[i],H[j],H[r]) <= dtri(H[i],H[j],H[r+1]) ) r++ ; 
			maxi(ans,dtri(H[i],H[j],H[l]) + dtri(H[i],H[j],H[r]) ) ; 
		}
	}
	cout << ans ; 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */