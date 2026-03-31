/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void solve(struct TreeNode* root, int level, int* result, int* returnSize) {
    if (root == NULL)
        return;

    // If this is the first node of this level
    if (level == *returnSize) {
        result[*returnSize] = root->val;
        (*returnSize)++;
    }

    // Visit right first
    solve(root->right, level + 1, result, returnSize);
    solve(root->left, level + 1, result, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100); // assume max 100 nodes
    *returnSize = 0;

    solve(root, 0, result, returnSize);

    return result;
}