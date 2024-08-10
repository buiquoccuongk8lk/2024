#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), greater<int>());
  int left = q, right = n;
  int ans = -1;

  while (left <= right) {
    int mid = (left + right)/2;

    long long total = 0;
    for (int i = 0; i < n; i++) {
      if (i < q - 1 || i >= mid - 1) {
        total += m;
        continue;
      }

      if (a[i] > a[mid-1] + m) {
        total = -1;
        break;
      }
      
      total += (a[mid-1] + m) - a[i];
    }

    if (total >= (long long) m * k) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << ans << '\n';
  return 0;
}