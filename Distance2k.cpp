// this is not correct we will modify it using burnt in bt 
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
   int val;
   TreeNode *right;
   TreeNode *left;

   TreeNode(int data)
   {
      val = data;
   }
};

class solution
{
public:
   TreeNode *parent(TreeNode *root, TreeNode *key)
   {

      if (root->right->val == key->val)
      {
         cout<<root->val;
         return 0;
      }
      parent(root->right, key);
      parent(root->left, key);
   }

   
   void Root_2_k(TreeNode *root)
   {
      vector<int> ans;
      queue<pair<TreeNode *, int>> q;// to check the distance;
      q.push({root, 0});
      while (!q.empty())
      {
         int size = q.size();

         for (int i = 0; i < size; i++)
         {
            auto temp = q.front();
            q.pop();
            if (temp.second == 1)
               ans.push_back(temp.first->val);
            if (temp.first->left)
               q.push({temp.first->left, temp.second + 1});
            if (temp.first->right)
               q.push({temp.first->right, temp.second + 1});
         }
      }
      for (auto i : ans)
      {
         cout << i << " ";
      }
   }
};


int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);

   solution s;
   s.parent(root,root->left);
   s.Root_2_k(root->left);
   return 0;
}