#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m == 0 && n == 0)
			return 0;
		if ((m + n) % 2 == 0) {
			double res1 = findNumbers(nums1, nums2, (m + n) / 2 - 1);
			double res2 = findNumbers(nums1, nums2, (m + n) / 2);
			return (res1 + res2) / 2;
		}
		else {
			return findNumbers(nums1, nums2, (m + n - 1) / 2);
		}
	}

	double findNumbers(vector<int>& nums1, vector<int>& nums2, const int& num) {
		if (nums1.empty())
			return findNumbers(nums2, nums1, num);
		if (nums2.empty())
			return nums1[num];
		int begin = 0;
		int end = 0;
		if (num < nums1.size())
			end = num;
		else
			end = nums1.size() - 1;
		bool finded = true;
		int binary = -1;
		while (begin != end || binary != end) {
			binary = (begin + end) / 2;
			if (binary + nums2.size() < num) {
				begin = binary;
				continue;
			}
			finded = true;
			if (num - binary - 1 >= 0 && nums1[binary] < nums2[num - binary - 1]) {
				if (begin == binary && begin != end)
					begin = binary + 1;
				else
					begin = binary;
				finded = false;
			}
			if (num - binary < nums2.size() && nums1[binary] > nums2[num - binary]) {
				if (end == binary && end != begin)
					end = binary - 1;
				else
					end = binary;
				finded = false;
			}
			if (finded)
				return nums1[binary];
		}
		return findNumbers(nums2, nums1, num);
	}
};