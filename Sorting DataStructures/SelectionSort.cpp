#include<iostream>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void SelectionSort(int array[], int& n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < n ; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min!=i)
        {
            swap(array[i],array[min]);
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
    SelectionSort(array, n);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}