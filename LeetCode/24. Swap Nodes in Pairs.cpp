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
	ListNode* swapPairs(ListNode* head) {
		ListNode* tmp = head;
		while(tmp != NULL) {
			if(tmp->next == NULL) break;
			swap(tmp->val, tmp->next->val);
			tmp = tmp->next->next;
		}
		return head;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
	

	return 0;

}