// lowest common ancestor using brute force approach
#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
   int data;
   BinaryTree *left;
   BinaryTree *right;

   BinaryTree(int val)
   {
      data = val;
      left = right = NULL;
   }
};

class path_to_Node
{
public:
   bool calculations(BinaryTree *root, int x, vector<int> &v)
   {
      if(!root) return false;
      v.push_back(root->data);

      if(root->data==x) return true;

      if(calculations(root->left,x,v) or calculations(root->right,x,v)) return true;

      v.pop_back();
      return false;
   }
};

void print(vector<int>v)
{
   for (auto i : v)
   {
      cout << i << endl;
   }
}

void Ancestor(vector<int>v1,vector<int>v2)
{
   int temp;
   for(int i=0;i<v1.size();i++)// we are asuming that our binary tree is full binary tree then size may be equal
   
   {
      if(v1[i]==v2[i])
      {
         temp=v1[i];
         continue;
      }
      break;

   }

   cout<<"The lowest common ancestor is " <<temp;
}
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
   vector<int> v1;
   vector<int>v2;
   p.calculations(root, 7, v1);
   p.calculations(root, 4, v2);

   print(v1);
   cout<<endl;
   print(v2);

   Ancestor(v1,v2);
   
   return 0;
}