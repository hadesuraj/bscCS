public class secondLargest{
    public static void selection (int arr[], int n){
        int minDex,i;
        for( i=0;i<n-1;i++){
            minDex = i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minDex])
                    minDex = j;
            }
            int temp = arr[minDex];
            arr[minDex] = arr[i];
            arr[i] = temp;
        }
    }
    public static void main(String args[]){
        int arr[] = {1,5,6,7,11,17};
        int n = arr.length;
        selection(arr,n);
        System.out.println("Sorted array: ");
        for(int i : arr){
           System.out.print(i+" ");}
           System.out.println();
           int secondL = arr.length - 1;
           System.out.println("Second largest element: "+ arr[secondL-1]);
        
    }
}
/*
Sorted array: 
1 5 6 7 11 17 
Second largest element: 11
*/
