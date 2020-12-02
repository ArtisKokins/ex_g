#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

struct Node
{
    int data;
    Node *link;
};
//------------------------------------------------------------------------------
void PrintList(Node *head)
{
    Node *cur;
    cout<<"List of elements:\n";
    cur=head;
    while (cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->link;
    }
}
//------------------------------------------------------------------------------
Node *CreateNode()
{
    Node *newNode;
    newNode = new Node;
    cout<<"Input number: ";
    cin>>newNode->data;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Wrong input! Input an integer number: ";
        cin>>newNode->data;
    }
    newNode->link=NULL;
    return newNode;
}
//------------------------------------------------------------------------------
void CreateManyElements(Node *head)
{
    int i, n;
    Node *cur, *cur2;
    cout<<"\nNumber of elements (keeping in mind that one exists): ";
    cin>>n;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Wrong input! Input an integer number: ";
        cin>>n;
    }
    cur=head;

    for(i=1;i<=n;i++)
    {
        cur2=cur;
        cur = CreateNode();
        cur2->link=cur;
    }
}
//------------------------------------------------------------------------------
void AddLastNode(Node *head)
{
    int i, n;
    Node *cur, *cur2;
    cur=head;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur2=CreateNode();
    cur->link=cur2;
}
//------------------------------------------------------------------------------
Node *AddFirstNode(Node *head)
{
    int i, n;
    Node *cur;
    cur=CreateNode();
    cur->link=head;
    head=cur;
    return cur;
}
//------------------------------------------------------------------------------
Node *FindNode(Node *head, int x)
{
    Node *cur;
    cur = head;
    while(cur && cur->data!=x)
    {
        cur=cur->link;
    }
    return cur;
}
//------------------------------------------------------------------------------
Node *FindNode2(Node *head, int x)
{
    Node *cur, *cur2;
    cur = head;
    while(cur && cur->data!=x)
    {
        cur2=cur;
        cur=cur->link;
    }
    return cur2;
}

Node *FindNode3(Node *head, int x)
{
    Node *cur, *cur2, *cur3;
    cur = head;
    cur2 = head;
    while(cur && cur->data!=x)
    {
        cur2=cur;
        cur3=cur2;
        cur=cur->link;
        cur2=cur2->link;
    }
    return cur3;
}
//------------------------------------------------------------------------------
Node *DeleteFirst(Node *head)
{
    Node *cur, *cur2;
    cur2=head;
    cur=head->link;
    head=cur;
    delete cur2;
    cout<<"Element was deleted!"<<endl;
    system("Pause>>nul");
    return head;
}
//------------------------------------------------------------------------------
Node *DeleteLast(Node *head)
{
    Node *cur, *cur2;
    if(head->link!=NULL)
    {
        cur = head;
        while(cur && cur->link!=NULL)
        {
            cur2=cur;
            cur=cur->link;
        }
        delete cur;
        cur2->link=NULL;
        cout<<"Element was deleted!"<<endl;
        system("Pause>>nul");
    }
    else head=DeleteFirst(head);
    return head;
}
//------------------------------------------------------------------------------
Node *DeleteAfter(Node *head)
{
    Node *cur, *deletenode;
    int x;

    cout<<"Enter a number, after which element will be deleted: ";
    cin>>x;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Wrong input! Input an integer number: ";
        cin>>x;
    }
    cur=FindNode(head, x);
    if(!cur){cout<<"Chosen number is not found!"<<endl;system("Pause>>nul");}
    else
    {
        if(cur->link!=NULL)
        {
            deletenode=cur->link;
            cur->link=deletenode->link;
            delete deletenode;
        }
        else{cout<<"This is the last node"<<endl; system("Pause>>nul");}
    }
    return head;

}
//------------------------------------------------------------------------------
int NumberOfElements(Node *head)
{
    int number = 0;
    Node *cur;
    cur = head;
    while(cur->link!=NULL)
    {
        cur=cur->link;
        number++;
    }
    return number;
}
//------------------------------------------------------------------------------
Node *DeleteList(Node *head)
{
    Node *cur;
    cur=head;
    if(cur->link==NULL){return DeleteFirst(head);}
    while(cur)
    {
        cur=cur->link;
        head=DeleteFirst(head);
    }
    return head;
}
//------------------------------------------------------------------------------
int main()
{
    int n, i, choice, x, number, y;
    Node *head=NULL, *cur, *cur2, *cur3, *newnode, *deletenode;

    cout<<"\t\tData Structure: List"<<endl;
    do
    {
        system("cls");
        cout<<"\nAuthor: Artis Kokins"<<endl;
        cout<<"Linear List"<<endl;
        cout<<"Date: 18.11.2020"<<endl;
        cout<<"Version 9.3"<<endl<<endl;

        cout<<"\t\tData Structure: Linear List"<<endl;
        cout<<"1. Create head"<<endl;
        cout<<"2. Print head"<<endl;
        cout<<"3. Create list elements"<<endl;
        cout<<"4. Print List"<<endl;
        cout<<"5. Add element - End of the list"<<endl;
        cout<<"6. Add element - Before head"<<endl;
        cout<<"7. Add element - After"<<endl;
        cout<<"8. Add element - Before"<<endl;
        cout<<"9. Delete element - Last element"<<endl;
        cout<<"10. Delete element - First element"<<endl;
        cout<<"11. Delete element - After"<<endl;
        cout<<"12. Delete element - Before"<<endl;
        cout<<"13. Element count"<<endl;
        cout<<"14. Delete List"<<endl;
        cout<<"0. End the program"<<endl;
        cout<<"\nChoose an action: ";
        cin>>choice;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Wrong input! Input an integer number: ";
            cin>>choice;
        }

        switch(choice)
        {
            case 1:if(!head)
                    {
                    cout<<"Create head: "<<endl;
                    head = CreateNode();
                    cout<<"Head created!"<<endl;
                    }
                    else cout<<"Head already exists!";
                    system("Pause>>nul");
                    break;
            case 2:if(head)
                    {
                        cout<<"Head = "<<head->data<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Head doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 3: if(head)
                    {
                        CreateManyElements(head);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Head doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 4: if(head)
                    {
                        PrintList(head);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Head doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 5: if(head)
                    {
                        AddLastNode(head);
                        cout<<"Element was added!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Head doesn't exist! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    break;
            case 6: if(head)
                    {
                        head=AddFirstNode(head);
                        cout<<"Element was added!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Head doesn't exist! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    break;
            case 7: if(!head)
                    {
                        cout<<"Head doesn't exist! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Enter a number, after which element will be inserted: ";
                        cin >> x;
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout<<"Wrong input! Input an integer number: ";
                            cin>>x;
                        }
                        cur=FindNode(head, x);
                        if(!cur){cout<<"Chosen number is not found!"<<endl;system("Pause>>nul");}
                        else
                        {
                            newnode=CreateNode();
                            newnode->link=cur->link;
                            cur->link=newnode;
                            cout<<"Element was added!"<<endl;
                            system("Pause>>nul");
                        }
                    }
                    break;
            case 8: if(!head)
                    {
                        cout<<"Head doesn't exist! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Enter a number, before which element will be inserted: ";
                        cin>>x;
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout<<"Wrong input! Input an integer number: ";
                            cin>>x;
                        }
                        if(head->data==x){head=AddFirstNode(head); break;}
                        cur=FindNode(head, x);
                        if(!cur){cout<<"Chosen number is not found!"<<endl;system("Pause>>nul");}
                        else
                        {
                            cur2=FindNode2(head, x);
                            newnode=CreateNode();
                            newnode->link=cur2->link;
                            cur2->link=newnode;
                            cout<<"Element was added!"<<endl;
                            system("Pause>>nul");
                        }
                    }
                    break;
            case 9: if(!head)
                    {
                        cout<<"There is no list to delete! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else{head=DeleteLast(head);}
                    break;
            case 10: if(!head)
                    {
                        cout<<"There is no list to delete! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else{head=DeleteFirst(head);}
                    break;
            case 11: if(!head)
                    {
                        cout<<"There is no list to delete! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        if(head->link==NULL){cout<<"There is nothing to delete"<<endl; system("Pause>>nul");}
                        else {head=DeleteAfter(head);}
                    }
                    break;
            case 12: if(!head)
                    {
                        cout<<"Head doesn't exist! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Enter a number, before which element will be deleted: ";
                        cin>>x;
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout<<"Wrong input! Input an integer number: ";
                            cin>>x;
                        }
                        if(head->data==x)
                        {
                            cout<<"There is nothing to delete before head!"<<endl;
                            system("Pause>>nul");
                            break;
                        }
                        cur=FindNode(head, x);
                        if(!cur){cout<<"Chosen number is not found!"<<endl;}
                        else
                        {
                            cur2=FindNode2(head, x);
                            if(cur2==head)
                            {
                                head=DeleteFirst(head);
                                system("Pause>>nul");
                                break;
                            }
                            else
                            {
                                cur2->data=y;
                                cur3=FindNode2(head, y);
                                if(cur3->link==head)
                                {
                                    cout<<"There is nothing to delete before the chosen number!"<<endl;
                                    break;
                                    system("Pause>>nul");
                                }
                                else
                                {
                                    cur3->link=cur;
                                    delete cur2;
                                    cout<<"Element was deleted!"<<endl;
                                }
                            }
                        }
                    }
                    system("Pause>>nul");
                    break;
            case 13: if(!head)
                    {
                        cout<<"There is no list to count! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        number=NumberOfElements(head);
                        cout<<"Number of elements in the list: "<<number+1<<endl;
                        system("Pause>>nul");
                    }
                    break;
            case 14: if(!head)
                    {
                        cout<<"There is no list to delete! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        head=DeleteList(head);
                        cout<<"List was deleted!"<<endl;
                        system("Pause>>nul");
                    }
                    break;
            case 0: cout<<"End!!!"<<endl;
                    cout<<"Thank you for using the program!"<<endl;
                    break;
            default: cout<<"Incorrect choice!";
                     system("Pause>>nul");
        }
    }
    while(choice!=0);

    system("Pause>>nul");
    return 0;
}
