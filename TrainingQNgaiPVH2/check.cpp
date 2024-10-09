#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define TASK  "4"
#define             pb  push_back  
#define             ll  long long
#define             se  second 
#define             fi  first
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)


typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const long long inf = 1e18;
const ll N = 2e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9+7 /*1234567891*/ , base =311 ;

ll n;
ll kingx,kingy;
map<pair<ll,ll>,ll> mp;
vector<pair<ll,ll>> cot,hang,L,R;
ll a[N],b[N];

signed main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    while(cin>>n)
    {
        if(n==-1) break;
        hang.clear();
        cot.clear();
        L.clear();
        R.clear();
        cin>>kingx>>kingy;
        cot.pb({0,0});
        hang.pb({0,0});
        L.pb({0,0});
        R.pb({0,0});
        fu(i,1,n)
        {
            char s;cin>>s;
            ll x,y;cin>>x>>y;
            x-=kingx;
            y-=kingy;
            // cout<<x<<" "<<y<<el;
            if(s=='R') // xe
            {
                if(x==0)
                {
                    cot.pb({y,1});
                    // cout<<1<<el;
                }
                else if(y==0)
                {
                    hang.pb({x,1});
                }
                else if(abs(x)==abs(y) && x*y<0)
                {
                    L.pb({x,-1});
                }
                else if(abs(x)==abs(y) && x*y>0)
                {
                    R.pb({x,-1});
                }
            }
            else if(s=='B') // tượng
            {
                if(x==0)
                {
                    cot.pb({y,-1});
                    // cout<<1<<el;
                }
                else if(y==0)
                {
                    hang.pb({x,-1});
                }
                else if(abs(x)==abs(y) && x*y<0)
                {
                    L.pb({x,1});
                }
                else if(abs(x)==abs(y) && x*y>0)
                {
                    R.pb({x,1});
                }
            } 
            else
            {
                if(x==0)
                {
                    cot.pb({y,1});
                    // cout<<1<<el;
                }
                else if(y==0)
                {
                    hang.pb({x,1});
                }
                else if(abs(x)==abs(y) && x*y<0)
                {
                    L.pb({x,1});
                }
                else if(abs(x)==abs(y) && x*y>0)
                {
                    R.pb({x,1});
                }
            }
        }
        sort(all(hang));
        sort(all(cot));
        sort(all(L));
        sort(all(R));
        // cout<<hang.size()<<" "<<cot.size()<<" "<<L.size()<<" "<<R.size()<<el;;
        // memset(a,0,sizeof(a));
        // memset(b,0,sizeof(b));
        ll sz=hang.size();
        fu(i,1,sz) a[i]=hang[i-1].fi,b[i]=hang[i-1].se;
        b[sz+1]=0;
        ll j=lower_bound(alla(a,sz),0)-a;
        if(b[j-1]==1 || b[j+1]==1)
        {
            cout<<"YES"<<el;continue;
        }
        // memset(a,0,sizeof(a));
        // memset(b,0,sizeof(b));
        sz=cot.size();
        fu(i,1,sz) a[i]=cot[i-1].fi,b[i]=cot[i-1].se;
        b[sz+1]=0;
        j=lower_bound(alla(a,sz),0)-a;
        if(b[j-1]==1 || b[j+1]==1)
        {
            cout<<"YES"<<el;continue;
        }
        // memset(a,0,sizeof(a));
        // memset(b,0,sizeof(b));
        sz=L.size();
        fu(i,1,sz) a[i]=L[i-1].fi,b[i]=L[i-1].se;
        b[sz+1]=0;
        j=lower_bound(alla(a,sz),0)-a;
        if(b[j-1]==1 || b[j+1]==1)
        {
            cout<<"YES"<<el;continue;
        }
        // memset(a,0,sizeof(a));
        // memset(b,0,sizeof(b));
        sz=R.size();
        fu(i,1,sz) a[i]=R[i-1].fi,b[i]=R[i-1].se;
        b[sz+1]=0;
        j=lower_bound(alla(a,sz),0)-a;
        if(b[j-1]==1 || b[j+1]==1)
        {
            cout<<"YES"<<el;continue;
        }
        cout<<"NO"<<el;
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}