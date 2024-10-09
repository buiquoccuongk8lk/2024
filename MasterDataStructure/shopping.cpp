/// Code By Watborhihi:>>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define SZ(a) (int)a.size()
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define ALL(a) a.begin() , a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(v) sort(ALL(v)) , v.resize( unique( ALL(v)) - v.begin())

const int N = 2e5 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

void add(ll &x,const ll &y) {x+=y;if(x>=MOD)x-=MOD;}
void sub(ll &x,const ll &y) {x-=y;if(x<0)x+=MOD;}

bool maximize(ll &x,const ll &y) {if(x < y){x=y;return 1;}return 0;}
bool minimize(ll &x,const ll &y) {if(x > y){x=y;return 1;}return 0;}

int n , q , l , r , S ;
ll a[N] , ans[N] ; 
struct Queries
{
    int L ; 
    int R ; 
    ll T ; 
    int id ; 
}Q[N] ; 
ll st[4*N] ; 

void input(void) 
{
    cin >> n >> q ; 
    FOR(i,1,n) cin >> a[i] ;    
    FOR(i,1,q) 
    {
        cin >> Q[i].T >> Q[i].L >> Q[i].R ;
        Q[i].id = i ;
    }
}

void update(int id,int l,int r,int pos,ll val)
{
    if(pos < l or pos > r) return ; 
    if(l==r)
    {
        st[id] = val ; 
        return ; 
    }
    int mid = (l+r) >> 1 ; 
    if(pos<=mid) update(id<<1,l,mid,pos,val) ; 
    else update(id<<1|1,mid+1,r,pos,val) ;
    st[id] = st[id<<1] + st[id<<1|1] ;
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v or r < u) return 0 ; 
    if(l >= u and r <= v) return st[id] ; 
    int mid = (l+r) >> 1 ; 
    return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
}

int Walk(int id,int l,int r,int u,int v,ll val)
{
    if( l > v or r < u ) return -1 ; 
    if(l==r) return l ; 
    int mid = (l+r) >> 1 ; 
    if(st[id<<1] <= val) return Walk(id<<1|1,mid+1,r,u,v,val-st[id<<1]) ; 
    else return Walk(id<<1,l,mid,u,v,val) ; 
}

ll calc(ll val,ll T)
{
    if(val==0) return 0 ;
    return val * (T/val) ; 
}
void MO(int id)
{
    while(l > Q[id].L)
    {
        l-- ; 
        update(1,1,n,l,calc(a[l],Q[id].T)) ; 
    }
    while(l < Q[id].L)
    {
        update(1,1,n,l,0) ;  
        l++ ;
    }
    while(r > Q[id].R)
    {
        update(1,1,n,r,0) ;  
        r-- ; 
    }
    while(r < Q[id].R)
    {
        r++ ; 
        update(1,1,n,r,calc(a[r],Q[id].T)) ; 
    }
    int pos = Walk(1,1,n,Q[id].L,Q[id].R,Q[id].T) ; 
    if(get(1,1,n,Q[id].L,pos) > Q[id].T) pos-- ;
    Q[id].T-=get(1,1,n,Q[id].L,pos) ; 
    FOR(i,pos+1,Q[id].R)
    {
        if(Q[id].T >= calc(a[i],Q[id].T))
        {
            Q[id].T-=calc(a[i],Q[id].T) ; 
        }
    }
    ans[Q[id].id] = Q[id].T ;
}

void solve(void) 
{
    S = sqrt(n) ; 
    sort(Q+1,Q+1+q,[](Queries u,Queries v)
    {
        if(u.L/S==v.L/S) return u.R < v.R ; 
        else return u.L < v.L ;
    }) ; 
    FOR(i,1,q)
    {
        MO(i) ; 
    }
    FOR(i,1,q)
    {
        cout << ans[i] << '\n' ;
    }
}

signed main(void) 
{
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if( fopen(TASK".INP","r") ) 
    {
        freopen(TASK".INP","r",stdin) ; 
        freopen(TASK".OUT","w",stdout);
    }
    input() ; solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}