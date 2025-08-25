#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; 
    cin >> N >> K;

    deque<int> q;
    for (int i = 1; i <= N; ++i) q.push_back(i);

    vector<int> ans; 
    ans.reserve(N);

    while (!q.empty()) {
        for (int i = 1; i < K; ++i) {
            q.push_back(q.front());
            q.pop_front();
        }
        ans.push_back(q.front());
        q.pop_front();
    }

    cout << '<';
    for (int i = 0; i < N; ++i) {
        if (i) cout << ", ";
        cout << ans[i];
    }
    cout << ">\n";
    return 0;
}
