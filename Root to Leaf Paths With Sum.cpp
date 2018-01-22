/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void TreeTraversal(TreeNode *root,vector<int> &current_path,int remain_sum,vector<vector<int>> &temp){
	if(root == NULL)
		return;

	remain_sum = remain_sum - root->val;
	current_path.push_back(root->val);

	if(root->left == NULL && root->right == NULL){	//if we reach leafnode
		if(remain_sum == 0){						//correct path
			temp.push_back(current_path);
		}
		current_path.pop_back();					//wrong path,goto previous node
		return;
	}

	//traverse the tree
	TreeTraversal(root->left,current_path,remain_sum,temp);
	TreeTraversal(root->right,current_path,remain_sum,temp);
	current_path.pop_back();
	return;

}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int> current_path;
    TreeTraversal(root,current_path,sum,result);
    return result;
}
