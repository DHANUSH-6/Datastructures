#include<iostream>
void insertionSort(int array[],int &n)
{
    for(int i=1;i<n;i++)
    {
        int temp = array[i];
        int j=i-1;
        while(j>=0 && array[j]>temp)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=temp;
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
    insertionSort(array, n);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}