#include <stdio.h>
#include <stdlib.h>

// 采用递归的方式解决，但是总是报Runtime error，实际测试可用


/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	int *res, *left, *right, beginSize = returnSize[0], centerSize, i;
	if(root->right == NULL && root->left == NULL) {
		res = malloc(sizeof(int));
		res[0] = root->val;
//		printf("null %d\n", res[0]);
	}else {
		if(root->right != NULL) {
			right = postorderTraversal(root->right, returnSize);
		}
//		printf("right后面 %d\n", returnSize[0]);
		centerSize = returnSize[0];
		if(root->left != NULL){
			left = postorderTraversal(root->left, returnSize);
		}
		
		res = malloc((returnSize[0]-beginSize+1)*sizeof(int));
		for(i=beginSize;i<centerSize;i++) {
			res[i-beginSize] = right[i-beginSize];
//			printf("right %d\n", res[i-beginSize]);
		}
		for(i=centerSize;i<returnSize[0];i++) {
			res[i-beginSize] = left[i-centerSize];
//			printf("left %d\n", res[i-beginSize]);
		}
//		if(centerSize > beginSize) free(left);
//		if(returnSize[0] > centerSize) free(right);
		res[returnSize[0]-beginSize] = root->val;
	}

	
	returnSize[0]++;
	return res;
}

int main(int argc, char *argv[]) {
	struct TreeNode *t = (struct TreeNode *)calloc(4, sizeof(struct TreeNode));
	struct TreeNode *p = t;
	int atest[100] = {1,2,3,4,5,4,5};
	p->val = 4;

    p->left = ++t;
    t->val = 2;
    p->left->left = ++t;
    t->val = 1;
    t->left = t->right = NULL;
    p->left->right = ++t;
    t->val = 3;
    t->left = t->right = NULL;

    p->right = ++t;
    t->val = 5;
    t->left = t->right = NULL;
	// p->val = 1;

	// p->right = ++t;
	// p->left = NULL;
	// t->val = 2;
	// p->right->left = ++t;
	// t->val = 3;
	// p->right->right = NULL;
	// t->left = NULL;
	// t->right = NULL;

	// p->val = 4;
	// p->left = NULL;
	// p->right = NULL;

//	p->left = ++t;
//	t->val = 2;
//	t->left = NULL;
//	p->left->right = ++t;
//	t->val = 3;
//	t->left = t->right = NULL;
//
//	p->right = ++t;
//	t->val = 5;
//	t->left = t->right = NULL;

	int size = 0;
	int *ret = postorderTraversal(p, &size);
	int i;
	/* should be 13254 */
	for (i = 0; i < size; i++) {
		printf("%d", ret[i]);
	}
	printf("\n");
}