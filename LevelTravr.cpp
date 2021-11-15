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
      left = NULL;
      right = NULL;
   }
};

class Linear_traversal
{
public:
   Node *traversal(Node *root);
};

Node *Linear_traversal::traversal(Node *root)
{
   vector<vector<int>> ans;
   if (root == NULL) return NULL;

   queue<Node *> q;
   q.push(root);

   while (!q.empty())
   {
      int Size = q.size();
      vector<int> v;
      for (int i = 0; i < Size; i++)
      {
         Node *temp = q.front();
         q.pop();

         if (temp->left != NULL) q.push(temp->left);
         if (temp->right != NULL) q.push(temp->right);

         v.push_back(temp->data);
      }
      ans.push_back(v);
   }

   for (int i = 0; i < ans.size(); i++)
   {
      for (int j = 0; j < ans[i].size(); j++)
      {
         /* code */

         cout<<ans[i][j]<<" ";
      }
      
      /* code */
      cout<<endl;
   }
   
   return 0;
}

int main()
{
   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->right = new Node(8);
   root->left->right->left = new Node(6);

   Linear_traversal l;
   l.traversal(root);
   return 0;
}