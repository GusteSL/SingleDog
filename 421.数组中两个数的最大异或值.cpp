/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;
        Node(int num = 0){val = num; left = NULL; right = NULL;}
    };
    class OZTree {
    public:
        OZTree() {}
        ~OZTree() {}
        void add(int num) {
            unsigned int num_mask = 0x80000000;
            Node* p = &root;
            for(int i = 0; num_mask != 0; ++i) {
                if( (num&num_mask) == 0) {
                    if(p->left == NULL) {
                        p->left = new Node(0);
                    }
                    p = p->left;
                    cout << '0';
                } else {
                    if(p->right == NULL) {
                        p->right = new Node(1);
                    }
                    p = p->right;
                    cout << '1';
                }
                num_mask = num_mask >> 1;
            }
            cout << ":" << num << endl;
        }
        int maxXor() {
            Node* p = &root;
            while(p->left == NULL || p->right == NULL) {
                if(p->left == NULL) {
                    p = p->right;
                } else if(p->right == NULL) {
                    p = p->left;
                } else {
                    break;
                }
            }
            if() {

            }
            return maxXor(p->left, p->right, 0);
        }
        int maxXor(Node *left_p, Node *right_p, unsigned int result) {
            result = (result<<1) + (left_p->val^right_p->val);
            if(left_p->left == NULL && left_p->right == NULL && right_p->left == NULL && right_p->right == NULL) {
                cout << left_p->val << "  " << right_p->val << ":" << result << endl;
                return result;
            }
            int case0 = 0, case1 = 0, case2 = 0, case3 = 0;
            if(left_p->left != NULL && right_p->left != NULL) {
                case0 = maxXor(left_p->left, right_p->left, result);
            }
            if(left_p->left != NULL && right_p->right != NULL) {
                case1 = maxXor(left_p->left, right_p->right, result);
            }
            if(left_p->right != NULL && right_p->left != NULL) {
                case2 = maxXor(left_p->right, right_p->left, result);
            }
            if(left_p->right != NULL && right_p->right != NULL) {
                case3 = maxXor(left_p->right, right_p->right, result);
            }
            cout << case0 << "  "
                 << case1 << "  "
                 << case2 << "  "
                 << case3 << endl;
            return max(max(case0,case1), max(case2, case3));
        }
    private:
        Node root;
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty()) return 0;
        OZTree tree;
        for(int i = 0; i < nums.size(); ++i) {
            tree.add(nums[i]);
        }
        return tree.maxXor();
    }
};
// @lc code=end

