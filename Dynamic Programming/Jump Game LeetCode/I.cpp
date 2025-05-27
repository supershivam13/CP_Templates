class Solution {
public:
  bool canJump(vector<int>& a) {

    int maxIndex = 0;       // maximum index upto which we can reach

    for (int i = 0 ; i < a.size(); i++) {
      if (maxIndex < i)         // if we reached index greater than maxIndex, not possible
        return false;

      maxIndex = max(maxIndex , i + a[i]);       // max( maxIndex, index + maxJumpPossible)
    }
    
    return true;
  }
};
