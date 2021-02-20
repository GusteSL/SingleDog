/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 按递增顺序显示卡牌
 */

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> result;
        if (deck.empty()) return result;
        std::sort(deck.begin(), deck.end());
        list<int> index;
        for (int i = 0; i < deck.size(); ++i) {
            index.push_back(i);
        }
        list<int> sort_index;
        while (!index.empty()) {
            sort_index.push_back(index.front());
            index.pop_front();
            if (!index.empty()) {
                index.push_back(index.front());
                index.pop_front();
            }
        }
        result.resize(deck.size());
        int i = 0;
        for (const auto &num : sort_index) {
            result[num] = deck[i];
            ++i;
        }
        return result;
    }
};
// @lc code=end

