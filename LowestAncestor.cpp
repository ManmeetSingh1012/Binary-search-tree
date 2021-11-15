#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
   public:
   int val;
   TreeNode *left;
   TreeNode*right;

   TreeNode(int data)
   {
      val=data;
      left=right=NULL;
   }
};

class find_anc{
   public:
   TreeNode* ancestor(TreeNode*root,TreeNode*p,TreeNode*q)
   {
      if(!root) return root;

      if(root==p or root==q) return root;
      TreeNode* lft=ancestor(root->left,p,q);
      TreeNode* rgt=ancestor(root->right,p,q);

      if(rgt==NULL) return lft;
      if(lft==NULL) return rgt;
      if(rgt!=NULL or lft!=NULL)  return root;

   }
};

int main()
{
   TreeNode*root=new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(7);

   
   find_anc A;
   TreeNode*p=root->left->left;
   TreeNode*q=root->right->right;
   TreeNode* ans=A.ancestor(root,p,q);
   cout<<"Lowest Ancestor is "<<ans->val;
   return 0;
}