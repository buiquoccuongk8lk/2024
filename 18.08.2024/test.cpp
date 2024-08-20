#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define down '\n'
#define lli long long int
#define ulli unsigned long long int
#define ld long double
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2222;

ulli a[maxn], dp[maxn][maxn], n ,  l, r;
void read()
{
	cin >> n >> l >> r;
	for( int i = 1; i <= n; i ++ ) cin >> a[i];
	ulli sum = 0;
	for( int i = 1; i < 2001; i ++ )
    {
        for( int j = 1 ; j <= r; j ++ ) dp[i][j] = LLONG_MAX;
    }
	for( int i = 1; i <= n; i ++ )
    {
        sum +=  a[i];
        dp[i][1] = sum;
    }
}
void solve()
{
    ulli maxx,minn;
    for( int i = 2; i <= n ; i ++ )
    {
        maxx =  min( static_cast<ulli>(i) , r );
        for( int j = 2; j <= maxx ; j ++ )
        {
            ulli sum = a[i] ;
            minn = j-1;
            for( int k = i - 1 ; k >= minn ; k -- )
            {
                dp[i][j] =  min( dp[i][j] ,  (sum|dp[k][ minn ] ) );
                sum += a[k];
            }
        }
    }
    ulli ans = LLONG_MAX;
    for( ulli i = l; i <= r; i ++ ) ans = min( ans , dp[n][i] );
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    read();
    solve();
    return 0;
}
