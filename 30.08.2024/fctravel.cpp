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

int n , q ;
vi g[MAXN] ;
int a[MAXN] ;
ii e[MAXN] ;

void init() {
    cin >> n >> q ; 
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,n-1) {
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
        e[i]={u,v} ;
    }
}

struct HLD {
    int sz[MAXN] , par[MAXN] , cur[MAXN] , head[MAXN] , arr[MAXN] , pos[MAXN] , val[MAXN] , h[MAXN] ;
    int crt , timeDFS ; 
    void dfs_sz(int u) {
        sz[u] = 1 ;
        for(auto v : g[u]) if(v!=par[u]) {
            par[v] = u ;
            h[v] = h[u]+1 ; 
            dfs_sz(v) ;
            sz[u]+= sz[v] ;  
        }
    }
    void dfs_hld(int u) {
        if(head[crt]==0)head[crt]=u ;
        cur[u] = crt ; 
        pos[u] = ++timeDFS ; 
        arr[pos[u]] = u ; 

        int nxt = -1 ; 
        for(auto v : g[u]) {
            if(v==par[u])continue ;
            if(nxt==-1||sz[v]>sz[nxt])nxt=v ; 
        }

        if(nxt!=-1)dfs_hld(nxt) ;

        for(auto v : g[u]) {
            if(v==par[u]||v==nxt)continue ;
            ++crt ; 
            dfs_hld(v) ; 
        } 
    }   

    int st[4*MAXN] , lazy[4*MAXN] ;

    void build(int id,int l,int r) {
        if(l==r) {
            st[id] = val[arr[l]] ; 
            return ; 
        }
        int mid = (l+r)/2 ; 
        build(id<<1,l,mid) ;
        build(id<<1|1,mid+1,r) ;
        st[id] = st[id<<1]+st[id<<1|1] ; 
    }

    void down(int id,int l,int r) {
        if(lazy[id]==-1e18) return ; 

        int mid = (l+r)/2 ; 

        st[id<<1] = (mid-l+1)*lazy[id] ; 
        st[id<<1|1] = (r-mid)*lazy[id] ; 

        lazy[id<<1] = lazy[id] ; 
        lazy[id<<1|1] = lazy[id] ; 

        lazy[id] = -1e18 ; 
    }

    void update(int id,int l,int r,int u,int v,int val) {
        if(l>v||r<u)return ;
        if(l>=u&&r<=v) {
            st[id] = (r-l+1)*val ; 
            lazy[id] = val ; 
            return ; 
        }
        int mid=(l+r)/2 ;
        down(id,l,r) ;
        update(id<<1,l,mid,u,v,val) ; 
        update(id<<1|1,mid+1,r,u,v,val) ; 
        st[id] = st[id<<1]+st[id<<1|1] ;
    }

    int get(int id,int l,int r,int u,int v) {
        if(l>v||r<u)return 0;
        if(l>=u&&r<=v)return st[id] ; 
        down(id,l,r) ; 
        int mid=(l+r)/2 ; 
        return get(id<<1,l,mid,u,v)+get(id<<1|1,mid+1,r,u,v) ;
    }

    int lca(int u,int v) {
        while(cur[u]!=cur[v]) {
            if(cur[u]>cur[v]) u=par[head[cur[u]]] ; 
            else v=par[head[cur[v]]] ; 
        }
        if(h[u]<h[v])return u ;
        else return v ; 
    }

    void upqry(int u,int v,int val) {
        int p = lca(u,v) ; 
        while(cur[u]!=cur[p]) {
            update(1,1,n,pos[head[cur[u]]],pos[u],val) ;
            u = par[head[cur[u]]] ; 
        }
        while(cur[v]!=cur[p]) {
            update(1,1,n,pos[head[cur[v]]],pos[v],val) ; 
            v = par[head[cur[v]]] ; 
        }
        if(pos[u]>pos[v]) update(1,1,n,pos[v]+1,pos[u],val) ; 
        else if(pos[v]>pos[u]) update(1,1,n,pos[u]+1,pos[v],val) ; 
    }

    int getqry(int u,int v) {
        int ans = 0 ; 
        int p = lca(u,v) ; 
        while(cur[u]!=cur[p]) {
            ans+= get(1,1,n,pos[head[cur[u]]],pos[u]) ;
            u = par[head[cur[u]]] ; 
        }
        while(cur[v]!=cur[p]) {
            ans+= get(1,1,n,pos[head[cur[v]]],pos[v]) ; 
            v = par[head[cur[v]]] ; 
        }
        if(pos[u]>pos[v]) ans+= get(1,1,n,pos[v]+1,pos[u]) ; 
        else if(pos[v]>pos[u]) ans+= get(1,1,n,pos[u]+1,pos[v]) ; 
        return ans ;
    }

    void init() {
        dfs_sz(1) ; 
        dfs_hld(1) ;
        FOR(i,1,n-1) {
            int u=e[i].fi,v=e[i].se ; 
            if(u==par[v])val[v] = max(abs(a[u]+a[v]),abs(a[u]-a[v])) ; 
            else val[u] = max(abs(a[u]+a[v]),abs(a[u]-a[v])) ; 
        }
        FOR(i,1,4*n)lazy[i]=-1e18 ;
        build(1,1,n) ;
    }
} hld ;

void solve() {
    hld.init() ;
    while(q--) {
        int t ; cin >> t ; 
        if(t==1) {
            int u , x ; cin >> u >> x ; 
            a[u] = x ; 
            for(auto v : g[u]) {
                hld.upqry(u,v,max(abs(a[u]+a[v]),abs(a[u]-a[v]))) ; 
            }
        }else {
            int u , v ; cin >> u >> v ; 
            cout << hld.getqry(u,v) << '\n' ; 
        }
    }
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