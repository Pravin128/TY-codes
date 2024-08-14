/* Implement a problem of smallest number with at
least n trailing zeroes in factorial.
Statement: Given a number n. The task is to find the
smallest number whose factorial contains at least n
trailing zeroes.
Input : n = 1                  Output : 5
Input : n = 6                  Output : 25  */

#include <iostream>
using namespace std;

int TrailingZeros(int num) // COUNT NUMBER OF ZEROS IN FACTORIAL
{
    int count = 0;
    for (int i = 5; num / i >= 1; i *= 5)
    {
        count += num / i; // number of zeros are counted by counting number of factors of 5 and its powers.
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter Number of trailing zeros:" << endl;
    cin >> n;

    int low = 0;
    int high = 5 * n;
    int result = -1;

    while (low <= high) //find minimum element
    {
        int mid = (low + high) / 2;
        int Zeros = TrailingZeros(mid);

        if (Zeros < n)
        {
            low = mid + 1;
        }
        else if (Zeros > n)
        {
            high = mid - 1;
        }
        else
        {
            result = mid;
            high = mid - 1;
        }
    }

    if (result != -1)
    {
        cout << "The smallest number having factorial with " << n << " trailing zeros is " << result << endl;
    }
    else
    {
        cout << "No such number exists." << endl;
    }

    return 0;
}
