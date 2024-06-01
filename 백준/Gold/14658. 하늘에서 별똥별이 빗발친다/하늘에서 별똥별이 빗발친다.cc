#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, l, k;
    std::cin >> n >> m >> l >> k;

    std::vector<std::pair<int, int>> stars(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> stars[i].first >> stars[i].second;
    }

    int maxStars = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            int x1 = stars[i].first;
            int y1 = stars[j].second;

            int count = 0;

            for (int t = 0; t < k; ++t) {
                int x2 = stars[t].first;
                int y2 = stars[t].second;
                if (x1 <= x2 && x2 <= x1 + l && y1 <= y2 && y2 <= y1 + l) {
                    count++;
                }
            }

            maxStars = std::max(maxStars, count);
        }
    }

    int result = k - maxStars;
    std::cout << result << std::endl;

    return 0;
}
