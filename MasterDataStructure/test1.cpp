#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5 ;
const long long inf = 1e18;

int n , q ;
long long a[N] ; 
struct Node
{
    long long maxi ; 
    long long maxL ; 
    long long maxR ; 
    long long sum ; 
}st[4*N] ; 
long long lazy[4*N] ; 

Node merge(Node a,Node b)
{
    Node res ;
    res.maxi = max({ a.maxi , b.maxi , a.maxR + b.maxL } ) ;
    res.maxL = max({ a.maxL , a.sum + b.maxL }) ;
    res.maxR = max({ b.maxR , b.sum + a.maxR })  ; 
    res.sum = a.sum + b.sum ;
    return res ; 
}

void down(int id,int l,int r)
{
    if(lazy[id] == -1e18) return ; 
    int mid = ( l + r ) >> 1 ; 

    st[id<<1].sum = (mid-l+1) * lazy[id] ; 
    st[id<<1|1].sum = (r-mid + (l==r) ) * lazy[id] ; 

    st[id<<1].maxi =  ( mid - l + 1) * lazy[id]  ;
    st[id<<1|1].maxi = ( r - mid + (l==r) ) * lazy[id]  ; 

    st[id<<1].maxL = ( mid - l + 1) * lazy[id] ;
    st[id<<1|1].maxL = ( r - mid + (l==r) ) * lazy[id] ; 

    st[id<<1].maxR =  ( mid - l + 1) * lazy[id] ;
    st[id<<1|1].maxR = ( r - mid + ( l==r ) ) * lazy[id] ; 

    lazy[id<<1] = lazy[id] ; 
    lazy[id<<1|1] = lazy[id] ; 

    lazy[id] = -1e18 ; 
}

void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id] = { a[l] , a[l] , a[l] , a[l] } ;
        return ; 
    }
    int mid = (l+r)>> 1 ; 
    build(id<<1,l,mid) ; 
    build(id<<1|1,mid+1,r) ; 
    st[id] = merge(st[id<<1],st[id<<1|1]) ; 
}

void update(int id,int l,int r,int u,int v,long long val)
{
    if(l > v or r < u) return ; 
    if(l >= u and r <= v)
    {
        st[id].sum = ( r - l + 1) * val ; 
        st[id].maxL = (r - l + 1) * val ; 
        st[id].maxR = (r - l + 1) * val ; 
        st[id].maxi =  (r - l + 1) * val  ; 
        lazy[id] = val ; 
        return ;
    }
    down(id,l,r) ; 
    int mid = ( l + r ) >> 1 ; 
    update(id<<1,l,mid,u,v,val) ; 
    update(id<<1|1,mid+1,r,u,v,val) ; 
    st[id] = merge(st[id<<1],st[id<<1|1]) ; 
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v or r < u) return { (long long) -1e18 ,(long long) -1e18 ,(long long) -1e18 , 0 } ; 
    if(l >= u and r <= v) return st[id] ;
    down(id,l,r) ; 
    int mid = ( l + r ) >> 1 ; 
    return merge( get(id<<1,l,mid,u,v) , get(id<<1|1,mid+1,r,u,v) ) ;
}

signed main()
{
    #define TASK "test1"
    ios_base::sync_with_stdio(false); cin.tie(0);
    if( fopen(TASK".INP","r") )
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> q;
    for(int i(1) ; i <= n ; i++)
    {
        cin >> a[i] ; 
    }
    build(1,1,n) ;    
    for(int i(1) ; i <= 4*N ; i ++) lazy[i] = -1e18 ; 
    while(q--)
    {
        int t , u , v ;
        long long x ; 
        cin >> t >> u >> v ; 
        if(t==1)
        {
            cin >> x ; 
            update(1,1,n,u,v,x) ; 
        }else
        {
            Node ans = get(1,1,n,u,v) ;  
            //cout << ans.sum << '\n' ; 
            cout << max( 1ll * 0 , ans.maxi ) << '\n' ; 
        }
    }
    return 0;
}



