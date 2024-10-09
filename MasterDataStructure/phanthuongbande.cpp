#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)  for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)

const int N = 1e5 + 5 ;
const long long MOD = 1e9 + 7 ;
const long long inf = 1e18 ;

int n , q ;
int a[N] ;

void doc(void)
{
    cin >> n >> q ;
    FOR(i,1,n) cin >> a[i] ;
}
struct Node
{
    int cnt[103] ;
    Node()
    {
        memset(cnt,0,sizeof(cnt)) ;
    }
    friend Node operator +(Node a, Node b)
    {
        Node ans ;
        FOR(i,1,100)
        {
            ans.cnt[i] = a.cnt[i] + b.cnt[i] ;
        }
        return ans ;
    }
}st[4*N] ;
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].cnt[a[l]]++ ;
        return ;
    }4
    int mid = (l+r) >> 1 ;
    build(id<<1,l,mid) ;
    build(id<<1|1,mid+1,r) ;
    st[id] = st[id<<1] + st[id<<1|1] ;
}
Node get(int id,int l,int r,int u,int v)
{
    if(l > v or r < u)
    {
        Node emp ;
        return emp ;
    }
    if(l >= u and r <= v) return st[id] ;
    int mid = (l+r) >> 1 ;
    return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
}
void solve(void)
{
    build(1,1,n) ;
    while(q--)
    {
        int l , r , t ;
        cin >> l >> r >> t ;
        Node res = get(1,1,n,l,r) ;
        int ans = 0 ;
        FOR(i,1,100)
        {
            if(t >= i*res.cnt[i])
            {
                ans+= res.cnt[i] ;
                t-= i*res.cnt[i] ;
            }else
            {
                ans+= t/i ;
                t-= i * (t/i) ;
                break ;
            }
            //cout << res.cnt[i] << endl ;
        }
        cout << ans << '\n' ;
    }
}

signed main(void)
{
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") )
    {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    doc() ;
    solve() ;
    return 0;
}
