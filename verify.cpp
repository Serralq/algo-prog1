#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // Global var
    bool invalid = false;
    std::string reason = "";

    // Reading length
    int n;
    if (!(std::cin >> n) ) {
        std::cout << "Missing data\n";
        return 0;
    }

    // Hospital preferences with index start at 1
    std::vector<std::vector<int>> prefH(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> prefH[i][j];
        }
    }

    // Read Student Preferences
    std::vector<std::vector<int>> prefS(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int h;
            std::cin >> h;
            prefS[i][h] = j; 
        }
    }

    // Read given matching
    std::vector<int> matchHtoS(n + 1, 0);
    std::vector<int> matchStoH(n + 1, 0);
    std::vector<bool> hMatched(n + 1, false);
    std::vector<bool> sMatched(n + 1, false);


    for (int i = 0; i < n; i++) {
        int h, s;
        // Can read
        if (!(std::cin >> h >> s)) {
            invalid = true;
            reason = "Incomplete matching provided.";
            break;
        }

        // Correct range
        if (h < 1 || h > n || s < 1 || s > n) {
            invalid = true;
            reason = "ID out of bounds.";
            break;
        } 

        // Previous match
        if (hMatched[h] || sMatched[s]) {
            invalid = true;
            reason = "Duplicate match detected.";
            break;
        } 

        matchHtoS[h] = s;
        matchStoH[s] = h;
        hMatched[h] = true;
        sMatched[s] = true;
    }

    // Check if all are matched
    if (!invalid) {
        for (int i = 1; i <= n; ++i) {
            if (!hMatched[i] || !sMatched[i]) {
                invalid = true;
                reason = "Unmatched student/hospital.";
                break;
            }
        }
    }

    if (invalid) {
        std::cout << "INVALID (" << reason << ")" << std::endl;
        return 0;
    }

    // Check Stability
    for (int h = 1; h <= n; ++h) {
        // Currently assigned S to H
        int currentS = matchHtoS[h];
        
        for (int j = 1; j <= n; ++j) {
            // A S' that hospital prefers compared to current S
            int preferredS = prefH[h][j];
            
            // Break so don't check what's prefered less than current
            if (preferredS == currentS) break;

            // S' currently assigned H'
            int currentHofS = matchStoH[preferredS];
            // If S' H rank is lower (aka better) than S' H' rank
            if (prefS[preferredS][h] < prefS[preferredS][currentHofS]) {
                std::cout << "UNSTABLE (Blocking pair: H " << h << ", S " << preferredS << ")" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "VALID STABLE" << std::endl;
    return 0;
}
