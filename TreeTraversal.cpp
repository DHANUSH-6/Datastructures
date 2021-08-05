//Binary Tree
#include <iostream>
struct Node
{
	std::string data;
	Node* left = NULL, * right = NULL;
	~Node()
	{
		//std::cout << "\nTree Deleted Successfully";
	}
};
Node* root = NULL;
void print(const std::string &functions)
{
    std::cout<<functions<<std::endl;
}
void inorderTraversal(struct Node* temp)
{
	if (temp == NULL)
		return;
	inorderTraversal(temp->left);
	std::cout << temp->data << ' ';
	inorderTraversal(temp->right);
}
void preorderTraversal(struct Node* temp)
{
	if (temp == NULL)
		return;
	std::cout << temp->data << ' ';
    preorderTraversal(temp->left);
	preorderTraversal(temp->right);
}
void postorderTraversal(struct Node* temp)
{
	if (temp == NULL)
		return;
	postorderTraversal(temp->left);
	postorderTraversal(temp->right);
    std::cout << temp->data << ' ';
}
struct Node *TreeCreation()
{
	std::string element;
	Node* temp = new(Node);
	std::cout << "Enter the Element to be inserted in the Tree (! to terminate):";
	std::cin >> element;
	if (element == "!")
		return NULL;
	temp->data = element;
	std::cout << "Enter the left child of " << element << " :";
	temp->left = TreeCreation();
	std::cout << "Enter the right child of " << element << " :";
	temp->right = TreeCreation();
	return temp;
}

int main()
{
    int choice;
	root = TreeCreation();
	while(1)
    {
        print("\n---------------------------");
        print("Inorder - 1");
        print("Preorder - 2");
        print("postorder - 3");
        print("Press any other key to Exit");
        print("---------------------------");
        std::cin>>choice;
        switch(choice)
        {
            case 1:std::cout<<"-----Inorder Traversal-----\n";
                    inorderTraversal(root);
                    std::cout<<std::endl;
                    break;
            case 2:std::cout<<"-----Preorder Traversal-----\n";
                    preorderTraversal(root); 
                    std::cout<<std::endl;
                    break;
            case 3:std::cout<<"-----Postorder Traversal-----\n";
                    postorderTraversal(root); 
                    std::cout<<std::endl;
                    break;

            default:exit(EXIT_SUCCESS);
        }
    }
	delete root;
}