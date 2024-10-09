#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;


int n , q , a[N] , st[4*N] ,pos[N] ,last[N] , ans[N] ; 

struct Queries
{
	int L ;
	int R ; 
	int id ; 
} Q[N];

void update(int id,int l,int r,int pos,int val)
{
	if(pos < l or pos > r) return ; 
	if(l==r)
	{
		st[id] = val ; 
		return ;
	}
	int mid = (l+r)>>1 ; 
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = st[id<<1] + st[id<<1|1];
}

int get(int id,int l,int r,int u,int v)
{
	if(l > v or r < u) return  0 ;
	if(l >= u and r <= v) return st[id] ; 
	int mid = (l+r)>>1;
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
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
	cin >> n >> q ; 
	vector<int> v ;
	for(int i(1) ; i <= n ; i++)
	{
		cin >> a[i] ; 
		v.push_back(a[i]) ;
	}
	sort(v.begin(),v.end()) ; 
	unordered_map<int,int> mp ; 
	v.resize( unique(v.begin(),v.end()) - v.begin() ) ;
	for(int i(0) ; i <= (int)v.size() - 1 ; i++)
	{
		mp[v[i]] = i + 1 ;  
	}
	for(int i(1) ; i <= n ; i++)
	{
		a[i] = mp[a[i]];
		//cout << a[i] <<" ";
	}
	for(int i(1) ; i <= q ; i++)
	{
		cin >> Q[i].L >> Q[i].R ;
		Q[i].id = i ; 
	}
	sort(Q+1,Q+1+q,[](Queries u,Queries v)
	{
		if(u.R==v.R) return u.L < v.L ; 
		return u.R < v.R;
	});
	int j = 1 ; 

	for(int i(1) ; i <= q ; i++)
	{
		while( j <= Q[i].R )
		{
			update(1,1,n,last[a[j]],0);
			last[a[j]] = j;
			update(1,1,n,last[a[j]],1);
			j++;
		} 
		ans[Q[i].id] = get(1,1,n,Q[i].L,Q[i].R);
	}

	for(int i(1) ; i <= q ; i++)
	{
		cout << ans[i] << '\n' ; 
	}


	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}