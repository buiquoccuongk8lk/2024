#include <bits/stdc++.h>
#define UB upper_bound
#define LB lower_bound
#define ll long long
#define dat ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ft(i,a,n) for(ll i=a;i<=n;i++)
#define fd(i,a,n) for(ll i=a;i>=n;i--)
using namespace std;
ll n,f[200000+5],dd[200000+5];
vector <ll> g[200000+5];
void doc()
{
	 cin>>n;
	 ft(i,1,n-1)
	 {
	 	ll x,y;
	 	cin>>x>>y;
	 	g[x].push_back(y);
	 	g[y].push_back(x);
	 }
}
struct bg
{
	ll id;
	ll ts;
};
void dfs(ll u,ll p)
{
	f[u]=1;
	for(ll v:g[u])
	{
		if(v==p) continue;
		dfs(v,u);
		f[u]+=f[v];
	}
}
set<ll> s,tp;
ll chia(ll x,ll p)
{
	ll res=2e9;
	auto it=s.UB((n+f[x])/2);
	ll fy=*it;
	if(it!=s.end())res=min(res,max({fy-f[x],f[x],n-fy})-min({f[x],fy-f[x],n-fy}));
	if(it!=s.begin()) 
	{
			it--;
			fy=*it;
			res=min(res,max({fy-f[x],f[x],n-fy})-min({f[x],fy-f[x],n-fy}));
	}
	auto it1=tp.UB((n-f[x])/2);
	fy=*it1;
	if(it1!=tp.end()) res=min(res,max({fy,f[x],n-fy-f[x]})-min({fy,f[x],n-f[x]-fy}));
	if(it1!=tp.begin()) 
	{
			it1--;
			fy=*it1;
			res=min(res,max({fy,f[x],n-fy-f[x]})-min({fy,f[x],n-f[x]-fy}));
	}
	s.insert(f[x]);
	for(ll v:g[x])
	{
		if(v==p) continue;
		res=min(res,chia(v,x));
	}
	s.erase(f[x]);
	tp.insert(f[x]);
	return res;
	
}
void sub1()
{
	dfs(1,1);
	cout<<chia(1,0);
}
void sub2()
{

}
void time()
{
    cerr<< endl<<"Time: "<<clock()<<"ms"<<endl;
}
signed main()
{
	#define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
	dat
	doc();
	sub1();
	sub2();
	time();
}
