// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
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

const int MAXN = 1e5 + 5 ;

int n , m ;
struct DL {
	int x , y , w , t ;
} a[MAXN] ;
struct Queries {
	int u , v , id , t ; 
} Q[MAXN] ;
vi id[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,n)cin>>a[i].x>>a[i].y>>a[i].w ;
	FOR(i,1,n) {
		if(a[i].x>a[i].y) a[i].t = 1 , swap(a[i].x,a[i].y) ;
	}
	FOR(i,1,n) id[a[i].t].pb(i) ;
	FOR(i,1,m) {
		int u,v;
		cin>>u>>v;
		bool dir = (u>v) ;
		if(u>v)swap(u,v) ;
		Q[i] = {u,v,i,dir} ;
	}
}

namespace subtask_1 {
	void solve() {
		FOR(i,1,m) {
			int u = Q[i].u , v = Q[i].v , dir = Q[i].t ;
			int ans = v - u ;
			for(auto id : id[dir]) {
				int i = id ;
				if(a[i].x<=u&&a[i].y>=u&&a[i].y<=v) mini(ans,u-a[i].x+a[i].w+v-a[i].y) ;
				if(a[i].x>=u&&a[i].x<=v&&a[i].y>=v) mini(ans,a[i].x-u+a[i].w+a[i].y-v) ; 
				if(a[i].x>=u&&a[i].y<=v) mini(ans,a[i].x-u+a[i].w+v-a[i].y) ; 
				if(a[i].x<=u&&a[i].y>=v) mini(ans,u-a[i].x+a[i].w+a[i].y-v) ;
			}
			cout << ans << '\n' ; 
		}	
	}
}

namespace subtask_2 {

	struct BG {
		int x , y , w , id , t ; 
	} seg[2 * MAXN] ;
	int sz = 0 ;

	unordered_map<int,int> pos ; 
	int ans[MAXN] ;
	int VAL ;

	void Compress() {
		vi V ; 
		FOR(i,1,sz) {
			V.pb(seg[i].x) ;
			V.pb(seg[i].y) ;
		} 
		sort(all(V)) ;
		V.resize(unique(all(V))-V.begin()) ;
		VAL = V.size() ;
		FOR(i,0,V.size()-1)pos[V[i]]=i+1 ;
	}

	struct SegmentTree {
		int st[8*MAXN][2][2] ;
		void update(int id,int l,int r,int pos,int val,int t1,int t2) {
			if(pos<l||pos>r)return ;
			if(l==r) {
				st[id][t1][t2] = min(st[id][t1][t2],val) ;
				return ; 
			}
			int mid = (l+r)/2 ; 
			update(id<<1,l,mid,pos,val,t1,t2) ; 
			update(id<<1|1,mid+1,r,pos,val,t1,t2) ; 
			st[id][t1][t2] = min(st[id<<1][t1][t2],st[id<<1|1][t1][t2]) ; 
		}
		int get(int id,int l,int r,int u,int v,int t1,int t2) {
			if(l > v || r < u) return 2e9 ; 
			if(l >= u && r <= v) return st[id][t1][t2] ; 
			int mid = (l+r)/2 ; 
			return min(get(id<<1,l,mid,u,v,t1,t2),get(id<<1|1,mid+1,r,u,v,t1,t2)) ; 
		}
		void reset() {
			FOR(i,1,4*VAL)FOR(t1,0,1)FOR(t2,0,1) st[i][t1][t2] = 2e9 ;
		}
	} st ; 

	void solve() {
		FOR(i,1,n) {
			sz++ ;
			seg[sz].x = a[i].x ;
			seg[sz].y = a[i].y ; 
			seg[sz].w = a[i].w ; 
			seg[sz].id = 0 ;
			seg[sz].t = a[i].t ; 
		}
		FOR(i,1,m) {
			sz++ ; 
			seg[sz].x = Q[i].u ; 
			seg[sz].y = Q[i].v ; 
			seg[sz].id = i ; 
			seg[sz].t = Q[i].t ; 
		}


		FOR(i,1,m) ans[i] = Q[i].v - Q[i].u ;

		sort(seg+1,seg+1+sz,[](BG u,BG v) {
			return u.x < v.x ;  
		}) ; 	

		Compress() ;

		st.reset() ;

		FOR(i,1,sz) {
			if(seg[i].id > 0) {
				int dir = seg[i].t ;
				int id = seg[i].id ; 
				mini(ans[id], st.get(1,1,VAL,pos[seg[i].y],VAL,dir,0) + seg[i].x - seg[i].y) ; 
				mini(ans[id], st.get(1,1,VAL,1,pos[seg[i].y],dir,1) + seg[i].x + seg[i].y) ;
			} else {
				int dir = seg[i].t ; 
				st.update(1,1,VAL,pos[seg[i].y],-seg[i].x+seg[i].w+seg[i].y,dir,0) ;
				st.update(1,1,VAL,pos[seg[i].y],-seg[i].x+seg[i].w-seg[i].y,dir,1) ;
			}	
		}

		sort(seg+1,seg+1+sz,[](BG u,BG v) {
			return u.x > v.x ;  
		}) ; 

		st.reset() ;

		FOR(i,1,sz) {
			if(seg[i].id > 0) {
				int dir = seg[i].t ;
				int id = seg[i].id ; 
				mini(ans[id], st.get(1,1,VAL,pos[seg[i].y],VAL,dir,0) - seg[i].x - seg[i].y) ; 
				mini(ans[id], st.get(1,1,VAL,1,pos[seg[i].y],dir,1) - seg[i].x + seg[i].y) ;
			} else {
				int dir = seg[i].t ; 
				st.update(1,1,VAL,pos[seg[i].y],seg[i].x+seg[i].w+seg[i].y,dir,0) ;
				st.update(1,1,VAL,pos[seg[i].y],seg[i].x+seg[i].w-seg[i].y,dir,1) ;
			}	
		}

		FOR(i,1,m) cout << ans[i] << '\n' ;
	}	

}

signed main() {
    #define task "wshipper"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    subtask_1::solve() ;
  ///  cout << endl ;
  //  subtask_2::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */