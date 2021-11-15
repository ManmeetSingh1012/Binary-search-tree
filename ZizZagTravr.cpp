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
      left = right = NULL;
   }
};

class ZiZ_Zag
{
public:
   void traversal(Node *root)
   {
      vector<vector<int>> ans;
      //if(root==NULL) return ans;

      queue<Node *> q;
      int flag = 0;
      q.push(root);

      while (!q.empty())
      {
         int Size = q.size();
         vector<int> v;
         for (int i = 0; i < Size; i++)
         {
            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
               q.push(temp->left);
            if (temp->right != NULL)
               q.push(temp->right);

            v.push_back(temp->data);
         }

         if (flag == 1)
         {
            reverse(v.begin(), v.end());
            flag--;
         }
         else
            flag++;

         ans.push_back(v);
      }

      for (int i = 0; i < ans.size(); i++)
      {
         for (int j = 0; j < ans[i].size(); j++)
         {
            /* code */

            cout << ans[i][j] << " ";
         }

         /* code */
         cout << endl;
      }
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

   ZiZ_Zag z;
   z.traversal(root);
   return 0;
}