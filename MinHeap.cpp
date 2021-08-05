#include<iostream>
#define Max 50

int noOfElements = 0;

int isFull()
{
    return noOfElements==Max;
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
int searchElement(int MinHeap[] , int &element)
{
    if(MinHeap[0] == element)
    {
        return 1;
    }
    for(int i = 1 ; i<noOfElements ; i++)
    {
        if(element == MinHeap[i])
        return i;
    }
    return 0;
}
void heapify(int array[],int &size,int &position)
{
    if(size>1)
    {
        int smallest = position;
        int leftChild = (2 * position) + 1;
        int rightChild = (2 * position) + 2;
        if(size>leftChild && array[leftChild]<array[smallest])
        {
            smallest = leftChild;
        }
        if(size>rightChild && array[rightChild]<array[smallest])
        {
            smallest = rightChild;
        }
        if(smallest != position)
        {
            swap(array[position],array[smallest]);
            heapify(array,size,smallest);
        }
    }
}
void insertMinHeap(int MinHeap[] , int &element)
{
    if(noOfElements==0)
    {
        MinHeap[noOfElements++] = element;
    }
    else
    {
        MinHeap[noOfElements++] = element;
        for(int i = (noOfElements/2) - 1; i>=0;i--)
        {
            heapify(MinHeap,noOfElements,i);
        }
    }
}
void deleteElement(int MinHeap[] , int &element)
{
    int i;
    if(MinHeap[0] == element)
    {
        i = 0;
        goto del;
    }
    i = searchElement(MinHeap,element);
    if (i)
     {
        del:
        swap(MinHeap[i],MinHeap[noOfElements - 1]);
        noOfElements -= 1;
        for(int i = (noOfElements/2) - 1; i>=0;i--)
            {
                heapify(MinHeap,noOfElements,i);
            }
            std::cout << element << " has been deleted from the Min Heap" << std::endl;
        }
    else {
                std::cout << element << " is not present in the Min heap,enter a valid element present in the heap to delete\n";
        }
    
}
void displayMinHeap(int MinHeap[])
{
    if(isEmpty())
    {
        print("Heap is empty,Try to insert some elements");
    }
    else
    {
        for(int i = 0 ; i<noOfElements ; i++)
        {
            std::cout<<MinHeap[i]<<" ";
        }
    }
}
int main()
{
    int MinHeap[Max];
    int choice, key;
    while (1)
    {
        print("---------------------------");
        print("Enter Your Choice");
        print("To display the Min Heap - 0");
        print("To insert an element in the Min Heap - 1");
        print("To delete an Element in the Min Heap - 2");
        print("To search an Element in the Min Heap - 3");
        print("To print the total no of elements - 4");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            displayMinHeap(MinHeap);
            std::cout << std::endl;
            break;
        case 1:
            std::cout << "Enter an element :";
            std::cin >> key;
            insertMinHeap(MinHeap,key);
            std::cout << key << " has been inserted to the Min Heap" << std::endl;
            break;
        case 2:
        std::cout << "Current Elements are ( ";
            displayMinHeap(MinHeap);
            std::cout << ") Try to delete one of these elements\n";
            std::cout << "Enter an element to be deleted:";
            std::cin >> key;
            deleteElement(MinHeap,key);
            break;
        case 3:
            std::cout << "Enter an element to be searched:";
            std::cin >> key;
            if (searchElement(MinHeap,key))
                std::cout << key << " is present in the Min Heap\n";
            else
                std::cout << key << " is not present in the Min Heap\n";
            break;
        case 4:
            std::cout<<"Total Number of Elements are : "<<noOfElements<<std::endl;
            break;
        default:
            exit(EXIT_SUCCESS);
        }
    }
}