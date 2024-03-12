/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *first = NULL;

    //! Step - 1 Find the atrget Node.
    void find(TreeNode *root, int start)
    {

        if (root == NULL)
        {
            return;
        }

        if (root->val == start)
        {
            first = root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }

    // !step - 2 Mark the parent Nodes
    void markParent(TreeNode *root,
                    unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
            parent[root->left] = root;
        if (root->right != NULL)
            parent[root->right] = root;
        markParent(root->left, parent);
        markParent(root->right, parent);
    }

    int amountOfTime(TreeNode *root, int start)
    {
        find(root, start);
        unordered_map<TreeNode *, TreeNode *> parent;
        markParent(root, parent);
        unordered_set<TreeNode *> s;
        s.insert(first);
        queue<pair<TreeNode *, int>> q;
        // Pair <TreeNode*,int>p;
        //  p.first = first;
        //  p.second = 0;
        q.push({first, 0});

        // Now we need to Run a BFS
        int maxLev = 0;

        while (q.size() > 0)
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            int level = p.second;
            TreeNode *temp = p.first;
            maxLev = max(maxLev, level);

            if (temp->left)
            {
                if (s.find(temp->left) == s.end())
                {
                    q.push({temp->left, level + 1});
                    s.insert(temp->left);
                }
            }

            if (temp->right)
            {
                if (s.find(temp->right) == s.end())
                {
                    q.push({temp->right, level + 1});
                    s.insert(temp->right);
                }
            }

            // !Checking for Parent Node
            if (parent.find(temp) != parent.end())
            {
                if (s.find(parent[temp]) == s.end())
                {
                    q.push({parent[temp], level + 1});
                    s.insert(parent[temp]);
                }
            }
        }

        return maxLev;
    }
};