//Author: hayborl(Haibo Liu)

//使用队列能很容易的解决问题

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> results;
        
        if (root != NULL)
        {
            queue<TreeNode *> treeQueue;
            treeQueue.push(root);
            while (!treeQueue.empty())
            {
                int size = treeQueue.size();
                vector<int> subRst(size);
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = treeQueue.front();
                    subRst[i] = node->val;
                    if (node->left != NULL)
                    {
                        treeQueue.push(node->left);
                    }
                    if (node->right != NULL)
                    {
                        treeQueue.push(node->right);
                    }
                    treeQueue.pop();
                }
                results.push_back(subRst);
            }
        }
        
        return results;
    }
};