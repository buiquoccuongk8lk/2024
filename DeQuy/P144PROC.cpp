
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define WATBOR ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr(i,a,b) for(i=a;i<=b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define lb lower_bound
#define up upper_bound
ll n,i,j,k,x,y,z,t,l,r;ll maxx=-2e9;ll minn=2e9;
const ll SIZE =1e5+5;
//ll mi[10000000];
//ll ma[10000000];
//ll ps[1000000];
//ll a[SIZE];
//ll b[SIZE];
//ll dp[SIZE];
ll a,b;
ll gcd(ll a,ll b) {ll temp;while(b!=0) {temp = a%b;a=b;b=temp;}return a;}
ll lcm(ll a,ll b) {return a/gcd(a,b) *b;}
/*ll prime[1000007];const ll N =1000007;ll cnt=1;
void Sang() {
    for(i=2;i<=N;i++) {
        prime[i] = 1;
    }
    prime[1]=prime[0] =0;
    for(i=2;i<=sqrt(N);i++) {
        if(prime[i]==1){
            for(j=i*i;j<=N;j+=i) {
                prime[j] =0;}
        }   
    }
    fr(i,1,N){
        if(prime[i]){
            b[cnt++] = i;
        }
    }
}*/

ll Sol(ll x , ll y){
    if(y==0) return 1;
    ll temp = Sol(x,y/2);
    if(y%2==1) return ((temp*temp)%(1000000007)*x)%(1000000007);
    else return (temp*temp)%(1000000007);
}
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    WATBOR
    /*if(fopen("Watbor.inp","r")){
        freopen("Watbor.inp","r",stdin);
        freopen("Watbor.out","w",stdout);
    }*/
    while(1){
        cin >> a >> b;
        if(a==0 && b==0) return 0;
        cout << Sol(a,b)<<endl;
    }
    LamMau();
}