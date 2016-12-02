#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class BinTreeNode{
public:
  BinTreeNode(int value){
    this->value=value;
    this->left=NULL;
    this->right=NULL;
  }
  int value;
  BinTreeNode* left;
  BinTreeNode* right;

};

BinTreeNode* tree_insert(BinTreeNode* tree, int item){
  if(tree==NULL)
    tree=new BinTreeNode(item);
  else
    if(item < tree->value)
      if(tree->left==NULL)
        tree->left=new BinTreeNode(item);
      else
        tree_insert(tree->left,item);
    else
      if(tree->right==NULL)
        tree->right=new BinTreeNode(item);
      else
        tree_insert(tree->right,item);
  return tree;

}

void postorder(BinTreeNode* tree){
  if(tree->left!=NULL)
    postorder(tree->left);
  if(tree->right!=NULL)
    postorder(tree->right);
  cout << tree->value << endl;

}

void inOrder(BinTreeNode* tree)
{
    vector<int> results;
    stack<BinTreeNode*> s;
    int temp;

    s.push(tree);

    //While the stack isn't empty...
    while (!s.empty())
    {
        //If there is a node to the left...
        if (tree->left!=NULL)
        {
            //Check to see if that node has already been visited and stored in the results vector
            if (find(results.begin(), results.end(), tree->left->value) != results.end())
            {
                //If it has been visited then that means we need to pop and store the current value
                //on the top of the stack and check if there is any nodes to the right
                BinTreeNode* test = s.top();
                temp = test->value;
                s.pop();
                results.push_back(temp);
                if (tree->right!=NULL)
                {
                    s.push(tree->right);
                    tree=tree->right;
                }
                else
                {
                    //If there isn't anything to the right then we need to jump back up the tree
                    //As long as there is still something in the stack (check in case we've reached
                    //the end of the tree...)
                    if (!s.empty())
                    {
                        tree = s.top();
                    }
                }
            }
            else
            {
                //If the value to the left isn't already stored then we just want to go there
                s.push(tree->left);
                tree=tree->left;
            }
        }
        else
        {
            //If there isn't a node to the left then pop, store and check to the right
            BinTreeNode* test = s.top();
            temp = test->value;
            s.pop();
            results.push_back(temp);

            if (tree->right!=NULL)
            {
                s.push(tree->right);
                tree=tree->right;
            }
            else
            {
                if (!s.empty())
                {
                    tree = s.top();
                }
            }
        }
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }

}

void in_order(BinTreeNode* tree){
  if(tree->left!=NULL)
    in_order(tree->left);
  cout << tree->value << endl;
  if(tree->right!=NULL)
    in_order(tree->right);
}

int main(int argc, char *argv[])
{
  BinTreeNode* t=tree_insert(0,6);
  tree_insert(t,10);
  tree_insert(t,5);
  tree_insert(t,2);
  tree_insert(t,3);
  tree_insert(t,4);
  tree_insert(t,11);
  in_order(t);
  cout << "My in order values" << endl;
  inOrder(t);
  return 0;
}
