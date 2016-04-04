#include <iostream>
using namespace std;

class Solution{
public:
	int const MAX = 0x7fffffff;
	int reverse(int x){
		if (x < 0) {
			x = 0 - x;
			return 0 - _ReverseCore(x);
		}
		return _ReverseCore(x);
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
		if (result > MAX){
			result = 0;
		}
		return result;
	}
};