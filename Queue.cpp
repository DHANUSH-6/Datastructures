#include<iostream>

struct Node
{
  int data;
  struct Node *next = NULL;  
};
struct Node *front = NULL, *rear = NULL;

void print(const std::string &functions)
{
    std::cout<<functions<<std::endl;
}
void display()
{
    struct Node *temp;
    temp = front;
    if(!temp)
        std::cout<<"Queue is Empty!!\n";
    if(temp){
    std::cout<<"----------------------\n";
    while(temp)
    {
        std::cout<<temp->data<<std::endl;
        temp = temp->next;
    }
    std::cout<<"----------------------\n";
    }
    delete temp;
}
int totalNoOfelements()
{
    int count=0;
    Node *temp;
    temp = front;
    while(temp!=rear->next)
    {
        temp = temp->next;
        count++;
    }
    delete temp;
    return count;
}
void enQueue()
{
    int data;
    Node *newnode = new Node();
    std::cout<<"Enter the data to be enqueued:";
    std::cin>>data;
    newnode->data = data;
    newnode->next = NULL;
    if(!(front&&rear))
    {
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    std::cout<<rear->data<<" has been enqueued successfully\n";
}
void deQueue()
{
    Node *temp;
    temp = front;
    std::cout<<front->data<<" has been dequeued successfully\n";
    front = front->next;
    delete temp;
}
void peek()
{
    int choice;
    std::cout<<"press 0 for front or any other number for rear:";
    std::cin>>choice;
    (choice == 0)?std::cout<<"front element ="<<front->data<<std::endl : std::cout<<"rear element ="<<rear->data<<std::endl;
}
int main()
{
    
    int choice;
    while(1){
        print("---------------------------");
        print("To Display - 0");
        print("To Perform Enqueue - 1");
        print("To Perform Dequeue - 2");
        print("To Display the front/rear element - 3");
        print("To view Total No Of Elements - 4");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin>>choice;
        switch(choice)
        {
            case 0:display(); break;
            case 1:enQueue(); break;
            case 2:deQueue(); break;
            case 3:peek(); break;
            case 4:std::cout<<"Total No Of Elements in Queue :"<<totalNoOfelements()<<std::endl;
                    break;
            default:exit(EXIT_SUCCESS);
        }
    }
}