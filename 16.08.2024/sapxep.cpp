#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)
template<class X,class Y> bool maxi(X &x,const Y &y) {if(x < y){x = y ; return 1;}else return 0;}
template<class X,class Y> bool mini(X &x,const Y &y) {if(x > y){x = y ; return 1;}else return 0;}
using namespace std ; 
#define MAXN 200005

int n ;
int a[MAXN] , pos[MAXN] , ans[MAXN] ;

void init() {
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ;
    FOR(i,1,n) pos[a[i]] = i ; 
}

struct SegmentTree {
    int lazy[4*MAXN] , st[4*MAXN] ;
    void down(int id) {
        if(lazy[id]==0) return ; 

        st[id<<1]+= lazy[id] ; 
        st[id<<1|1]+= lazy[id] ; 

        lazy[id<<1]+= lazy[id] ; 
        lazy[id<<1|1]+= lazy[id] ;

        lazy[id] = 0 ; 
    }
    void update(int id,int l,int r,int u,int v,int val) {
        if(l > v || r < u) return ; 
        if(l >= u && r <= v) {
            st[id]+= val ; 
            lazy[id]+= val ; 
            return ; 
        }
        int mid = (l+r)/2 ; 
        down(id) ;
        update(id<<1,l,mid,u,v,val) ;
        update(id<<1|1,mid+1,r,u,v,val) ; 
        st[id] = max(st[id<<1],st[id<<1|1]) ;
    }
    int get(int id,int l,int r,int u,int v) {
        if(l > v || r < u) return 0 ; 
        if(l >= u && r <= v) return st[id] ; 
        int mid = (l+r)/2 ; 
        down(id) ;
        return max(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v)) ;
    } 
} st ;


void solve() {  
    FOR(i,1,n) st.update(1,1,n,i,i,i) ;     
    set<int> se ; 
    FOR(i,1,n) se.insert(a[i]) ; 
    FOR(i,1,n) {
        if(i&1) {
            int val = *se.begin() ; 
            se.erase(val) ; 
            int old_pos = pos[val] ;
            int now_pos = st.get(1,1,n,old_pos,old_pos) ; 
            ans[i] = now_pos - val ; 
            st.update(1,1,n,1,old_pos,1) ; 
        } else {
            int val = *se.rbegin() ; 
            se.erase(val) ; 
            int old_pos = pos[val] ;
            int now_pos = st.get(1,1,n,old_pos,old_pos) ; 
            ans[i] = val - now_pos ; 
            st.update(1,1,n,old_pos,n,-1) ; 
        }
    }   
    FOR(i,1,n) cout << ans[i] << endl ;
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