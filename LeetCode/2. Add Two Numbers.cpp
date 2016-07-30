#include <iostream>
#include <stdio.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL && l2 == NULL) {
    		return NULL;
    	}
    	ListNode* ret;
    	int len1 = 0, len2 = 0, carry = 0;
    	for(ListNode* it = l1; it != NULL; it = it->next) {
    		len1 ++;
    	}
    	for(ListNode* it = l2; it != NULL; it = it->next) {
    		len2 ++;
    	}
    	int len = len1 > len2 ? len1 : len2;
    	ListNode* a = l1;
    	ListNode* b = l2;
    	ListNode* tmp = ret;
    	for(int i = 0; i < len; i ++) {
    		int x, y;
    		if(l1 == NULL) x = 0;
    		else {
    			x = l1->val;
    			l1 = l1->next;
    		}
    		if(l2 == NULL) y = 0;
    		else { 
    			y = l2->val;
    			l2 = l2->next;
    		}
    		int k = x + y + carry;
    		tmp->val = k % 10;
    		carry = k / 10;
    		tmp = tmp->next;
    	}
    	return ret;
    }
};
#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
//	freopen("/Users/apple/out.txt","w",stdout);
#endif
    int n, m;
    scanf("%d", &n); 
    ListNode* l1, *a;
    ListNode* l2, *b;
    a = l1;
    b = l2; 
    for(int i = 0; i < n; i ++) {
    	int x;
    	scanf("%d", &x);
    	a = a->next = new ListNode(x);
    }
    for(int i = 0; i < m; i ++) {
    	int x;
    	scanf("%d", &x);
    	b = b->next = new ListNode(x);
    }
	Solution ans;
	ListNode* ret = ans.addTwoNumbers(l1->next, l2->next);
	while(ret != NULL) {
		printf("%d ", ret->val);
		ret = ret->next;
	}
}