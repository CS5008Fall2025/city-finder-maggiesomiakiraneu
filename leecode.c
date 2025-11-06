/*
I learned that bit manipulation can solve some problems in constant time, which 
is much faster than using loops. Before this, I usually thought about solutions 
using loops and conditions, but learning how numbers look in binary helped me 
see a new way to solve problems. This relates to the idea that efficiency can 
depend on the way we represent and work with data, not just on the algorithm 
we use.

I did not compare my solution with others. I think O(1) is already fast enough, 
so I did not feel the need to look at other solutions.


Link to the question: https://leetcode.com/problems/power-of-two/description/?envType=list&envId=ofbudylr
*/



bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}