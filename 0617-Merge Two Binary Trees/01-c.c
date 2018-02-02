#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (t1 == NULL) node = t2;
    else if (t2 == NULL) node = t1;
    else {
        node->val = t1->val + t2->val;
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
    }
    return node;
}

int main() {
    struct TreeNode* t1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t1->val = 1;
    t1->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t1->left->val = 3;
    t1->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t1->right->val = 2;
    t1->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t1->left->left->val = 5;
    t1->left->right = NULL;
    t1->right->left = NULL;
    t1->right->right = NULL;
    t1->left->left->left = NULL;
    t1->left->left->right = NULL;

    struct TreeNode* t2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t2->val = 2;
    t2->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t2->left->val = 1;
    t2->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t2->right->val = 3;
    t2->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t2->left->right->val = 4;
    t2->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t2->right->right->val = 7;
    t2->left->left = NULL;
    t2->right->left = NULL;
    t2->left->right->left = NULL;
    t2->left->right->right = NULL;
    t2->right->right->left = NULL;
    t2->right->right->right = NULL;

    struct TreeNode* res = mergeTrees(t1,t2);
    printf("test");
    return 1;
}