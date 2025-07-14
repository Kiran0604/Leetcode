/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int res = 0;
        string tem = "";
        while (temp != NULL) {
            tem = tem + to_string(temp->val);
            temp = temp->next;
        }
        int n = tem.size(), i = 0;
        while (n > 0) {
            res = res + pow(2, i) * (tem[n - 1] - '0');
            n--;
            i++;
        }
        return res;
    }
};