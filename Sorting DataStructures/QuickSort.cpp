#include<iostream>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partitioning(int array[], int lowerbound,int upperbound)
{
    int pivot = array[lowerbound];
   int start = lowerbound;
   int end = upperbound;
   while(start < end)
   {
       while(array[start]<=pivot)
       {
           start++;
       }
       while(array[end]>pivot)
       {
           end--;
       }
       if(start<end)
       {
           swap(array[start],array[end]);
       }
   }
   swap(array[lowerbound],array[end]);
   return end;
}
void QuickSort(int array[], int lowerbound,int upperbound)
{
    if(lowerbound<upperbound)
    {
        int location = partitioning(array,lowerbound,upperbound);
        QuickSort(array,lowerbound,location-1);
        QuickSort(array,location+1,upperbound);
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
    QuickSort(array, 0, n-1);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}