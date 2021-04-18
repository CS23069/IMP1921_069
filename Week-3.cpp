//pdf question nth element
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

void display() {
   struct node *temp = head;
   cout<<"\n[head] =>";
  
   while(temp!= NULL) {        
      cout<<temp->data<<" -> ";
      temp = temp->next;
   }

   cout<<" [null]\n";
}
void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = head;
   head = link;
}
void Nth_ele_from_end(struct node *head, int N)
{
	int len=0;
	int i;
	struct node* temp = head;
	while(temp!=NULL)
	{
		temp=temp->next;
		len++;
	}
    if(len < N)
	return;
	
	temp = head;
	
	for(i=0; i<len-N; i++)
	temp=temp->next;

  cout<<temp->data;
  
  return; 	
}

int main() {
  int i,n,k,N;
  cout<<"Enter the number of elements\n"; 
  cin>>n;
  cout<<"Enter your elements\n";
  for(i=0;i<n;i++)
  {
  	cin>>k;
  	insert(k);
  }
   display();
   cout<<"Enter the nth element you want from the end";
   cin>>N;
   Nth_ele_from_end(head, N);
   return 0;
}
//BAsic idea to detect loop
bool detectLoop(struct Node* h)     
{
    unordered_set<Node*> s;
    while (h != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (s.find(h) != s.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}
//pdf question middle element

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

void display() {
   struct node *temp = head;
   cout<<"\n[head] =>";
  
   while(temp!= NULL) {        
      cout<<temp->data<<" -> ";
      temp = temp->next;
   }

   cout<<" [null]\n";
}
void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = head;
   head = link;
}
int ll_middle(struct node* head)
{
	struct node* current=head;
	int count;
	
	while(current!=NULL)
	{
		current=current->next;
		count++;
	}
	current=head;
	if(count%2 !=0)
	{
		cout<<"The linked list length is odd, so the middle element is\n";
		for(int i=0;i<(count-1)/2;i++)
		{
			current=current->next;
		}
		cout<<current->data;
	}
	else
	{
		cout<<"The linked list length is even, so the middle elements are:\n";
		for(int i=0; i<(count-2)/2;i++)
		{
			current=current->next;
		}
		cout<<current->next->data<<"\n";
		cout<<current->data;	
	}
}


int main() {
  int i,n,k,N;
  cout<<"Enter the number of elements\n"; 
  cin>>n;
  cout<<"Enter your elements\n";
  for(i=0;i<n;i++)
  {
  	cin>>k;
  	insert(k);
  }
   display();
   cout<<"\n\tTo find the middle element\n";
   cout<<"\tWe have two cases: (i)Even length (ii)Odd length \n\n";
   ll_middle(head);
   return 0;
}
//pdf question union and intersection

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct node* head=0;

void push(struct node **head, int data)
{
	struct node* n_node;
	n_node=(struct node*)malloc(sizeof (struct node));
	n_node->data=data;
	n_node->next = (*head);
	(*head)=n_node;
}

void display(struct node *p)
{
	p=head;
	while(p!=0)
	{
		cout<<p->data;
		p=p->next;
	}
}
bool isPresent(struct node* head, int data)
{
    struct node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

struct node* get_union(struct node* head1, struct node *head2)
{
   struct node *res=NULL;
   struct node *temp1=head1;
   struct node *temp2=head2;
   
   while(temp1!=0)
   {
   	push(&res, temp1->data);
   	temp1=temp1->next;
   }
   
   while(temp2!=0)
   {
   	if(!isPresent(res,temp1->data))
   	push(&res,temp2->data);
   	temp2=temp2->next;
   }
   return res;
}
struct node* get_intersect(struct node *head1, struct node *head2)
{
	struct node *res=NULL;
	struct node *temp1=head1;
	while(temp1!=0)
	{
		if(isPresent(head2,temp1->data))
		push(&res,temp1->data);
		temp1=temp1->next;
	}
return res;
}


int main()
{
	struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersect = NULL;
    struct node* uni = NULL;
    push(&head1, 10);
    push(&head1, 11);
    push(&head1, 12);
    push(&head1, 23);
    
    push(&head2, 1);
    push(&head2, 7);
    push(&head2, 8);
    push(&head2, 9);
    
    uni = get_union(head1, head2);
    intersect = get_intersect(head1, head2);
    
    cout<<"After Union";
	display(uni);
    
    cout<<"After Intersection";
	display(intersect);
    
}

//pdf question reverse a linked list

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

void display() {
   struct node *temp = head;
   cout<<"\n head =>";
  
   while(temp!= NULL) {        
      cout<<temp->data<<" -> ";
      temp = temp->next;
   }

   cout<<" [null]\n";
}
void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = head;
   head = link;
}

void reverse_list()
{
// Initializing current, previous and next pointers
  struct node *current = head;
  struct node *left = NULL;
  struct node *right = NULL;
while (current != NULL)
    {
	right = current->next;
	current->next = left;   	// This is to reverse current node's pointer
	
	left = current;
	current = right;
	}
	head = left;
}

int main() {
  int i,n,k,N;
  cout<<"Enter the number of elements\n"; 
  cin>>n;
  cout<<"Enter your elements\n";
  for(i=0;i<n;i++)
  {
  	cin>>k;
  	insert(k);
  }
  cout<<"Your linked list :";
   display();
   cout<<"your linked list after reversing";
   reverse_list();
   display();
   return 0;
}

//removing consecutive duplicates

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
struct node* root=NULL;
void insert()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(root == NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p=NULL;
		p=root;
		while(p->next!=0)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;	
	}
}
void duplicates(int n)
{
	struct node *a,*b,*dup;
	a=root;
	while(a->next!=0)
	{
		b=a;
		while(b->next!=0)
		{
			if(b->data == b->next->data)
			{
				dup=b->next;
				b->next=b->next->next;
				free(dup);
			}
			else
			b=b->next;
		}
		a=a->next;
	}
	
}

void display()
{
	struct node* p;
	p=root;
	cout<<"HEAD ->";
	while(p!=0)
	{
		cout<<p->data<<"-->";
		p=p->next;
	}
	cout<<"\n";
}

int main()
{
	int i,n;
	cout<<"Enter the no of elements for your DLL\n";
	cin>>n;
	cout<<"Enter your elements\n";
	for(i=0;i<n;i++)
	{
		insert();
	}
	display();
	duplicates(n);
	cout<<"After removing duplicates\n";
	display();
}

//reoate K times (needs improvement not fully correct)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

void display() {
   struct node *temp = head;
   cout<<"\n head =>";
  
   while(temp!= NULL) {        
      cout<<temp->data<<" -> ";
      temp = temp->next;
   }

   cout<<" [null]\n";
}
void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = head;
   head = link;
}
struct node *rotate (struct node *head, int K)
{    
	struct node* current = head;
		
	for(int i =0;i<K;i++)
	{
		
	   while(current->next->next != NULL)
	   {
	   	current=current->next;
	   }
	   	current->next->next = head;
	   	head = current->next;
	   	current->next = NULL;
	   	current=head;
	}
}

int main() {
  int i,n,k,K;
  cout<<"Enter the number of elements\n"; 
  cin>>n;
  cout<<"Enter your elements\n";
  for(i=0;i<n;i++)
  {
  	cin>>k;
  	insert(k);
  }
  cout<<"Your linked list :";
   display();
   cout<<"enter your value of K\n";
   cin>>K;
   rotate(head,K);
   display();
   return 0;
}

//pdf question palindorme single ll

#include <stdio.h>  
#include <stdbool.h>  
   
//Represent a node of the singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
int size = 0;  
   
//addNode() will add a new node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
    //Size will count the number of nodes present in the list  
    size++;  
}  
   
//reverseList() will reverse the singly linked list and return the head of the list  
struct node* reverseList(struct node *temp){  
    struct node *current = temp;  
    struct node *prevNode = NULL, *nextNode = NULL;  
      
   //Swap the previous and next nodes of each node to reverse the direction of the list  
    while(current != NULL){  
        nextNode = current->next;  
        current->next = prevNode;  
        prevNode = current;  
        current = nextNode;  
    }  
    return prevNode;  
}  
   
//isPalindrome() will determine whether given list is palindrome or not.  
void isPalindrome(){  
    struct node *current = head;  
    bool flag = true;  
      
    //Store the mid position of the list  
    int mid = (size%2 == 0)? (size/2) : ((size+1)/2);  
      
    //Finds the middle node in given singly linked list  
    for(int i=1; i<mid; i++){  
        current = current->next;  
    }  
      
    //Reverse the list after middle node to end  
    struct node *revHead = reverseList(current->next);  
   
    //Compare nodes of first half and second half of list  
    while(head != NULL && revHead != NULL){  
        if(head->data != revHead->data){  
            flag = false;  
            break;  
        }  
        head = head->next;  
        revHead = revHead->next;  
    }  
   
    if(flag)  
        printf("Given singly linked list is a palindrome\n");  
    else  
        printf("Given singly linked list is not a palindrome\n");  
}  
      
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of singly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(2);  
    addNode(1);  
      
    display();  
      
    //Checks whether given list is palindrome or not  
    isPalindrome();  
      
    return 0;  
} 

//pdf palindrome double linked list

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
struct node* root=NULL;
void insert()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(root == NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p=NULL;
		p=root;
		while(p->next!=0)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;	
	}
}
void check_palin(int n)
{
	int i,j,count=0;
	i=0;
	j=n-1;
	struct node *p,*q;
	p=q=root;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	while(i<j)
 {
	
	if(p->data==q->data)
	{
		count++;
		i++;
		j--;
		p=p->next;
		q=q->prev;
	}
    else
    {
    	break;
	}
}
	if(count==n/2)
	{
		cout<<"This is a palindrome\n";
	}
	else
	{
		cout<<"This is not a palindrome\n";
	}	
}
void display()
{
	struct node* p;
	p=root;
	cout<<"HEAD ->";
	while(p!=0)
	{
		cout<<p->data<<"-->";
		p=p->next;
	}
	cout<<"\n";
}

int main()
{
	int i,n;
	cout<<"Enter the no of elements for your DLL\n";
	cin>>n;
	cout<<"Enter your elements\n";
	for(i=0;i<n;i++)
	{
		insert();
	}
	display();
	check_palin(n);
}

//pdf reverse a group of size K throughout

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

void display() {
   struct node *temp = head;
   cout<<"\n head =>";
  
   while(temp!= NULL) {        
      cout<<temp->data<<" -> ";
      temp = temp->next;
   }

   cout<<" [null]\n";
}
void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = head;
   head = link;
}
struct node *reverse (struct node *head, int k)
{
    if (!head)
        return NULL;
   
    struct node *current = head;
    struct node *right = NULL;
    struct node *left = NULL;
    int count = 0;
    
   
    while (current != NULL && count < k)   //doing the basic reverse with count < K condition
    {
        right  = current->next;
        current->next = left;
        left = current;
        current = right;
        count++;
    }
     
 
    if (right !=  NULL)
       head->next = reverse(right, k);  //considering that the next group of K elements as a ll
 
    return left;
}
int main() {
  int i,n,k,K;
  cout<<"Enter the number of elements\n"; 
  cin>>n;
  cout<<"Enter your elements\n";
  for(i=0;i<n;i++)
  {
  	cin>>k;
  	insert(k);
  }
  cout<<"Your linked list :";
   display();
   cout<<"enter your value of K\n";
   cin>>K;
   head = reverse(head,K);
   display();
   return 0;
}




