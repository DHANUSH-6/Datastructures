#include<iostream>
#define MAX 50

int noOfElements = 0;
int isFull()
{
    return noOfElements==MAX;
}
int isEmpty()
{
    return noOfElements==0;
}
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void print(const std::string& functions)
{
    std::cout << functions << std::endl;
}
int searchElement(int MaxHeap[] , int &element)
{
    if(MaxHeap[0] == element)
    {
        return 1;
    }
    for(int i = 1 ; i<noOfElements ; i++)
    {
        if(element == MaxHeap[i])
        return i;
    }
    return 0;
}
void heapify(int array[],int &size,int &position)
{
    if(size>1)
    {
        int largest = position;
        int leftChild = (2 * position) + 1;
        int rightChild = (2 * position) + 2;
        if(size>leftChild && array[leftChild]>array[largest])
        {
            largest = leftChild;
        }
        if(size>rightChild && array[rightChild]>array[largest])
        {
            largest = rightChild;
        }
        if(largest != position)
        {
            swap(array[position],array[largest]);
            heapify(array,size,largest);
        }
    }
}
void insertMaxHeap(int MaxHeap[] , int &element)
{
    if(noOfElements==0)
    {
        MaxHeap[noOfElements++] = element;
    }
    else
    {
        MaxHeap[noOfElements++] = element;
        for(int i = (noOfElements/2) - 1; i>=0;i--)
        {
            heapify(MaxHeap,noOfElements,i);
        }
    }
}
void deleteElement(int MaxHeap[] , int &element)
{
    int i;
    if(MaxHeap[0] == element)
    {
        i = 0;
        goto del;
    }
    i = searchElement(MaxHeap,element);
    if (i)
     {
        del:
        swap(MaxHeap[i],MaxHeap[noOfElements - 1]);
        noOfElements -= 1;
        for(int i = (noOfElements/2) - 1; i>=0;i--)
            {
                heapify(MaxHeap,noOfElements,i);
            }
            std::cout << element << " has been deleted from the Max Heap" << std::endl;
        }
    else {
                std::cout << element << " is not present in the Max heap,enter a valid element present in the heap to delete\n";
        }
    
}
void displayMaxHeap(int MaxHeap[])
{
    if(isEmpty())
    {
        print("Heap is empty,Try to insert some elements");
    }
    else
    {
        for(int i = 0 ; i<noOfElements ; i++)
        {
            std::cout<<MaxHeap[i]<<" ";
        }
    }
}

int main()
{
    int MaxHeap[MAX];
    int choice, key;
    while (1)
    {
        print("---------------------------");
        print("Enter Your Choice");
        print("To display the Max Heap - 0");
        print("To insert an element in the Max Heap - 1");
        print("To delete an Element in the Max Heap - 2");
        print("To search an Element in the Max Heap - 3");
        print("To print the total no of elements - 4");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            displayMaxHeap(MaxHeap);
            std::cout << std::endl;
            break;
        case 1:
            std::cout << "Enter an element :";
            std::cin >> key;
            insertMaxHeap(MaxHeap,key);
            std::cout << key << " has been inserted to the Max Heap" << std::endl;
            break;
        case 2:
        std::cout << "Current Elements are ( ";
            displayMaxHeap(MaxHeap);
            std::cout << ") Try to delete one of these elements\n";
            std::cout << "Enter an element to be deleted:";
            std::cin >> key;
            deleteElement(MaxHeap,key);
            break;
        case 3:
            std::cout << "Enter an element to be searched:";
            std::cin >> key;
            if (searchElement(MaxHeap,key))
                std::cout << key << " is present in the Max Heap\n";
            else
                std::cout << key << " is not present in the Max Heap\n";
            break;
        case 4:
            std::cout<<"Total Number of Elements are : "<<noOfElements<<std::endl;
            break;
        default:
            exit(EXIT_SUCCESS);
        }
    }
}