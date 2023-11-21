#include<iostream>
#include<vector>

using namespace std;

template <typename T>
int linearSearch(vector<T>& arr, T& target){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==target)
			return i;
	}
	return -1;
}
template <typename T>
int binarySearch(vector<T>& arr, T& target){
	int hole, value;
	for(int i=0;i<arr.size();i++){
		value = arr[i];
		hole = i - 1;
		while(hole>=0 && arr[hole]>value){
			arr[hole+1] = arr[hole];
			hole = hole - 1;
		}
		arr[hole+1]=value;
	}
	int low = 0;
	int high = arr.size()-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(arr[mid]==target)
			return mid;
		else if(arr[mid]<target)
			return low = mid + 1;
		else
			return low = mid - 1;
	}
	return -1;
}
int main(){
	cout << "Enter the number of elements: ";
	int n;
	cin >> n;
	vector<int> List;
	cout << "Enter the elements of the lists: ";
	int element;
	for(int i=0;i<n;i++){
		cin >> element;
		List.push_back(element);
	}
	cout << "Enter the element to search for: ";
	int target;
	cin >> target;
	cout << "Choose Searching Algorithm:\n";
	cout << "1. Linear Search\n";
	cout << "2. Binary Search\n";
	int choice;
	cout << "Enter Choice: ";
	cin >> choice;
	int result;
	switch(choice){
		case 1: 
			result = linearSearch(List,target);
			break;
		case 2:
			result = binarySearch(List,target);
			break;
		default:
			cout << "Invalid Choice. Exit Program.";
			return 1;
	}
	if(result != -1)
		cout << "Element " << target << " found at index " << result << endl;
	else 
		cout << "Element " << target << " not found in the list." << endl;
	return 0;
}
