#include <iostream>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int *hash = new int[256]();
		int length = 0;
		int tmplength = 0;
		int first = 0, last = 0;

		while (first <= last && last < s.size()){
			if (!hash[s[last]]){
				hash[s[last]] = 1;
				last++;
				tmplength++;
			}
			else{
				hash[s[first]] = 0;
				first++;
				tmplength--;
			}
			if (tmplength > length){
				length = tmplength;
			}
		}
		delete[] hash;
		return length;
	}
};