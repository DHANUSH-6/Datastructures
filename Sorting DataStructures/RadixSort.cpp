#include<iostream>
int getMax(const int array[],const int& n)
{
    int temp = array[0];
    for (int i = 1; i < n ; i++)
    {
        if(array[i]>temp)
        {
            temp = array[i];
        }
    }
    return temp;
}
void countSort(int array[], int n,int position)
{
    int count[10] = {0,0,0,0,0,0,0,0,0,0};
    int temp[50];
    for (int i = 0; i < n ; i++)
    {
        ++count[(array[i]/position) % 10];
    }
    for(int i = 1; i <= 9 ; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for(int i = n-1; i >= 0 ; i--)
    {
        temp[(--count[(array[i]/position) % 10])] = array[i];
    }
    for (int i = 0; i < n ; i++)
    {
        array[i] = temp[i];
    }
}
void RadixSort(int array[], int& n)
{
    int max = getMax(array,n);
    for(int bitPosition = 1; max/bitPosition > 0; bitPosition = bitPosition*10)
    {
        countSort(array,n,bitPosition);
    }    
}
int main()
{
    int n;
    int array[50];
    std::cout << "Enter the Total Number of elements needs to be sorted:";
    std::cin >> n;
    std::cout << "Enter " << n << " Elements:";
    for (int i = 0; i < n; i++)
        std::cin >> array[i];
    RadixSort(array, n);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}