//  here we have find the diameter of the binary tree or maximum path between two nodes 
//  sum of the lh and rh gives the diameter of the tree
#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
   Node*left;
   Node*right;
   int data;

   Node(int val)
   {
      data=val;
      left=right=NULL;
   }
};


class Diameter_Bt
{
   public:
   
   int diameter(Node*root, int &maxi)
   {
      if(root==NULL) return 0;

      int lh=diameter((root->left),maxi);
      int rh=diameter((root->right),maxi);

      maxi=max(maxi,lh+rh);

      return 1+max(lh,rh);
   }
};

int main()
{
   Node*root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->left=new Node(6);
   root->right->right=new Node(7);

   int maxi=INT_MIN;

   Diameter_Bt b;
   b.diameter(root,maxi);
   cout<<"Maximum Diameter of the binary tree is "<< maxi;;
   return 0;
   
}