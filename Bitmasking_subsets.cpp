/*Implement program to find all distinct subsets of a
given set using Bit Masking Approach.
Statement Given an array of integers arr[], The task is
to find all its subsets. The subset cannot contain
duplicate elements, so any repeated subset should be
considered only once in the output.
Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2,
2}, {1, 2,2}
Input: S = {1, 2} Output: {}, {1}, {2}, {1, 2}
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<int> &nums)
{
    set<vector<int>> res;
    vector<int> subset;
    int size = nums.size();
    int N = 1 << size;
    for (int i = 1; i < N; i++)
    {
        int bit = i;
        subset.clear();
        int pos = 0;

        while (bit)
        {
            if (bit & 1)
            {
                subset.push_back(nums.at(pos));
            }
            pos++;
            bit >>= 1;
        }
        res.insert(subset);
    }
    vector<vector<int>> result;
    for (auto u : res)
        result.push_back(u);
    return result;
}
int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solve(nums);
    for (auto v : result)
    {
        for (int i : nums)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}