
#include<bits/stdc++.h>

using namespace std;

#define         TASK ""
#define         INPUT TASK".INP"
#define         OUTPUT TASK".OUT"

#define int long long
#define Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define fillchar(a,x) memset(a,x,sizeof(a))
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair

const int inf = 1e18 , MOD = 1e9+7 , N  = 1e5+5;
int add(int a,int b){
    return (a+b)%MOD;
}
int mul(int a,int b){
    return (a*b)%MOD;
}
int fact[(int)2e6+5];
void factory(){
    fact[0] = 1;
    fr(i,1,2e6) fact[i] = mul(fact[i-1],i);
}
int LT(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    int c = LT(x,y/2);
    if(y%2==1) return mul(c,mul(c,x));
    else return mul(c,c);
}
int C(int n,int k){
    return mul( fact[n] , LT ( mul(fact[k],fact[n-k])  , MOD-2    )  );
}
string s;
void Doc() {
    cin >> s;
}
void Sol(){
    factory();
    map<char,int>mp;
    for(auto x:s){
        mp[x]++;
    }
    int ans = 1;
    int W = s.size();
    for(auto x:mp){ 
        ans = mul(ans, C(W,x.se));
        W-=x.se;
    }
    cout << ans;
}


signed main(){
    Boost
    if(fopen(INPUT,"r")){
        freopen(INPUT,"r",stdin) ; freopen(OUTPUT,"w",stdout);
    }
    Doc();
    Sol();
}


