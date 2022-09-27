#include <string>
using std::string;
class Solution {
  public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr_la[4] = {0};
        int arr_ab[4] = {0};
        int arr_aa[4] = {0};
        int arr_lb[4] = {0};
        int arr_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < 2; i++) {
            arr_la[i] = leaveAlice[i] - '0';
            arr_ab[i] = arriveBob[i] - '0';
            arr_aa[i] = arriveAlice[i] - '0';
            arr_lb[i] = leaveBob[i] - '0';
        }
        for (int i = 3; i < 5; i++) {
            arr_la[i - 1] = leaveAlice[i] - '0';
            arr_ab[i - 1] = arriveBob[i] - '0';
            arr_aa[i - 1] = arriveAlice[i] - '0';
            arr_lb[i - 1] = leaveBob[i] - '0';
        }
        int m_la = arr_la[0] * 10 + arr_la[1];
        int day_la = 0;
        for (int i = 1; i < m_la; i++) {
            day_la += arr_month[i];
        }
        day_la += arr_la[2] * 10 + arr_la[3];
        int m_ab = arr_ab[0] * 10 + arr_ab[1];
        int day_ab = 0;
        for (int i = 1; i < m_ab; i++) {
            day_ab += arr_month[i];
        }
        day_ab += arr_ab[2] * 10 + arr_ab[3];
        int m_aa = arr_aa[0] * 10 + arr_aa[1];
        int day_aa = 0;
        for (int i = 1; i < m_aa; i++) {
            day_aa += arr_month[i];
        }
        day_aa += arr_aa[2] * 10 + arr_aa[3];
        int m_lb = arr_lb[0] * 10 + arr_lb[1];
        int day_lb = 0;
        for (int i = 1; i < m_lb; i++) {
            day_lb += arr_month[i];
        }
        day_lb += arr_lb[2] * 10 + arr_lb[3];
        if (day_la < day_ab ||day_lb < day_aa)
            return 0;
        else {
            ifl (day_aa <= day_ab)
        }
    }
};