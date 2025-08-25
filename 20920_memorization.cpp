#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<string, int> freq; 

    for (int i = 0; i < N; i++) {
        string w;
        cin >> w;
        if ((int)w.size() >= M) {
            freq[w]++;
        }
    }


    vector<pair<string, int>> words(freq.begin(), freq.end());


    sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;       // 빈도 우선
        if (a.first.size() != b.first.size()) return a.first.size() > b.first.size(); // 길이
        return a.first < b.first; 
    });

    for (auto& p : words) {
        cout << p.first << '\n';
    }

    return 0;
}
