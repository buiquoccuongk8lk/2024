/* 29 . 03 . 2008 */
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
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
#define uni(a) sort(all(a)), a.resize(unique(all(a))-a.begin())
#define MASK(a) (1ll << a)

int gcd(int x, int y) {return __gcd(x, y) ;}
int lg(int x) {return __lg(x) ;}
int lcm(int x, int y) {return x / __gcd(x, y) * y ;}

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 2e5 + 5, M = 5e3 + 5, LG = __lg(N) + 1, base = 311 ;
const int oo = 2e9, sm = 1e9 + 7, mod1 = 1e9 + 7, mod2 = 1e9 + 3 ;
const long long inf = 1e18 ;

int n, q ;
ll a[N] ;
vi g[N] ;

struct Queries {
    int t, u, v ;
    ll x ;
} Q[N] ;

void init() {
    cin >> n >> q ;
    FOR(i, 1, n) cin >> a[i] ;
    FOR(i, 1, n - 1) {
        int u, v ; cin >> u >> v ;
        g[u].push_back(v) ; g[v].push_back(u) ;
    }
    FOR(i, 1, q) {
        cin >> Q[i].t ;
        if(Q[i].t == 1) {
            cin >> Q[i].u ;
        }
        if(Q[i].t == 2) {
            cin >> Q[i].u >> Q[i].v >> Q[i].x ;
        }
        if(Q[i].t == 3) {
            cin >> Q[i].u ;
        }
    }
}

namespace subtask_1 {
    bool check() {return n <= 5e3 && q <= 5e3;}

    int par[N], cur_par[N] ;

    void dfs(int u) {
        for(int v : g[u]) {
            if(v == par[u]) continue ;
            par[v] = u ;
            dfs(v) ;
        }
    }

    int root = 1 ;

    void change_root(int u) {
        int cur = u ;

        vector <int> List ;

        while(1) {
            List.push_back(cur) ;
            if(cur == root) break ;
            int v = par[cur] ;
            cur_par[v] = cur ;
            cur = v ;
        }

        for(int x : List) par[x] = cur_par[x] ;

        par[u] = 0 ;
        root = u ;
    }

    void dfsUp(int u, ll x) {
        a[u]+= x ;
        for(int v : g[u]) {
            if(v == par[u]) continue ;
            dfsUp(v, x) ;
        }
    }

    void update(int u, int v, ll x) {
        vector <int> mark(n + 2, 0) ;

        int cur_u = u, cur_v = v ;

        for(cur_u; cur_u; cur_u = par[cur_u]) {
            mark[cur_u] = 1 ;
        }

        int p = - 1 ;

        for(cur_v; cur_v; cur_v = par[cur_v]) {
            if(mark[cur_v]) {
                p = cur_v ;
                break ;
            }
        }

        dfsUp(p, x) ;
    }

    ll res = 0 ;

    void dfsGet(int u) {
        res+= a[u] ;
        for(int v : g[u]) {
            if(v == par[u]) continue ;
            dfsGet(v) ;
        }
    }

    ll get(int u) {
        res = 0 ;
        dfsGet(u) ;
        return res ;
    }

    void solve() {
        dfs(1) ;
        root = 1 ;

        FOR(i, 1, q) {
            int t = Q[i].t ;
            if(t == 1) {
                change_root(Q[i].u) ;
            }
            if(t == 2) {
                update(Q[i].u, Q[i].v, Q[i].x) ;
            }
            if(t == 3) {
                cout << get(Q[i].u) << endl ;
            }
        }
    }
}

namespace subtask_2 {
    bool check() {FOR(i, 1, q) if(Q[i].t==1)return 0; return 1;}
    int in[N], out[N], timeDFS, arr[N] ;

    void dfs(int u, int p) {
        in[u] = ++ timeDFS ;
        arr[in[u]] = u ;
        for(int v : g[u]) {
            if(v == p) continue ;
            dfs(v, u) ;
        }
        out[u] = timeDFS ;
    }

    struct SegmentTree {
        ll lazy[4 * N], st[4 * N] ;

        void build(int id, int l, int r) {
            if(l == r) {
                st[id] = a[arr[l]] ;
                return ;
            }
            int mid = (l + r) >> 1 ;
            build(id << 1, l, mid) ;
            build(id << 1 | 1, mid + 1, r) ;
            st[id] = st[id << 1] + st[id << 1 | 1] ;
        }

        void down(int id, int l, int r) {
            if(lazy[id] == 0) return ;

            int mid = (l + r) >> 1 ;

            st[id << 1]+= 1ll * (mid - l + 1) * lazy[id] ;
            st[id << 1 | 1]+= 1ll * (r - mid) * lazy[id] ;

            lazy[id << 1] += lazy[id] ;
            lazy[id << 1 | 1] += lazy[id] ;

            lazy[id] = 0 ;
        }

        void update(int u, int v, ll val, int id = 1, int l = 1, int r = n) {
            if(l > v || r < u) return ;
            if(l >= u && r <= v) {
                st[id]+= 1ll * (r - l + 1) * val ;
                lazy[id]+= val ;
                return ;
            }
            int mid = (l + r) >> 1 ;
            down(id, l, r) ;
            update(u, v, val, id << 1, l, mid) ;
            update(u, v, val, id << 1 | 1, mid + 1, r) ;
            st[id] = st[id << 1] + st[id << 1 | 1] ;
        }

        ll get(int id, int l, int r, int u, int v) {
            if(l > v || r < u) return 0 ;
            if(l >= u && r <= v) return st[id] ;
            down(id, l, r) ;
            int mid = (l + r) >> 1 ;
            return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v) ;
        }
    } st ;

    struct LowestCommonAncestor {
        int P[N][LG], h[N] ;

        void dfs(int u) {
            for(int v : g[u]) {
                if(v == P[u][0]) continue ;
                P[v][0] = u ;
                h[v] = h[u] + 1 ;
                dfs(v) ;
            }
        }

        int find(int u, int v) {
            if(h[u] < h[v]) swap(u, v) ;
            int z = __lg(h[u]) ;
            FORD(s, z, 0) if((h[u] - h[v]) >= (1 << s)) u = P[u][s] ;
            if(u == v) return u ;
            FORD(s, z, 0) if(P[u][s] != P[v][s]) {
                u = P[u][s] ;
                v = P[v][s] ;
            }
            return P[u][0] ;
        }

        void init() {
            dfs(1) ;
            for(int j = 1; (1 << j) <= n; j++) FOR(i, 1, n)
                P[i][j] = P[P[i][j - 1]][j - 1] ;
        }
    } lca ;

    void solve() {
        dfs(1, 1) ;
        st.build(1, 1, n) ;
        lca.init() ;

        FOR(i, 1, q) {
            if(Q[i].t == 2) {
                int p = lca.find(Q[i].u, Q[i].v) ;
                st.update(in[p], out[p], Q[i].x) ;
            } else {
                cout << st.get(1, 1, n, in[Q[i].u], out[Q[i].u]) << endl ;
            }
        }
    }
}

namespace subtask_3 {
    bool check() {return 1;}

    void solve() {

    }
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;cout.tie(0) ;
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ;
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    init() ;
//    if(subtask_1::check()) return subtask_1::solve(), 0 ;
//    if(subtask_2::check()) return subtask_2::solve(), 0 ;
    if(subtask_3::check()) return subtask_3::solve(), 0 ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
/* Watbor */

/*
4 6
4 3 5 6
1 2
2 3
3 4
3 1
1 3
2 2 4 3
1 1
2 2 4 -3
3 1
*/
