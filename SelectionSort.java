public class SelectionSort{
    public static void selection (int arr[], int n){
        int minDex,i;
        for( i=0;i<n-1;i++){
            minDex = i;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[minDex])
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
        for(int i=0;i<n;i++)
           System.out.println(arr[i]+" ");
        
    }
}
