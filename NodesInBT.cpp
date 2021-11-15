#include<bits/stdc++.h>
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
   int total_nodes;
   int hight_cal(TreeNode*root)
   {
      if(!root) return 0;
      int lft=hight_cal(root->left);
      int rgt=hight_cal(root->right);
      return 1+max(lft,rgt);
   }

   int Node_cal(TreeNode*root)
   {
      if(!root) return 0;
      int lht=hight_cal(root->left);
      int rgt=hight_cal(root->right);

      if(lht==rgt) return pow(2,lht+1)-1;
      return 1+Node_cal(root->left)+Node_cal(root->right);
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
   int node=s.Node_cal(root);
   cout<<"The no of nodes in a BT is "<<node;
   return 0;
}