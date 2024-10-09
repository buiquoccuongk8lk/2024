

/// Code By Watborhihi:>>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;
#define int long long
int n,q ;
int a[N] ;
__int128 st[4*N] ;
__int128 lazy[4*N] ;
void input(void) {
    cin >> n >> q ;
    for(int i(1) ; i <= n ; i++) cin >> a[i] ;
}
void down(int id)
{
    if(!lazy[id]) return ;
    __int128 x = lazy[id];
    st[id<<1] = x;
    lazy[id<<1] = x;
    st[id<<1|1] = x;
    lazy[id<<1|1] = x;
    lazy[id] = 0;
}

void update(int id , int l , int r , int u , int v , int bit)
{
   if(l > v || r < u) return;
   if(l >= u && r <= v)
   {
      st[id] = ((__int128)1 << bit);
      lazy[id] = ((__int128)1 << bit);
      return;
   }
   down(id);
   int mid = (l + r) / 2;
   update(id * 2 , l , mid , u , v , bit);
   update(id * 2 + 1 , mid + 1 , r , u , v , bit);
   st[id] = (st[id * 2] | st[id * 2 + 1]);
}

__int128 get(int id , int l , int r , int u , int v)
{
   if(l > v || r < u) return 0;
   if(l >= u && r <= v) return st[id];
   down(id);
   int mid = (l + r) / 2;
   return get(id * 2 , l , mid , u , v) | get(id * 2 + 1 , mid + 1 , r , u , v );
}

void solve(void) {
    for(int i(1) ; i <= n ; i++) update(1,1,n,i,i,a[i] - 1) ;
    while(q--) {
        long long t , l , r , val ;
        cin >> t >> l >> r ;
        if(t==1) {
            cin >> val ;
            update(1,1,n,l,r,val-1) ;
        }else {
            __int128 ans = get(1,1,n,l,r) ;
            long long cnt = 0 ;
            for(int i(100) ; i >= 0 ; i--){
                if((ans>>i)&1) cnt++ ;
            }
            cout << cnt << '\n' ;
        }
    }
}
signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ){
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    input() ; solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}
