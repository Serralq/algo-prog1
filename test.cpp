#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::cout << n << "\n";

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    // Setup random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // Hospital preference
    for (int i = 0; i < n; i++) {
        std::shuffle(p.begin(), p.end(), g);
        for (int j = 0; j < n; j++) {
            std::cout << p[j] << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    // Student preference
    for (int i = 0; i < n; i++) {
        std::shuffle(p.begin(), p.end(), g);
        for (int j = 0; j < n; j++) {
            std::cout << p[j] << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
