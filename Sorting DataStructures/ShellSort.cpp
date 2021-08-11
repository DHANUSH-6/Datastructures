#include<iostream>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void ShellSort(int array[], int& n)
{
    for (int gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (array[i + gap] > array[i])
                {
                    break;
                }
                else {
                    swap(array[i + gap], array[i]);
                }
            }
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
    ShellSort(array, n);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}