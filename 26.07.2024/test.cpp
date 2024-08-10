#include<bits/stdc++.h>

using namespace std;

#define TASK ""
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#define 	___Watbor___ signed main()
#define         ll long long
#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(ll i=a;i<=b;i++)
#define         fd(i,a,b) for(ll i=a;i>=b;i--)
#define         fi first
#define         se second
typedef pair<ll,ll> ii;
typedef vector<pair<ll,ll> > vii;
const ll inf = 1e18;
const int MOD = 1e9+7;
const int N  = 1e5+5;
int n,m,c;
int a[100005];
void Doc() {
    cin >> n >> m >> c;
    fr(i,1,n) cin >> a[i];
}
namespace sub_task1{


    bool Check(ll x){
        
        ll cnt = 0;
        ll i = 1;
        while(i<=n){
            ll id = upper_bound(a+1,a+n+1,a[i]+x)-a;
            id--;
            id = min(id-i+1,(ll)c);
            i = i + id ;
            cnt++;
        }
        return (cnt<=m);
    }

    void Sol(){
        sort(a+1,a+1+n);
        ll d = 1;
        ll c = 1e18;
        while(d+1<c){
            ll mid = (d+c)/2;
            if(Check(mid)) c = mid;
            else d = mid;
        }
        if(Check(d)) cout << d;
        if(Check(c)) cout << c;
    }

}
namespace sub_task2{

    void Sol(){

        
    }

}
___Watbor___{
    Boost
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    Doc();
    sub_task1::Sol();
    sub_task2::Sol();
    cerr << "\nTime elapsed:" << 0.001*clock();
}