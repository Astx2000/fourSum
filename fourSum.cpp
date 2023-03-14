#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

// std::vector<std::vector<int>> fourSum(std::vector<int>& arr, int target) {
//     sort(arr.begin(), arr.end());
//     std::unordered_map<int, std::vector<std::pair<int,int>>> mp;
//     if (arr.size() < 4)
//         return {};
//     for(int i = 0; i < arr.size(); ++i) {
//         for (int j = i + 1; j < arr.size(); ++j) {
//             int sum = arr[i] + arr[j];
//             mp[sum].push_back(std::make_pair(i, j)); 
//         }
//     }

//     std::vector<std::vector<int>> result;
//     for (int i = 0; i < arr.size(); ++i) {
//         if (i == 0 || arr[i - 1] != arr[i]) {
//             for (int j = i + 1; j < arr.size(); ++j) {
//                 if (j != i + 1 && arr[j] == arr[j - 1]) {
//                     continue;
//                 }
//                 int sum = arr[i] + arr[j];
//                 int leftover = target - sum;
//                 std::set<int> s;
//                 for (int k = 0; k < mp[leftover].size(); ++k) {
//                     int a = mp[leftover][k].first;
//                     int b = mp[leftover][k].second;
//                     if (i == a || j == b) {
//                         continue;
//                     }
//                     if (j == a || i == b) {
//                         continue;
//                     }
//                     if (j > a) {
//                         continue;
//                     }    
//                     std::vector<int> res {arr[i], arr[j], arr[a], arr[b]};
//                     if (s.find(arr[a]) != s.end()) {
//                         continue;
//                     }
//                     s.insert(arr[a]);
//                     result.push_back(res); 
//                 }
//             }
//         }
//     }   
//     return result;
// }


std::vector<std::vector<int>> fourSum(std::vector<int>& arr, int tg) {
    std::vector<std::vector<int>>ans;
    std::set<std::vector< int>>st;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 3 ; i++) {
        if (i > 0 && (arr[i - 1] == arr[i])) {
            continue;
        }
        for (int j = i + 1; j < arr.size() - 2; j++) {
            if (j >  i + 1 && arr[j - 1] == arr[j]) {
                continue;
            }
            int l = j + 1; 
            int r = arr.size() - 1;
            int tg_nw = arr[i] + arr[j];
            while (l < r) {
                int rem = tg - tg_nw;
                int now = arr[l] + arr[r];
                if (rem == now) {
                    st.insert({
                        arr[i],
                        arr[j],
                        arr[l],
                        arr[r]
                    });
                    ++l;
                }
                if (now < rem) {
                    ++l;
                }
                if (now > rem) {
                    --r;
                }
            }
        }
    }
    for (auto it : st) {
        ans.push_back(it);
    }
    return ans;
}




int main() {
    std::vector<int> nums{1, 0, 1, -1, -3, 2};
    std::vector<std::vector<int>> result;
    int target;
    std::cout << "target =   ";
    std::cin >> target;
    result = fourSum(nums, target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            std::cout << result[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
