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

bool validateInput(vector<vector<int>> &preferences) {
    int r = preferences.size();
    if (r == 0) return false;
    int c = preferences[0].size();
    if (r != c * 2) return false;
    for (int i = 0; i < r; i++) {
        if (preferences[i].size() != c) return false;
    }
    return true;
}

bool applicantPrefersH1ToH(vector<vector<int>> &preferences, int a, int h, int h1) {
    int n = preferences[0].size();
    for (int i = 0; i < n; i++)
    {
        // if we get to h1 first, applicant a prefers h1 to h
        if (prefer[n + a - 1][i] == h1)
            return true;
        // if we get to h first, applicant a does not prefer h1 to h
        if (prefer[n + a - 1][i] == h)
            return false;
    }
}

void solve() {
    vector<vector<int>> preferences = readInput();
    bool valid = validateInput(preferences);
    if (!valid) {
        std::cout << "INVALID INPUT" << std::endl;
        return;
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();
}
