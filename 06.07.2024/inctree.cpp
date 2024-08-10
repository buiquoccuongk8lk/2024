#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC

const int maxn = 1e5 + 5 ;
const int LO = __lg(maxn) + 1 ;

int n,m,q ;
vector<int> G[maxn] ;
int h[maxn],sz[maxn],cur[maxn],pos[maxn],par[maxn],head[maxn],arr[maxn] ;
int timeDFS , crt ;
int P[maxn][LO] ;

void init(void) {
    cin >> n >> m >> q ;
    FOR(i,1,n-1) {
        int u,v ;
        cin >> u >> v ;
        G[u].pb(v) ;
        G[v].pb(u) ;
    }
}

void dfs(int u) {
    sz[u] = 1 ;
    for(auto v : G[u]) {
        if(v==par[u]) continue ;
        h[v] = h[u] + 1 ;
        P[v][0] = u ;
        par[v] = u ;
        dfs(v) ;
        sz[u]+=sz[v] ;
    }
}

void init_LCA(void) {
    for(int j(1) ; (1<<j) <= n ; j++) {
        FOR(i,1,n) {
            int x = P[i][j-1] ;
            P[i][j] = P[x][j-1] ;
        }
    }
}

int LCA(int u,int v) {
    if(h[u]<h[v]) swap(u,v) ;
    int z = __lg(h[u]) ;
    FORD(s,z,0) if( (h[u]-h[v]) >= (1<<s) ) {
        u = P[u][s] ;
    }
    if(u==v) return u ;
    FORD(s,z,0) if(P[u][s]!=P[v][s]) {
        u = P[u][s] ;
        v = P[v][s] ;
    }
    return P[u][0] ;
}

void dfs_hld(int u) {
    if(head[crt]==0) {
        head[crt] = u ;
    }
    pos[u] = ++timeDFS ;
    arr[pos[u]] = u ;
    cur[u] = crt ;
    int nxt = - 1 ;

    for(auto v : G[u]) {
        if(v==par[u]) continue ;
        if(nxt==-1 || sz[v] > sz[nxt]) nxt = v ;
    }

    if(nxt!=-1) dfs_hld(nxt) ;

    for(auto v : G[u]) {
        if(v==par[u] || v==nxt) continue ;
        crt++ ;
        dfs_hld(v) ;
    }

}

int st[4*maxn] , lazy[4*maxn] ;

void down(int id,int l,int r) {
    if(lazy[id]==0) return ;
    int mid = (l+r)>>1 ;

    st[id<<1]+=(mid-l+1)*lazy[id] ;
    st[id<<1|1]+=(r-mid)*lazy[id] ;

    lazy[id<<1]+=lazy[id] ;
    lazy[id<<1|1]+=lazy[id] ;

    lazy[id] = 0 ;
}

void update(int id,int l,int r,int u,int v,int val) {
    if(l > v or r < u) return ;
    if(l >= u and r <= v) {
        st[id]+= (r-l+1)*val ;
        return ;
    }
    int mid = (l+r)>>1 ;
    down(id,l,r) ;
    update(id<<1,l,mid,u,v,val) ;
    update(id<<1|1,mid+1,r,u,v,val) ;
    st[id] = st[id<<1] + st[id<<1|1] ;
}

int get(int id,int l,int r,int u,int v) {
    if(l > v or r < u) return 0 ;
    if(l >= u and r <= v) return st[id] ;
    int mid = (l+r)>>1 ;
    down(id,l,r) ;
    return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
}

void up(int u,int v,int val) {
    while(cur[u]!=cur[v]) {
        if(cur[u] > cur[v]) {
            update(1,1,n,head[cur[u]],pos[u],val) ;
            u = par[head[cur[u]]] ;
        } else {
            update(1,1,n,head[cur[v]],pos[v],val) ;
            v = par[head[cur[v]]] ;
        }
    }
    if(pos[u]>pos[v]) {
        update(1,1,n,pos[v] + 1 , pos[u],val) ;
    } else if(pos[v] > pos[u]) {
        update(1,1,n,pos[u] + 1 , pos[v],val) ;
    }
}

int qry(int u,int v) {
    int ret = 0 ;
    while(cur[u]!=cur[v]) {
        if(cur[u] > cur[v]) {
            ret+= get(1,1,n,head[cur[u]],pos[u]) ;
            u = par[head[cur[u]]] ;
        } else {
            ret+= get(1,1,n,head[cur[v]],pos[v]) ;
            v = par[head[cur[v]]] ;
        }
    }
    if(pos[u] > pos[v]) {
        ret+= get(1,1,n,pos[v]+1,pos[u]) ;
    } else if(pos[v] > pos[u]) {
        ret+= get(1,1,n,pos[u]+1,pos[v]) ;
    }
}

void solve(int a,int b,int c,int d) {
    if(h[a]>h[b]) swap(a,b) ;
    if(h[c]>h[d]) swap(c,d) ;

    if( LCA(d,a) == d ) {
        up(a,b,1) ;
    } else if( LCA(c,b) == b ) {
        up(a,b,1) ;
    } else if( LCA(a,c)==a and LCA(c,b)==c and LCA(b,d)==b ) {
        up(a,c,1) ;
    } else if( LCA(c,a)==c and LCA(a,d)==a and LCA(d,b)==d ) {
        up(d,b,1) ;
    } else if( LCA(a,c)==a and LCA(c,d)==c and LCA(d,b)==b ) {
        up(a,c,1) ;
        up(d,b,1) ;
    } else if( LCA(c,a)==a and LCA(b,c)==c and LCA(a,d)==a ) {
        up(a,d,1) ;
    } else if( LCA(d,a)==a and LCA(b,d)==d and LCA(c,a)==a ) {
        up(a,c,1) ;
    } else if( LCA(c,a)==c and LCA(a,d)==a and LCA(b,c)==c ) {
        up(b,c,1) ;
    } else if( LCA(b,c)==c and LCA(b,d)==b and LCA(a,c)==c ) {
        up(c,a,1) ;
    } else if( LCA(a,c)!=c and LCA(a,c)!=a ) {
        up(a,b,1) ;
    } else if( LCA(a,c)==a and LCA(b,d)==b ) {
        up(a,b,1) ;
    } else if( LCA(c,a)==c and LCA(d,b)==d ) {
        up(c,a,1) ;
        up(b,d,1) ;
    } else if( LCA(a,d)==a and LCA(c,b)==c ) {
        up(a,d,1) ;
        up(c,b,1) ;
    } else if( LCA(a,d)==a and LCA(c,b)== c ) {
        up(a,d,1) ;
        up(c,b,1) ;
    } else if( LCA(a,c)==c and LCA(b,d)== b ) {
        up(a,c,1) ;
    }
}

void process(void) {
    dfs(1) ;
    //ok
    init_LCA() ;
    //ok
    dfs_hld(1) ;
    //ok
    while(m--) {
        int a,b,c,d ;
        cin >> a >> b >> c >> d ;
        solve(a,b,c,d) ;
    }
    while(q--) {
        int u ,v ;
        cin >> u >> v ;
        cout << qry(u,v) << endl ;
    }
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; process() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ;
}
