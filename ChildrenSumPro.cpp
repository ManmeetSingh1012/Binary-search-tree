// in this we have to check the sum of the children of a root is equal or not if sum is small then the children value = root->val
// but in other case it would be root->val=left child + right child
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int val)
   {
      data = val;
      left = right = NULL;
   }
};

class solution
{
public:
   void changeTree(TreeNode *root)
   {
      if (!root)
         return;

      if (root == NULL)
         return;
      int child = 0;
      if (root->left)
      {
         child += root->left->data;
      }
      if (root->right)
      {
         child += root->right->data;
      }

      if (child >= root->data)
         root->data = child;
      else
      {
         if (root->left)
            root->left->data = root->data;
         else if (root->right)
            root->right->data = root->data;
      }

      changeTree(root->left);
      changeTree(root->right);

      int tot = 0;
      if (root->left)
         tot += root->left->data;
      if (root->right)
         tot += root->right->data;
      if (root->left or root->right)
         root->data = tot;
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
   s.changeTree(root);
   

   return 0;
}