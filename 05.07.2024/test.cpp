#include <bits/stdc++.h>
using namespace std;

#define fore(i,a,b) for(auto i=(a);i<=(b);i++)

const int maxn = 305 + 5,
					dx[] = {0, 0, 1, -1},
					dy[] = {1, -1, 0, 0};

void solve()
{
	int n, m, ans = 1e9; cin >> n >> m;
	vector<vector<char>> a(n + 1, vector<char>(m + 1));
	fore(i, 1, n)
		fore(j, 1, m) cin >> a[i][j];
	fore(s, '0', '9')
	{
		vector<vector<int>> dist_up(n + 1, vector<int>(m + 1, 1e9)),
												dist_down(n + 1, vector<int>(m + 1, 1e9));
		// get distance from up row
		{
			vector<queue<pair<int,int>>> q((m + n) * 4 * 9);
			fore(i, 1, m) 
				q[abs(s - a[1][i])].push({1, i}),
				dist_up[1][i] = abs(s - a[1][i]);
			for (int i = 0; i < (m + n) * 4 * 9; i++)
				while (q[i].size())
				{
					auto [x, y] = q[i].front(); q[i].pop();
					if (i != dist_up[x][y]) continue;
					fore(k, 0, 3)
					{
						int u = x + dx[k], v = y + dy[k];
						if (u > n || u < 1 || v > m || v < 1) continue;
						int w = abs(a[u][v] - s);
						if (dist_up[u][v] > i + w)
							dist_up[u][v] = i + w,
							q[i + w].push({u, v});
					}
				}
		}
		// get distance from down row
		{
			vector<queue<pair<int,int>>> q(((m + n)) * 4 * 9);
			fore(i, 1, m) 
				q[abs(s - a[n][i])].push({n, i}),
				dist_down[n][i] = abs(s - a[n][i]);
			for (int i = 0; i < ((m + n)) * 4 * 9; i++)
				while (q[i].size())
				{
					auto [x, y] = q[i].front(); q[i].pop();
					if (i != dist_down[x][y]) continue;
					fore(k, 0, 3)
					{
						int u = x + dx[k], v = y + dy[k];
						if (u > n || u < 1 || v > m || v < 1) continue;
						int w = abs(a[u][v] - s);
						if (dist_down[u][v] > i + w)
							dist_down[u][v] = i + w,
							q[i + w].push({u, v});
					}
				}
		}

		vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(m + 1, vector<int>(4, 1e9)));
		vector<queue<tuple<int, int, int>>> q(((m + n)) * 4 * 9);
		fore(i, 1, n)
			q[abs(a[i][1] - s)].push({i, 1, 0}),
			dist[i][1][0] = abs(a[i][1] - s);
		fore(i, 0, ((m + n)) * 4 * 9 - 1)
			while (q[i].size())
			{
				auto [x, y, state] = q[i].front(); q[i].pop();
				if (dist[x][y][state] != i) continue;
				if (y == m && state == 3) 
				{
					ans = min(ans, i);
					break;
				}
				if (state == 0)
				{
					if (dist[x][y][1] > i + dist_up[x][y] - abs(s - a[x][y]))
						dist[x][y][1] = i + dist_up[x][y] - abs(s - a[x][y]),
						q[dist[x][y][1]].push({x, y, 1});
					if (dist[x][y][2] > i + dist_down[x][y] - abs(s - a[x][y])) 
						dist[x][y][2] = i + dist_down[x][y] - abs(s - a[x][y]),
						q[dist[x][y][2]].push({x, y, 2});
				}
				else if (state == 1)
				{
					if (dist[x][y][3] > i + dist_down[x][y] - abs(s - a[x][y]))
						dist[x][y][3] = i + dist_down[x][y] - abs(s - a[x][y]),
						q[dist[x][y][3]].push({x, y, 3});
				}
				else if (state == 2)
				{
					if (dist[x][y][3] > i + dist_up[x][y] - abs(s - a[x][y]))
							dist[x][y][3] = i + dist_up[x][y] - abs(s - a[x][y]),
							q[dist[x][y][3]].push({x, y, 3});
				}
				fore(k, 0, 3)
				{
					int u = x + dx[k], v = y + dy[k];
					if (u > n || u < 1 || v < 1 || v > m) continue;
					int w = abs(s - a[u][v]);
					if (dist[u][v][state] > i + w)
						dist[u][v][state] = i + w,
						q[i + w].push({u, v, state});
				}
			}
	}
	cout << ans;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int tc; cin >> tc;
	while (tc--)
		solve(),
		cout << '\n';
	return 0;
}