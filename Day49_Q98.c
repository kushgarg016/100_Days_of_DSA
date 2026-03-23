struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // If tree is empty, create new node
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Insert in left subtree
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    // Insert in right subtree
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
