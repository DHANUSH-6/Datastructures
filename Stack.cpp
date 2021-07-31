#include<iostream>

struct Node
{
    int data;
    struct Node *next = NULL;
};
struct Node *top = NULL;
void print(const std::string &functions)
{
    std::cout<<functions<<std::endl;
}
void display()
{
    struct Node *temp;
    temp = top;
    if(!temp)
        std::cout<<"Stack is Empty!!\n";
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
    temp = top;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    delete temp;
    return count;
}
void Push()
{
    int data;
    Node *newnode = new Node();
    std::cout<<"Enter the data to be pushed:";
    std::cin>>data;
    newnode->data = data;
    if(!top)
    {
        newnode->next = NULL;
    }
    else
    {
        newnode->next = top;
    }
    top = newnode;
    std::cout<<top->data<<" is Pushed to stack\n";
}
void Pop()
{
    Node *temp;
    temp = top;
    std::cout<<top->data<<" is Poped from stack\n";
    top = top->next;
    delete temp;
}
void peek()
{
    std::cout<<"Peek Element = "<<top->data<<std::endl;
}
int main()
{
    int choice;
    while(1){
        print("---------------------------");
        print("To Display - 0");
        print("To Push an element into stack - 1");
        print("To Pop an element out of stack - 2");
        print("To Display the peek element - 3");
        print("To view Total No Of Elements - 4");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin>>choice;
        switch(choice)
        {
            case 0:display(); break;
            case 1:Push(); break;
            case 2:Pop(); break;
            case 3:peek(); break;
            case 4:std::cout<<"Total No Of Elements in stack :"<<totalNoOfelements()<<std::endl;
                    break;
            default:exit(EXIT_SUCCESS);
        }
    }
}