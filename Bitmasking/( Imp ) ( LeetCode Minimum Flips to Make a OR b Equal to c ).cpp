class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        // either from f(0,31) or f(0,32) it won't make any difference
        // because all the integers are given positive so the sign determing bit
        // will be same for every integer
        for(int i=0;i<31;i++){
            
            bool a1 = false, b1 = false, c1= false;
            
            // checking whether i-th bit of a is set or not
            if(a&(1<<i))
                a1 = true;
            
            // checking whether i-th bit of b is set or not
            if(b&(1<<i))
                b1 = true;
            // checking whether i-th bit of c is set or not
            if(c&(1<<i))
                c1 = true;
        
            if(c1==false){
                
                if(a1==true&&b1==true)
                    flips+=2;
                else if(a1==true||b1==true)
                    flips++; 
            }
            else{
                
                if(a1==false&&b1==false)
                    flips++;
            }
        }
        
        return flips;
    }
};
