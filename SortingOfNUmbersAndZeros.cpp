/*
Name:Pravin Thorve
Div:TY-B
Implement a problem of move all zeroes to end of
array.
Statement: Given an array of random numbers, Push all the zero’s
of a given array to the end of the array. For example, if the given
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9,
8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be
same.
Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};*/
#include <iostream>
using namespace std;
int main()
{
    int array[10],n,Number,temp;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    temp=n;
    cout<<"Enter Array Elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        array[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>Number;
        if(Number==0)
        {
            array[n]=0;
            n--;
            i--;
        }
        else
        {
            array[i]=Number;
        }
    }
    for(int i=0;i<temp;i++)
    {
        cout<<array[i]<<"\t";
    }
return 0;
}