int isCousins(struct TreeNode* root, int x, int y) {
    struct TreeNode* queue[100];
    struct TreeNode* parent[100];

    int front = 0, rear = 0;

    queue[rear] = root;
    parent[rear] = NULL;
    rear++;

    while (front < rear) {
        int size = rear - front;

        struct TreeNode* px = NULL;
        struct TreeNode* py = NULL;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front];
            struct TreeNode* par = parent[front];
            front++;

            if (node->val == x)
                px = par;

            if (node->val == y)
                py = par;

            if (node->left != NULL) {
                queue[rear] = node->left;
                parent[rear++] = node;
            }

            if (node->right != NULL) {
                queue[rear] = node->right;
                parent[rear++] = node;
            }
        }

        if (px != NULL || py != NULL)
            return px != NULL && py != NULL && px != py;
    }

    return 0;
}