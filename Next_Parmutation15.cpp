#include "bits/stdc++.h"
using namespace std;

void display(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
}

vector<int> nextPermutation(vector<int> &nums)
{
    if (nums.size() > 2)
    {
        int i, c = 0;
        for (i = nums.size() - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                c++;
                break;
            }
        }
        if (c != 0)
        {
            i = i - 1;
            for (int j = nums.size() - 1; j > i; j--)
            {
                if (nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin() + i + 1, nums.end());
                    break;
                }
            }
        }
        else
        {

            reverse(nums.begin(), nums.end());
        }
    }
    else if (nums.size() == 2)
    {
        swap(nums[0], nums[1]);
    }

    return nums;
}
int main()
{
    vector<int> nums = {8, 7, 6, 5, 4, 3}; 
    nextPermutation(nums);
    display(nums);

    return 0;
}

