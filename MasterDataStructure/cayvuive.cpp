#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5 ;
const int MAX = 1e7 ; 
const long long inf = 1e18 , MOD = 1e9 + 7 ;

int n , q , timeDFS ; 
long long st[4*N] , lazy[4*N] ; 
int L[N] , R[N] ,a[N] ; 
vector<int> G[N] ; 
vector<int> vec ;
int prime[MAX + 5] ; 

void DFS(int u,int par)
{
	L[u] = R[u] = ++timeDFS ; 
	for(auto v : G[u])
	{
		if(v==par) continue ; 
		DFS(v,u) ;
		R[u] = max(R[u],R[v]) ; 
	}
}
void down(int id,int l,int r)
{
	if(!lazy[id]) return ; 
	int mid = (l + r) >> 1 ; 
	st[id<<1] = (mid-l+1)*lazy[id] ; 
	st[id<<1|1] = (r-mid)*lazy[id] ; 
	lazy[id<<1] = lazy[id] ; 
	lazy[id<<1|1] = lazy[id] ;
	lazy[id] = 0 ;
}
void update(int id,int l,int r,int u,int v,int val)
{
	if(l > v or r < u) return ;
	if(l >= u and r <= v)
	{
		st[id] = (r-l+1)*val ; 
		lazy[id] = val ; 
		return ;
	}
	down(id,l,r) ; 
	int mid = (l + r) >> 1 ; 
	update(id<<1,l,mid,u,v,val) ; 
	update(id<<1|1,mid+1,r,u,v,val) ; 
	st[id] = st[id<<1] + st[id<<1|1] ; 
}
long long get(int id,int l,int r,int u,int v)
{
	if(l > v or r < u) return 0 ; 
	if(l >= u and r <= v) return st[id] ; 
	down(id,l,r) ; 
	int mid = (l + r) >> 1 ; 
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
}

void prep(void)
{
	DFS(1,1) ; 
	for(int i(1) ; i <= n ; i++)
	{
		update(1,1,n,L[i],L[i],a[i]) ; 
	}
}

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) 
{
    u64 result = 1;
    base %= mod;
    while (e) 
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) 
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) 
{
    if (n < 4) return n == 2 || n == 3;
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) 
    {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter; i++) 
    {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
bool GoldBach(long long sum)
{
	if(sum <= 2) return 0 ; 
	else if(sum % 2 == 0) return 1 ; 
	else if(MillerRabin(sum-2)) return 1 ; 
	return 0 ;
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
	cin >> n ; 
	for(int i(1) ; i <= n ; i++)
	{
		cin >> a[i] ; 
	}
	for(int i(1) ; i <= n - 1 ; i++)
	{
		int u , v ; 
		cin >> u >> v ; 
		G[u].push_back(v) ; 
		G[v].push_back(u) ; 
	} 
	prep() ;
	cin >> q ; 
	while(q--)
	{
		int type ;
		cin >> type ; 
		if(type==1)
		{
			int u , val ;
			cin >> u >> val ; 
			update(1,1,n,L[u],R[u],val) ; 
		}else
		{
			int u ;
			cin >> u ;
			long long sum = get(1,1,n,L[u],R[u]) ; 
			if(GoldBach(sum)) cout << "YES" ; else cout << "NO";
			cout << '\n' ; 
		}
	}
	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}