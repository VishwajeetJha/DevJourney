class palindrome {
    static int nDigits(int n)
    {
        return(1 + (int)Math.log10(n));
    }

    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        else if(x < 10){
            return true;
        }
        // String bits = Integer.toBinaryString(x);
        // int l = length(bit) + 1; // found n

        // int k=0;
        // String b1[100];

        // To store the reverse of n
        int rev = 0;
        int n = x;

        // Reversing the digits
        while (n > 0) 
        {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }

        if(x == rev){
            return true;
        }
        
        // // Iterate through all digits in rev
        // while(rev > 0)
        // {
          
        //     // Find Binary for each digit
        //     // using bitset
        //     String b = Integer.toBinaryString(rev % 10);
            
        //     b = String.format("%04d", Integer.parseInt(b));
            
        //     //store
        //     b1[k] = b;
        //     k++;
          
        //     // Divide rev by 10 for next digit
        //     rev /= 10;
        // }
        
        // //BCD Conversion then (2^n), n times left shift
        // //10 = 1010 ==== 0001 0000
        //             // 0010 0000
        //             // 0100 0000
        //             // 1000 0000
        //             // 0000 0001
        // //01 = 0001 ==== 0000 0001
        // // or = 1011 = 11
        // // ex-or = 0101
        // // ex-nor = ~(ex-or) =  1010
        // //  10 left shift 2^4 = 4 times
        // // 0101
        // // 1010
        // // 0101
        // // 1010

        // // 121 / 10 = 120 + 1       //1st division remainder
        // // 120 / 10 = 12 + 0
        // // 12 / 10 = 10 + 2
        // // 10 / 10 = 1 + 0          //length times divisions, quotient
        // // 121 = 1111001 ==== 0001 0010 0001
        // // 121 = 1111001 64+32+16+8+1  ->2^7
        // //      121 left shift 2^7 = 7 times
        // // 1110011  1st
        // // 1100111  2nd
        // // 1001111  3rd
        // // 0011111  4th
        // // 0111110  5th
        // // 1111100  6th
        // // 1111001  7th
        // // 121 = 1111001
        // //  or = 1111001
        // //  and = 1111001
        // //  ex-or = 0000110
        // //  ex-nor = ~(ex-or) = 1111001

        // // 131 = 10000111
        // // 131 = 10000111
        // //

        return false;
    }
}