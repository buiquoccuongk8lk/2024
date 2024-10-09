#include<bits/stdc++.h>
using namespace std;
#define         ll long long
#define         goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(i=a;i<=b;i++)
#define         fd(i,b,a) for(i=b;i>=a;i--)



ll n,k;
ll t[31];
void Doc() {
    cin >> n >> k;
    ll i;
    fr(i,1,n) cin >> t[i]; 
    
    
}
ll ans=2e9;
ll cnt = 0;
void ql2(ll pos,ll sum,ll cnt){
    if(sum>k || cnt>ans) return ;
    if(pos>n){
        if(sum==k) ans = min(ans,cnt);
        return ;
    }
    ql2(pos+1,sum,cnt);//khong chon i
    ql2(pos+1,sum+t[pos],cnt+1);
}

void Sol(){
  //ql1(1);
  ql2(0,0,0);
  cout << ans;
}
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    goi5gviettel
    
    Doc();
    Sol();
    LamMau();
}
