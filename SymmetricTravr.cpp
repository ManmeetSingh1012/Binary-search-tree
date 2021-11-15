// here we have checked the symatric of binary tree or impose of right part to left part
#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{
   public:
   int data;
   BinaryTree *left;
   BinaryTree *right;

   BinaryTree(int val)
   {
      data=val;
      left=right=NULL;
   }
};

class solution
{
   public:
   bool check(BinaryTree *left,BinaryTree*right)
   {
      if(left==NULL || right==NULL) return left==right;

      if(right->data!=left->data) return false;

      return check(left->left,right->left) and
      check(left->right,right->left);

   }
   bool isSymmetric(BinaryTree* root)
   {
     cout<<check(root->left,root->right);

   }
};

int main()
{
  BinaryTree *root = new BinaryTree(4);
   root->left = new BinaryTree(4);
   root->right = new BinaryTree(4);
   root->left->left=new BinaryTree(4);
   root->right->right=new BinaryTree(4);
   root->right->left=new BinaryTree(4);
   root->left->right=new BinaryTree(4);
   solution s;
   s.isSymmetric(root);
   
   return 0;
}