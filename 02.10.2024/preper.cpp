/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 1e5 + 5 ;
const int LO = __lg(N) + 2 ;

int n , q ;
int a[N] , b[N] ;
struct Queries {
	int x , y , u , v , l , r ;
	int id ; 
} Q[N] ;

void init() {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ;
	FOR(i,1,n) cin >> b[i] ; 
	FOR(i,1,q) {
		cin >> Q[i].x >> Q[i].y >> Q[i].u >> Q[i].v ; 
		Q[i].id = i ;
	}
}

namespace subtask_1 {
	bool check() {
		return n <= 5e3 && q <= 5e3 ; 
	}

	int cnt[N] ;

	void solve() {
		FOR(t,1,q) {
			int x = Q[t].x ; int y = Q[t].y ; int u = Q[t].u ; int v = Q[t].v ; 
			FOR(i,x,y) cnt[a[i]]++ ; 
			FOR(i,u,v) cnt[b[i]]++ ;
			int ans = 0 ;
			FOR(i,1,n) if(cnt[i]==2) ans++ ; 
			cout << ans << endl ; 
			FOR(i,1,n) cnt[i] = 0 ;
		}
	}
}

namespace subtask_2 {
	bool check() {
		FOR(i,1,q) if(Q[i].x!=Q[i].u || Q[i].y!=Q[i].v) return 0 ;
		return 1 ; 
	}
	int sqrtN , l , r , res ;
	int ans[N] , cnt[N] ; 
		
	void MO(int id) {
		while(l < Q[id].l) {
			cnt[a[l]]-- ; 
			cnt[b[l]]-- ; 
			if(a[l]==b[l] && cnt[a[l]] == 0) res-- ;
			else {
				if(cnt[a[l]] == 1) res-- ; 
				if(cnt[b[l]] == 1) res-- ; 
			}
			l++ ; 
		}
		while(l > Q[id].l) {
			l-- ; 
			cnt[a[l]]++ ; 
			cnt[b[l]]++ ; 
			if(a[l]==b[l] && cnt[a[l]]==2) res++ ; 
			else {
				if(cnt[a[l]]==2) res++ ; 
				if(cnt[b[l]]==2) res++ ;
			} 
		}
		while(r < Q[id].r) {
			r++ ; 
			cnt[a[r]]++ ; 
			cnt[b[r]]++ ; 
			if(a[r]==b[r] && cnt[a[r]]==2) res++ ; 
			else {
				if(cnt[a[r]]==2) res++ ; 
				if(cnt[b[r]]==2) res++ ;
			} 
		}
		while(r > Q[id].r) {
			cnt[a[r]]-- ;
			cnt[b[r]]-- ; 
			if(a[r]==b[r] && cnt[a[r]] == 0) res-- ; 
			else {
				if(cnt[a[r]] == 1) res-- ; 
				if(cnt[b[r]] == 1) res-- ; 
			}
			r-- ;
		}
		ans[Q[id].id] = res ; 
		cout << endl ;
	}

	void solve() {
		FOR(i,1,q) {
			Q[i].l = Q[i].u , Q[i].r = Q[i].v ;
		}
		sqrtN = sqrt(n) ; 
		sort(Q+1,Q+1+q,[](Queries X,Queries Y) {
			if(X.u/sqrtN==Y.u/sqrtN) return X.v < Y.v ; 
			else return X.u < Y.u ; 
		}) ; 
		l = 1 , r = 0 ; 
		FOR(i,1,q) MO(i) ; 
		FOR(i,1,q) cout << ans[i] << endl ;
	}
}

namespace subtask_3 {
	bool check() {
		return 1 ; 
	}

	struct PersistentSegTree {
		int H[N] ; 
		int L[N*LO + 2] ; 
		int R[N*LO + 2] ; 
		int st[N * LO + 2] ; 
		int node ;

		int up(int old,int l,int r,int pos,int val) {
			int cur = ++ node ;
			if(l == r) {
				st[cur] = st[old] + val ; 
				return cur ; 
			} 
			int mid = (l+r)>>1 ; 
			if(pos <= mid) {
				R[cur] = R[old] ; 
				L[cur] = up(L[old],l,mid,pos,val) ; 
			} else {
				L[cur] = L[old] ; 
				R[cur] = up(R[old],mid+1,r,pos,val) ; 
			}
			st[cur] = st[L[cur]] + st[R[cur]] ; 
			return cur ; 
		}

		int get(int id,int l,int r,int u,int v) {
			if(l > v || r < u) return 0 ;
			if(l >= u && r <= v) return st[id] ; 
			int mid = (l+r)>>1 ; 
			return get(L[id],l,mid,u,v) + get(R[id],mid+1,r,u,v) ; 
		}
	} PST ; 	
	int pos[N] ; 

	void solve() {	
		FOR(i,1,n) pos[b[i]] = i ; 
		FOR(i,1,n) {
			PST.H[i] = PST.up(PST.H[i-1],1,n,pos[a[i]],1) ;
		}
		FOR(i,1,q) {
			int x = Q[i].x , y = Q[i].y , u = Q[i].u , v = Q[i].v ; 
			cout << PST.get(PST.H[y],1,n,u,v) - PST.get(PST.H[x-1],1,n,u,v) << endl ;
		}
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    if(subtask_1::check()) return subtask_1::solve(),0 ;
    if(subtask_2::check()) return subtask_2::solve(),0 ; 
    if(subtask_3::check()) return subtask_3::solve(),0 ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */