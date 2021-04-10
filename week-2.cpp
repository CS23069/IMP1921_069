//knapsack problem
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max(int a, int b)
{
	if(a>b)
	return a;
	else 
	return b;
}

int knapsack(int val[], int wt[], int T, int n)
{
	if(T==0 || n==0)
	return 0;
	
	if (wt[n-1]>T)
	{
		return knapsack(val, wt, T,n-1);
	}
	
	else
	return max(val[n-1]+knapsack(val, wt , T-wt[n-1],n-1), knapsack(val, wt, T, n-1));
}

int main ()
{
	int value[]={60, 100, 120};
	int weight[]={10, 20, 30};
	int W =50;
	int n = sizeof(value)/sizeof(value[0]);

	cout<<knapsack(value, weight, W, n);
	return 0;
}
------------------------------------------------------------------------------------------
//min cost path(from pdf)
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int min_of_three(int a, int b, int c)
{
	if(a < b)
	return (a < c ) ? a : c;
	else
	return(b < c) ? b : c;
}

mincost(int cost[3][3], int m, int n)
{
	if(m<0 || n<0 )
	cout<<"invalid";
	else if (m==0 || n==0)
	return cost[m][n];
	else
	return cost[m][n] + min_of_three(mincost(cost, m , n-1), mincost(cost, m-1, n), mincost(cost, m-1, n-1));
}


int main()
{
	int costof[3][3]={{1, 2, 5},    
	                  {2, 19, 11},
				      {7, 6, 9}};
	int i,j;			   
	cout<<"Enter the row of the destination\n";
	cin>>i;	
	cout<<"Enter the coloumn of the destination\n";		   
	cin>>j;
				   
	cout<<mincost(costof, i, j)<<endl;	
	return 0;		   
}
---------------------------------------------------------------------------------
//min length of subarray greater than k
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int subarraycalc(int arr[], int n , int k )
{
	int start = -1;
	int end = -1;
	int min=1000000;
	int i,j;
	
	for(i=0;i<n;i++)
	{
		int currentsum=0;
		for(j=i;j<n && (j-i+1) < min; j++)
		{
	    	currentsum = currentsum + arr[j];
		if(currentsum > k)
			{
				start = i;
				end = j;
				min = end - start + 1;
				break;
	    	}
        }
    }
	cout<<"The minimum length of  sub array with sum k="<< k <<" is "<< min <<endl;
}
int main()
{
	int arr[100],i,n,k;
	cout<<"To find the minimum length of subarray with sum k\n";
	cout<<"\nEnter the size of array: \n";
	cin>>n;
	cout<<"Enter your elements: \n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter your value of k:\n";
	cin>>k;
	
	subarraycalc(arr, n ,k);
	
	return 0;
}
---------------------------------------------------------------------------------------
 //minimum length subarray
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int subarraycalc(int arr[], int n , int k )
{
	int start = -1;
	int end = -1;
	int min=1000000;
	int i,j;
	
	for(i=0;i<n;i++)
	{
		int currentsum=0;
		for(j=i;j<n && (j-i+1) < min; j++)
		{
	    	currentsum = currentsum + arr[j];
		if(currentsum == k)
			{
				start = i;
				end = j;
				min = end - start + 1;
				break;
	    	}
        }
    }
	cout<<"The minimum length of  sub array with sum k="<< k <<" is "<< min <<endl;
}
int main()
{
	int arr[100],i,n,k;
	cout<<"To find the minimum length of subarray with sum k\n";
	cout<<"\nEnter the size of array: \n";
	cin>>n;
	cout<<"Enter your elements: \n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter your value of k:\n";
	cin>>k;
	
	subarraycalc(arr, n ,k);
	
	return 0;
}
-----------------------------------------------------------------------------
  //no of words in a string
 #include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{

char str[100];
int word,i;

cout<<"enter your sentence\n";
fgets(str, sizeof str, stdin);

word=0;
i=0;

while(str[i]!='\0')
{
	if(str[i]==' ' || str[i]=='\t' || str[i]=='\n')
	{
		word++;
	}
	i++;
} 
cout<<"no of words in your sentence is :"<< word <<endl;
}
------------------------------------------------------------------------------
  //permutaions of a string 
  #include<bits/stdc++.h>
#include<iostream>
using namespace std;

void permute(string s, int l , int r){
	if(l==r){
		cout<<s<<endl;
	}
	else{
		 for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permute(s, l+1, r);
            swap(s[l], s[i]);
        }
	}
}
int main(){
	char str[100];
	cin>>str;
	int n= strlen(str);
	permute(str, 0 ,n-1);
}
---------------------------------------------------------------------------
  //string palindrome
  #include<bits/stdc++.h>
using namespace std;


int main(){
	char s[100];
	int i;
	bool x=1;
	cin>>s;
	int j=strlen(s)-1;
	for(i=0;i<j;i++){
		if(s[i]!=s[j])
		{
			x=0;
		}
		j--;
	}
	if(x){
		cout<<"yes, its a palindrome";
	}
	else{
		cout<<"no, it is not a palindrome";
	}
}
--------------------------------------------------------------------------
 //hackerrank array question: rotate array k no of times:

#include<bits/stdc++.h>
using namespace std;

void rotate( int arr[],int n){
    int b[100],i;
    for(i=0;i<n;i++){
        b[i]=arr[i+1];
    b[n-1]=arr[0];
    }
    for(i=0;i<n;i++){
        arr[i]=b[i];
    }
}
int printarray(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
int main ()
{
    int arr[100],i,n,k;
    cout<<"enter size of array:\n";
    cin>>n;
    cout<<"enter the number of times you want to rotate\n";
    cin>>k;
    cout<<"enter your elements:\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<k;i++){
        rotate(arr,n);
    } 
    cout<<"array after rotation\n";
    printarray(arr,n);
}
----------------------------------------------------------------------
  //this code is wrong, need changes, duplicates in the range of k


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int find_duplicate(int arr[], int n , int k )
{
	int dup=0;
	
	for(int i=0;i<n-k+1;i++)
	{
		for(int j=i+1;j<i+k;j++)
		{
		  if(arr[i]==arr[i+j])
		  {
		  	dup++;
		  	cout<<"duplicate for"<< arr[i] << "was found";
		  }
	}
		if(dup!=0)
		{
			cout<<"\nduplicates were found in round"<< i+1 << endl;;
			dup=0;
		}
		else
		{
			cout<<"\nduplicates were not found";
		}
	}
}
int main()
{
	int arr[100],i,n,k;
	cout<<"To find the minimum length of subarray with sum k\n";
	cout<<"\nEnter the size of array: \n";
	cin>>n;
	cout<<"Enter your elements: \n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter your value of k:\n";
	cin>>k;
	
	find_duplicate(arr, n ,k);
	
	return 0;
}
