// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef pair<int,int> ii ;
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
template<class T> bool maxi(T &x,T y) { if(x < y) { x = y ; return 1 ;} return 0 ;}
template<class T> bool mini(T &x,T y) { if(x > y) { x = y ; return 1 ;} return 0 ;}

const int MAXN = 3000 + 5 ;

int n ;
struct point {
	int x , y ;
} P[MAXN] , H[MAXN] ;
int m ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> P[i].x >> P[i].y ;
}

int ccw(point a,point b,point c) {
	return (b.x - a.x) * (c . y - b.y) - (b.y - a.y) * (c.x - b.x) ;
}

int dttg(point a,point b,point c) {
	return abs( (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) ) ; 
}

int dist(point a,point b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) ; 
}

void build_Convex() {
	sort(P+1,P+1+n,[](point u,point v) {
		if(u.y==v.y) return u.x < v.x ; 
		else return u.y < v.y ;  
	}) ; 
	sort(P+2,P+1+n,[](point A,point B) { 
		if(ccw(P[1],A,B)==0) return dist(P[1],A) < dist(P[1],B) ; 
		else return ccw(P[1],A,B) > 0 ; 
	}) ;
	P[n+1] = P[1] ; 
	m = 2 ; 
	H[1] = P[1] ; 
	H[2] = P[2] ; 
	FOR(i,3,n+1) {
		while(m >= 2 && ccw(H[m-1],H[m],P[i]) <= 0) m-- ;
		H[++m] = P[i] ; 
	}
}

void solve() {
	build_Convex() ; 
	int ans = 0 ; 
	cout << m ;
	/*m-- ;
	FOR(i,1,m-3) {
		int l = i + 1 , r = i + 3 ; 
		FOR(j,i+2,m-2) {
			while(l <= j - 1 && dttg(H[i],H[l],H[j]) <= dttg(H[i],H[l+1],H[j]) ) l++ ; 
			while(r <= m && dttg(H[j],H[i],H[r]) <= dttg(H[j],H[i],H[r+1]) ) r++ ; 
			maxi(ans,dttg(H[i],H[l],H[j]) + dttg(H[j],H[i],H[r])) ; 
		}
	}*/
	cout << setprecision(1) << fixed << (double) ans / 2 ;  
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */
