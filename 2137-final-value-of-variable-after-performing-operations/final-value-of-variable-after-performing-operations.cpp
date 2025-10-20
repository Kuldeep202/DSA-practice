class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;
    for(auto &it : operations){
      if(it == "--X"){
          X = X-1;
      }else if(it == "X++"){
          X = X+1;
      }else if(it == "++X"){
          X = X+1;
      }else{
          X = X-1;
      }
  }
  return X;
    }
};