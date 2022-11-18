// 821. 字符的最短距离
// https://leetcode-cn.com/problems/shortest-distance-to-a-character/

#include <iostream>
#include<cmath>
#include <vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer;
        set<int> taget_char;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                taget_char.insert(i);
            }
        }
        // 遍历
        for(int i = 0; i < s.size(); i++){
            int dis = 1e4;
            // for(set<int>::iterator it = taget_char.begin(); it != taget_char.end(); it++){
            //     dis = min(dis, abs(i - *it));
            // }
            for(auto &x : taget_char) dis = min(dis, abs(i - x));
            answer.push_back(dis);
        }
        return answer;
    }
};

int main(void) 
{
    string s;
    char c;

    cin >> s >> c;

    vector<int> result;

    Solution res;
    result = res.shortestToChar(s,c);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}
