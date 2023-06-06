
//Platform : https://www.interviewbit.com/problems/repeat-and-missing-number-array/
//try placing the numbers in correct position 
//if at current index i , it shoud have i+1 as the number
// if it is not true, then the number at i is repated and (i+1) is the missing number
vector<int> Solution::repeatedNumber(const vector<int> &A) {
   vector<int>lola=A;
   int i=0;
   while(i<A.size()){
       if(lola[i]==lola[lola[i]-1]){
           i++;
       }
       else{
           swap(lola[i],lola[lola[i]-1]);
       }
   }
   for(int i=0;i<A.size();i++){
       if(lola[i]!=i+1){
           return {lola[i],i+1};
       }
   }
   return {};
}
