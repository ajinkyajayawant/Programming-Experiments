/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int m_dep = -1;
    int m1 = 0, m2 = 0;
    
    if(root == NULL)
        m_dep = 0;    
    else{
        if(root->left != NULL)
            m1 = maxDepth(root->left);
        if(root->right != NULL)
            m2 = maxDepth(root->right);
        m_dep = 1 + (((m1) > (m2)) ? (m1) : (m2));
    }
    return m_dep;
}
