#include <bits/stdc++.h>

using namespace std;

vector<int> toVector(long long n) {
    vector<int> res;
    while (n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    if (res.empty())
        res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}

const int MAXN = 16;
long long cnt[MAXN][2][2], freq[MAXN][2][2], dp[MAXN][2][2];

long long solve(long long x) {
    vector<int> s = toVector(x);
    int n = s.size();
    long long ans = 0;

    for(int a = 0; a <= 9; ++a) {
        for(int len = 0; len <= n; ++len)
            for(int lo = 0; lo <= 1; ++lo)
                for(int lead = 0; lead <= 1; ++lead)
                    cnt[len][lo][lead] = freq[len][lo][lead] = dp[len][lo][lead] = 0;
        cnt[0][0][0] = 1;
        freq[0][0][0] = 0;
        dp[0][0][0] = 0;

        for(int len = 0; len < n; ++len) {
            for(int lo = 0; lo <= 1; ++lo) {
                for(int lead = 0; lead <= 1; ++lead) {
                    int lim = lo ? 9 : s[len];
                    for(int d = 0; d <= lim; ++d) {
                        int nxtLo = lo | (d < s[len]);
                        int nxtLead = lead | (d > 0);

                        cnt[len+1][nxtLo][nxtLead] += cnt[len][lo][lead];

                        freq[len+1][nxtLo][nxtLead] += freq[len][lo][lead];
                        if (d == a && (d > 0 || lead))
                            freq[len+1][nxtLo][nxtLead] += cnt[len][lo][lead];

                        dp[len+1][nxtLo][nxtLead] += dp[len][lo][lead];
                        if (d > a)
                            dp[len+1][nxtLo][nxtLead] += freq[len][lo][lead];
                    }
                }
            }
        }

        for(int lo = 0; lo <= 1; ++lo)
            for(int lead = 0; lead <= 1; ++lead)
                ans += dp[n][lo][lead];
    }

    return ans;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        cout << solve(r) - solve(l-1) << endl;
    }

    return 0;
}