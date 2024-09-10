#include <bits/stdc++.h>
using namespace std;
long long c,x,y,z,n,m,q;
int i,j,k;
bool d[1000001];
typedef pair<long long,int>i2;
typedef pair<long long,i2>i3;
vector<i3>g;
vector<i2>b,a[1000001];
priority_queue<i2,vector<i2>,greater<i2> >pq;
long long dem[1000001],dij[1000001];
void dijkstra()
{
    for (int i=1;i<=n;i++)
    dij[i]=1e18;
    dij[1]=-q-1;
    pq.push({dij[1],1});
    while (pq.size()!=0)
    {
        long long w=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        //if (dij[u]<w) continue;
        long long z=0;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].second;
            z=max(w,a[u][i].first);
            if (dij[v]>z)
            {
                dij[v]=z;
                pq.push({dij[v],v});
            }
        }
    }
}
int main()
{
    freopen(".inp", "r" ,stdin);
    freopen(".out", "w" ,stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        g.push_back({0,{x,y}});
        dem[y]++;
    }
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>z>>x;
        b.push_back({z,x});
        if (z==1 && g[x-1].first==0)
        {
            g[x-1].first=i;
        }
    }
    for (int i=0;i<m;i++)
    {
        z=g[i].first; x=g[i].second.first; y=g[i].second.second;
        if (z==0) z=q+1;
//        cout<<i+1<<" "<<z<<"\n";
        z=-z;
        if (x==y) continue;
        a[x].push_back({z,y});
    }
    dijkstra();
//    for (int i=1;i<=n;i++)
//        cout<<dij[i]<<" ";
    for (int i=1;i<=q;i++)
    {
        z=b[i-1].first; x=b[i-1].second;
        if (z==1)
        {
            if (d[x]==0){
            d[x]=1;
            y=g[x-1].second.second;
            dem[y]--;
            }
        } else {
        c=-dij[x];
        if (c<i) cout<<0<<"\n"; else cout<<dem[x]<<"\n";
        }
    }
}