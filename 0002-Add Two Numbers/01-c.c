#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *result = (struct ListNode*)malloc(sizeof(struct ListNode)), *tempnode;
	int l1_add_temp = 0, l2_add_temp = 0, carry = 0, result_temp;
	tempnode = result;
	while(1){
		if(l1 == NULL && l2 == NULL && carry == 0) {
			break;
		}
		if(l1 != NULL){
			l1_add_temp = l1->val;
			l1 = l1->next;
		}else {
			l1_add_temp = 0;
		}
		if(l2 != NULL){
			l2_add_temp = l2->val;
			l2 = l2->next;
		}else {
			l2_add_temp = 0;
		}
		result_temp = l1_add_temp+l2_add_temp+carry;
		carry = (int)result_temp/10;
		tempnode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		tempnode = tempnode->next;
		tempnode->val = result_temp%10;
		tempnode->next = NULL;
	}
	result = result->next;
	return result;
}


int main(int argc, char *argv[]) {
	struct ListNode *l1_head, *l2_head, *temp;
	struct ListNode *result;
	int l1_len = 3;
	int l2_len = 3;
	int listnode1[100000] = {2,4,5};
	int listnode2[100000] = {5,6,4};


	l1_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	temp = l1_head;
	for(int i=0;i<l1_len;i++){
		temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp = temp->next;
		temp->val = listnode1[i];
		temp->next = NULL;
	}
	l1_head = l1_head->next;
	
	
	
	l2_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	temp = l2_head;
	for(int i=0;i<l2_len;i++){
		temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp = temp->next;
		temp->val = listnode2[i];
		temp->next = NULL;
	}
	l2_head = l2_head->next;
	
	
	
	result = addTwoNumbers(l1_head, l2_head);
	
	
	
	while(1) {
		printf("%d", result->val);
		if(result->next != NULL) {
			result = result->next;
		}else {
			break;
		}
	}
	return 0;
}