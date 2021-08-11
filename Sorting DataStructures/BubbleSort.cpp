#include<iostream>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort(int array[], int& n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
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
    BubbleSort(array, n);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}