#include <iostream>
#include "Leet_1.h"

using namespace std;


int main() {
    /* Leet_2
    ListNode *l1_3 = new ListNode(5, nullptr);
    ListNode* l1_2 = new ListNode(2, l1_3);
    ListNode* l1 = new ListNode(9, l1_2);

    ListNode* l2_3 = new ListNode(7);
    ListNode* l2_2 = new ListNode(3, l2_3);
    ListNode* l2 = new ListNode(8, l2_2);

    ListNode* result = addTwoNumbers(l1, l2);

    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
    */

    vector<int> nums1 = { 1,3,5,7 };
    vector<int> nums2 = { 2,4,6,8 };
    double median = findMedianSortedArrays(nums1, nums2);
    cout << median << endl;

    return 0;
}