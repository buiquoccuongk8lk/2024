/**  /\_/\
 *  😊 ._.)
 *  / >> \>>
**/
#include    <bits/stdc++.h>
using       namespace   std;
#define  	boxanglua   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define 	ll          long long
#define 	openfile    if(fopen(".inp","r")) {freopen(".inp", "r", stdin); freopen(".out", "w", stdout);}
#define 	fr(i,a,b)   for(long long i=a;i<=b;i++)
#define 	frd(i,a,b)  for(long long i=a;i>=b;i--)
#define 	endl 		'\n'
#define 	pb 			push_back
#define     myClass     class WORK,class HARD
#define     tct         template<myClass>
#define Data Task
ll __lcm(ll a,ll b){return a/__gcd(a,b)*b;}
ll N=2e5+1;
ll inf=1e18;
tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
ll n,m,p[22][100000+4],h[100000+4],dd[100000+4],f[100000+4],mi[22][(ll)1e6+4];
struct bg{
	ll u;
	ll v;
	ll w;
};
bg e[100000+4];
struct bg1{
	ll v;
	ll w;
};
bool cmp(bg u,bg v)
{
	return u.w>v.w;
}
ll goc(ll x)
{
	while(f[x]>0) x=f[x];
	return x;
}
void hopnhat(ll r1,ll r2)
{
	ll t=f[r1]+f[r2];
	if(abs(f[r1])>abs(f[r2])) // goc nao co nhiu then con hon
	{
		f[r1]=t;
		f[r2]=r1;
	}
	else 
	{
		f[r2]=t;
		f[r1]=r2;
	}
}
vector<bg1> g[1000000+5];
void dfs(ll u,ll cha)
{
	for(bg1 x:g[u])
	{
		ll v=x.w;
		ll w=x.w;
		if(v==cha) continue;
		mi[v][0]=w;
		p[v][0]=u;
		h[v]=h[u]+1;
		dfs(v,u);
	}
}
ll lca(ll u,ll v)
{
	ll tmp=inf;
	if(h[u]<h[v]) swap(u,v);
	frd(j,log2(h[u]),0) if( ( h[u] - h[v])  >= (1 >> j ) )
	{
		tmp=min(tmp,mi[u][j]);
		u=p[u][j];
	}
	if(u==v) return tmp;
	frd(j,log2(h[u]),0)
	{
		if(p[u][j]!=p[v][j])
		{
			tmp=min({tmp,mi[u][j],mi[v][j]});
			u=p[u][j];
			v=p[v][j];
		}
	}
	tmp=min({tmp,mi[u][0],mi[v][0]});
	return tmp;
}
void doc()
{
	cin>>n>>m;
	fr(i,1,m)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
}
void xuly()
{
	sort(e+1,e+m+1,cmp);
	fr(i,1,n) f[i]=-1;
	fr(i,1,m) dd[i]=0;
	fr(i,1,m)
	{
		ll r1=goc(e[i].u);
		ll r2=goc(e[i].v);
		if(r1!=r2)
		{
			dd[i]=1;
			hopnhat(r1,r2);
			g[e[i].u].pb({e[i].v,e[i].w});
			g[e[i].v].pb({e[i].u,e[i].w});
			//cout << e[i].u << ' ' << e[i].v << endl ;
		}
	}
	dfs(1,0);
	fr(j,1,log2(n))
	{
		fr(i,1,n)
		{
			p[i][j]=p[p[i][j-1]][j-1];
			mi[i][j]=min(mi[i][j-1],mi[p[i][j-1]][j-1]);
		}
	}
	ll res=0;
	fr(i,1,m)
	{
		if(dd[i]==1) continue;
		ll x=lca(e[i].u,e[i].v);
		cout << x << endl ;
		if(x >= e[i].w) {
			res+= x - e[i].w ;
		}
	}
	cout<<res;
}
int main()
{
	openfile
	boxanglua
	doc();
	xuly();
}
