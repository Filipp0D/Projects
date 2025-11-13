// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Leet_1.h"
#include <unordered_set>
#include <set>

using namespace std;

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
vector<int> twoSum(vector<int> nums, int target) {
	int temp = 0;
	bool isFound = false;
	for (int i = 0; i < nums.size(); i++)
	{
		temp = target - nums[i];
		for (int j = i; j < nums.size(); j++) {
			if (nums[j] == temp) {
				isFound = true;
				return { i, j };
			}
		}
	}
	if (!isFound) {
		cout << "no couple found to satisfy the target" << endl;
		return { 0,0 };
	}
}

//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order, and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	int carry = 0;
	ListNode dummy;		//supporto per la testa della coda
	ListNode* curr = &dummy;	// associo a &dummy il suo stesso indirizzo

	while (l1 != nullptr || l2 != nullptr) {
		int sum = l1->val + l2->val + carry;

		if (sum > 9) {
			sum = sum - 10;
			carry = 1;
		}
		else {
			carry = 0;
		}

		curr->next = new ListNode(sum);
		l1 = l1->next;
		l2 = l2->next;
		curr = curr->next;
	}
	return dummy.next;
}

//Given a string s, find the length of the longest substring without duplicate characters.
int lengthOfLongestSubstring(string s) {
	
	unordered_set<char> charsFound;
	int idx_lastrep = 0;
	int maxLenght = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (charsFound.find(s[i]) != charsFound.end()) {
			if (maxLenght < i - idx_lastrep) maxLenght = i - idx_lastrep;
			idx_lastrep = i;
			charsFound.clear();
		}
		charsFound.insert(s[i]);
	}
	return maxLenght;

}

//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log(m + n)).
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> mergedArray;
	int idx_1 = 0;
	int idx_2 = 0;
	double median = 0;
	mergedArray = mergeArrayRecursive(mergedArray, nums1, nums2, idx_1, idx_2);
	
	int sizeArr = mergedArray.size();
	if ((sizeArr%2) == 0)
	{
		median = (mergedArray[sizeArr - 1] + mergedArray[sizeArr]) / 2;
	}
	else {
		median = mergedArray[sizeArr - 1];
	}
	return median;

}
vector<int> mergeArrayRecursive(vector<int> mergedArray,vector<int>& arr1, vector<int>& arr2, int idx_1, int idx_2) {
	if (idx_1 != arr1.size() || idx_2 != arr2.size()) {
		if (arr1[idx_1] <= arr2[idx_2]) {
			mergedArray.push_back(arr1[idx_1]);
			idx_1++;
			mergeArrayRecursive(mergedArray, arr1, arr2, idx_1, idx_2);
		}
		else
		{
			mergedArray.push_back(arr1[idx_2]);
			idx_2++;
			mergeArrayRecursive(mergedArray, arr1, arr2, idx_1, idx_2);
		}
	}
	else
	{
		return mergedArray;
	}
}