// maximum no of leafs in a last level of a binary tree  
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

class width
{
   public:
   int widhtofbinarytree(BinaryTree*root)
   {
      if(!root) return 0;
      int ans=0;
      queue<pair<BinaryTree*,int >>q;
      q.push({root,0}); 
      while(!q.empty())
      {
         int size=q.size();
         int min= q.front().second;
         int first,last;
         for(int i=0;i<size;i++)
         {
            int cur_id=q.front().second-min;
            BinaryTree* node=q.front().first;
            q.pop();
            if(i==0) first=cur_id;
            if(i==size-1) last=cur_id;
            if(node->left) q.push({node->left,cur_id*2+1});
            if(node->right) q.push({node->right,cur_id*2+2});
            
         }
         ans=max(ans,last-first+1);

      }
      return ans;
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
    
   width w;
   int ans=w.widhtofbinarytree(root);
   cout<<ans;
   return 0;

}