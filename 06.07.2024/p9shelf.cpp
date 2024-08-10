
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC

const int maxn = 1e5 + 5 ;

int n ;
struct STICKS {
    int x1,x2,y ;
    bool operator < (const STICKS &s) const {
        return y < s.y ;
    }
} a[maxn] ;

void init(void) {
    cin >> n ;
    FOR(i,1,n) cin >> a[i].x1 >> a[i].x2 >> a[i].y ;
}

ll st[8*maxn] , lazy[8*maxn] ; 

void down(int id,int l,int r) {
    if(lazy[id]==0) return ; 

    int mid = (l+r)>>1 ; 

    st[id<<1] = 1LL * (mid-l+1)*lazy[id] ; 
    st[id<<1|1] = 1LL * (r-mid)*lazy[id] ; 

    lazy[id<<1] = lazy[id] ;
    lazy[id<<1|1] = lazy[id] ; 

    lazy[id] = 0 ;
}

void update(int id,int l,int r,int u,int v,int val) {
    if(l > v or r < u) return ; 
    if(l >= u and r <= v) {
        st[id] = 1LL * (r-l+1)*val ; 
        lazy[id] = val ; 
        return ; 
    }
    int mid = (l+r)>>1 ; 
    down(id,l,r) ; 
    update(id<<1,l,mid,u,v,val) ; 
    update(id<<1|1,mid+1,r,u,v,val) ; 
    st[id] = st[id<<1] + st[id<<1|1] ; 
}

ll get(int id,int l,int r,int u,int v) {
    if(l > v or r < u ) return  0 ; 
    if(l >= u and r <= v) return st[id] ; 
    int mid = (l+r)>>1 ; 
    down(id,l,r) ; 
    return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
}

void process(void) {
    sort(a+1,a+1+n) ;
    vector<int> vec ;
    FOR(i,1,n) {
        vec.pb(a[i].x1) ;
        vec.pb(a[i].x2) ;
    }
    sort(all(vec)) ; 
    vec.resize( unique(all(vec)) - vec.begin() ) ; 
    FOR(i,1,n) {
        a[i].x1 = lower_bound(all(vec),a[i].x1) - vec.begin() + 1 ; 
        a[i].x2 = lower_bound(all(vec),a[i].x2) - vec.begin() + 1 ; 
    }
    ll ans = 0 ; 
    int VAL = vec.size() ;
    FOR(i,1,n) {
        ans+= 1LL * 2 * a[i].y - ( get(1,1,VAL,a[i].x1,a[i].x1) + get(1,1,VAL,a[i].x2,a[i].x2) ) ; 
        update(1,1,VAL,a[i].x1,a[i].x2,a[i].y) ; 
    }
    cout << ans ; 
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
