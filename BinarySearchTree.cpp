//Binary Search Tree
#include<iostream>

struct Node
{
    int data;
    struct Node* left = NULL, * right = NULL;
};
struct Node* root = NULL;
void print(const std::string& functions)
{
    std::cout << functions << std::endl;
}
struct Node* createTree(int data)
{
    //Creating the root node
    struct Node* temp;
    temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* insertTree(struct Node* temp, int key)
{
    if (!temp) //if node is null
        return createTree(key);

    if (temp->data > key)
        temp->left = insertTree(temp->left, key);

    if (temp->data < key)
        temp->right = insertTree(temp->right, key);

    return temp;
}
struct Node* smallestElement(struct Node* temp)
{
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}
struct Node* largestElement(struct Node* temp)
{
    while (temp && temp->right != NULL)
        temp = temp->right;
    return temp;
}
struct Node* deleteNode(struct Node* temp, int key)
{
    if (!temp)  //if node is null
        return temp;

    if (temp->data > key)                        //if the key is present in left subtree
        temp->left = deleteNode(temp->left, key);

    if (temp->data < key)                        //if the key is present in right subtree
        temp->right = deleteNode(temp->right, key);
    else if (temp->data == key) {
        if (temp->left == NULL && temp->right == NULL)
        {
            struct Node* toReplace = nullptr;
            temp = toReplace;
            delete toReplace;
            return temp;
        }
        else if (!temp->left)    //if left child if not present
        {
            struct Node* toReplace = temp->right;
            if (toReplace->left)
            {
                temp->left = toReplace->left;
            }
            else
            {
                temp->left = NULL;
            }
            if (toReplace->right)
            {
                temp->right = toReplace->right;
            }
            else
            {
                temp->right = NULL;
            }
            temp = toReplace;
            temp->data = toReplace->data;
            //delete toReplace;
            return temp;
        }
        else if (!temp->right)   //if right child if not present
        {
            struct Node* toReplace = temp->left;
            if (toReplace->right)
            {
                temp->right = toReplace->right;
            }
            else
            {
                temp->right = NULL;
            }
            if (toReplace->left)
            {
                temp->left = toReplace->left;
            }
            else
            {
                temp->left = NULL;
            }
            temp = toReplace;
            temp->data = toReplace->data;
            //delete toReplace;
            return temp;
        }

        //when node has 2 children
        if (temp->right) {
            struct Node* tempNode = smallestElement(temp->right);   //In this step we are finding the inorder successor by calling the smallestElement using the right subtree
            temp->data = tempNode->data;                            //then assigning the inorder successor to the number to be deleted
            temp->right = deleteNode(temp->right, tempNode->data);  //the deleting the inorder successor
        }
        else if (temp->left) {
            struct Node* tempNode = largestElement(temp->left);   //In this step we are finding the inorder predecessor by calling the smallestElement using the right subtree
            temp->data = tempNode->data;                          //then assigning the inorder predecessor to the number to be deleted
            temp->left = deleteNode(temp->left, tempNode->data);  //the deleting the inorder predecessor
        }
       

    }
     return temp;
}
int searchTree(struct Node* temp, int data)
{
    if (!temp)
        return 0;
    else if (temp->data > data)
        searchTree(temp->left, data);
    else if (temp->data < data)
        searchTree(temp->right, data);
    else if (temp->data == data)
        return 1;

}
void displayTree(struct Node* temp)
{
    if (temp == NULL)
        return;
    displayTree(temp->left);
    std::cout << temp->data << ' ';
    displayTree(temp->right);
}

int main()
{
    int choice, key;
    while (1)
    {
        print("---------------------------");
        print("Enter Your Choice");
        print("To display the Binary search Tree - 0");
        print("To insert an element in BST - 1");
        print("To search an Element in BST - 2");
        print("To delete an Element in BST - 3");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin >> choice;
        switch (choice)
        {
        case 0:if (root) {
            displayTree(root);
            std::cout << std::endl;
        }
              else {
            print("Tree is Empty, try to create a tree by inserting elments");
        }
              break;
        case 1:
            std::cout << "Enter an element :";
            std::cin >> key;
            root = insertTree(root, key);
            std::cout << key << " has been inserted to BST" << std::endl;
            break;
        case 2:
            std::cout << "Enter an element to be searched:";
            std::cin >> key;
            if (searchTree(root, key))
                std::cout << key << " is present in the BST\n";
            else
                std::cout << key << " is not present in the BST\n";
            break;
        case 3:
        deletion:
            std::cout << "Current Elements are ( ";
            displayTree(root);
            std::cout << ") Try to delete one of these elements\n";
            std::cout << "Enter an element to be deleted:";
            std::cin >> key;
            if (searchTree(root, key)) {
                root = deleteNode(root, key);
                std::cout << key << " has been deleted from BST\n";
            }
            else {
                std::cout << key << " is not present in BST,enter a valid element present in BST\n";
                goto deletion;
            }
            break;
        default:
            exit(EXIT_SUCCESS);
        }
    }
}