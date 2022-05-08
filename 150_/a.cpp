#include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <ctime>
#include <climits>
using namespace std;
/** 
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
示例 1：
输入：n = 13
输出：6
示例 2：
输入：n = 0
输出：0
 
提示：

0 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-digit-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

class Solution{
  public:
    int countDigitOne(int n){
      int e=0; // 计数
      int r=0; // 后面的数
      for(int i = 0; n!= 0;i ++){
        int m = n/10;
        if(m*10 + 1<n){
          m++;  // 尾数为1的情况
        }else if(m*10 + 1 ==n){
          e+= r+1;  // 10进制位为1的情况
        }
        e += (m * pow(10,i)); // 乘以位数
        r += (n%10 * pow(10,i));  // 更新后面的数
        n /=10;   // 除以10，处理下一位
      }
      return e;
    }
  private:

};

/**
 * 咱们先随便写个数，来找个规律。

以3421为例

先找个位，什么时候个位会出现1？很简单，每一个10都会出现一个1，所以，直接找有几个十就行了，
一共有342个十，但是342*10<3421，说明还有一个1没有计入，所以个位有343个1。

同理十位，一共有34个一百，又34*100<3421，所以加1。

又十位有1的情况一共有10,11，12,13,14,15,16,17，18,19十种，所以一共有35*10个1。

同理百位，有4*100个1。

千位，有1*1000个1。

将所有位上出现的1的数目加起来，我们就可以得出答案。

但事情还没那么简单，像3413这个数，在找十位的时候，我们发现如果直接（34+1）*10的话，会多出3414到3419的6种情况。

所以更正确的做法是，先找到有34个百，再看34*100+20是否小于等于要找的数。

如果小于等于，那就是3421这种情况，直接（34+1）*10就行

否则就34*10之后，再加上它后面的数，3413的十位后面的数是3，就加上3，由于还有一个3410，
所以还有加上1，一共有340+3+1个1。

作者：ningfan
链接：https://leetcode-cn.com/problems/number-of-digit-one/solution/zhao-ge-gui-lu-qing-song-de-chu-da-an-hu-p6l6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */

int main(){
  int a = 13;
  Solution sl;
  int result = sl.countDigitOne(a);
  cout << result << endl;
  return 0;
}