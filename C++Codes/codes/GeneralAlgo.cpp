#include "header.h"

namespace GeneralAlgo {

//============================ Quick Sort =============================//

int partition(vector<int>& nums, int left, int right)
{
    int i = left, j = right;
    while (i < j) 
    {
        while ((i < j) && nums[j] >= nums[left]) --j;
        while ((i < j) && nums[i] <= nums[left]) ++i;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}


//============================ Binary Search =============================//

int binary_search(const vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

}


int main()
{
    vector<int> nums = { 5, 2, 4, 6, 1, 3 };
    GeneralAlgo::quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;

    int target = 3;
    int index = GeneralAlgo::binary_search(nums, target);
    if (index == -1) cout << "Not found" << endl;
    else cout << "Found at index " << index << endl;

    return 0;
}