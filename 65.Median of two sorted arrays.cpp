// https://www.codingninjas.com/studio/problems/median-of-two-sorted-arrays_8230788?challengeSlug=striver-sde-challenge&leftPanelTab=0


int getK(const vector<int>& A, const vector<int>& B, int k, int aStart, int aEnd, int bStart, int bEnd) {
        // If the segment of on array is empty, it means we have passed all
        // its element, just return the corresponding element in the other array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];
        
        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) { 
            if (aValue > bValue) {
                return getK(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return getK(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        } 
        // Otherwise, remove the larger right half.
        else { 
            if (aValue > bValue) {
                return getK(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return getK(A, B, k, aStart, aEnd, bStart, bIndex - 1);       
            }
        }
        return -1;
    }


double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size(),m=B.size();
    int tot=(n+m);
    if(tot%2==1){
        return getK(A,B,tot/2,0,n-1,0,m-1);
    }
    else{
        int aa=getK(A,B,tot/2,0,n-1,0,m-1);
        int bb=getK(A,B,(tot-1)/2,0,n-1,0,m-1);
        return (double)(aa+bb)/2.0;
    }
}

}
