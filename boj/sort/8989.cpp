//* 정렬 - 8989 <시계> 실버 1
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(const pair<int, string> &time1, const pair<int, string> &time2)
{
    if (time1.first == time2.first)
    {
        return time1.second < time2.second;
    }
    else
    {
        return time1.first < time2.first; //false이면 swap
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, string> times[5];
    int t;

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            string time;
            cin >> time;
            int hour = stoi(time.substr(0, 2));
            if (hour >= 12)
                hour -= 12;
            int minute = stoi(time.substr(3, 2));
            int degree = abs((hour * 60 + minute) - (minute * 12));
            
            degree = min(degree, 720 - degree);

            times[i] = make_pair(degree, time);
        }

        sort(times, times + 5);

        cout << times[2].second << "\n";
    }

    return 0;
}