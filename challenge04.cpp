#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e18;

vector<pair<int, int>> take[N];
long long dp[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    take[b].emplace_back(a, c);
  }
  fill(dp, dp + N, -inf);
  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
    for (auto it : take[i]) {
      dp[i] = max(dp[i], dp[it.first - 1] + it.second);
    }
  }
  cout << dp[N - 1] << endl;
  return 0;
}
