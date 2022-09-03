#include <iostream>

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int l=0;
//        int r=nums.size()-1;
//        int mid;
//        while(l<=r)
//        {
//            mid=(l+r)/2;
//            if(nums[mid]==target)
//            {
//                return mid;
//            }
//            if(nums[0]<=nums[mid])
//            {
//                if(nums[mid]>target&&nums[0]<=target)
//                {
//                    r=mid-1;
//                }else{
//                    l=mid+1;
//                }
//
//            }else
//            {
//                if(nums[mid]<target&&nums[r]>=target)
//                {
//                    l=mid+1;
//                }else{
//                    r=mid-1;
//                }
//            }
//        }
//        return -1;
//    }
//};

  //Definition for singly-linked list.
  struct ListNode {
     int val;
      struct ListNode *next;
  };



int getDecimalValue(struct ListNode* head){
    int count = 0, num = 0;
    int a[30] = { 0 };
    struct ListNode* cur = head;
    while(cur->val == 0 || cur->val == 1)
    {
        a[count++] = cur->val;
        cur = cur->next;
    }
    for(int i = count - 1; i >= 0; i--)
    {
        num += pow(2, count - 1 - i);
    }
    return num;
}