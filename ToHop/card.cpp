//https://codeforces.com/group/zs18jcQ3u7/contest/405732/problem/E
//time limit 1000ms
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")  
// #pragma GCC optimize("unroll-loops")  
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define vi vector<int>
#define vii vector<ii>
#define mii map<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ep emplace_back
#define endl "\n"
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x,i) ((x) & MASK(i))
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~MASK(i))
#define oo 1e18
#define __lcm(a,b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define FORR(i,l,r,k) for (int i=l;i<=r;i+=k)
#define FODD(i,l,r,k) for (int i=l;i<=r;i-=k)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NAME "a"

int t, n, k;
int facto[(int)1e4 + 10];
int mod = 1e9 + 7;

int mul(int x, int y)
{
    return (x % mod) * (y % mod) % mod;
}

int POWM(int x, int y)
{
    if(y == 1)
        return x;
    int half = POWM(x, y / 2);
    if(y % 2 == 0)
        return mul(half, half);
    else
        return mul(half, mul(half, x));
}

int cnr(int a, int b)
{
    return mul(facto[a], POWM(mul(facto[b], facto[a - b]), mod - 2));
}

int add(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}

bool cmp(int x, int y)
{
    return x > y;
}

signed main() 
{
    faster;
    //freopen(NAME".inp", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    facto[0] = 1;
    FOR(i, 1, 1e4)
        facto[i] = mul(facto[i - 1], i);
    cin >> t;
    int cnt = 1;
    while(t--)
    {
        cin >> n >> k;
        int a[(int)1e4 + 10];
        FOR(i, 1, n)
            cin >> a[i];
        sort(a + 1, a + n + 1, cmp);
        int ans = 0;
        int dem = 1;
        while(dem <= n - k + 1)
        {
            ans = add(ans, mul(a[dem], cnr(n - dem, k - 1)));
            dem++;
        }
        cout << "Case #" << cnt << ": " << ans << endl;
        cnt++;
    }
    return 0;
}                                                                                         
