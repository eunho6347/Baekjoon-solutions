#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<string> words;

    for(int i=0; i<N; i++){
        string k;
        cin >> k;
        words.push_back(k);
    }

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
    });
    
    words.erase(unique(words.begin(), words.end()), words.end());
    
    for(auto k: words){
        cout << k << '\n';
    }

    return 0;
}
