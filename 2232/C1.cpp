#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    vector<int> dp(x + 1, -INF);
    dp[x] = 0;

    for (char c : u) {
        vector<int> next_dp = dp;

        for (int e = 0; e <= x; e++) {
            if (dp[e] == -INF) continue;

            int ans = dp[e];
            int fs = (x - e) * s - ans;

            if (c == 'I') {
                next_dp[e] = max(next_dp[e], ans);
                if (e > 0) {
                    next_dp[e - 1] = max(next_dp[e - 1], ans + 1);
                }
            } else if (c == 'E') {
                if (fs > 0) {
                    next_dp[e] = max(next_dp[e], ans + 1);
                }
            } else if (c == 'A') {
                if (fs > 0) {
                    next_dp[e] = max(next_dp[e], ans + 1);
                }
                if (e > 0) {
                    next_dp[e - 1] = max(next_dp[e - 1], ans + 1);
                }
            }
        }
        dp = move(next_dp);
    }

    int max_seated = 0;
    for (int e = 0; e <= x; e++) {
        max_seated = max(max_seated, dp[e]);
    }

    cout << max_seated << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
