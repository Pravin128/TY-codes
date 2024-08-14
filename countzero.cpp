#include <iostream>
using namespace std;

int main()
{
    int array[10], n;
    cout << "Enter number of elements: " << endl;
    cin >> n;

    cout << "Enter elements: "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at position " << i << ": ";
        cin >> array[i];
        if (array[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                cout << "Enter element at position " << j << ": ";
                cin >> array[j];
                if (array[j] == 1)
                {
                    cout << "You cannot insert 1 after 0" << endl;
                    j--;
                }
            }
            break;
        }
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)  //display array
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    int low = 0, high = n - 1, mid;
    while (low <= high) //divide array till we get first zero
    {
        mid = (low + high) / 2;
        if (array[mid] == 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Number of zeros: " << (n - low) << endl;

    return 0;
}
