#include <iostream>
using namespace std;
class node
{
public:
	node*pred; //Defining a pointer to the previous node
	node*succ; //Defining a pointer to the next node
	int data;
	//Default Constructor
	node()
	{
		pred=NULL;
		succ=NULL;
	}
};
class Dlist
{
public:
	//Defining a pointer to the first node
	node*head;
	//Defining a pointer to the last node
	node*tail;
	//Default constructor
	Dlist()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int value)
	{
		node*temp=new node;
		temp->data=value;
		if (head==NULL) head=temp;
		else
		{
			tail->succ=temp;
			temp->pred=tail;
		}
		tail=temp;
	}
	void insertAt(int position,int value)
	{
		node*t=head;
		int j=0;
		while (t!=NULL)
		{
			t=t->succ;
			j++;
		}
		cout<<j<<endl;
		node*current=head;
		int i=1;
		if(j>=position)
		{	
			while (i<position-1)
			{
				i++;
				current=current->succ;
			}

			cout<<current->data<<endl;
			node*temp=new node; // Creating a new node
			temp->data=value;  //Assigning it to the required value
			temp->succ=current->succ; //Change the successor of temp to current's successor
			temp->pred=current;  //Make temp's predecessor as the current node
			current->succ->pred=temp;  //Make current's successor's predecessor as temp
			current->succ=temp; //Make current's successor as temp
			//Keep the order in mind
		}
		else
		{
			cout<<"Check the number of elements in the list."<<endl;
		}
	}
	void del()
	{
		node*t=tail;
		node*current=head;
		while(current->succ->succ!=NULL)
		{
			current=current->succ;
		}
		cout<<current->data<<endl;
		current->succ=NULL;
		current=tail;
		delete t;
	}
	void delAt(int position)
	{
		node*q=head;
		int j=0;
		while (q!=NULL)
		{
			q=q->succ;
			j++;
		}
		if (j>=position)
		{
			node*current=head;
			int i=1;
			while (i<position-1)
			{
				current=current->succ;
			}
			node*temp=current->succ;
			current->succ=temp->succ;
			temp->succ->pred=current;
			delete temp;
		}
		else cout<<"Check the number of entries in the list."<<endl; 
	}
	void count()
	{
		node*t=head;
		int i=0;
		while (t!=NULL)
		{
			t=t->succ;
			i++;
		}
		cout<<"The nummber of entries in your list is : "<<i<<endl;
	}
	void display()
	{
		node*temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" -> ";
			temp=temp->succ;
		}
		cout<<endl;
	}
};
int main()
{
	Dlist l;
	l.insert(3);
	l.insert(4);
	l.insert(45);
	l.count();
	l.display();
	l.insertAt(3,455);
	l.count();
	l.display();
	l.del();
	l.count();
	l.display();
	l.insert(245);
	l.insert(3535);
	l.insertAt(3,635);
	l.count();
	l.display();
	l.del();
	l.count();
	l.display();
	l.delAt(2);
	l.count();
	l.display();
	return 0;
}