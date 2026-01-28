#include <bits/stdc++.h>

vector<vector<int>> readInput() {
    int n;
    std::cin >> n;
    vector<vector<int>> preferences(2 * n, vector<int>(n, -1));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            int p;
            std::cin >> p;
            preferences[i][j] = p;
        }
    }
    return preferences;
}

void solve() {
    int n;
    std::cin >> n;
    while (n--) {
        std::string s;
        std::cin >> s;
        std::cout << s << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();
}
