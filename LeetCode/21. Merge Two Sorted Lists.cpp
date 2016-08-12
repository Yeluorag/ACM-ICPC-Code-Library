#include <iostream>
#include <cstdio>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head(-1);
		ListNode* tmp = &head;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				tmp->next = l1;
				l1 = l1->next;
			} else {
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		if(l1) tmp->next = l1;
		if(l2) tmp->next = l2;
		return head.next;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

	return 0;

}