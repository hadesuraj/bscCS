#include<bits/stdc++.h>
#include<vector>
using namespace std;

template <typename T>
void insertionSort(vector<T>& arr){
	int hole, value;
	for(int i=1;i<arr.size();i++)
	{
		value = arr[i];
		hole = i - 1;
		while(hole>=0 && arr[hole]>value){
			arr[hole+1] = arr[hole];
			hole = hole-1;
		}
		arr[hole+1] = value;
	}
}
template <typename T>
void selectionSort(vector<T>& arr){
	int minDex, i;
	for(i=0;i<arr.size()-1;i++){
		minDex=i;
		for(int j=i+1;j<arr.size();j++){
			if(arr[j]<arr[minDex])
				minDex=j;
		}
		int temp = arr[minDex];
		arr[minDex]=arr[i];
		arr[i]=temp;
	}
}
template <typename T>
void bubbleSort(vector<T>& arr){
	for(int i=0;i<arr.size()-1;i++){
		for(int j=0;j<arr.size()-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
template <typename T>
void printArray(vector<T>& arr){
	int i;
	for(i=0;i<arr.size();i++)
	{
		cout<<arr[i] << " ";
	}
	cout << endl;
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
	cout << "Unsorted Array: ";
	printArray(List);
	cout << "Choose Sorting Algorithm:\n";
	cout << "1. Insertion Sort\n";
	cout << "2. Selection Sort\n";
	cout << "3. Bubble Sort\n";
	int choice;
	cout << "Enter Choice: ";
	cin >> choice;
	switch (choice) {
        	case 1:
            		insertionSort(List);
            		break;
        	case 2:
            		selectionSort(List);
            		break;
        	case 3:
            		bubbleSort(List);
            		break;
       	 	default:
            		cout << "Invalid Choice. Exit Program.";
            		return 1;
   	}
   	cout << "Sorted Array: ";
 	printArray(List);
	return 0;
}

