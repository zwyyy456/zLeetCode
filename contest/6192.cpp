class Solution {
  private:
    int max_factor(int a, int b) {
        while (a % b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return b;
    }

  public:
    int commonFactors(int a, int b) {
        int factor = max_factor(a, b);
        int cnt = 0;
        for (int i = 1; i <= factor; i++) {
            if (factor % i == 0)
                cnt++;
        }
        return cnt;
    }
};