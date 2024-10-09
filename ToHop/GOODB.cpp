
#include<bits/stdc++.h>

using namespace std;

#define TASK ""
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#define 	___Watbor___ signed main()

#define         ll long long
#define 	ld long double
#define 	ull unsigned long long

#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define         fr(i,a,b) for(int i=a;i<=b;i++)
#define        	fd(i,a,b) for(int i=a;i>=b;i--)

#define         fi first
#define         se second

typedef pair<ll,ll> ii;
typedef vector<pair<ll,ll> > vii;
const ll inf = 1e18;
const int MOD = 1e9+7;
const int N  = 1e5+5;
ll n,w,t,r;
void Doc() {
    cin >> n >> w >> t >> r;
}

ll mul(ll a,ll b){
    return (a*b)%MOD;
}
ll LT(ll x,ll y){
    if(y==0) return 1;
    if(y==1) return x;
    ll tmp = LT(x,y/2);
    if(y%2==1) return (((tmp*tmp)%MOD)*x)%MOD;
    else return (tmp*tmp)%MOD;
}
ll fact[(ll)1e6+5];
ll C(ll n,ll k){
    return mul(fact[n],LT(mul(fact[k],fact[n-k]),MOD-2));
}
void Sol1() {
    fact[0] = 1;
    fr(i,1,1e6){
        fact[i]=mul(fact[i-1],i);
    }
   	ll s1 = C(n,w);
   	ll s2 = C(n-w,t);
   	cout << (s1*s2)%MOD;

}
void Sol2(){


}



___Watbor___{
    Boost
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    Doc();
    Sol1();
    Sol2();
    cerr << "\nTime elapsed:" << 0.001*clock();
}

