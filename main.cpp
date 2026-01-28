#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> readInput() {
    int n;
    cin >> n;
    vector<vector<int>> preferences(2 * n, vector<int>(n, -1));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
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
        if (preferences[n + a][i] == h1 + 1)
            return true;
        // if we get to h first, applicant a does not prefer h1 to h
        if (preferences[n + a][i] == h + 1)
            return false;
    }
}

void solve() {
    vector<vector<int>> preferences = readInput();
    
    bool valid = validateInput(preferences);
    if (!valid) {
        cout << "INVALID INPUT" << endl;
        return;
    }
    
    int n = preferences[0].size();
    vector<int> hospitalMatches(n, -1);
    vector<int> applicantMatches(n, -1);
    vector<int> attemptTracker(n, 0);
    int freeCount = n;

    // while there are unmatched pairs
    while (freeCount > 0) {
        // find a free hospital
        int hospital;
        for (hospital = 0; hospital < n; hospital++) {
            if (hospitalMatches[hospital] == -1) {
                break;
            }
        }
        // find the next applicant that the hospital hasn't already tried to match with
        int curAttempt = attemptTracker[hospital];
        attemptTracker[hospital]++;
        int applicant = preferences[hospital][curAttempt] - 1;

        // check if the applicant is free
        if (applicantMatches[applicant] == -1) {
            hospitalMatches[hospital] = applicant;
            applicantMatches[applicant] = hospital;
            freeCount--;
        // otherwise check if that applicant prefers this new hospital to the one they are already paired with
        } else {
            int currentAssignment = applicantMatches[applicant];
            if (applicantPrefersH1ToH(preferences, applicant, currentAssignment, hospital)) {
                hospitalMatches[hospital] = applicant;
                applicantMatches[applicant] = hospital;
                hospitalMatches[currentAssignment] = -1;
            }
        }
    }
    // print out all results (+1 needed because hospitals and applicants are tracked as 0 indexed in my implementation)
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << hospitalMatches[i] + 1 << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}
