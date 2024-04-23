#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
	int pivot = arr[low];
	int i = low;
	int j = high;
	while(i<j){
		while(arr[i] <= pivot && i <= high - 1){
			i++;
		}
		while(arr[j] > pivot && j>= low + 1){
			j--;
		}
		if(i<j){ swap(arr[i],arr[j]); }
	}
	swap(arr[low],arr[j]);
	return j;
}

void qs(vector<int> &arr, int low, int high){
	if(low < high){
		int pIndex = partition(arr, low, high);
		qs(arr, low, pIndex - 1);
		qs(arr, pIndex + 1, high); 
	}
}

void quickSort(vector<int> &arr){
	qs(arr, 0, arr.size()-1);
};

int main(){
	int n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++) {
        	cin >> arr[i];
    	}
	cout << "Given array is \n";
	for (int i = 0; i < n; i++)
        	cout << arr[i] << " ";
	cout << endl;
	quickSort(arr);
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
	        cout << arr[i] << " ";
	cout << endl;
	return 0;
}
/*
OUTPUT:
Enter the number of elements in the array: 7
Enter 7 elements: 4 6 5 2 7 9 1 3
Given array is 
4 6 5 2 7 9 1 
Sorted array is 
1 2 4 5 6 7 9 
*/
