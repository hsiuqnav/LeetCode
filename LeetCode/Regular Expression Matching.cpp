#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool isMatch(string s, string p){
		return isMatchCore(s, p, 0, 0);
	}

private:
	bool isMatchCore(string s, string p, int s_pos, int p_pos){
		if (s_pos >= s.length() && p_pos >= p.length())
			return true;
		if (p_pos >= p.length())
			return false;
		bool result = false;
		bool repeat = false;
		bool anychar = false;
		int next_p = p_pos + 1;
		if (p_pos + 1 < p.length() && '*' == p[p_pos + 1]){
			repeat = true;
			next_p += 1;
		}
		if ('.' == p[p_pos])
			anychar = true;

		if (repeat){
			result = result || isMatchCore(s, p, s_pos, next_p);
			while (s_pos < s.length()){
				if (anychar || s[s_pos] == p[p_pos])
					s_pos++;
				else
					break;
				result = result || isMatchCore(s, p, s_pos, next_p);
			}
			return result;
		}
		else{
			if (s_pos < s.length() && (anychar || s[s_pos] == p[p_pos])){
				s_pos++;
				return isMatchCore(s, p, s_pos, next_p);
			}
			else
				return false;
		}
	}
};


int main(){
}