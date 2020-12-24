/* Copyright (c) 2019-2021 Grant Hadlich
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverseOne(TreeNode* root1) {
        if (root1 == nullptr) return;
        
        traverseOne(root1->left);
        one.push(root1->val);
        traverseOne(root1->right);
    }
    
    void traverseTwo(TreeNode* root1) {
        if (root1 == nullptr) return;
        
        traverseTwo(root1->left);
        two.push(root1->val);
        traverseTwo(root1->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverseOne(root1);
        traverseTwo(root2);
        
        vector<int> ret;
        
        while (one.size() || two.size()) {
            if (one.size() && two.size()) {
                if (one.front() < two.front()) {
                    ret.push_back(one.front());
                    one.pop();
                }
                else {
                    ret.push_back(two.front());
                    two.pop();
                }
            }
            else if (one.size()) {
                ret.push_back(one.front());
                one.pop();
            }
            else {
                ret.push_back(two.front());
                two.pop();
            }
        }
        
        return ret;
    }
    
    queue<int> one;
    queue<int> two;
};