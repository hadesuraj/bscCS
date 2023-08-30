#include<iostream>
using namespace std;
int main()
{
	int i,n,num,flag=0;
	cout<<"Enter the number of array elements: ";
	cin>>n;
	int arr[n];
	cout<<"The array elements are:\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the element to be searched: ";
	cin>>num;
	for(i=0;i<n;i++)
	{
		if (arr[i]==num)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	cout<<"The element is present at the index of "<<i<<endl;
	else
	cout<<"Entered element not present! ERROR-404!"<<endl;
	return 0;
}
