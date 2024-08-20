#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN (int)3e5+5

int n , q , m ;
struct Queries {
    int id , w ; 
} Q[MAXN] ; 
struct Edges {
    int u , v , w ; 
} e[MAXN] ;
vii g[MAXN] ;
int in[MAXN] , timeDFS ;
int h[MAXN] , ID[MAXN] , oldID[MAXN] , a[MAXN * 8] , h_cur[MAXN] , height[MAXN] ;
int fiID[MAXN] , laID[MAXN] , lastVAL[MAXN] ; 

void init() {
    cin >> n >> q ;
    FOR(i,1,n-1) {
        cin >> e[i].u >> e[i].v >> e[i].w ;
        g[e[i].u].pb({e[i].v,e[i].w}) ; 
        g[e[i].v].pb({e[i].u,e[i].w}) ; 
    }
    FOR(i,1,q) cin >> Q[i].id >> Q[i].w ; 
}

void euler(int u,int par) {
    in[u] = ++timeDFS ; 
    for(auto x : g[u]) {
        int v = x.fi , w = x.se ; 
        if(v==par) continue ; 
        euler(v,u) ;
    }
}

void dfs(int u,int par) {
    a[++m] = ID[u] ; 
    for(auto x : g[u]) {
        int v = x.fi , w = x.se ;
        if(v==par) continue ; 
        h_cur[v] = h_cur[u] + w ;
        height[v] = height[u] + 1 ;
        dfs(v,u) ;
        a[++m] = ID[u] ; 
    }
}

struct {
    struct Node {
        int f[3][3] ; 
    } st[10*MAXN] ; 
    int lazy[10*MAXN] ; 

    Node merge(Node a,Node b) {
        Node ans ;  
        FOR(i,0,2) FOR(j,0,2) ans.f[i][j] = max({a.f[i][j],b.f[i][j]}) ; 
        FOR(i,0,2) FOR(j,i,2) {
            FOR(k,i,j-1) {
                ans.f[i][j] = max(ans.f[i][j],a.f[i][k] + b.f[k+1][j]) ; 
            }
        }      
        return ans ; 
    }

    void build(int id,int l,int r) {
        if(l==r) {
            st[id].f[0][0] = h[l] ; 
            st[id].f[0][1] = h[l] - 2 * h[l] ; 
            st[id].f[0][2] = h[l] - 2 * h[l] + h[l] ; 
            st[id].f[1][1] = -2 * h[l] ; 
            st[id].f[1][2] = -2 * h[l] + h[l] ; 
            st[id].f[2][2] = h[l] ; 
            return ; 
        }
        int mid = (l+r)/2 ; 
        build(id<<1,l,mid) ; 
        build(id<<1|1,mid+1,r) ; 
        st[id] = merge(st[id<<1],st[id<<1|1]) ; 
    }

    void down(int id) {
        if(lazy[id]==0) return ; 
        int &val = lazy[id] ; 

        st[id<<1].f[0][0]+= val ; 
        st[id<<1].f[0][1]+= val - 2 * val ; 
        st[id<<1].f[0][2]+= val - 2 * val + val ; 
        st[id<<1].f[1][1]+= - 2 * val ; 
        st[id<<1].f[1][2]+= - 2 * val + val ; 
        st[id<<1].f[2][2]+= val ;
        lazy[id<<1]+= val ; 

        st[id<<1|1].f[0][0]+= val ; 
        st[id<<1|1].f[0][1]+= val - 2 * val ; 
        st[id<<1|1].f[0][2]+= val - 2 * val + val ; 
        st[id<<1|1].f[1][1]+= - 2 * val ; 
        st[id<<1|1].f[1][2]+= - 2 * val + val ; 
        st[id<<1|1].f[2][2]+= val ;
        lazy[id<<1|1]+= val ; 

        val = 0 ; 
    }

    void update(int id,int l,int r,int u,int v,int val) {
        if(l > v || r < u) return ; 
        if(l >= u && r <= v) {
            st[id].f[0][0]+= val ; 
            st[id].f[0][1]+= val - 2 * val ; 
            st[id].f[0][2]+= val - 2 * val + val ; 
            st[id].f[1][1]+= - 2 * val ; 
            st[id].f[1][2]+= - 2 * val + val ; 
            st[id].f[2][2]+= val ;
            lazy[id]+= val ; 
            return ; 
        } 
        int mid = (l+r)/2 ;
        down(id) ; 
        update(id<<1,l,mid,u,v,val) ; 
        update(id<<1|1,mid+1,r,u,v,val) ; 
        st[id] = merge(st[id<<1],st[id<<1|1]) ; 
    }

    int best(int id) {
        return st[id].f[0][2] ; 
    }
} IT ; 

void solve() {
    euler(1,1) ;
    vii cur_vec ;   
    FOR(i,1,n) cur_vec.pb({in[i],i}) ; 

    sort(all(cur_vec)) ; 
    FOR(i,0,cur_vec.size()-1) {
        ID[cur_vec[i].se] = i + 1 ;   
        oldID[i+1] = cur_vec[i].se ; 
    }

    m = 0 ;
    dfs(1,1) ;  
    FORD(i,m,1) fiID[a[i]] = i ; 
    FOR(i,1,m) laID[a[i]] = i ;  
    FOR(i,1,m) {
        h[i] = h_cur[oldID[a[i]]] ;    
    }

    IT.build(1,1,m) ;
    FOR(i,1,n-1) lastVAL[i] = e[i].w ; 
    FOR(i,1,q) {
        int u = e[Q[i].id].u , v = e[Q[i].id].v ; 
        int new_val = Q[i].w - lastVAL[Q[i].id] ; 
        lastVAL[Q[i].id] = Q[i].w ;  
        if(height[u] > height[v]) swap(u,v) ; 
        IT.update(1,1,m,fiID[ID[v]],laID[ID[v]],new_val) ;
        cout << IT.best(1) << '\n' ; 
    }       
}

signed main() {
    #define task "vtravel"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".ans","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}