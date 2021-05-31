#include "bits/stdc++.h"
using namespace std;

void display(vector<vector<int>> &intervals)
{
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << intervals[i][0] << " " << intervals[i][1] << endl;
    }
}
vector<vector<int>> merge(vector<vector<int>> intervals)
{

    sort(intervals.begin(), intervals.end()); //sorting the vector
    int index = 0;
    for (auto interval : intervals)
    {

        if (interval[0] <= intervals[index][1])
        {

            intervals[index][1] = max(interval[1], intervals[index][1]);
        }
        else
        {
            index++;
            intervals[index] = interval;
        }
    }

    intervals.resize(distance(intervals.begin(), intervals.begin() + index + 1));
    display(intervals);
    return intervals;
}

int main()
{

    vector<vector<int>> intervals;
    vector<int> v1 = {2, 3};
    vector<int> v2 = {2, 2};
    vector<int> v3 = {3, 3};
    vector<int> v4 = {1, 3};
    vector<int> v5 = {5, 7};
    vector<int> v6 = {2, 2};
    vector<int> v7 = {4, 6};

    intervals.push_back(v1);

    intervals.push_back(v2);

    intervals.push_back(v3);
    intervals.push_back(v4);
    intervals.push_back(v5);
    intervals.push_back(v6);
    intervals.push_back(v7);

    merge(intervals);
    display(intervals);
}
