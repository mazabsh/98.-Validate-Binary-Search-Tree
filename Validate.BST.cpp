#include<iostream> 
#include<vector>

using namespace std; 

struct TreeNode{
public: 
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};

class Solution{
public: 
    bool isValid(TreeNode* root, TreeNode* low, TreeNode* high){
      if(root==nullptr) return true; 
      if((low != nullptr && root->val <= low->val) ||(high!=nullptr && root->val>= high->val)) return false; 
      return isValid(root->left, low, root) && isValid(root->right, root, high); 
    }
    bool isValidBST(TreeNode* root){
      return isValid(root, nullptr, nullptr); 
    }
};
int main(){
  TreeNode* root = new TreeNode(5); 
  root->left = new TreeNode(1); 
  root->right = new TreeNode(4); 
  root->right->left = new TreeNode(3); 
  root->right->right = new TreeNode(6); 
  Solution sol; 
  cout << boolalpha << sol.isValidBST(root) <<endl; 
}
