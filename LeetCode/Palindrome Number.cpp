#include <iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if (0 <= x && _ReverseCore(x) == x)
			return true;
		return false;
	}
private:
	unsigned long long _GetUnits(unsigned long long num){
		return num % 10;
	}

	unsigned long long _RightShiftWithDecimal(unsigned long long num){
		return num / 10;
	}

	unsigned long long _LeftShiftWithDecimal(unsigned long long num){
		return num * 10;
	}

	int _ReverseCore(unsigned long long num){
		unsigned long long result = 0;
		while (num > 0){
			result = _LeftShiftWithDecimal(result);
			result += _GetUnits(num);
			num = _RightShiftWithDecimal(num);
		}
		if (result > INT_MAX){
			result = 0;
		}
		return result;
	}
};