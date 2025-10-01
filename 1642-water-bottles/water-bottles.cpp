class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0, empties = 0;
        while (numBottles > 0) {
            total += numBottles;       
            empties += numBottles;     
            numBottles = empties / numExchange; 
            empties %= numExchange;    
        }
        return total;
    }
};