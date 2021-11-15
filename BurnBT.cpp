// here we will burn a binary tree and find how much time taken to burn the tree
// this question is not on leet code vedio no 31 take u bt series
#include <bits/stdc++.h>
using namespace std;

// declraing a tree 
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
   // this fucntion will find the the parent of each node and it will store in a map
   map<TreeNode *, TreeNode *> parent_cal(TreeNode *root)
   {
      map<TreeNode *, TreeNode *> mp;
      //if(!root) return root;
      if (root->left)
      {
         mp[root->left] = root;
         parent_cal(root->right);
      }
      if (root->right)
      {
         mp[root->right] = root;
         parent_cal(root->left);
      }

      return mp;
   }

   // this fucntion will calculate time taken or steps taken to  burn a binary tree
   // it will check the parent , left and right in burnt map or visted map
   int time_to_burn(TreeNode *key, map<TreeNode *, TreeNode *> &prt)
   {
      //map<TreeNode*,TreeNode*>parent_cal(root);
      unordered_map<TreeNode *, int> burn;
      queue<TreeNode *> q;
      int time_ans = 0;
      q.push(key);
      burn[key]=1;
      while (!q.empty())
      {
         int fl = 0;
         int size = q.size();
         for (int i = 0; i < size; i++)
         {

            TreeNode *temp = q.front();
            q.pop();
            if (temp->left and burn.find(temp->left) == burn.end())
            {

               q.push(temp->left);
               burn[temp->left] = 1;
               fl = 1;
            }

            if (temp->right and burn.find(temp->right) == burn.end())
            {
               q.push(temp->right);
               burn[temp->right] = 1;
               fl = 1;
            }

            if (prt.find(temp) != prt.end())
            {
               auto it = prt.find(temp);
               auto parnt = it->second;
               if (burn.find(parnt) == burn.end())
               {
                  q.push(parnt);
                  burn[parnt] = 1;
                  fl = 1;
               }
            }
         }

         if (fl)
            time_ans++;
      }
      return time_ans;// returning the result
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

   map<TreeNode *, TreeNode *> mp;
   solution s;
   mp = s.parent_cal(root);

   int ans = s.time_to_burn(root->left, mp);
   cout << ans;
   return 0;
}