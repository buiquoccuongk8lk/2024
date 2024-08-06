// Author : WatborNoLegit - Bùi Quốc Cường - ITK34 - THPT Chuyên Lê Khiết - Quảng Ngãi
#include<bits/stdc++.h>

using namespace std;

#define         TASK ""
#define         int long long
#define         FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define         FORD(i,a,b) for(int i = a ; i >= b ; i--)
const int inf = 1e18 , MOD = 1e9+7 , N = 1e6+5; 

int n,m;
vector<int> G[N];
void Doc()
{
    cin >> n >> m ;
    FOR(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

}

namespace sub
{
    int low[N],num[N],tp[N],visited[N],par[N],nc[N],k[N];
    vector<int> br ;
    deque<int>dq;
    int stt = 0 ;
    int scc = 0 ; 
    int cc =  0 ;
    int khop = 0;
    void tarjan(int u)
    {
        stt++;
        num[u] = low[u] = stt;
        nc[u] = 0;
        dq.push_back(u);
        for(auto v : G[u])
        {
            if(par[u] == v) continue;
            if(visited[v]) continue;
            if(num[v] > 0)
            {
                low[u] = min( low[u] , num[v] ); 
            }else
            {
                par[v] = u;
                nc[u]++;
                tarjan(v);
                low[u] = min( low[u] , low[v] );
                if( low[v] > num[u] ) 
                {
                    cc++;
                    br.push_back(v) ;
                    br.push_back(u) ;
                }
                if(low[v] >= num[u])
                {
                    k[u] = 1;
                }
            }
        }
        if(low[u] == num[u])
        {
            scc++;
            int x;
            do
            {
                x = dq.back();
                dq.pop_back();
                tp[x] = scc;
                visited[x] = 1;
            }while( x!=u );
        }
    }
    void Sol()
    {
        
        FOR(i,1,n)
        {
            if(num[i]==0)
            {
                tarjan(i);
                if(nc[i] < 2) k[i] = 0;
            }
        }
        int dem = 0 ;FOR(i,1,n) if(k[i])dem++;
        cout << dem << endl ;
        FOR(i,1,n) if(k[i]) cout << i << ' ' ;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(TASK".INP","r") ) 
    {
        freopen(TASK".INP","r",stdin); freopen(TASK".OUT","w",stdout);
    }
    
    Doc();
    sub::Sol();
}