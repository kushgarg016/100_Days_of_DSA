/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Step 1: flatten left and right
    flatten(root->left);
    flatten(root->right);

    // Step 2: store left and right
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    // Step 3: move left to right
    root->right = left;
    root->left = NULL;

    // Step 4: go to end of new right
    struct TreeNode* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }

    // Step 5: attach original right
    temp->right = right;
}