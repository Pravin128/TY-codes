#include <iostream>
using namespace std;

void sortShops( int e[], int n, int index[])
{
    for (int i = 0; i < n; i++)
    {
        index[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (e[index[j]] < e[index[minIndex]])
            {
                minIndex = j;
            }
        }
        int temp = index[i];
        index[i] = index[minIndex];
        index[minIndex] = temp;
    }
}

int visited(int s[], int e[], int n, int k)
{
    int index[10];
    sortShops(e, n, index);

    int lastVisited[10] = {0};
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int shopIndex = index[i];
        for (int j = 0; j < k; j++)
        {
            if (s[shopIndex] >= lastVisited[j])
            {
                lastVisited[j] = e[shopIndex];
                count++;
                break;
            }
        }
    }

    return count;
}

int main()
{
    int s[10], e[10], n, k;
    cout << "Enter number of shops: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter opening time of shop " << i + 1 << ": ";
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter closing time of shop " << i + 1 << ": ";
        cin >> e[i];
    }

    cout << "Enter number of persons: " << endl;
    cin >> k;

    int result = visited(s, e, n, k);
    cout << "Maximum number of shops that can be visited: " << result << endl;

    return 0;
}
