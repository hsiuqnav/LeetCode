#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> result;
		unordered_multimap<int, int> hash;
		for (int i = 0; i < nums.size(); i++)
		{
			hash.insert(pair<int, int>(nums[i], i + 1));
		}
		sort(nums.begin(), nums.end());
		int s = 0, e = nums.size() - 1;
		int sum = 0;
		while (1)
		{
			sum = nums[s] + nums[e];
			if (s >= e)
				break;
			if (sum == target)
			{
				if (nums[s] != nums[e])
				{
					result.push_back(hash.find(nums[s])->second);
					result.push_back(hash.find(nums[e])->second);
				}
				else
				{
					pair<unordered_multimap<int, int>::iterator,
						unordered_multimap<int, int>::iterator> ele = hash.equal_range(nums[s]);
					result.push_back(ele.first->second);
					unordered_multimap<int, int>::iterator it = ++ ele.first;
					result.push_back(it->second);
				}
				int tmp = result[0];
				if (tmp > result[1])
				{
					result[0] = result[1];
					result[1] = tmp;
				}
				return result;
			}
			else if (sum > target)
			{
				e--;
			}
			else
			{
				s++;
			}
		}
		return result;
	}
};