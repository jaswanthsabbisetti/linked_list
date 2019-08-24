//using floyd's cycle finding algorithm
#include<bits/stdc++.h>
#include<iostream>
#include<ios>
using namespace std;
class Node
{
public:	
	int data;
	Node *next;
};
void push(Node **head,int value)
{
	Node *temp = new Node();
	temp->data = value;
	temp->next = (*head);
	(*head) = temp;
}
void detectloop(Node *list)
{
	Node *fastp=list,*slowp = list;
	while(slowp && fastp && fastp->next)
	{
		slowp= slowp->next;
		fastp= fastp->next->next;
		if(slowp==fastp)
		{
			cout << "cycle found" << endl;
			return;
		}
	}
	cout<<"no cycle found"<<endl;
	return;
}
int main()
{
	 ios::sync_with_stdio(false);
  cin.tie(0);
	Node *head = new Node();
	
	push(&head,4);
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,5);
	//to test if cycle present 
   head->next->next->next= head; 
    detectloop(head); 
}