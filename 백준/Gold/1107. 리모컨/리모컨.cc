#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int targetChannel, brokenCount;
    std::cin >> targetChannel >> brokenCount;

    std::vector<int> brokenButtons(brokenCount);
    for (int i = 0; i < brokenCount; ++i) {
        std::cin >> brokenButtons[i];
    }

    auto isButtonUsable = [&](int button) {
        return std::find(brokenButtons.begin(), brokenButtons.end(), button) == brokenButtons.end();
    };

    auto canPressChannel = [&](int channel) {
        if (channel == 0) {
            return isButtonUsable(0);
        }
        while (channel > 0) {
            if (!isButtonUsable(channel % 10)) {
                return false;
            }
            channel /= 10;
        }
        return true;
    };

    int currentChannel = 100;
    int minPresses = std::abs(targetChannel - currentChannel);

    for (int i = 0; i <= 1000000; ++i) {
        if (canPressChannel(i)) {
            int presses = std::to_string(i).length() + std::abs(i - targetChannel);
            if (presses < minPresses) {
                minPresses = presses;
            }
        }
    }

    std::cout << minPresses << std::endl;

    return 0;
}