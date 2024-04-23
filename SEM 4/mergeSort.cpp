#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int high, int mid){
	vector<int> temp;
	int left = low;
	int right = mid + 1;
	while(left<=mid && right<=high){
		if (arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i = low; i<=high; i++){
		arr[i] = temp[i-low];
	}
}

void mergeS(vector<int> &arr, int low, int high){
	if(low==high) return;
	int mid = (low+high)/2;
	mergeS(arr, low, mid);
	mergeS(arr, mid+1, high);
	merge(arr, low, high, mid);
}

void mergeSort(vector <int> &arr, int n){
	mergeS(arr, 0, n-1);
}

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
	mergeSort(arr, n);
	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

/*
OUTPUT:
Enter the number of elements in the array: 9
Enter 9 elements: 3 1 2 4 1 5 2 6 4
Given array is 
3 1 2 4 1 5 2 6 4 
Sorted array is 
1 1 2 2 3 4 4 5 6 
*/
