class Solution {
public:
    int divide(int dividend, int divisor) {
          if(divisor==0){return INT_MAX;}
           //ans will be positive
           if((dividend>INT_MIN && dividend<INT_MAX) && (divisor>INT_MIN && divisor<INT_MAX)){
               return dividend/divisor;
           }
           if(dividend==INT_MIN){
               //Two things divisor is negative
               if(divisor<0){
                   //ans should be positive check for overflow
                   //If overflow happens return INT_MAX else return the ans
                   if(divisor==-1){return INT_MAX;}
               }
               //Divisor is positive
               return dividend/divisor;
           }
        if(dividend==INT_MAX){
            return dividend/divisor;
        }
           
           
      return dividend/divisor;
        
        
    }
};
