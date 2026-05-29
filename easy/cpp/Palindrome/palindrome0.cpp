#include <charconv>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        char buffer[10];
        auto [ptr, ec] = std::to_chars(buffer, buffer + sizeof(buffer), x);

        if (ec == std::errc()) {
            std::string intStr(buffer, ptr);
            std::string newStr = "";
            int index = static_cast<int>(intStr.size() - 1);

            for (; index >= 0; --index) {
                newStr += intStr[index];
            }

            if (intStr == newStr) {
                return true;
            }
        }

        return false;
    }
};