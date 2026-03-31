/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // both NULL → symmetric
    if (left == NULL && right == NULL)
        return true;

    // one NULL → not symmetric
    if (left == NULL || right == NULL)
        return false;

    // check values + mirror children
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}