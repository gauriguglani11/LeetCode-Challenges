QUESTION:- Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]



SOLUTION IN C++

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //Here we use the Breadth First Search(BFS) Algorithm;
        vector<vector<int> > result;
        vector<int> level;
        queue<TreeNode*> myQueue;
        if(root == NULL)
            return result;
        myQueue.push(root);
        int currentLevelNodeNum = 1;//used to record num of nodes in current level
        int nextLevelNodeNum = 0;//used to record num of nodes in next level
        while(!myQueue.empty()){
            TreeNode* temp = myQueue.front();
            myQueue.pop();
            level.push_back(temp->val);
            currentLevelNodeNum--; 
            if(temp->left != NULL){
                myQueue.push(temp->left);
            	nextLevelNodeNum++;
            }
            if(temp->right!= NULL){
            	myQueue.push(temp->right);
            	nextLevelNodeNum++;
            }
            if(currentLevelNodeNum == 0){//if we have traversed current level, turn to next level
            	result.push_back(level);//push the current level into result
        		level.clear();//clear level
        		currentLevelNodeNum = nextLevelNodeNum;//assign next level node num to current
        		nextLevelNodeNum = 0;//set next level num to 0
        	}
        }
        vector<vector<int> > final; //we have to reverse the order to get the final result
        for(int i = result.size()-1;i>=0;i--){
        	final.push_back(result[i]);
        }
        return final;
    }
};
