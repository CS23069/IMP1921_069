//reverse bits (on leetcode/PDF)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int res=0;
        for(int i=0;i<32;i++)
        {   
          res <<= 1;
            
            if((n & 1)==1)
                res++;
         n >>= 1;
            }
        return res;
        
        
    }
};

//counting bits (on leetcode/PDF)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> count(num+1, 0);
            for(int i=1;i<=num;++i)
                count[i]=count[i>>1] + i%2;
        return count;
        
    }
};

//counting no of 1 bits (on leetcode/PDF)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int result=0;
        while(n!=0)
        {
            result+=(n%2) & 1;
            n>>=1;
        }
        return result;
    }
};

//check if power of 2 (on leetcode)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long int i=1;
        while(i<n)
        {
            i*=2;
        }
        if(i==n)
            return true;
        else
            return false;
    }
};





