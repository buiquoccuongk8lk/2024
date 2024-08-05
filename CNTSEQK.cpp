// Author : WatborNoLegit 
// Road To VOI
// More and more code 
#include<bits/stdc++.h>

using namespace std;

#define         	TASK "CNTSEQK"
#define         	INPUT TASK".INP"
#define         	OUTPUT TASK".OUT"

#define         	int long long
#define         	FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define         	FORD(i,a,b) for(int i = a ; i >= b ; i--)
#define         	fi first
#define         	se second
#define         	endl '\n'
#define         	ii pair<int,int>
#define         	iii pair<int,pair<int,int>>
#define         	vii vector<pair<int,int>>
#define         	vi vector<int>
#define         	pb push_back
#define         	pf push_front		

 
int dx[] = { -1 , 0 , 1 ,  0 };
int dy[] = {  0 , 1 , 0 , -1 };

const int inf = 1e18 , MOD = 1e9+7 , N  = 1e6+5;
const double eps = 1e-8;

int n,k;
int a[N];
void Doc()
{
	cin >> n >> k;
	FOR(i,1,n) cin >> a[i];
}

namespace sub
{
	int st[400005][105];
	void update(int id,int l,int r,int pos,int val,int j)
	{	
		if(pos < l or pos > r ) return ;
		if( l == r)
		{
			st[id][j]+=val;
			return;
		}
		int mid = (l+r)>>1;
		update(id<<1,l,mid,pos,val,j);
		update(id<<1|1,mid+1,r,pos,val,j);
		st[id][j] = st[id<<1][j] + st[id<<1|1][j] ; 
	}
	int get(int id,int l,int r,int u,int v,int j)
	{
		if( l > v or r < u ) return 0;
		if( l >= u and r <= v) return st[id][j];
		int mid = (l+r)>>1;
		return get(id<<1,l,mid,u,v,j) + get(id<<1|1,mid+1,r,u,v,j);
	}
	void Sol()
	{
		map<int,int>mp;
		vi v;
		FOR(i,1,n) v.pb(a[i]);
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		FOR(i,0,v.size()-1)
		{
			mp[v[i]] = i + 1;
		}
		FOR(i,1,n)
		{
			update(1,1,n, mp[a[i]] , 1 , 1);
			FOR(j,2,k)
			{
				update(1,1,n, mp[a[i]] , get(1,1,n,1,mp[a[i]] - 1,j-1) , j);
			}
		}
		cout << get(1,1,n,1,n,k);
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(INPUT,"r") ) 
    {
        freopen(INPUT,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    
    Doc();
    sub::Sol();
}
