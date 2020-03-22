#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
class Solution {
public:
    int romanToInt(string s)
    {
        int sum = 0;
        string::const_iterator begin = s.cbegin();
        string::const_iterator end = s.cend();

        while (begin != end) {
            switch (*begin) {
            case 'I': {
                if (begin + 1 != end) {
                    if (*(begin + 1) == 'V') {
                        sum += 4;
                        begin++;
                        break;
                    } else if (*(begin + 1) == 'X') {
                        sum += 9;
                        begin++;
                        break;
                    }
                }
                sum += 1;
                break;
            }
            case 'V': {
                sum += 5;
                break;
            }
            case 'X': {
                if (begin + 1 != end) {
                    if (*(begin + 1) == 'L') {
                        sum += 40;
                        begin++;
                        break;
                    } else if (*(begin + 1) == 'C') {
                        sum += 90;
                        begin++;
                        break;
                    }
                }
                sum += 10;
                break;
            }
            case 'L': {
                sum += 50;
                break;
            }
            case 'C': {
                if (begin + 1 != end) {
                    if (*(begin + 1) == 'D') {
                        sum += 400;
                        begin++;
                        break;
                    } else if (*(begin + 1) == 'M') {
                        sum += 900;
                        begin++;
                        break;
                    }
                }
                sum += 100;
                break;
            }
            case 'D': {
                sum += 500;
                break;
            }
            case 'M': {
                sum += 1000;
                break;
            }
            default:
                cout << "input error" << endl;
                return -1;
            }
            begin++;
        }
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        string res = "";
        char c;
        string::size_type size = 0, tmp = 0;
        vector<string>::iterator begin = strs.begin();
        vector<string>::iterator end = strs.end();

        while (begin != end) {
            tmp = (*begin).size();
            if (size > tmp) {
                size = tmp;
            }
            begin++;
        }

        for (int i = 0; i < size; i++) {
            begin = strs.begin();
            c = (*begin)[i];
            begin++;
            while (begin != end) {
                if (c != (*begin)[i]) {
                    return res;
                }
                begin++;
            }
            res += c;
        }

        return res;
    }
    string longestCommonPrefix1(vector<string>& strs)
    {
        string tmp = strs.size() ? strs[0] : "";

        for (auto s : strs) {
            while (s.substr(0, tmp.size() - 1) != tmp) {
                tmp = tmp.substr(0, tmp.size() - 1);
                if (tmp == "") {
                    return tmp;
                }
            }
        }

        return tmp;
    }

    bool isValid(string s)
    {
        char tmp;
        stack<char> st;
        string::iterator begin = s.begin(), end = s.end();

        while (begin != end) {
            switch (*begin) {
            case '(':
            case '{':
            case '[':
                st.push(*begin);
                break;
            case ')':
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
                break;
            case '}':
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
                break;
            case ']':
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
                break;
            default:
                break;
            }

            begin++;
        }

        if (!st.empty()) {
            return false;
        }
        return true;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *head = nullptr, *tmp = nullptr;
        ListNode *tmp1 = l1, *tmp2 = l2;

        if (!l1 && l2) {
            return l2;
        } else if (l1 && !l2) {
            return l1;
        } else if (!l1 && !l2) {
            return nullptr;
        }

        while (tmp1 && tmp2) {
            if (tmp1->val <= tmp2->val) {
                if (!head) {
                    head = tmp = tmp1;
                    tmp1 = tmp1->next;
                    continue;
                } else {
                    tmp->next = tmp1;
                }
                tmp1 = tmp1->next;
            } else {
                if (!head) {
                    head = tmp = tmp2;
                    tmp2 = tmp2->next;
                    continue;
                } else {
                    tmp->next = tmp2;
                    tmp2 = tmp2->next;
                }
            }
            tmp = tmp->next;
        }
        if (tmp1) {
            tmp->next = tmp1;
        } else if (tmp2) {
            tmp->next = tmp2;
        } else {
            tmp->next = nullptr;
        }

        return head;
    }

    int removeDuplicates(vector<int>& nums)
    {
        int res = nums.size();
        int tmp = 0, index = 1;
        if (!res) {
            return res;
        }
        tmp = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (tmp == nums[i]) {
                res--;
            } else {
                tmp = nums[i];
                nums[index] = nums[i];
                index += 1;
            }
        }

        return res;
    }

    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }

        int val = head->val;
        ListNode *tmp = head, *cur = head->next;
        ListNode* new_head = head;

        while (cur) {
            if (val == cur->val) {
                cur = cur->next;
            } else {
                val = cur->val;
                tmp->next = cur;
                tmp = tmp->next;
            }
        }
        tmp->next = nullptr;

        return new_head;
    }

    int strStr(string haystack, string needle)
    {
        if (haystack.size() == 0) {
            if (needle.size() != 0) {
                return -1;
            } else {
                return 0;
            }
        }
        if (needle.size() == 0) {
            return 0;
        }

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }

        return -1;
    }

    int removeElement(vector<int>& nums, int val)
    {
        if (nums.size() == 0) {
            return 0;
        }

        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }

        return index;
    }

    int searchInsert(vector<int>& nums, int target)
    {
        int i = 0, index = 0;
        if (nums[0] >= target) {
            return index;
        }

        for (; i < nums.size(); i++) {
            if (nums[i] == target) {
                index = i;
                break;
            } else if (i + 1 < nums.size() && nums[i + 1] > target) {
                index = i + 1;
                break;
            }
        }

        if (i == nums.size()) {
            index = nums.size();
        }

        return index;
    }

    string countAndSay(int n)
    {
        string res_tmp = "1";
        string res = "1";
        int count = 0;

        for (int i = 2; i <= n; i++) {
            res = "";
            char tmp = res_tmp[0];
            count = 0;
            for (int j = 0; j < res_tmp.size() + 1; j++) {
                if (res_tmp[j] == tmp) {
                    count++;
                } else {
                    res += ('0' + count);
                    res += tmp;
                    if (j == res_tmp.size()) {
                        break;
                    } else {
                        tmp = res_tmp[j];
                        count = 1;
                    }
                }
            }
            res_tmp = res;
        }

        return res;
    }

    int maxSubArray_dynamic(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int dp = nums[0], res = nums[0];

        /*
        two case, the max sub array sum is one of them:
        1 dp[i - 1] + nums[i];
        2 nums[i];
        find the max of the dp
        */
        for (int i = 1; i < nums.size(); i++) {
            dp = max(dp + nums[i], nums[i]);
            res = max(dp, res);
        }

        return res;
    }

    int maxSubArray_greedy(vector<int>& nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++) {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0) {
                sum = 0;
            }
        }

        return result;
    }

    int lengthOfLastWord(string s)
    {
        if (s.size() == 0 || (s.size() == 1 && s[0] == ' ')) {
            return 0;
        } else if (s.size() == 1) {
            return 1;
        }

        int index = s.size() - 1;
        int real_size = s.size();
        while (index >= 0) {
            if (s[index] == ' ') {
                real_size--;
            } else {
                break;
            }
            index--;
        }

        if (real_size == 0) {
            return 0;
        }

        int space_index = 0;
        for (int i = 0; i < real_size; i++) {
            if (s[i] == ' ') {
                space_index = i;
            }
        }

        if (space_index == 0 && s[0] != ' ') {
            return real_size;
        }

        return real_size - space_index - 1;
    }

    vector<int> plusOne(vector<int>& digits)
    {
        if (digits.size() == 0) {
            digits.push_back(1);
            return digits;
        }

        int i = 0;
        int carry = 1;
        for (i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            if (digits[i] > 9) {
                digits[i] = 0;
            } else {
                carry = 0;
                break;
            }
        }

        if (i == -1 && carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

    string addBinary(string a, string b)
    {
        if (a.size() == 0) {
            return b;
        } else if (b.size() == 0) {
            return a;
        }

        string res = a.size() > b.size() ? a : b;
        string::size_type len = a.size() > b.size() ? a.size() : b.size();
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1, k = len - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry == 1) {
                    res[k] = '1';
                } else {
                    res[k] = '0';
                }
                carry = 1;
            } else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) {
                if (carry == 1) {
                    res[k] = '0';
                    carry = 1;
                } else {
                    res[k] = '1';
                    carry = 0;
                }
            } else {
                if (carry == 1) {
                    res[k] = '1';
                    carry = 0;
                } else {
                    res[k] = '0';
                }
            }
            k--;
            i--;
            j--;
        }
        while (k >= 0) {
            if (carry == 1) {
                if (res[k] == '0') {
                    res[k] == '1';
                    carry = 0;
                } else {
                    res[k] = '0';
                }
            } else {
                break;
            }
            k--;
        }
        if (k == -1 && carry == 1) {
            res.insert(res.begin(), '1');
        }

        return res;
    }

    static bool compare(int a, int b)
    {
        return a < b;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0) {
            return;
        }

        int i = m, j = 0;
        while (j < n) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }

        sort(nums1.begin(), nums1.begin() + n + m - 1, compare);

        return;
    }

    ListNode* reverseList_recu(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* new_head = reverseList_recu(head->next);

        head->next->next = head;
        head->next = NULL;
        
        return new_head;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head, *cur_next = head->next, *tmp;

        while (cur_next) {
            tmp = cur_next->next;
            cur_next->next = cur;
            cur = cur_next;
            cur_next = tmp;
        }

        head->next = nullptr;

        return cur;
    }
};

int main()
{
    vector<int> vec1 = { 2, 0 };
    vector<int> vec2 = { 1 };

    vector<int> vec3 = { 2, 1, 3 };
    vector<int>::iterator end = vec3.begin() + 2;

    sort(vec3.begin(), end);

    for (auto vec : vec3) {
        cout << vec << " ";
    }
    cout << endl;

    Solution s;
    s.merge(vec1, 1, vec2, 1);

    return 0;
}