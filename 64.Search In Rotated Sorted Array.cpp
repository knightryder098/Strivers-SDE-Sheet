
//https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_8230687?challengeSlug=striver-sde-challenge&leftPanelTab=0

int search(int* arr, int n, int key) {
    // Write your code here.
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==key){
            return mid;
        }

        if(arr[mid]>arr[r]){
            if(key<arr[mid] and key>=arr[l]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else if(arr[mid]<arr[l]){
            if(key>arr[mid] and key<=arr[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        else{
            if(key<arr[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

    }
    return -1;
}
