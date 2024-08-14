#include <iostream>
#include<cmath>
using namespace std;

long double factorial(int Num)
{
    long double fact = 1;
    while (Num > 0)
    {
        fact = Num * fact;
        Num--;
    }
    return fact;
}

long double countZero(long double fact)
{
    int count = 0;
    while (fact >= 10 && fmod(fact, 10) == 0)
    {
        count++;
        fact /= 10;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the number of trailing zeros required: ";
    cin >> n;

    if (n == 0)
    {
        cout << "The smallest number with " << n << " trailing zeros is 0" << endl;
        return 0;
    }

    long double Num = 5;
    while (true)
    {
        long double fact = factorial(Num);
        if (countZero(fact) == n)
        {
            cout << "Number having factorial with " << n << " trailing zeros is " << Num << endl;
            break;
        }
        Num += 1;
    }
    return 0;
}
