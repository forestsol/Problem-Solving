/***********************************************
 * 2025-08-21
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

pair<int, int> make_num(int k){  // k를 받아 k자릿수의 시작과 끝을 반환.
    int first_num;
    int end_num;
    vector<char> first_num_arr(k, '0');
    first_num_arr[0] = '1';
    string frist_num_string(first_num_arr.begin(), first_num_arr.end());
    first_num = stoi(frist_num_string);

    vector<char> end_num_arr(k, '9');
    string end_num_string(end_num_arr.begin(), end_num_arr.end());
    end_num = stoi(end_num_string);

    return make_pair(first_num, end_num);
}

bool unique_nums(int num){  // 각 자릿수가 다른 수인지 검사.
    string num_s = to_string(num);
    sort(num_s.begin(), num_s.end());

    auto last = unique(num_s.begin(), num_s.end()); // unique는 중복되지 않은 요소들을 앞으로 옮기고 그 끝을 가리키는 반복자를 반환함.
    return num_s.end() == last;
}

vector<bool> sieve(int n){  // 에라토스테네스의 채.
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; ++i){
        if(is_prime[i]){
            for(int j = i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    fastio;
    int k, m; // k는 자릿수, m은 나누는수
    cin >> k >> m;
    auto nums = make_num(k);
    auto primes = sieve(nums.second);
    int cnt = 0;

    for(int i = nums.first; i <= nums.second; i++){
        if(!unique_nums(i)) continue;

        bool first_cond = false;
        bool second_cond = false;
        int i_cur = i;

        for(int j = 2; j < i/2 ; j++){
            if(primes[j] && primes[i - j]){
                first_cond = true;
                break;
            }
        }

        while(i_cur % m == 0){
            i_cur /= m;
        }

        for(int j = 2; j*j < i+1 ; j++){      
            if(primes[j]){
                if(i_cur % j == 0 && primes[i_cur / j]){
                    second_cond = true;
                }
            }
        }

        if(first_cond && second_cond) cnt++;        
    }
    cout << cnt;

    

    // 알고리즘 문제 풀이 시작
    return 0;
}