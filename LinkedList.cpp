#include<iostream>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void listCreation(const int &NumberOfElements)
{
    if(NumberOfElements){
    int data;
    Node *newnode,*temp;
    head = new Node();
    std::cout << "Enter the data of node 1:";
    std::cin >> data;
    head->data = data;
    head->next = NULL;
    temp = head;
    for(int i = 1;i < NumberOfElements;i++)
    {
        newnode = new Node();
        std::cout << "Enter the data of node "<<i+1<<":";
        std::cin >> data;
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }

   }
}
void print(const std::string &functions)
{
    std::cout<<functions<<std::endl;
}
void display()
{
    struct Node *temp;
    temp = head;
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
    temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    delete temp;
    return count;
}
void insertAtBegining()
{
    int data;
    Node *temp;
    temp = new Node();
    std::cout << "Enter the data to be added at begining:";
    std::cin >> data;
    temp->data = data;
    temp->next = head;
    head = temp;
    //delete temp;
}

void insertAtLast()
{
    int data;
    Node *temp,*newnode;
    temp = head;
    newnode = new Node();
    std::cout << "Enter the data to be added at last:";
    std::cin >> data;
    while(temp->next)
    {
        temp=temp->next;
    }    
    newnode->data = data;
    newnode->next = NULL;
    temp->next=newnode;
    temp=newnode;
    //delete newnode;
}

void insertAtPosition(const int &position,const int &NumberOfElements)
{
    if(position==1)
    {
        insertAtBegining();
    }
    else if(position + 1==NumberOfElements)
    {
        insertAtLast();
    }
    else if(position>NumberOfElements)
    {
        std::cout<<"Enter a position less than "<<NumberOfElements<<" (Within the list Size)\n";
    }
    else{
    int data;
    Node *temp,*newnode;
    temp = head;
    newnode = new Node();
    std::cout << "Enter the data to be added at the position "<<position<<":";
    std::cin >> data;
    for(int i = 2;i < position;i++)
    {
        temp=temp->next;
    }    
    newnode->data = data;
    newnode->next = temp->next;
    temp->next=newnode;
    temp=newnode;
    //delete newnode;
    }
}
void deleteAtBegining()
{
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
    
}

void deleteAtLast()
{
    Node *temp;
    temp = head;
    while(temp->next->next)
    {
        temp=temp->next;
    } 
    temp->next = NULL;
    temp = temp->next;
    delete temp;
    
}

void deleteAtPosition(const int &position,const int &NumberOfElements)
{
    if(position==1)
    {
        deleteAtBegining();
    }
    else if(position==NumberOfElements)
    {
        deleteAtLast();
    }
    else if(position>NumberOfElements)
    {
        std::cout<<"Enter a position less than "<<NumberOfElements<<" (Within the list Size)\n";
    }
    else{
    Node *temp1,*temp2;
    temp1 = head;
    for(int i = 0;i < position - 1;i++)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }    
    temp2->next = temp1->next;
    delete temp1;
    
    }
}


int main()
{
    int NumberOfElements,choice,position,presentNoOfElements;
    std::cout << "Enter the no of Elements to be created:";
    std::cin >> NumberOfElements;
    listCreation(NumberOfElements);
    while(1){
        print("---------------------------");
        print("Enter Your Choice");
        print("To Display - 0");
        print("To Insert At Begining - 1");
        print("To Insert At Position - 2");
        print("To Insert At Last - 3");
        print("To Delete At Begining - 4");
        print("To Delete At Position - 5");
        print("To Delete At last - 6");
        print("To view Total No Of Elements - 7");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin >> choice;
        switch(choice)
        {
            case 0:display(); break;
            case 1: insertAtBegining(); break;
            case 2: print("Enter the position");
                    std::cin>>position;
                    presentNoOfElements = totalNoOfelements();
                    insertAtPosition(position,presentNoOfElements);
                    break;
            case 3: insertAtLast(); break;
            case 4: deleteAtBegining(); break;
            case 5: print("Enter the position");
                    std::cin>>position;
                    presentNoOfElements = totalNoOfelements();
                    deleteAtPosition(position,presentNoOfElements);
                    break;
            case 6: deleteAtLast(); break;
            case 7: std::cout<<"Total No of Elements at present:"<<totalNoOfelements()<<std::endl; break;
            default : exit(EXIT_SUCCESS);
        }
    }
}