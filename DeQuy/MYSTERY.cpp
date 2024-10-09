
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr(i,a,b) for(i=a;i<=b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define lb lower_bound
#define up upper_bound
ll i,m,c,n,j,k,x,y,z,t,l,r;ll maxx=-2e9;ll minn=2e9;
const ll SIZE =1e6;
//ll mi[10000000];
//ll ma[10000000];
//ll ps[1000000];
ll a[SIZE];
//ll b[SIZE];
//ll dp[SIZE];
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
void Doc() {
    cin >> n ;
}
const ll MOD = 20122007;
ll Sol(ll x , ll y){
    if(y==0) return 1;
    ll temp = Sol(x,y/2);
    if(y%2==1) return ((temp*temp)%(MOD)*x)%(MOD);
    else return (temp*temp)%(MOD);
}
void Sol(){
    ll cnt=1;
    fr(i,1,sqrt(n)){
        if(n%i==0){
            a[cnt++] = i;
            if(i!= n/i){
                a[cnt++] = n/i;
            }
        }
    }
    cnt--;  
    ll s=1;
    fr(i,1,cnt){
        s=  (ll)(  ( (s%MOD)*  (Sol(3,a[i]) -1)%MOD)   ) %MOD  ;
    }
    cout << s%MOD;

}
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    goi5gviettel
    /*if(fopen("Watbor.inp","r")){
        freopen("Watbor.inp","r",stdin);
        freopen("Watbor.out","w",stdout);
    }*/
    Doc();
    Sol();
    LamMau();
}
