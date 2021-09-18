
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/** 
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
// class Solution {
// public:
//   string multiply(string num1, string num2){
//     int s1 = num1.size();
//     int s2 = num2.size();
//     string accum(std::max(s1,s2)+10,'0');
//     string calResult;
//     for (size_t i = 0; i < s1; i++){
//       // 分两步，第一步，借位乘法，第二步，加法
//       calResult = multiplyOne(num2,num1[i]);
//       for (size_t j = 0; j < s2; i++)
//       {
//         /* code */
//       }
      

//     }
//   };
// private:
//   string multiplyOne(const char * b,const char *a){
//     // pair<int, int> result;
//     // int ai = atoi(a);
//     // int bi = atoi(b);
//     // result.first = ai*bi % 10;  // remainder
//     // result.second = ai*bi / 10; // quotient
//     // return result;
//   };

//   string plus(const string a,const string b){
//     string result;
//     // int ai = atoi(a);
//     // int bi = atoi(b);
//     // result.first = ai+bi % 10;  // remainder
//     // result.second = ai+bi / 10; // quotient
//     return result;
//   };
// };
class Solution{
  public:
    string multiply(string num1,string num2){
      if(num1 == "0" || num2 == "0"){
        return "0";
      }
      string ans = "0";
      int m = num1.size(), n= num2.size();
      for (int i = n-1; i >= 0; i--){ // from tail to head. 数字位从低到高
        string curr;  // 这次计算的结果
        int add = 0;  // 每次的进位
        for (int j = n-1; j >i; j--){ // 根据计算的位置，加上10进制的进位，后面补0
          curr.push_back(0);  // 往string里面加数据
        }
        int y = num2.at(i) - '0';
        for (int j = m-1; j >= 0; j--){
          int x = num1.at(j) - '0';
          int product = x*y + add; // 乘法
          curr.push_back(product % 10);
          add = product / 10;
        }
        while (add != 0) { // 最高位有进位
          curr.push_back(add%10);
          add /= 10;
        }
        reverse(curr.begin(),curr.end());// should include <algorithm>
        for (auto &c:curr){
          c += '0'; // 转换成字符串，原来存的是数字值。
        }
        ans = addStrings(ans,curr);   // 结果的加法
      }
      return ans;
    }
  private:
    // string plus 
    string addStrings(string &num1,string &num2){
      int i = num1.size()-1, j= num2.size()-1, add = 0;
      string ans;
      while (i >= 0 || j>= 0 || add != 0){
        int x =i >= 0 ? num1.at(i) -'0':0;
        int y =j >= 0 ? num2.at(j) -'0':0;
        int result = x + y+ add;  //加法
        ans.push_back(result % 10);
        add = result /10;
        i--;
        j--;
      }
      reverse(ans.begin(),ans.end()); 
      for (auto &c:ans)
      {
        c+= '0';
      }
      return ans;
    }
};

// TODO: Other optimizations.

int main(){
  string input1("123");
  string input2("456");
  Solution sl;
  string result = sl.multiply(input1,input2);
  cout << result << endl;
  return 0;
}