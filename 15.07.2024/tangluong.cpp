#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC

const int maxn = 1e5 + 5 ;

int n,m,q ;
vector<int> g[maxn] ;
struct QUERIES1 {
    int u,w ;
}Q1[maxn] ;
struct QUERIES2 {
    int l,r,u,id ;
}Q2[maxn] ;

void init(void) {
    cin >> n >> m >> q ;
    FOR(i,2,n) {
        int p ; cin >> p ;
        g[p].pb(i) ; g[i].pb(p) ;
    }
    FOR(i,1,m) cin >> Q1[i].u >> Q1[i].w ;
    FOR(i,1,q) {
        cin >> Q2[i].l >> Q2[i].r >> Q2[i].u ;
        Q2[i].id = i ;
    }
}

bool CheckSub1() {
    FOR(i,1,q) if(Q2[i].l!=1 or Q2[i].r!=m) return 0 ;
    return 1 ;
}
namespace sub1 {

    int pos[maxn],in[maxn],out[maxn] ;
    int timeDFS = 0 ;
    ll st[4*maxn],lazy[4*maxn] ;

    void dfs(int u,int par) {
        in[u] = ++timeDFS ;
        for(auto v : g[u]) {
            if(v==par) continue ;
            dfs(v,u) ;
        }
        out[u] = timeDFS ;
    }

    void down(int id,int l,int r) {
        if(lazy[id]==0) return ;
        int mid = (l+r)>>1 ;

        st[id<<1]+= (mid-l+1)*lazy[id] ;
        st[id<<1|1]+= (r-mid)*lazy[id] ;

        lazy[id<<1]+=lazy[id] ;
        lazy[id<<1|1]+=lazy[id] ;

        lazy[id] = 0 ;
    }

    void update(int id,int l,int r,int u,int v,ll val) {
        if(l > v or r < u) return ;
        if(l >= u and r <= v) {
            st[id]+=(r-l+1)*val ;
            lazy[id]+=val ;
            return ;
        }
        int mid = (l+r)>>1 ;
        down(id,l,r) ;
        update(id<<1,l,mid,u,v,val) ;
        update(id<<1|1,mid+1,r,u,v,val) ;
        st[id] = st[id<<1] + st[id<<1|1] ;
    }

    ll get(int id,int l,int r,int u,int v) {
        if(l > v or r < u) return 0 ;
        if(l >= u and r <= v) return st[id] ;
        int mid = (l+r)>>1 ;
        down(id,l,r) ;
        return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
    }

    void solve(void) {
        dfs(1,1) ;
        FOR(i,1,m) {
            int u = Q1[i].u ; int w = Q1[i].w ;
            update(1,1,n,in[u],out[u],w) ;
        }
        FOR(i,1,q) {
            int u = Q2[i].u ;
            cout << get(1,1,n,in[u],in[u]) << '\n' ;
        }
    }
}

bool CheckSub2() {
    return n <= 500 and m <= 500 and q <= 500 ;
}

namespace sub2 {

    int pos[maxn],in[maxn],out[maxn] ;
    int timeDFS = 0 ;
    ll st[4*maxn],lazy[4*maxn] ;

    void dfs(int u,int par) {
        in[u] = ++timeDFS ;
        for(auto v : g[u]) {
            if(v==par) continue ;
            dfs(v,u) ;
        }
        out[u] = timeDFS ;
    }

    void down(int id,int l,int r) {
        if(lazy[id]==0) return ;
        int mid = (l+r)>>1 ;

        st[id<<1]+= (mid-l+1)*lazy[id] ;
        st[id<<1|1]+= (r-mid)*lazy[id] ;

        lazy[id<<1]+=lazy[id] ;
        lazy[id<<1|1]+=lazy[id] ;

        lazy[id] = 0 ;
    }

    void update(int id,int l,int r,int u,int v,ll val) {
        if(l > v or r < u) return ;
        if(l >= u and r <= v) {
            st[id]+=(r-l+1)*val ;
            lazy[id]+=val ;
            return ;
        }
        int mid = (l+r)>>1 ;
        down(id,l,r) ;
        update(id<<1,l,mid,u,v,val) ;
        update(id<<1|1,mid+1,r,u,v,val) ;
        st[id] = st[id<<1] + st[id<<1|1] ;
    }

    ll get(int id,int l,int r,int u,int v) {
        if(l > v or r < u) return 0 ;
        if(l >= u and r <= v) return st[id] ;
        int mid = (l+r)>>1 ;
        down(id,l,r) ;
        return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
    }

    void solve(void) {

        dfs(1,1) ;

        FOR(i,1,q) {
            int l = Q2[i].l ; int r = Q2[i].r ; int u = Q2[i].u ;
            FOR(i,1,4*n) st[i] = lazy[i] = 0 ;
            FOR(j,l,r) {
                int p = Q1[j].u ;
                int w = Q1[j].w ;
                update(1,1,n,in[p],out[p],w) ;
            }
            cout << get(1,1,n,in[u],in[u]) << '\n' ;
        }

    }
}

bool CheckSub3() {
    return n <= 5000 and m <= 5000 and q <= 5000 ;
}

namespace sub3 {

    int pos[maxn],in[maxn],out[maxn] ;
    int timeDFS = 0,S,itL,itR ;
    ll st[4*maxn],lazy[4*maxn],ans[maxn] ;

    void dfs(int u,int par) {
        in[u] = ++timeDFS ;
        for(auto v : g[u]) {
            if(v==par) continue ;
            dfs(v,u) ;
        }
        out[u] = timeDFS ;
    }

    void down(int id,int l,int r) {
        if(lazy[id]==0) return ;
        int mid = (l+r)>>1 ;

        st[id<<1]+= (mid-l+1)*lazy[id] ;
        st[id<<1|1]+= (r-mid)*lazy[id] ;

        lazy[id<<1]+=lazy[id] ;
        lazy[id<<1|1]+=lazy[id] ;

        lazy[id] = 0 ;
    }

    void update(int id,int l,int r,int u,int v,ll val) {
        if(l > v or r < u) return ;
        if(l >= u and r <= v) {
            st[id]+=(r-l+1)*val ;
            lazy[id]+=val ;
            return ;
        }
        int mid = (l+r)>>1 ;
        down(id,l,r) ;
        update(id<<1,l,mid,u,v,val) ;
        update(id<<1|1,mid+1,r,u,v,val) ;
        st[id] = st[id<<1] + st[id<<1|1] ;
    }

    ll get(int id,int l,int r,int u,int v) {
        if(l > v or r < u) return 0 ;
        if(l >= u and r <= v) return st[id] ;
        int mid = (l+r)>>1 ;
        down(id,l,r) ;
        return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
    }

    void MO(int id) {

        while(itL < Q2[id].l) {
            int u = Q1[itL].u ; int w = Q1[itL].w ;
            update(1,1,n,in[u],out[u],-w) ;
            itL++ ;
        }

        while(itL > Q2[id].l) {
            itL-- ;
            int u = Q1[itL].u ; int w = Q1[itL].w ;
            update(1,1,n,in[u],out[u],w) ;
        }

        while(itR < Q2[id].r) {
            itR++ ;
            int u = Q1[itR].u ; int w = Q1[itR].w ;
            update(1,1,n,in[u],out[u],w) ;
        }

        while(itR > Q2[id].r) {
            int u = Q1[itR].u ; int w = Q1[itR].w ;
            update(1,1,n,in[u],out[u],-w) ;
            itR-- ;
        }

    }

    void solve(void) {

        dfs(1,1) ;

        S = sqrt(n) ;

        sort(Q2+1,Q2+1+q,[](QUERIES2 u ,QUERIES2 v) {
            if(u.l/S==v.l/S) return u.r < v.r ;
            else return u.l < v.l ;
        }) ;

        FOR(i,1,q) {
            MO(i) ;
            int u = Q2[i].u ;
            ans[Q2[i].id] = get(1,1,n,in[u],in[u]) ;
        }

        FOR(i,1,q) cout << ans[i] << '\n' ;
    }

}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    init() ;
    if(CheckSub1())sub1::solve() ;
    else if(CheckSub2()) sub2::solve() ;
    else sub3::solve() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ;
}

