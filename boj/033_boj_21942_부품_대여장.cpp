/***********************************************
 * 2025-08-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

static const int month_to_days[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};

long long to_minutes(int M, int D, int h, int m){
    long long result = 0;
    
    long long days = 0;
    for(int i = 1; i < M; i++){
        days += month_to_days[i];
    }

    days += (D-1);

    result += days * 1440LL;
    result += h * 60LL;
    result += m;

    return result;

}

bool compare(const pair<string, long long>& a, const pair<string, long long>& b){
    return a.first < b.first;
}

int main() {
    fastio;
    int n, f;
    string l;
    cin >> n >> l >> f;

    int l_day = stoi(l.substr(0,3));
    int l_hour = stoi(l.substr(4,2));
    int l_minute = stoi(l.substr(7,2));

    long long l_to_minute = l_day * 1440LL + l_hour * 60LL + l_minute;

    map<pair<string, string>, pair<string, string>> listing;

    map<string, long long> money_listing;

    for(int i = 0 ; i < n; i++){
        string date, time, p, m; // 부품이름 p, 닉네임 m
        cin >> date >> time >> p >> m;
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int hour = stoi(time.substr(0,2));
        int minute = stoi(time.substr(3,2));
        long long total_m = to_minutes(month, day, hour, minute);

        
        pair<string, string> key = {p, m};
        pair<string, string> value = {date, time};
        if(listing.find(key) == listing.end()){
            listing.insert({key, value});
        }
        else{
            string prev_date = listing[key].first;
            string prev_time = listing[key].second;
            int prev_month = stoi(prev_date.substr(5,2));
            int prev_day = stoi(prev_date.substr(8,2));
            int prev_hour = stoi(prev_time.substr(0,2));
            int prev_minute = stoi(prev_time.substr(3,2));
            long long prev_total_m = to_minutes(prev_month, prev_day, prev_hour, prev_minute);

            long long diff = total_m - prev_total_m;
            if(diff > l_to_minute){
                money_listing[m] += (diff - l_to_minute) * f;
            }
            listing.erase(key);
        }
    }

    if(money_listing.empty()){
        cout << -1 << endl;
        return 0;
    }
    else{
        for (auto &it : money_listing) {
            cout << it.first << " " << it.second << '\n';
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}