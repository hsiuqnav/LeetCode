#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		if (s.length() == 1)
			return s;
		int start = 0, max_length = 0;
		int middle = 0;
		while (middle < s.length() && s.length() - middle > max_length / 2) {
			int left = middle, right = middle;
			while (right < s.length() - 1 && s[right] == s[right + 1])
				right ++;
			middle ++;
			while (left > 0 && s[left - 1] == s[right + 1]) {
				left --;
				right ++;
			}
			if (max_length < right - left + 1) {
				max_length = right - left + 1;
				start = left;
			}
		}
		return s.substr(start, max_length);
	}
};