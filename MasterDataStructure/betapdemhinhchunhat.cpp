#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

int n , q ; 
struct DL1
{
	int x1 , y1 , x2 , y2 ; 
};
DL1 a[N] ;
int ans[N] ; 
struct Queries
{
	int u ;
	int v ; 
	int id ; 
}Q[N] ; 
long long st[4*N] ; 
void update(int id,int l,int r,int pos,int val)
{
	if(pos < l or pos > r) return;
	if(l==r)
	{
		st[id]+= val;
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = st[id<<1] + st[id<<1|1];
}
long long get(int id,int l,int r,int u,int v)
{
	if( l > v or r < u ) return 0;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return t1 + t2 ;
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
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 ; 
	}
	cin >> q ; 
	for(int i(1) ; i <= q ; i++)
	{
		cin >> Q[i].u >> Q[i].v ;
		Q[i].id = i ; 
	}
	vector<int> v ; 
	unordered_map<int,int> pos ;
	for(int i(1) ; i <= n ; i++)
	{
		v.push_back(a[i].y1) ; 
		v.push_back(a[i].y2) ; 
	}
	v.push_back(0) ; 
	for(int i(1) ; i <= q ; i++)
	{
		v.push_back(Q[i].v) ; 
	}
	sort(v.begin(),v.end()) ; 
	v.resize(unique(v.begin(),v.end()) - v.begin()) ; 
	for(int i(0) ; i <= (int)v.size() - 1 ; i++)
	{
		pos[v[i]] = i + 1 ; 
	}
	sort(Q+1,Q+1+q,[](Queries x,Queries y)
	{
		return x.u < y.u ; 
	}) ;
	sort(a+1,a+1+n,[](DL1 u,DL1 v)
	{
		return u.x2 < v.x2 ; 
	}) ; 
	int j = 1 ; 
	int m = v.size() ; 
	for(int i(1) ; i <= q ; i++)
	{
		while(j <= n and a[j].x2 <= Q[i].u)
		{
			update(1,1,m,pos[a[j].y2],1) ; 
			j++ ;
		}
		ans[Q[i].id] = get(1,1,m,pos[0],pos[Q[i].v]) ; 
	}
	for(int i(1) ; i <= q ; i++)
	{
		cout << ans[i] << '\n' ; 
	}
	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}