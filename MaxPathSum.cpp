/// here we have find the maximum path sum similar to diameter

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

      // here we are doing maximum becuase sometimes we can get -ve value so we have used max func with zero

      int lh=max(0,diameter((root->left),maxi));  
      int rh=max(0,diameter((root->right),maxi));

      // only difference bw diameter and max sum path is sum of
      maxi=max(maxi,lh+rh+root->data);

      return root->data+max(lh,rh);
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