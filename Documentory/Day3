Question 1

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l2 != nullptr) ? l2->val : 0;
        int total = val1 + val2 + carry;
        carry = total / 10;
        current->next = new ListNode(total % 10);
        current = current->next;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    return dummyHead->next;
}

Question 2

#include <iostream>
#include <vector>

int lastRemaining(int n) {
    bool leftToRight = true;
    std::vector<int> remaining(n);
    for (int i = 0; i < n; ++i) {
        remaining[i] = i + 1;
    }

    while (remaining.size() > 1) {
        std::vector<int> newRemaining;
        if (leftToRight) {
            for (int i = 1; i < remaining.size(); i += 2) {
                newRemaining.push_back(remaining[i]);
            }
        } else {
            for (int i = remaining.size() - 1; i >= 0; i -= 2) {
                newRemaining.push_back(remaining[i]);
            }
        }
        remaining = newRemaining;
        leftToRight = !leftToRight;
    }

    return remaining[0];
}

Question 3

#include <iostream>
#include <vector>

bool PredictTheWinner(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }

    return dp[0][n - 1] >= 0;
}

Question 4

#include <iostream>

int findTheWinner(int n, int k) {
    int winner = 0;  // Josephus position for 1 person
    for (int i = 2; i <= n; ++i) {
        winner = (winner + k) % i;
    }
    return winner + 1;  // Convert from 0-indexed to 1-indexed
}

Question 5

#include <iostream>

const int MOD = 1e9 + 7;

int minNonZeroProduct(int p) {
    long long max_num = (1LL << p) - 1;  // 2^p - 1
    long long min_product = (max_num * (max_num - 1) / 2) % MOD;
    return min_product;
}
