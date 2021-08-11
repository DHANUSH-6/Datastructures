#include<iostream>
void Merge(int array[], int lowerbound,int mid,int upperbound)
{
    int i = lowerbound;
    int j = mid+1;
    int k = lowerbound;
    int temp[50];
    while(i<=mid && j<=upperbound)
    {
        if(array[i]<=array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else{
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=upperbound)
        {
            temp[k] = array[j];
            j++ , k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k] = array[i];
            i++ , k++;
        }
    }
    for (k = lowerbound; k <= upperbound; k++)
    {
        array[k] = temp[k];
    }
}
void MergeSort(int array[], int lowerbound,int upperbound)
{
    if(lowerbound<upperbound)
    {
        int mid= (lowerbound + upperbound) / 2; 
        MergeSort(array,lowerbound,mid);
        MergeSort(array,mid + 1,upperbound);
        Merge(array,lowerbound,mid,upperbound);
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
    MergeSort(array, 0, n-1);
    std::cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}