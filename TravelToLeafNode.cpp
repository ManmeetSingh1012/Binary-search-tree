// here we find the path to from pathe node
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

class path_to_Node
{
   public:
   bool calculations(BinaryTree*root,int x,vector<int>&v)
   {
      if(!root) return false;
      v.push_back(root->data);

      if(root->data==x) return true;

      if(calculations(root->left,x,v) or calculations(root->right,x,v)) return true;

      v.pop_back();
      return false;

   }
};

int main()
{
   BinaryTree *root = new BinaryTree(1);
   root->left = new BinaryTree(2);
   root->right = new BinaryTree(3);
   root->left->left = new BinaryTree(4);
   root->left->right = new BinaryTree(5);
   root->right->left = new BinaryTree(6);
   root->right->right = new BinaryTree(7);
   path_to_Node p;
   vector<int>v;
   p.calculations(root,7,v);

   for(auto i:v)
   {
     cout<<i<<endl;
   }
   return 0;
}
