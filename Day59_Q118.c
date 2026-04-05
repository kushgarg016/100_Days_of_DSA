// helper function to find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// recursive function to build tree
struct TreeNode* build(int* inorder, int* postorder, int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // create root from postorder
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    // if only one node
    if (start == end)
        return root;

    int index = findIndex(inorder, start, end, root->val);

    // build right first
    root->right = build(inorder, postorder, index + 1, end, postIndex);
    root->left = build(inorder, postorder, start, index - 1, postIndex);

    return root;
}

// main function (given by LeetCode)
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}