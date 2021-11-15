// here we have done the the boundary traversal of the tree but the this file is'nt giving any value so run this file in online compiler
// ans will be 1 2 4 5 6 7 3 
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
   }
};

class Solution
{
   // leaf function to check the leaf or not
   bool isLeaf(Node *root)
   {
      return !root->left && !root->right;
   }

   void addLeftBoundary(Node *root, vector<int> &res)
   {
      Node *cur = root->left;
      while (cur)
      {
         if (!isLeaf(cur))
            res.push_back(cur->data);
         if (cur->left)
            cur = cur->left;
         else
            cur = cur->right;
      }
   }
   void addRightBoundary(Node *root, vector<int> &res)
   {
      Node *cur = root->right;
      vector<int> tmp;
      while (cur)
      {
         if (!isLeaf(cur))
            tmp.push_back(cur->data);
         if (cur->right)
            cur = cur->right;
         else
            cur = cur->left;
      }
      for (int i = tmp.size() - 1; i >= 0; --i)
      {
         res.push_back(tmp[i]);
      }
   }

   void addLeaves(Node *root, vector<int> &res)
   {
      if (isLeaf(root))
      {
         res.push_back(root->data);
         return;
      }
      if (root->left)
         addLeaves(root->left, res);
      if (root->right)
         addLeaves(root->right, res);
   }

public:
   // Traversal starts from here
   vector<int> printBoundary(Node *root)
   {
      vector<int> res;
      if (!root)
         return res;

      if (!isLeaf(root))
         res.push_back(root->data);

      // first left boundary
      addLeftBoundary(root, res);

      // second add leaf nodes
      addLeaves(root, res);

      // third right boundary
      addRightBoundary(root, res);
      return res;
   }
};

int main()
{
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);

   vector<int> ans;
   Solution S;
   ans = S.printBoundary(root);

   for (auto i : ans)
   {
      cout << i << " ";
   }

   return 0;
}
