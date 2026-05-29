[Understanding Array Decay and Pointers](https://leetcode.com/problems/palindrome-number/solutions/8301653/understanding-array-decay-and-pointers-b-kzh0/)

# Intuition
1. My first thought was to check if the integer is less than 0. Negative numbers cannot be palindromes because the - sign only appears on the left side.

2. Next, convert the integer into characters using std::to_chars() and write them into a fixed-size buffer. This avoids allocating memory for a string during the conversion.

3. From there, there are two valid approaches:

    * Compare characters from both ends and move inward.
    * Create a string from the buffer, reverse it, and compare the two strings.

Both work, but the pointer approach avoids creating an additional string and does less work overall.

# Approach

This solution relies on C/C++ array-to-pointer decay and avoids creating a reversed copy of the number.

buffer decays to a pointer to its first element (&buffer[0]), which becomes the left pointer.

std::to_chars() returns a pointer (ptr) to one past the last character written, similar to end() on a container. Subtracting one (ptr - 1) moves us to the last digit, which becomes the right pointer.

We then compare both digits and move inward (++left, --right) until the pointers meet. If any pair of digits differs, the number is not a palindrome.
