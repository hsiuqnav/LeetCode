#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
		int carry = 0;
		ListNode *front, *tmphead;
		int sum = 1, val1, val2;
		tmphead = new ListNode(0);
		front = tmphead;

		while (0 != sum || 0 != carry || NULL != l1 || NULL != l2){
			if (NULL != l1){
				val1 = l1->val;
				l1 = l1->next;
			}
			if (NULL != l2){
				val2 = l2->val;
				l2 = l2->next;
			}
			sum = val1 + val2 + carry;
			if (sum >= 10){
				carry = sum / 10;
				sum = sum % 10;
			}
			else
				carry = 0;
			front->next = new ListNode(sum);
			front = front->next;
			val1 = 0;
			val2 = 0;
			sum = 0;
		}
		return tmphead->next;
	}
};