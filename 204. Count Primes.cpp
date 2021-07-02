class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthenes 
        if(n<=2){
            return 0;
        }
        //Handling for case greater than 2 as rest of the prime numbers are odd
        bool countnotprime[n];
        memset(countnotprime,false,sizeof(countnotprime));
        int count=0;
        for(int i=2;i<n;i++){
            if(!countnotprime[i]){
                count++;
                for(int j=i;j<n;j+=i){
                    countnotprime[j]=true;
                }
            }
        }
        return count;
    }
};
