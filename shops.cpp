/*
Implement a problem of activity selection problem
with K persons.
Statement: Given two arrays S[] and E[] of size N denoting starting
and closing time of the shops and an integer value K denoting the
number of people, the task is to find out the maximum number of
shops they can visit in total if they visit each shop optimally based
on the following conditions:
 A shop can be visited by only one person
 A person cannot visit another shop if its timing collide with it
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
Output: 3
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Shop
{
    int start, end;
};

bool compare(Shop a, Shop b)
{
    return a.end < b.end;
}

int main()
{
    int n, k;
    cout << "Enter Number of shops: " << endl;
    cin >> n;

    Shop shops[10];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter opening time of shop " << i + 1 << ": ";
        cin >> shops[i].start;
        cout << "Enter closing time of shop " << i + 1 << ": ";
        cin >> shops[i].end;
    }

    cout << "Enter number of persons: " << endl;
    cin >> k;
    sort(shops, shops + n, compare);

    vector<int> lastVisited(k, 0);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (shops[i].start >= lastVisited[j])
            {
                lastVisited[j] = shops[i].end;
                count++;
                break;
            }
        }
    }

    cout << "Maximum number of shops that can be visited: " << count << endl;

    return 0;
}
