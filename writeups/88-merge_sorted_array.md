# Merge Sorted Array (88)

## Description
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

## Analysis

Let's analyse You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.some approaches.

First approach:

- Merge the 2 vectors by insterting nums2 at the end of nums1
- Apply merge sort on the merged vector

Code (C++):

"""
#include <iostream>
#include <vector>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        nums1 = merge_sort(nums1);
    }

    std::vector<int> merge_sort(vector<int> vector) {
        if (vector.size() <= 1)
            return vector;

        int mid = vector.size() / 2;
        std::vector<int> left_half(vector.begin(), vector.begin() + mid);
        std::vector<int> right_half(vector.begin() + mid,
                                    vector.begin() + vector.size());

        std::vector<int> sorted_left = merge_sort(left_half);
        std::vector<int> sorted_right = merge_sort(right_half);

        return merge_vector(sorted_left, sorted_right);
    }

    std::vector<int> merge_vector(vector<int> left_vector,
                                  vector<int> right_vector) {
        vector<int> sorted_vector;

        int i = 0;
        int j = 0;
        while (i < left_vector.size() && j < right_vector.size()) {
            if (left_vector[i] <= right_vector[j]) {
                sorted_vector.push_back(left_vector[i]);
                i++;
            } else {
                sorted_vector.push_back(right_vector[j]);
                j++;
            }
        }

        if (i < left_vector.size()) {
            sorted_vector.insert(sorted_vector.end(), left_vector.begin() + i,
                                 left_vector.end());
        } else {
            sorted_vector.insert(sorted_vector.end(), right_vector.begin() + j,
                                 right_vector.end());
        }

        return sorted_vector;
    }
};
"""

Second approach:

- Merge the 2 vectors by insterting nums2 at the end of nums1
- Apply quick sort on the merged vector

Code (C++):

"""
#include <iostream>
#include <vector>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        quick_sort(nums1, 0, m+n-1);
    }

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int>& vector, int low, int high){
        int pivot = vector[high];
        int bigger = -1;
        int j = high-1;

        // Search for bigger from left
        for(int i=0; i<=j; i++){
            if(pivot < vector[i]){
                // Found it
                bigger = i;
                for(j=j; j>low; j--){
                    if (pivot > vector[j]){
                        cout << "Bigger: " << i << " Smaller: " << j << endl;
                        if(i >= j){
                            swap(vector[i], vector[high]);
                            return i;
                        }
                        swap(vector[i], vector[j]);
                        break;
                    }
                }
            }
        }
        if(bigger != -1){
            swap(vector[bigger], vector[high]);
            return bigger;
        }else{
            return high;
        }
    }

    void quick_sort(vector<int>& vector, int low, int high){
        if(low < high){
            int part_index = partition(vector, low, high);
            for (int i : vector) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            cout << part_index << endl;
            if(part_index != high){
                quick_sort(vector, part_index+1, high);
            }
            if(part_index != low){
                quick_sort(vector, low, part_index-1);
            }
        }
    }
};
"""

## THIRD APPROACH

SONO UN COGLIONE, GLI ARRAY SONO GIÀ IN ORDINE PER GIOVE.
MI BASTA LETTERALMENTE APPLICARE QUELLO CHE FACEVAMO COL MERGE.

Code (C++):
"""
#include <algorithm>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;

        vector<int> nums3;
        
        while (i < m && j < n){
            if(nums1[i] < nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        if (i<m) {
            nums3.insert(nums3.end(), nums1.begin()+i, nums1.begin()+m);
        }else{
            nums3.insert(nums3.end(), nums2.begin()+j, nums2.end());
        }

        nums1 = nums3;
    }
};
"""

OPPURE

"""
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;

        if(n==0){
            return;
        }

        for (int k=0; k<m+n; k++){
            if(j==n){
                return;
            }
            if(nums1[k] > nums2[j] || i==m){
                nums1.insert(nums1.begin() + k, nums2[j++]);
                nums1.pop_back();
            }else{
                i++;
            }
        }
 
    }
};
"""

OPPURE (ANCORA MEGLIO)

"""
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(j>=0){
            if (i >= 0 && nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }
};
"""
Piu veloce del while anche se non ha sensissimo

"""
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m-1;
    int j = n-1;

    for(int k=nums1Size-1; k>=0; k--){
        if( i>=0 && (j<0 || nums1[i] >= nums2[j])){
            nums1[k] = nums1[i];
            i--;
        }else{
            nums1[k] = nums2[j];
            j--;
        }
    }
}
"""
