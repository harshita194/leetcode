/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to find the position of the root element in inorder
    int findPosition(vector<int> &inorder, int element) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    // Recursive function to build the tree
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &preorderIndex, int inorderStart, int inorderEnd) {
        if(preorderIndex >= preorder.size() || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element);

        // recursive calls to build left and right subtree
        root->left = solve(inorder, preorder, preorderIndex, inorderStart, position - 1);
        root->right = solve(inorder, preorder, preorderIndex, position + 1, inorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        return solve(inorder, preorder, preorderIndex, 0, inorder.size() - 1);
    }
};