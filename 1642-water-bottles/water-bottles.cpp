class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int n=numBottles;
      int count=0;
      int left=0;
      while(numBottles>0){
        count+=numBottles;
        left += numBottles;
        numBottles=left/numExchange;
        left=left%numExchange;
      }
      return count;
    }
};