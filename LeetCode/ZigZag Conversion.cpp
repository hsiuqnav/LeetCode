#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (1 == numRows)
			return s;
		string result;
		int interval = 0;
		for (int i = 0; i < numRows; ++i) {
			if (numRows - 1 == i || 0 == i) {
				interval = 2 * (numRows - 1);
				ConvertCoreWithHeadOrEnd(s, i, interval, result);
			}
			else {
				interval = 2 * (numRows - i - 1);
				ConvertCoreExpectHeadOrEnd(s, interval, i, result);
			}
		}
		return result;
	}
	
	// return zero or one with even or odd
	// if isEvenZero true then return zero with even, return one with odd
	int ZeroOrOne(int para, bool isEvenZero) {
		bool isOdd = (para & 0x1 == 1);
		if (isOdd == isEvenZero)
			return 1;
		else
			return 0;
	}

	void ConvertCoreExpectHeadOrEnd(string s, int interval, int startNum, string &res) {
		int size = s.size();
		int index = startNum;
		int round = 1;
		while (startNum < size) {
			res.push_back(s[startNum]);
			startNum += interval * ZeroOrOne(round, true) + index * 2 * ZeroOrOne(round, false);
			round += 1;
		}
	}

	void ConvertCoreWithHeadOrEnd(string s, int startNum, int interval, string &res) {
		int size = s.size();
		while (startNum < size) {
			res.push_back(s[startNum]);
			startNum += interval;
		}
	}
};