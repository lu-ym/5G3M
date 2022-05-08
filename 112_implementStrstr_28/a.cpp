#include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
using namespace std;
// KMP代码
class Solution {
public:
  int strStr(string s, string p) {
    int n = s.size(), m = p.size();
    if(m == 0) return 0;
    //设置哨兵. 避免了各种+1、-1操作等。
    s.insert(s.begin(),' ');
    p.insert(p.begin(),' ');
    vector<int> next(m + 1);
    //预处理next数组. j表示相同前缀的长度
    for(int i = 2, j = 0; i <= m; i++){
      while(j and p[i] != p[j + 1]) j = next[j];  // C++ 可以用and
      if(p[i] == p[j + 1]) j++;
      next[i] = j;
    }
    vector<int>::iterator ite  = next.begin();
    while (ite != next.end()){
      cout << *ite++;
    }
    cout << endl;
    // cout << next.begin() << next.end()<< endl;
    //匹配过程。 j表示相同前缀的长度
    for(int i = 1, j = 0; i <= n; i++){
      while(j and s[i] != p[j + 1]) j = next[j];
      if(s[i] == p[j + 1]) j++;
      if(j == m) return i - m;
    }
    return -1;
  }
};
// BM算法
// class Solution {
// public:
//   int strStr(string s, string p) {
//     int n = s.size(), m = p.size();
//     if(m == 0) return 0;


//   }
// };
// // sunday 算法
// class Solution {
// public:
//   int strStr(string s, string p) {
//     int n = s.size(), m = p.size();
//     if(m == 0) return 0;


//   }
// };

int main(void){
  string total;
  string substr;
  Solution sl;
  while (true){
    cin >> total >>substr;
    int result =sl.strStr(total,substr);
    cout << result << endl;
  }
}
