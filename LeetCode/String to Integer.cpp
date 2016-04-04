#include <iostream>
using namespace std;

class Solution{
public:
	const int MAX = 0x7fffffff;
	const int MIN = 0x80000000;
	const int MAXBITS = 11;
	int myAtoi(string str){
		return myAtoiCore(str);
	}

private:
	string _DeletaFrontSpace(string str){
		int len = str.length();
		int pos = 0;
		for (int i = 0; i < len; ++i){
			if (' ' == str[i]){
				pos++;
			}
			else{
				break;
			}
		}
		if (pos == len)
			return string("0");
		else if (pos == 0)
			return str;
		else
			return str.substr(pos);
	}

	string _DeleteFrontZero(string str){
		int pos = 0;
		for (int i = 0; i < str.length(); ++i){
			if ('0' == str[i])
				pos++;
			else
				break;
		}
		return str.substr(pos);
	}

	string _Split(string str){
		for (int i = 0; i < str.length(); ++i){
			if ('0' > str[i] || '9' < str[i]){
				return str.substr(0, i);
			}
		}
		return str;
	}

	bool _isStringValid(string str){
		for (int i = 0; i < str.length(); ++i){
			if ('0' > str[i] || '9' < str[i])
				return false;
		}
		return true;
	}

	int myAtoiCore(string str){
		str = _DeletaFrontSpace(str);
		bool positive = true;
		if ('+' == str[0]){
			str = str.substr(1);
		}
		else if ('-' == str[0]){
			str = str.substr(1);
			positive = false;
		}
		str = _Split(str);
		if (!_isStringValid(str))
			return 0;
		str = _DeleteFrontZero(str);
		long long result = 0;
		if (MAXBITS <= str.length()){
			if (positive)
				return MAX;
			else
				return MIN;
		}
		for (int i = 0; i < str.length(); ++i){
			result *= 10;
			result += str[i] - '0';
		}

		if (positive){
			if (MAX < result){
				result = MAX;
			}
		}
		else{
			result = 0 - result;
			if (MIN > result){
				result = MIN;
			}
		}
		return result;
	}
};