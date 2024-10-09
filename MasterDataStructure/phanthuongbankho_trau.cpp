/// Code By Watborhihi:>>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define int long long
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define ALL(a) a.begin() , a.end()
#define FOR(i,a,b)  for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(v) sort(ALL(v)) , v.resize( unique( ALL(v)) - v.begin())

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

void add(ll &x,const ll &y) {x+=y;if(x>=MOD)x-=MOD;}
void sub(ll &x,const ll &y) {x-=y;if(x<0)x+=MOD;}

bool maximize(ll &x,const ll &y) {if(x < y){x=y;return 1;}return 0;}
bool minimize(ll &x,const ll &y) {if(x > y){x=y;return 1;}return 0;}

int n , q ;
int a[N] ;
struct Queries
{
	int L ;
	int R ;
	int T ; 
	int i ; 
}Q[N] ; 

int S , l , r , VAL ;
vi v ; 
int res[N] , pos[N] , cnt[N] , fi[N] ; 

struct BIT
{
	int sum ; 
	int sl ; 
} bit[N+ 10] ; 

void input(void)
{
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ;
	FOR(i,1,q)
	{
		cin >> Q[i].L >> Q[i].R >> Q[i].T ;
		Q[i].i = i ; 
	}
	S = sqrt(n) ; 
	sort(Q+1,Q+1+q,[](Queries u,Queries v)
	{
		if(u.L/S==v.L/S) return u.R < v.R ; 
		else return u.L < v.L ; 
	}) ;  
}

BIT getSum(int p) 
{
    int idx = p, ans1 = 0 , ans2 = 0 ; 
    while (idx > 0) 
    {
        ans1 += bit[idx].sum ;
        ans2 += bit[idx].sl ; 
        idx -= (idx & (-idx));
    }
    return {ans1 , ans2} ; 
}

void update(int u, int v,int val) 
{
    int idx = u;
    while (idx <= VAL) 
    {
        bit[idx].sum+= v*fi[val] ;
        bit[idx].sl+= v ;  
        idx += (idx & (-idx));
    }
}

BIT query(int l,int r)
{
	int sum = getSum(r).sum - getSum(l-1).sum ; 
	int sl = getSum(r).sl - getSum(l-1).sl ; 
	return {sum , sl} ; 	
}

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	for(int i= log(VAL) + 1 ; i>=0 ; i--)
	{
		if(pos + (1 << i) <= VAL and sum + bit[pos + (1 << i)].sum <= v)
		{
			sum += bit[pos + (1 << i)].sum ;
			pos += (1 << i);
		}
	}
	return pos ;
}

void MO(int id)
{	
	while(l > Q[id].L)
	{
		l-- ; 
		cnt[pos[a[l]]]++ ;
		update(pos[a[l]],1,pos[a[l]]) ;
	}
	while(l < Q[id].L)
	{
		cnt[pos[a[l]]]-- ; 
		if(pos[a[l]]!=0) update(pos[a[l]],-1,pos[a[l]]) ; 
		l++ ;
	}
	while(r > Q[id].R)
	{
		cnt[pos[a[r]]]-- ; 
		update(pos[a[r]],-1,pos[a[r]]) ; 
		r-- ; 
	}
	while(r < Q[id].R)
	{
		r++ ; 
		cnt[pos[a[r]]]++ ; 
		if(pos[a[r]]!=0) update(pos[a[r]],1,pos[a[r]]) ; 
	}
	int p = bit_search(Q[id].T)  ;
	BIT ans = query(1,p-1) ; 
	int kq = ans.sl ; 
	Q[id].T-= ans.sum ;
	if(Q[id].T >= fi[p]) kq+= min(cnt[p] , Q[id].T/fi[p]) ; 
	res[Q[id].i] = kq ;
}

void solve(void)
{
	FOR(i,1,n) v.pb(a[i]) ; 
	uni(v) ; 
	FOR(i,0,(int)v.size()-1)
	{
 		pos[v[i]] = i + 1 ; 
 		fi[i+1] = v[i] ; 
 	}
 	VAL = v.size() ;
	FOR(i,1,q)
	{	
		MO(i) ; 
	}
	FOR(i,1,q)
	{
		cout << res[i] << '\n' ;
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
    input() ; solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}
