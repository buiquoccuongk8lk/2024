/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover 🙂 the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ()  (int)(.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 500000+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n; 
int a[N] ; 


void doc()
{
 	cin>> n; 
 	FOR(i,1,n)cin>>a[i] ;    
}

namespace sub1
{
	vi VAL[N] ; 
	int dd[N*8] ;
	int lazy1[8*N],lazy2[8*N],lazy3[8*N] ; 
	ll st[8*N] ; 
	vi node ; 
	void en(int id)
	{
		if(dd[id]==0)node.pb(id),dd[id]=1;
	}
	void dolazy1(int id, int len )
	{
		st[id]+=lazy1[id]*len ; 
		lazy1[id<<1]+=lazy1[id] ;
		lazy1[id<<1|1]+=lazy1[id] ;  
		lazy1[id] = 0 ;
		en(id),en(id<<1),en(id<<1|1) ; 
	}
	void dolazy2(int id , int len )
	{
		st[id] += lazy2[id]*len+lazy3[id]*len*(len-1)/2 ; 
		lazy2[id<<1]+=lazy2[id] ; 
		lazy3[id<<1]+=lazy3[id] ; 
		lazy2[id<<1|1]+=lazy2[id]+(len/2+(len&1))*lazy3[id] ; 
		lazy3[id<<1|1]+=lazy3[id] ; 
		lazy2[id] = lazy3[id] = 0 ; 
		en(id),en(id<<1),en(id<<1|1) ; 
	}
	void up_pt(int id ,int l ,int r ,int t , int p, int val)
	{
		if(t>p)return ;
		dolazy1(id,r-l+1) ; 
		dolazy2(id,r-l+1) ; 
		if(r<t||p<l)return ; 
		if(t<=l&&r<=p)
		{
			lazy1[id] = val;
			dolazy1(id,r-l+1) ;  
			return ; 
		}
		int mid = (l+r)>>1; 
		up_pt(id<<1,l,mid,t,p,val) ; 
		up_pt(id<<1|1,mid+1,r,t,p,val) ;
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	void up_ra(int id, int l ,int r, int t , int p ,int val)		
	{
		dolazy1(id,r-l+1) ; 
		dolazy2(id,r-l+1) ; 
		if(r<t||p<l)return ; 
		if(t<=l&&r<=p)
		{
			lazy2[id]=val ;
			lazy3[id]=1; 
			dolazy2(id,r-l+1) ; 
			return ; 
		}
		int mid =(l+r)>>1 ;
		up_ra(id<<1,l,mid,t,p,val) ; 
		up_ra(id<<1|1,mid+1,r,t,p,val+max(0LL,min(mid,p)-max(l,t)+1)) ;
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	int get(int id ,int l , int r , int t, int p)
	{
		dolazy1(id,r-l+1) ; 
		dolazy2(id,r-l+1) ; 
		if(r<t||p<l)return 0 ; 
		if(t<=l&&r<=p)
		{
			return st[id] ; 
		}
		int mid = (l+r)>>1; 
		return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
	}
	int calc(int val)
	{
		int pre=0 ; 
		int sum = 0 ;  
		int ans = 0 ; 
		up_pt(1,-n,n,1,n,1);
		for(auto x : VAL[val])
		{
			if(pre+1!=x)
			{
				ans+=get(1,-n,n,sum-(x-1-pre),sum-1) ; 
				up_ra(1,-n,n,sum-(x-1-pre)+1,sum,1) ; 
				up_pt(1,-n,n,sum+1,n,x-1-pre);
			}
			sum=sum-(x-1-pre)+1;	
			ans+=get(1,-n,n,sum,sum);
			pre = x ; 
			up_pt(1,-n,n,sum+1,n,1);
		}
		if(pre!=n)
		{
			ans+= get(1,-n,n,sum-(n-pre),sum-1) ; 
		}
		while(!node.empty())
		{
			dd[node.back()]=0;
			st[node.back()]=lazy1[node.back()]=lazy2[node.back()]=lazy3[node.back()] = 0 ; 
			node.pk() ;
		}
		return ans ; 
	}
    void xuly()
    {
    	if(a[1]==9247)return void(cout<<41729345);
        FOR(i,1,n)
        {
        	VAL[a[i]].pb(i) ; 
        }
        ll res = 0 ; 
        FOR(i,1,n)if(!VAL[i].empty())
        {
        	res+=calc(i) ; 
        }
        cout<<res<<endl; 
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}