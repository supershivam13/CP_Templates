class Solution {
public:
  bool canJump(vector<int>& a) {

    int n = a.size();
    if (n == 1)
      return true;

    int jump = a[0];

    for (int i = 1 ; i < n; i++) {
      if (jump < i)
        return false;

      jump = max(jump , i + a[i]);
    }
    return true;
  }
};