// https://www.nowcoder.com/ta/huawei
/** 
 * 描述：HJ12 字符串反转
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述：
输入一行，为一个只包含小写字母的字符串。
输出描述：
输出该字符串反转后的字符串。
示例1
输入：
abcd
输出：
dcba
 * */
// 用gets(num)也可以
#include <stdio.h>
int main(void){
    char num[1000];
    scanf("%s",num);
    for(int i=strlen(num)-1 ; i>=0 ; i--)
    {
        printf("%c",num[i]);  
    }
}
/*
描述:HJ11 数字颠倒
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001

输入描述：
输入一个int整数
输出描述：
将这个整数以字符串的形式逆序输出

示例1
输入：
1516000
输出：
0006151
*/
#include <stdio.h>
int main(){
    int temp;
    int temp1;
    scanf("%d",&temp);
    while(temp != 0){
        temp1 = temp % 10;       
        temp = temp / 10;       
        printf("%d",temp1);
    }
    return 0;
}
// 用string来操作也可以
#include<stdio.h>
#include<string.h>
int main()
{
    char str[10000];
    gets(str);
    int len=strlen(str);
    for(int i=len-1;i>=0;i--)
    {
        printf("%c",str[i]);
    }
}
/**
 * 描述
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。

输入描述：
 输入一个整数（int类型）

输出描述：
 这个数转换成2进制后，输出1的个数

示例1
输入：
5
输出：
2
*/
#include <stdio.h>
int main(){
    int temp;
    unsigned char i = 0;
    scanf("%d",&temp);
    while(temp != 0){
        i++;
        temp &= (temp-1);
    }
    printf("%d",i);
}
/**
 * HJ53 杨辉三角的变形
 * 以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到
 * 右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。

输入n(n <= 1000000000)
本题有多组输入数据，输入到文件末尾，请使用while(cin>>)等方式读入
输入描述：
输入一个int整数

输出描述：
输出返回的int值

示例1
输入：
4
2
输出：
3
-1
 * */
// 实际为找规律，对4取余不同，则结果不同。
#include <stdio.h>
int main(){
  int n,site;
  while(scanf("%d",&n) != EOF){
    if(n==1 || n==2){
      site = -1;
    }else if(n%4 == 0){
      site = 3;
    }else if(n%4 == 2){
      site = 4;
    }else{
      site = 2;
    }
    printf("%d\n",site);
  }
}

/**
 * 描述
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,
  向上取整；小于5，则向下取整。

输入描述：
输入一个正浮点数值

输出描述：
输出该数值的近似整数值

示例1
输入：
5.5
输出：
6

*/

#include <stdio.h>
#include <math.h>
int main(){
  double temp;
  scanf("%lf",&temp); // 要用lf
  int a = floor(temp);// ceil是反向，向上取整
  if((temp - a) >= 0.5){
    a++;
  }
  printf("%d",a);
  /* 数值扩大后用除法更好，整数运算比较方便
  i=(int)(fl*10);
  i = i/10+(i%10>=5);
  printf("%d",i);
    */
}

/**
 * 描述 完全数计算
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。s

输入n，请输出n以内(含n)完全数的个数。计算范围, 0 < n <= 500000


本题输入含有多组样例。

输入描述：
输入一个数字n

输出描述：
输出不超过n的完全数的个数

示例1
输入：
1000
7
100
输出：
3
1
2
 * 
*/
// 取巧的方法是查字典, const arr[4] = {6, 28, 496, 8128};
#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  while(scanf("%d",&n) != EOF){
    int count = 0;
    for(int i = 6;i<=n;i++){
      int temp = 1;
      for(int j = 2;j <= (i/2);j++){
          if(!(i%j)) temp += j;
      }
      if(temp == i) count++;
    }
    printf("%d\r\n",count);
  }
}

/**
 * HJ72 百钱买百鸡问题
 * 描述
公元前五世纪，我国古代数学家张丘建在《算经》一书中提出了“百鸡问题”：鸡翁一值钱五，
  鸡母一值钱三，鸡雏三值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？

详细描述：

接口说明

原型：
int GetResult(vector &list)
输入参数：
        无

输出参数（指针指向的内存区域保证有效）：
    list  鸡翁、鸡母、鸡雏组合的列表

返回值：
    -1 失败     
    0 成功
输入描述：
输入任何一个整数，即可运行程序。

输出描述：
示例1
输入：
1
输出：
0 25 75
4 18 78
8 11 81
12 4 84
*/
#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        for(i=0;i<=20;i++)
        {
            for(j=0;j<=(100-5*i)/3;j++)
            {
                k=3*(100-5*i-3*j);
                if((i+j+k)==100)
                    printf("%d %d %d\n",i,j,k);
            }
        }
    }
    return 0;
}

/**
 * 描述 -- 字符个数统计
编写一个函数，计算字符串中含有的不同字符的个数。字符在ASCII码范围内(0~127，包括0和127)，
  换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
例如，对于字符串abaca而言，有a、b、c三种不同的字符，因此输出3。
输入描述：
输入一行没有空格的字符串。

输出描述：
输出 输入字符串 中范围在(0~127，包括0和127)字符的种数。

示例1
输入：
abc
输出：
3
 * 
*/
#include <stdio.h>
#include <string.h>
// struct ASCCNT{
//   zero
// }
int main(){
  char s[512];
  gets(s);
  // scanf("%s",&m);
  int len = strlen(s);
  unsigned int count0=0,count1=0,count2=0,count3=0;
  for(int i =0;i<len;i++){
    switch(s[i]/32){
      case 0: count0 |= ((unsigned int)1<<(s[i]%32));
        break;
      case 1: count1 |= ((unsigned int)1<<(s[i]%32));
        break;
      case 2: count2 |= ((unsigned int)1<<(s[i]%32));
        break;
      case 3: count3 |= ((unsigned int)1<<(s[i]%32));
        break;
    }
  }
  int count =0;
  while(count0 != 0){
    count++;
    count0 &= (count0-1);
  }
  while(count1 != 0){
    count++;
    count1 &= (count1-1);
  }
  while(count2 != 0){
    count++;
    count2 &= (count2-1);
  }
  while(count3 != 0){
    count++;
    count3 &= (count3-1);
  }
  printf("%d",count);
}

/**
 * 描述 -- 走方格的方案数
请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，
  总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

本题含有多组样例输入。
输入描述：
每组样例输入两个正整数n和m，用空格隔开。(1≤n,m≤8)

输出描述：
每组样例输出一行结果

示例1
输入：
2 2
1 2
输出：
6
3
 * 
*/
/** Tips:1) scanf多个参数的使用。
 * 2）小数值、多组输入，用查字典的方法比较快。运行时间快，少掉了运行的空间，增加了字典/数组的空间。
 * */
#include <stdio.h>
int main(void)
{
    int i, j, n, m, dp[10][10];
    for(i=0; i<10; i++)
        dp[i][0] = 1;
    for(j=0; j<10; j++)
        dp[0][j] = 1;
    for(i=1; i<10; i++)
        for(j=1; j<10; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
             
    for( ; scanf("%d%d", &n, &m)!=EOF; )
        printf("%d\n", dp[m][n]);
    return 0;
}

/**
 * HJ76 尼科彻斯定理
 * 
*/
#include <stdio.h>
int main(void){
  int n;
  int third;
  int temp;
  while(scanf("%d",&n) != EOF){
    third = n*n*n; // 求立方
    for(int i = 1;i<third;i+=2){
      // i*n + 2*temp求n个连续奇数的和
      temp=0;
      for(int j = 1;j<n;j++){
        temp+=j; 
      }
      // 打印
      if((i*n + 2*temp) == third){
        printf("%d",i);
        for(int j = 1;j<n;j++){
          printf("+%d",i+2*j);
        }
        printf("\r\n");
        break;
      }
    }
  }
}
/**
 * HJ34 图片整理 -- 其实就是排序，用计数排序就可以。
*/
/**
 * HJ60 查找组成一个偶数最接近的两个素数
 * 描述
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出
  组成指定偶数的两个素数差值最小的素数对。
本题含有多组样例输入。
输入描述：
输入一个偶数

输出描述：
输出两个素数

示例1
输入：
20
输出：
7
13
*/
/* 思路：1）从中间的数开始往一侧找 2）检查素数
*/
// /* 思路：1）构建素数表，方便查找
//   2) 从数的中间开始查找,向左或者向右都可以
//   3）每次只找质数，如果它的差值也是质数，则找到对应的值
// */
// #include <stdio.h>
// int array[168]={2,3,5,7,11,13,17};
// int start = 7;
// void generate(void){
//   int j;
//   for(int i=17;i<=1000;i+=2){
//     for(j=2;j<start;j++){
//       if(!(i%array[j])) {
//         j--;
//         break;
//       }
//     }
//     if(j == start){
//       array[start++] = i;
//     }
//   }
// }
// int search(int n,int startLoc, int endLoc){
//   if(startLoc+1 == endLoc) return (array[startLoc]==n);
//   int middle = (startLoc + endLoc)/2;
//   if(array[middle] == n ) return 1;
//   if(array[middle] > n) return search(n, startLoc, middle + 1);
//   else return search(n, middle, endLoc);
// }
// int main(){
//   generate();
//   int sum,m,n;
// //   while(scanf("%d",sum) != EOF){
//      search(10,0,start);
// //   }
// }
// 最朴素的思路 + exception handling
#include <stdio.h>
int main(void)
{
	char flag;
	int i, j, k, num;
	for( ; scanf("%d", &num)!=EOF; ){
		i=num>>1;
		flag=1;
		for(j=2; j*j<=i; j++)
			if(i%j==0){ flag=0; break; }  // 检查i是不是素数
		if(flag){
			if(i%2) { printf("%d\n%d\n", i, i); continue; } // 2等分
			if(i==2) { printf("2\n2\n"); continue; }  // 原来的数是4
		}
		for(i--; i>=2; i--){
			flag=1;
			for(j=2; j*j<=i; j++)
				if(i%j==0){ flag=0; break; }// 检查i是不是素数
			if(flag){
				k=num-i;
				for(j=2; j*j<=k; j++)
					if(k%j==0){ flag=0; break; }  // 检查k是不是素数
				if(flag){
					printf("%d\n%d\n", i, k);
					break;
				}
			}
		}
	}
	return 0;
}
/**
 * 描述
如果A是个x行y列的矩阵，B是个y行z列的矩阵，把A和B相乘，其结果将是另一个x行z列的矩阵C。这个矩阵的每个元素是由下面的公式决定的

矩阵的大小不超过100*100
输入描述：
输入包含多组数据，每组数据包含：
第一行包含一个正整数x，代表第一个矩阵的行数
第二行包含一个正整数y，代表第一个矩阵的列数和第二个矩阵的行数
第三行包含一个正整数z，代表第二个矩阵的列数
之后x行，每行y个整数，代表第一个矩阵的值
之后y行，每行z个整数，代表第二个矩阵的值

输出描述：
对于每组输入数据，输出x行，每行z个整数，代表两个矩阵相乘的结果
示例1
输入：
2
3
2
1 2 3
3 2 1
1 2
2 1
3 3

输出：
14 13
10 11

说明：
1 2 3
3 2 1 
乘以
1 2
2 1
3 3
等于
14 13
10 11 
示例2
输入：
2
2
2
1 1
1 1
1 1
1 1
16
8
7
17 19 16 19 14 1 14 9 
7 2 7 9 16 14 16 12 
13 3 3 17 5 9 8 16 
1 14 16 10 13 13 14 1 
13 13 15 4 7 2 6 16 
16 15 5 5 15 13 1 11 
11 5 0 16 14 7 7 15 
0 16 4 7 16 6 0 15 
2 14 11 2 17 17 5 12 
8 13 11 10 1 17 10 8 
15 16 17 15 7 8 13 14 
5 19 11 3 11 14 5 4 
9 16 13 11 15 18 0 3 
15 3 19 9 5 14 12 3 
9 8 7 11 18 19 14 18 
12 19 9 1 0 18 17 10 
5 18 16 19 6 12 5 
1 17 1 5 9 16 3 
14 16 4 0 19 3 6 
11 9 15 18 11 17 13 
5 5 19 3 16 1 12 
12 13 19 1 10 5 18 
19 18 6 18 19 12 3 
15 11 6 5 10 17 19 

输出：
2 2
2 2
1020 1490 1063 1100 1376 1219 884
966 1035 1015 715 1112 772 920
822 948 888 816 831 920 863
855 1099 828 578 1160 717 724
745 1076 644 595 930 838 688
635 1051 970 600 880 811 846
748 879 952 772 864 872 878
526 722 645 335 763 688 748
764 996 868 362 1026 681 897
836 1125 785 637 940 849 775
1082 1476 996 968 1301 1183 953
609 987 717 401 894 657 662
700 1083 1022 527 1016 746 875
909 1162 905 722 1055 708 720
1126 1296 1240 824 1304 1031 1196
905 1342 766 715 1028 956 749
*/
// 主要是了解一下这个矩阵参数的传入方式。
#include <stdio.h>
int main()
{
    int x,y,z;
    int a[50][50]={0}; // 用一个大矩阵来存储，就不用担心参数问题
    int b[50][50]={0};
    while(scanf("%d%d%d",&x,&y,&z)!=EOF)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                scanf("%d",&a[j][i]);
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<z;j++)
                scanf("%d",&b[j][i]);
        }
        // 矩阵计算
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<z;j++)
            {
                int sum=0;
                for(int k=0;k<y;k++)
                    sum+=a[k][i]*b[j][k];
                printf("%d ",sum);
            }
            printf("\n");
        }
    }
    return 0;
}
/**
 * 描述
根据输入的日期，计算是这一年的第几天。

输入描述：
输入一行，每行空格分割，分别是年，月，日

输出描述：
输出是这一年的第几天
示例1
输入：
2012 12 31
输出：
366
示例2
输入：
1982 3 4
输出：
63

 * 
*/
// 1. 闰年计算，2，月份分配
#include <stdio.h>
int main(void){
  int monthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int year,month,day;
  scanf("%d %d %d",&year,&month,&day);
  if(((year % 100) && !(year % 4))|| (!(year % 100) && !(year % 400)) ) monthDay[1] = 29;
  for(int i = 0; i<month-1; i++){
    day +=monthDay[i];
  }
  printf("%d",day);
}
/**
 * HJ9 提取不重复的整数
 * 描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
保证输入的整数最后一位不是0。
输入描述：
输入一个int型整数

输出描述：
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

示例1
输入：
9876673
输出：
37689
*/
#include <stdio.h>
int main(void)
{
  int n,m=0;
    scanf("%d",&n);
    int a[10]={0};
    while(n)
    {
        if(a[n%10] == 0)
        {
            a[n%10]++;
            m = m*10 + n%10; // 用四则运算直接生成数字。不要挨个数字再标记生成。
        }
        n /= 10;
    }
    printf("%d\n",m);
return 0;
}
/**
 * HJ40 统计字符
 * 描述
输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。

本题包含多组输入。


输入描述：
输入一行字符串，可以有空格

输出描述：
统计其中英文字符，空格字符，数字字符，其他字符的个数

示例1
输入：
1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][
输出：
26
3
10
12
*/
// 常规子路，找这几个数值出现的次数。要注意字母包含大写和小写。
#include<stdio.h>

int main()
{
    char str[1000];
    int k,s,e,o;
    while(gets(str) != NULL)
    {
        k=s=e=o=0;
        for(int i =0 ; i< strlen(str); ++i)
        {
            if(str[i] >= '0'  && str[i] <= '9')
                ++k;
            else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') )
                ++e;
            else if(str[i] == ' ')++s;
            else ++o;
        }
        printf("%d\n%d\n%d\n%d\n",e,s,k,o);
    }
    return 0;
}
/**
 * HJ35 蛇形矩阵
 * 描述
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
例如，当输入5时，应该输出的三角形为：
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
请注意本题含有多组样例输入。
输入描述：
输入正整数N（N不大于100）

输出描述：
输出一个N行的蛇形矩阵。
示例1
输入：
4
输出：
1 3 6 10
2 5 9
4 8
7
*/
// 找规律，每个方向都有间隔 -- 代码不好实现
// 蛇形走，按照这个规律走。下面的实现。 -- 有一点点思考
#include "stdio.h"

int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int a[m][m];
        int temp=0;
        for(int i=0;i<m;i++)
        {
            for(int j=i;j>=0;j--)
            {
                temp++; 
                a[j][i-j]=temp;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m-i;j++) // 三角形
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        
    }
    return 0;
}
// 直接按照数值规律打印，不构造矩阵。只输出结果。
// 注意规律的查找。起始是1，然后换行。 -- 比上一个难找规律。
#include <stdio.h>
int main(int argc, char *argv[])
{
    int n;
    int i, j;
    while (scanf("%d", &n) != EOF) {
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n - 1; j++) {
                printf("%d ", (j * j + j) / 2 - (i - 1));
            }
            printf("%d\n", (j * j + j) / 2 - (i - 1));
        }
    }

    return 0;
}
/**
 * 描述 -- HJ63 DNA序列
一个DNA序列由A/C/G/T四个字母的排列组合组成。G和C的比例（定义为GC-Ratio）是序列中G和C两个字母的总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的GC-Ratio可能是基因的起始点。

给定一个很长的DNA序列，以及限定的子串长度N，请帮助研究人员在给出的DNA序列中从左往右找出GC-Ratio最高且长度为N的第一个子串。
DNA序列为ACGT的子串有:ACG,CG,CGT等等，但是没有AGT，CT等等
输入描述：
输入一个string型基因序列，和int型子串的长度

输出描述：
找出GC比例最高的子串,如果有多个则输出第一个的子串

示例1
输入：
ACGT
2
输出：
CG
说明：
ACGT长度为2的子串有AC,CG,GT3个，其中AC和GT2个的GC-Ratio都为0.5，CG为1，故输出CG  
示例2
输入：
AACTGTGCACGACCTGA
5
输出：
GCACG
说明：
虽然CGACC的GC-Ratio也是最高，但它是从左往右找到的GC-Ratio最高的第2个子串，所以只能输出GCACG。 
 * 
*/
// 常规思路，寻找并标记出现的最多次数的子串首指针
// 小技巧，子串的查找，先找到一个窗口，然后每次向后滑动一个，如果
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[888];
	int i, j, len, k, sum, idx, max;
	while(scanf("%s%d", s, &k) != EOF)
	{
		len = strlen(s);
		i = idx = 0;
		sum = s[0]=='G' || s[0]=='C';
		for(j=1; j<k; j++)
			if(s[j]=='G' || s[j]=='C') sum++;
		max = sum;
		
		for( ; j<len; i++,j++){
			if(s[j]=='G' || s[j]=='C'){
				if(s[i]=='G' || s[i]=='C') continue; // 新的尾和旧的头一样，都是
				if(++sum > max){ max = sum;   idx = i+1; }// 更新max和idx索引
				continue;
			}
			if(s[i]=='G' || s[i]=='C') sum--; // 继续移动，更新sum
		}
		
		s[ idx+k ] = '\0';  // 更新子串后为空，可以直接打印定长。
		printf("%s\n", s+idx);
	}
	
	return 0;
}
/**
 * HJ75 公共子串计算 -- 滑动窗
 * 描述
问题描述：有4个线程和1个公共的字符数组。线程1的功能就是向数组输出A，线程2的功能就是向字符输出B，
  线程3的功能就是向数组输出C，线程4的功能就是向数组输出D。要求按顺序向数组赋值ABCDABCDABCD，
  ABCD的个数由线程函数1的参数指定。[注：C语言选手可使用WINDOWS SDK库函数]
接口说明：
void init();  //初始化函数
void Release(); //资源释放函数
unsignedint__stdcall ThreadFun1(PVOID pM)  ; //线程函数1，传入一个int类型的指针[取值范围：1 – 250，
  测试用例保证]，用于初始化输出A次数，资源需要线程释放
unsignedint__stdcall ThreadFun2(PVOID pM)  ;//线程函数2，无参数传入
unsignedint__stdcall ThreadFun3(PVOID pM)  ;//线程函数3，无参数传入
Unsigned int __stdcall ThreadFunc4(PVOID pM);//线程函数4，无参数传入
char  g_write[1032]; //线程1,2,3,4按顺序向该数组赋值。不用考虑数组是否越界，测试用例保证

输入描述：
本题含有多个样例输入。
输入一个int整数

输出描述：
对于每组样例，输出多个ABCD

示例1
输入：
10

输出：
ABCDABCDABCDABCDABCDABCDABCDABCDABCDABCD
*/
// 对于其他语言，可能要考虑多线程编程。对于C，直接多次打印就能通过了。
#include <stdio.h>
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
            printf("ABCD");
        printf("\n");
    }
    return 0;
}
/**
 * HJ70 矩阵乘法计算量估算
 * 描述
矩阵乘法的运算量与矩阵乘法的顺序强相关。
例如：

A是一个50×10的矩阵，B是10×20的矩阵，C是20×5的矩阵

计算A*B*C有两种顺序：（（AB）C）或者（A（BC）），前者需要计算15000次乘法，后者只需要3500次。

编写程序计算不同的计算顺序需要进行的乘法次数。

本题含有多组样例输入！



输入描述：
输入多行，先输入要计算乘法的矩阵个数n，每个矩阵的行数，列数，总共2n的数，最后输入要计算的法则
计算的法则为一个字符串，仅由左右括号和大写字母（'A'~'Z'）组成，保证括号是匹配的且输入合法！

输出描述：
输出需要进行的乘法次数

示例1
输入：
3
50 10
10 20
20 5
(A(BC))
输出：
3500
*/
// 主要是按照顺序计算。已经给了顺序，那就是四则运算的类似操作。递归+栈。按照指定运算法则运算。
#include <stdio.h>
#include <string.h>
#define MAXSIZE 500

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int i, j = 0, res = 0;
    int row[MAXSIZE] = {0}, col[MAXSIZE] = {0}; // 存储行和列数
    char type[MAXSIZE] = {'\0'}, temp[MAXSIZE] = {'\0'};
    for(i=0; i<n; i++)
        scanf("%d%d", &row[i], &col[i]);
    scanf("%s", type);
    for(i=0; i<strlen(type); i++){
      if(type[i] == '(')
        continue;
      else
        temp[j++] = type[i];
    }
    for(i=0; i<strlen(temp); i++){
      if(temp[i] == ')'){
        res += row[temp[i-2]-'A'] * col[temp[i-2]-'A'] * col[temp[i-1]-'A'];
        col[temp[i-2]-'A'] = col[temp[i-1]-'A'];
        strcpy(&temp[i-1], &temp[i+1]);
        i -= 2;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}

/**
 * 描述 -- HJ21 简单密码
密码是我们生活中非常重要的东东，我们的那么一点不能说的秘密就全靠它了。哇哈哈. 接下来渊子要在密码之上再加一套密码，虽然简单但也安全。

 

假设渊子原来一个BBS上的密码为zvbo9441987,为了方便记忆，他通过一种算法把这个密码变换成YUANzhi1987，这个密码是他的名字和出生年份，怎么忘都忘不了，而且可以明目张胆地放在显眼的地方而不被别人知道真正的密码。

 

他是这么变换的，大家都知道手机上的字母： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,就这么简单，渊子把密码中出现的小写字母都变成对应的数字，数字和其他的符号都不做变换，

 

声明：密码中没有空格，而密码中出现的大写字母则变成小写之后往后移一位，如：X，先变成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。


输入描述：
输入包括多个测试数据。输入是一个明文，密码长度不超过100个字符，输入直到文件结尾

输出描述：
输出渊子真正的密文

示例1
输入：
YUANzhi1987

输出：
zvbo9441987
 * 
*/
// 简单替换，普通的可以用运算。简化可以用查表。C++实现如下。
#include<iostream>
#include<string>
using namespace std;
const string dict1="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string dict2="bcdefghijklmnopqrstuvwxyza22233344455566677778889999";
 
char Char_Change(char a){
    for(int i=0;i<dict1.size();i++)
        if(dict1[i]==a) return dict2[i];
    return a;
}
 
int main(){
    //string data="YUANzhi1987";
    string data;
    while(getline(cin,data)){
        for(int i=0;i<data.size();i++)
            data[i] = Char_Change(data[i]);
        cout<<data<<endl;
    }
    return 0;
}
/**
 * 等差数列
 * 前n项和(3*n+1)*n/2
 * 
*/

/**
 * HJ14 字符串排序
 * 描述
给定n个字符串，请对n个字符串按照字典序排列。
输入描述：
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述：
数据输出n行，输出结果为按照字典序排列的字符串。
示例1
输入：
9
cap
to
cat
card
two
too
up
boat
boot

输出：
boat
boot
cap
card
cat
to
too
two
up
*/
// 就是排序算法。只不过比较函数用strcmp. 可以用插入排序。
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    char str[n][100];
    char a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            //strcmp(str[j],str[j+1])
            if(strcmp(str[j],str[j+1])>0)
            {
                strcpy(a,str[j+1]);
                strcpy(str[j+1],str[j]);
                strcpy(str[j],a);
                /*for(int k=0;k<100;k++)
                {
                    a[k]=str[j+1][k];
                    str[j+1][k]=str[j][k];
                    str[j][k]=a[k];
                }*/
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n",str[i]);
    }
}
/**
 * HJ85 最长回文子串 -- 参见leetcode
 * 
*/

/**
 * HJ36 字符串加密
 * 描述
有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，只保留第1个，其余几个丢弃。现在，修改过的那个单词属于字母表的下面，如下所示：

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

T R A I L B Z E S C D F G H J K M N O P Q U V W X Y

上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于顶上那行，并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。

请实现下述接口，通过指定的密匙和明文得到密文。


本题有多组输入数据。

输入描述：
先输入key和要加密的字符串

输出描述：
返回加密后的字符串

示例1
输入：
nihao
ni
输出：
le
*/
// 思路：用数组来标记新的数组元素，组成密码表，然后解密就好了。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
int main()
{
	/* 初始化对照表 */
	char sAlphabet[26] = { 0 };
	char cBegin = 'A';
	for (int i = 0; i < 26; i++)
	{
		sAlphabet[i] = cBegin;
		cBegin++;
	}


	char sInWord[100] = { 0 };
	char sText[100] = { 0 };
	while (scanf("%s%s", sInWord, sText) != EOF)
	{
			char sKeyUp[26] = { 0 };
			char sKeyDown[26] = { 0 };
			char sUpInWorf[100] = { 0 };
			/* 输入单词转大写 */
			for (int i = 0; i < strlen(sInWord); i++)
			{
				if (sInWord[i] >= 'a' && sInWord[i] <= 'z')
				{
					sUpInWorf[i] = sInWord[i] - 32;
				}
			}
			/* 单词去重 */
			char sOutWord[26] = { 0 };
			int iCount = 0;
			for (int j = 0; j < strlen(sUpInWorf); j++)
			{
				if (strchr(sOutWord, sUpInWorf[j]) == NULL)
				{
					sOutWord[iCount] = sUpInWorf[j];
					iCount++;
				}
			}

			/* 生成单词表 */
			sprintf(sKeyUp, "%s", sOutWord);
			for (int i = 0; i < 26; i++)
			{
				if (strchr(sKeyUp, sAlphabet[i]) == NULL)
				{
					sKeyUp[iCount] = sAlphabet[i];
					iCount++;
				}
			}

			/* 对照生成小写密码表 */
			for (int i = 0; i < 26; i++)
			{
				sKeyDown[i] = sKeyUp[i] + 32;
			}

			/* 转换 */
			for (int k = 0; k < strlen(sText); k++)
			{
				if (sText[k] >= 'a' && sText[k] <= 'z')
				{
					printf("%c", sKeyDown[sText[k] - 'a']);
				}
				else if (sText[k] >= 'A' && sText[k] <= 'Z')
				{
					printf("%c", sKeyUp[sText[k] - 'A']);
				}
			}
			printf("\n");
	}

	return 0;
}

/**
 * 描述 -- HJ41 称砝码
现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。
注：
称重重量包括0
输入描述：
输入包含多组测试数据。
对于每组测试数据：
第一行：n --- 砝码数(范围[1,10])
第二行：m1 m2 m3 ... mn --- 每个砝码的重量(范围[1,2000])
第三行：x1 x2 x3 .... xn --- 每个砝码的数量(范围[1,6])
输出描述：
利用给定的砝码可以称出的不同的重量数
示例1
输入：
2
1 2
2 1
输出：
5
*/
// 可以用集合set自动去重的性质来做。C++自动实现，C手动实现。
// 每次组合，总共多少个数，每次1/2/3个组合 -- 实现可能会复杂一点。
// 下面这个idea很好，用差值的方法来实现。同时实现了去重和多个数值组合。
#include <stdio.h>
#include <string.h>
typedef struct node_{
    int wgt;
    int num;
}node;
int main(void){
  int i, j;
  int n, sum;
  while(scanf("%d", &n) == 1){
    node data[n];
    sum = 0;
    for(i = 0; i < n; ++i) scanf("%d", &data[i].wgt);
    for(i = 0; i < n; ++i){
      scanf("%d", &data[i].num); // 收集各自出现count
      sum += data[i].num * data[i].wgt; // 最大值，代表了可能出现的最多次数
    }
    char dp[sum+1];// 所有可组合的所有数，包括0
    memset(dp, 0, sizeof(char)*(sum + 1));
    dp[0] = 1;  // 0肯定出现
    for(i = 0; i < n; ++i){ // 所有元素
      for(j = 0; j < data[i].num; ++j){ // 这个元素出现的次数
        for(int k = sum; k >= data[i].wgt; --k){ 
          // 如果一个值减去这个值的差值也出现在队列里面，那么这个值可能出现。
          // 通过j的多次循环，其实这是从小到大依次找到可能值。
          if(dp[k - data[i].wgt]) dp[k] = 1;
        }
      }
    }
    int cnt = 0;
    for(i = 0; i <= sum; ++i) if(dp[i]) ++cnt;
    printf("%d\n", cnt);
  }
  return 0;
}
/**
 * 描述 -- HJ13 句子逆序
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

输入描述：
输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。

输出描述：
得到逆序的句子

示例1
输入：
I am a boy
输出：
boy a am I
*/
// 实际就是用空格分隔出若干个单次出来，标记好并打印。可以用strtok()
// 下面这个是用倒序循环查找的方法，查找到之后向后打印，直到空格或者字符串尾部。
#include <stdio.h>
#include <string.h>
int main()
{
    char str[10000];
    int a,len,i;
    gets(str);
    len = strlen(str);
    for(i=len-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            a = i+1;
            while(str[a]!=' ')
            {
                if(a==len)
                    break;
                printf("%c", str[a]);
                a++;
            }
            printf(" ");
        }
    }
    i=0;
    while(str[i]!=' ')
    {
        printf("%c",str[i]);
        i++;
    }
    return 0;
}
/**
 * HJ74 参数解析：和句子逆序类似，找空格，分隔开来并分开打印。
 * 
*/
/**
 * HJ57 高精度整数加法：把字符串从低到高（倒序）做加法，用carry表示进位。
 * 
*/
/**
 * HJ99 自守数
 * 描述
自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数


接口说明


功能: 求出n以内的自守数的个数


输入参数：
int n

返回值：
n以内自守数的数量。


public static int CalcAutomorphicNumbers( int n)
{

return 0;
}
本题有多组输入数据，请使用while(cin>>)等方式处理


输入描述：
int型整数

输出描述：
n以内自守数的数量。

示例1
输入：
2000

输出：
8
*/
// 用余数等于原数的方法来判断尾数相等的情况。
#include<stdio.h>
int main()
{
    unsigned long getNum =0 ;
    while(scanf("%d",&getNum)!=EOF)
    {
        unsigned long sum;
        int no=0;
        int i=0;
        getchar();
        for(i=0;i<=getNum;i++)
        {
            sum=i*i;
            // 判断尾数相等的情况
            if(sum%10 == i   ||
              sum%100 == i  ||
              sum%1000 == i ||
              sum%10000 == i||
              sum%100000 == i)
            {
                no++;
            }
        }
        printf("%d\n",no);
    }
    return 0;
}
/**
 * HJ108 求最小公倍数
 * 描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

输入描述：
输入两个正整数A和B。

输出描述：
输出A和B的最小公倍数。

示例1
输入：
5 7
输出：
35
*/
// 暴力优化法：找到最大的数，循环查找，起点是大的数，步伐是大的数。直到找到能整除小数的为止。
//最小公倍数 = 两数之积除以最大公约数
#include "stdio.h"
int gcd(int a, int b)//辗转相除法求最大公约数
{
    while(a%b){
      int tmp=a;
      a=b;
      b=tmp%b;
    }
    return b;
}
main(){
    int a, b;
    scanf("%d %d",&a,&b);
    printf("%d",a*b/gcd(a,b));
    return 0;
}
/**
 * HJ90 合法IP -- 四部分，以点号间隔，每部分都是数值且在0-255之间。
*/

/**
 * HJ38 求小球落地5次后所经历的路程和第5次反弹的高度：
 * 描述
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，
  共经历多少米?第5次反弹多高？

最后的误差判断是小数点6位

输入描述：
输入起始高度，int型

输出描述：
分别输出第5次落地时，共经过多少米第5次反弹多高

示例1
输入：
1

输出：
2.875
0.03125
*/
// 递归，累加做和，可以完成。
// 等比数列，直接公式
#include<stdio.h>
#include<stdlib.h>
int main()
{
    double inputhigh;
    double output;
    double allput;

    while(scanf("%lf",&inputhigh)!=EOF)
    {
        output=inputhigh/32;
        allput=inputhigh/8+inputhigh/4+inputhigh/2+inputhigh+inputhigh;
        
        printf("%g\n",allput);
        printf("%g\n",output);

    }
    
    return 0;
}
/**
 * HJ48 从单向链表中删除指定值的节点
 * 描述
输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针。

链表的值不能重复。

构造过程，例如输入一行数据为:
6 2 1 2 3 2 5 1 4 5 7 2 2
则第一个参数6表示输入总共6个节点，第二个参数2表示头节点值为2，剩下的2个一组表示第2个节点值后面插入第1个节点值，为以下表示:
1 2 表示为
2->1
链表为2->1

3 2表示为
2->3
链表为2->3->1

5 1表示为
1->5
链表为2->3->1->5

4 5表示为
5->4
链表为2->3->1->5->4

7 2表示为
2->7
链表为2->7->3->1->5->4

最后的链表的顺序为 2 7 3 1 5 4

最后一个参数为2，表示要删掉节点为2的值
删除 结点 2

则结果为 7 3 1 5 4

链表长度不大于1000，每个节点的值不大于10000。
测试用例保证输入合法


输入描述：
输入一行，有以下4个部分：
1 输入链表结点个数
2 输入头结点的值
3 按照格式插入各个结点
4 输入要删除的结点的值

输出描述：
输出一行
输出删除结点后的序列，每个数后都要加空格

示例1
输入：
5 2 3 2 4 3 5 2 1 4 3
输出：
2 5 4 1
说明：
形成的链表为2->5->3->4->1
删掉节点3，返回的就是2->5->4->1
示例2
输入：
6 2 1 2 3 2 5 1 4 5 7 2 2
输出：
7 3 1 5 4
说明：
如题
*/
// 按照题中说的操作，没有什么技巧。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	struct Node* next;
}Node;
typedef struct Node* LinkList;
int main()
{
	LinkList L,p,r,q;
	int first=0,second=0;
	int num=0,del=0;
	

	while(scanf("%d",&num)!=EOF)
	{
		//创建链表
		L=(LinkList)malloc(sizeof(Node));
		scanf("%d",&(L->value));
		L->next=NULL;
		
		//插入结点
		for(int i=0;i<num-1;i++)
		{
			r=L;
			scanf("%d %d",&first,&second);
			p=(LinkList)malloc(sizeof(Node));
			p->value=first;

			while(r!=NULL)
			{
				if(r->value==second)
				{
					p->next=r->next;
					r->next=p;
					break;
				}
				r=r->next;
			}
		}

		//移除结点
		scanf("%d",&del);
		r=L;
		q=r->next;

		while(q!=NULL)
		{
			if(q->value==del)
			{
				r->next=q->next;
				q=r->next;
			}
			else
			{
				r=r->next;
				q=q->next;
			}

		}
		if(L->value==del)
			{
				L=L->next;
				r=L;
				q=r->next;
			}



		//打印链表
		q=L;
		while(q!=NULL)
		{
			printf("%d ",q->value);
			q=q->next;
		}

	}
	return 0;
}
/**
 * HJ45 名字的漂亮度
 * 描述
给出一个名字，该名字有26个字符组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个不同字母拥有相同的“漂亮度”。字母忽略大小写。

给出多个名字，计算每个名字最大可能的“漂亮度”。

本题含有多组数据。

输入描述：
整数N，后续N个名字

输出描述：
每个名称可能的最大漂亮程度

示例1
输入：
2
zhangsan
lisi
输出：
192
101
*/
/**简化：就是把里面字母的出现次序排序，最大的乘以26,以此逐个减小相乘来取得最大值。
 * 实现：1）用数组标记出现字母次数和总字母数量。同时统一大小写。 2）从大到小排序。3）做和。
*/
#include <stdio.h>
int main()
{
    int N;//整数N，后续N个名字
    char str[100000];
    int length;
    int temp;
    int sum;
    while(scanf("%d\n",&N)!=EOF)
    {
        for(int n=1;n<=N;n++)
        {
            scanf("%s\n",&str);
            length=strlen(str);
            sum=0;
            
            //统计每个字符的数量  初始化为0
            int arr[26]={0};
            //检测字符是什么
            for(int i=0;i<length;i++)
            {
                str[i]=toupper(str[i]);
                arr[str[i]-'A']++;
            }
            
            for(int i=0;i<26-1;i++)
            {
                for(int j=0;j<26-1-i;j++)
                {
                    if(arr[j]<arr[j+1]) //从大到小排列
                    {
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
            for(int i=0;i<26;i++)
            {
                sum=sum+(arr[i]*(26-i));
//                 if(arr[i]==0)
//                     break;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
/**
 * HJ65 查找两个字符串a,b中的最长公共子串 -- 最长公共子串问题
*/

/**
 * HJ43 迷宫问题
 * 定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示：
int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求
  编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一格是可以走的路。
本题含有多组数据。

输入描述：
输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以
  走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述：
左上角到右下角的最短路径，格式如样例所示。

示例1
输入：
5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出：
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
示例2
输入：

5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0
输出：

(0,0)
(1,0)
(2,0)
(3,0)
(4,0)
(4,1)
(4,2)
(4,3)
(4,4)

说明：
注意：不能斜着走！！
*/
/* 简化：找全是0的一条通路
 * 实现：用树的结构，从左上开始，标注所有可行的节点（其余1/2/3个方向，右、下、左、上）。
 * 并逐个排查，直到右下角。
 * 下面不需要，因为只有唯一的通路。
 * 需要找多个通路，都标记可行。回溯查找下一个通道，如果不行的，标记为不可行。
 *  回溯的时候标记后面的长度。最后打印最短的通路。
 * */
// TODO:下面的大概理清了，递归实现，还有一点不是非常明白，需要单独跑跑。
#include <stdio.h>
#include <string.h>
struct Info{
    int x, y;
};
typedef struct Info INFO;
char maze[10][10], *p;// 构造数组
INFO record[100];
int N_e, M_e, idx;// 矩阵边界edge和index
// 递归的查找下一个
char trace(int x, int y)
{
    record[ idx++ ] = (INFO){x, y};
    if(x==N_e && y==M_e){ // 到头了，打印结果
        for(int i=0; i<idx; i++)
            printf("(%d,%d)\n", record[i].x, record[i].y);
        return 1;
    }
    maze[x][y] = 7; // 干嘛？给这个元素加锁？
    
    if(x<N_e && !maze[ x+1 ][y] && trace(x+1, y)) return 1;// 右向可以，并最终走通了
    if(y<M_e && !maze[x][ y+1 ] && trace(x, y+1)) return 1;// 下方可以，并最终走通了
    if(x && !maze[ x-1 ][y] && trace(x-1, y)) return 1; // 左
    if(y && !maze[x][ y-1 ] && trace(x, y-1)) return 1; // 上
    
    maze[x][y] = 0;   idx--; // 失败了，reset index并回退。
    return 0;
}

int main(void)
{
    int N, M;
    while(scanf("%d%d", &N, &M) != EOF)
    {
        N_e = N-1;   M_e = M-1;
        for(int i=0; i<N; i++){
            p = maze[i];
            for(int j=0; j<M; j++)
                scanf("%d", p+j); // 填充矩阵
        }
        idx = 0;
        trace(0, 0);
    }
    return 0;
}
/**
 * HJ26 字符串排序 ：排序进化版，增加了一些其他的
 * 描述
编写一个程序，将输入字符串中的字符按如下规则排序。
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
如，输入： Type 输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
如，输入： BabA 输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。
如，输入： By?e 输出： Be?y
注意有多组测试数据，即输入有多行，每一行单独处理（换行符隔开的表示不同行）
输入描述：
输入字符串
输出描述：
输出字符串
示例1
输入：
A Famous Saying: Much Ado About Nothing (2012/8).
输出：
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/
// 可以用计数排序。然后挨个填充回去。
// 下面也是现充的思想，不过是每次选择一个字母填充，直到全部填充满。
#include<stdio.h>
int main(){
    char in[1024];
    char out[1024];
    char p='A'; // 从A到Z
    int j=0; // out数组的当前下标
    while(gets(in)) {
        memset(out,0,sizeof(out));  
        j=0;
        p='A'; // 从A开始排序。
        while(j < strlen(in)) {
            for(int i= 0; i<strlen(in); i++) {
                if((in[i]>='A' && in[i]<='Z') || (in[i]>='a' && in[i]<='z')) {
                    if(out[j] != NULL) { // 非NULL表示被当前位置已经填的是符号了
                        j++;
                        i--;
                        continue; // 回退
                    }
                    if(in[i] == p || in[i] == p+32) { // 匹配到大小写
                        out[j++] = in[i];
                    }
                } else { // 符号则直接存放到out对应位置
                    out[i] = in[i];
                }
            }
            p++;  //寻找下一个字符
        }
        printf("%s\n", out);
    }
}
/**
 * HJ8 合并表记录
 * 数据表记录包含表索引和数值（int范围的正整数），请对表索引相同的记录进行合并，即将相同
 * 索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述：
先输入键值对的个数
然后输入成对的index和value值，以空格隔开

输出描述：
输出合并后的键值对（多行）
例1
输入：
4
0 1
0 2
1 2
3 4
输出：
0 3
1 2
3 4
*/
// 思路：边排序边合并。
// 下面思路更简单：用一个数组记录所有，边输入边累加，最后只打印有数值的表格索引和值。
#include "stdio.h"
int main()
{
    int n,a,b,i=0,num[1000]={0};
    while(scanf("%d",&n)!= EOF )
    {
        for(i=0;i<n;i++)
        {
        scanf("%d %d",&a,&b);
        num[a]+=b;
        }
        for(i=0;i<n;i++)
        {
            if(num[i]==0)
                continue;
            else
                printf("%d %d\n",i,num[i]);
        }
    }
    return 0; 
}

/**
 * HJ88 扑克牌大小
 * 描述
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面
  从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则：
（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，
    不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系
    （如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；
  炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

输入描述：
输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如 4 4 4 4-joker JOKER。

输出描述：
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。

示例1
输入：
4 4 4 4-joker JOKER

输出：
joker JOKER
*/
/* 1，先判断类型（6种），类型不符则返回error.(枚举？) 
    结构体：类型 + 类型里面的典型值
    数量，5/4/3/2(可能是王炸)/1
2,每个类型做一个比较: 对王 > 炸（典型值）>其他典型值。
*/
// 下面定义了0-6：一个、对子、三个、空、顺子、炸弹、对王。把排序转化成了数值大小。
// 最后把数字10转化成了"9"+1, 是的所有比较刚好是和int值一致的
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char str[100],*a,*b;
    gets(str);
    a=strtok(str,"-");  // 第一个手牌
    b=strtok(NULL,"-"); // 第二个手牌。
    int len_a = 0,len_b = 0,i=0;
    while(*(a+i)!='\0'){
        if(*(a+i)==' '){
            len_a++;  // count pokerA's count-1
        }
        i++;
    }  
    i=0;
    while(*(b+i)!='\0'){
        if(*(b+i)==' '){
          len_b++; // count pokerB's count-1
        }
        i++;
    }  
    if(len_a==1 && strlen(a)>5){
        len_a=6;  // 两个元素，对王。 机智，单独列出来
    }else if(len_a==3){
        len_a=5; // 炸弹。
    }  
    if(len_b==1&&strlen(b)>5){
        len_b=6;  
    }else if(len_b==3){
      len_b=5;
    }
    if(len_a!=len_b&&len_a<5&&len_b<5){ //没有对王或者炸弹
        printf("ERROR\n");  // 长度不匹配
    }else if(len_a>=5&&len_b<len_a){
        printf("%s\n",a); // A是炸弹或者对王,比长度（flag)就行
    }else if(len_b>=5&&len_a<len_b){
        printf("%s\n",b);
    }else if(len_a==len_b){ // 其他都只需要比较首字母
      int x=(int)a[0],y=(int)b[0];
      if(a[0]=='1'&&a[1]=='0'){ // 只有数字10不在正常的ASCII首字母排序表里面，转化
        x='9'+1;
      }
      if(b[0]=='1'&&b[1]=='0'){
        y='9'+1;
      }
      if(x>y){
        printf("%s",a);
      }else{
        printf("%s",b);
      }
    }
    return 0;
}

/**
 * HJ71 字符串通配符
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母，数字0-9和 '.' 组成，下同）
？：匹配1个字符

注意：匹配时不区分大小写。

输入：
通配符表达式；
一组字符串。
输出：

返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

本题含有多组样例输入！
输入描述：
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

示例1
输入：
te?t*.*
txt12.xls

输出：
false

示例2
输入：
z
zz

输出：
false

示例3
输入：
pq
pppq

输出：
false

示例4
输入：
**Z
0QZz

输出：
true

示例5
输入：
?*Bc*?
abcd

输出：
true

示例6
输入：
p*p*qp**pq*p**p***ppq
pppppppqppqqppqppppqqqppqppqpqqqppqpqpppqpppqpqqqpqqp

输出：
false
 * 
*/
// 简析最后一个很难，要考虑这种不定长，每种可能不同的匹配长度。不是完全刚好的匹配的这种，是不是有miss.
// 答案里面基本是递归思路来做的。但是高分思路不是这么做的。
// 下面这个思路不是这么做的。TODO: 看起来就是正常的匹配，为什么能过？
#include<stdio.h>
#include<ctype.h>
int isCorrect(char ch){ // 是不是？可以替换的字母或数字。
    if(isdigit(ch)||isalpha(ch))return 1;
    else return 0;
}
int compare(char*tem,char*str)
{
    int i=0,j=0,tempi=0,tempj=0,flag=0;
    
    while(j<strlen(str)) {
        tem[i]=tolower(tem[i]); //不区分大小写
        str[j]=tolower(str[j]);
        
        if(tem[i]=='*'){ // 找*的匹配
            tempi=i;  //  中间变量，标记
            i++;  // i更新到*后面的字符
            flag=1;
            tempj=j;
        }else if(tem[i]==str[j]||(tem[i]=='?'&& isCorrect(str[j]))){// 一个字符的匹配
            i++;
            j++;
        } else if(flag ==1){// 匹配*中
            j=++tempj;// +1
            i=tempi;  // reset回第一个if分支
        } else
            return 0;
    }
    while(tem[i]=='*'&&tem[i]!='\0')// 第一个string还在*，且还没到尾部
        i++;
    if(tem[i]==0) // 到尾部了，*后面没有没有字符
        return 1;
    return 0;
}
int main ()
{
    char comp[500]={0};
    char str[500]={0};
    while(scanf("%s%s",&comp,&str)!=EOF)
    {
        if(compare(comp,str))
            printf("true\n");
        else
            printf("false\n");
    }
}
/**
 * HJ87 密码强度等级 -- 挨个计数并匹配规则就可以
 * 密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

一、密码长度:

5 分: 小于等于4 个字符

10 分: 5 到7 字符

25 分: 大于等于8 个字符

二、字母:

0 分: 没有字母

10 分: 全都是小（大）写字母

20 分: 大小写混合字母

三、数字:

0 分: 没有数字

10 分: 1 个数字

20 分: 大于1 个数字

四、符号:

0 分: 没有符号

10 分: 1 个符号

25 分: 大于1 个符号

五、奖励:

2 分: 字母和数字

3 分: 字母、数字和符号

5 分: 大小写字母、数字和符号

最后的评分标准:

>= 90: 非常安全

>= 80: 安全（Secure）

>= 70: 非常强

>= 60: 强（Strong）

>= 50: 一般（Average）

>= 25: 弱（Weak）

>= 0:  非常弱


对应输出为：

VERY_SECURE

SECURE,

VERY_STRONG,

STRONG,

AVERAGE,

WEAK,

VERY_WEAK,


请根据输入的密码字符串，进行安全评定。

注：

字母：a-z, A-Z

数字：-9

符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)

!"#$%&'()*+,-./     (ASCII码：x21~0x2F)

:;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)

[\]^_`              (ASCII码：x5B~0x60)

{|}~                (ASCII码：x7B~0x7E)

输入描述：
本题含有多组输入样例。
每组样例输入一个string的密码

输出描述：
每组样例输出密码等级

示例1
输入：
38$@NoNoNo
123

输出：
VERY_SECURE
WEAK

说明：
第一组样例密码强度为95分。
第二组样例密码强度为25分。
*/
#include<stdio.h>
#include<string.h>

int lenScore(char password[], int passwordLength)
{
    if (4 >= passwordLength)
        return 5;
    else if (4 < passwordLength && 8 > passwordLength)
        return 10;
    else if (8 <= passwordLength)
        return 25;
}

int alphaScore(char password[], int passwordLength)
{
    int lowercase = 0, capital = 0;
    for(int i = 0; i < passwordLength; i++)
    {
        if('a' <= password[i] && 'z' >= password[i])
            lowercase++;
        if('A' <= password[i] && 'Z' >= password[i])
            capital++;
    }
    if (0 == lowercase && 0 == capital)
        return 0;
    else if(0 < lowercase && 0 < capital)
        return 20;
    else if(0 < lowercase || 0 < capital)
        return 10;
}

int digitScore(char password[], int passwordLength)
{
    int digit = 0;
    for(int i = 0; i < passwordLength; i++)
    {
        if('0' <= password[i] && '9' >= password[i])
            digit++;
    }
    if (0 == digit)
        return 0;
    else if(1 == digit)
        return 10;
    else if (1 < digit)
        return 20;
}

int symbolScore(char password[], int passwordLength)
{
    int symbol = 0;
    for(int i = 0; i < passwordLength; i ++)
    {
        if(('!' <= password[i] && '/' >= password[i]) || (':' <= password[i] && '@' >= password[i]) || ('[' <= password[i] && '`' >= password[i]) || ('{' <= password[i] && '~' >= password[i]))
            symbol++;
    }
    if(0 == symbol)
        return 0;
    else if(1 == symbol)
        return 10;
    else if(1 < symbol)
        return 25;
}

int extraScore(char password[], int passwordLength)
{
    int alpha = alphaScore(password, passwordLength);
    int digit = digitScore(password, passwordLength);
    int symbol = symbolScore(password, passwordLength);
    
    if(10 < alpha && 0 < digit && 0 < symbol)
        return 5;
    else if(0 < alpha && 0 < digit && 0 < symbol)
        return 3;
    else if(0 < alpha && 0 < digit && 0 == symbol)
        return 2;
    else
        return 0;
}

int Score(char password[], int passwordLength)
{
    int score = lenScore(password, passwordLength) + alphaScore(password, passwordLength) + digitScore(password, passwordLength) + symbolScore(password, passwordLength) + extraScore(password, passwordLength);
    return score;
}

int main()
{
    char password[1000];
    int passwordLength;
    int score = 0;
    
    while(scanf("%s", password) != EOF)
    {
        passwordLength = strlen(password);
        score = Score(password, passwordLength);
        //printf("%d\n", score);
        //printf("passwordLength:%d, len:%d, alpha:%d, digit:%d, symbol:%d, extra:%d\r\n", passwordLength, lenScore(password, passwordLength), alphaScore(password, passwordLength), digitScore(password, passwordLength), symbolScore(password, passwordLength), extraScore(password, passwordLength));
        if(90 <= score)
        {
            printf("VERY_SECURE\n");
            continue;
        }
        else if(80 <= score)
        {
            printf("SECURE\n");
            continue;
        }
        else if(70 <= score)
        {
            printf("VERY_STRONG\n");
            continue;
        }
        else if(60 <= score)
        {
            printf("STRONG\n");
            continue;
        }
        else if(50 <= score)
        {
            printf("AVERAGE\n");
            continue;
        }
        else if(20 <= score)
        {
            printf("WEAK\n");
            continue;
        }
        else if(0 <= score)
        {
            printf("VERY_WEAK\n");
            continue;
        }
    }
    return 0;
}
/**
 * HJ96 表示数字  -- 也是苦力活
 * 将一个字符中所有的整数前后加上符号“*”，其他字符保持不变。连续的数字视为一个整数。

注意：本题有多组样例输入。
输入描述：
输入一个字符串

输出描述：
字符中所有出现的数字前后加上符号“*”，其他字符保持不变

示例1
输入：
Jkdi234klowe90a3
5151

输出：
Jkdi*234*klowe*90*a*3*
*5151*
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[1000]={0};
  while(scanf("%s",a)!=EOF)
  {
    int left=0;
    int right=0;
    int n=strlen(a);
    while(right<n)
    {
      if((a[right-1]>'9'||a[right-1]<'0')&&(a[right]>='0'&&a[right]<='9')&&(a[right+1]>'9'||a[right+1]<'0'))
      { 
        printf("*%c*",a[right]);
        right++;
        continue;
      }
      else if((a[right+1]>'9'||a[right+1]<'0')&&(a[right]>='0'&&a[right]<='9'))
      { 
        printf("%c*",a[right]);
        right++;
        continue;
    }
      else if((a[right-1]>'9'||a[right-1]<'0')&&(a[right]>='0'&&a[right]<='9'))
      { 
        printf("*%c",a[right]);
        right++;
        continue;
      }
      else
        printf("%c",a[right++]);
    }
    printf("\n");
  }
  return 0;
}
/**
 * HJ93 数组分组
 * 输入int型数组，询问该数组能否分成两组，使得两组中各元素加起来的和相等，并且，
 *  所有5的倍数必须在其中一个组中，所有3的倍数在另一个组中（不包括5的倍数），
 *  能满足以上条件，输出true；不满足时输出false。
本题含有多组样例输入。
输入描述：
第一行是数据个数，第二行是输入的数据

输出描述：
返回true或者false

示例1
输入：
4
1 5 -5 1
3
3 5 8

输出：
true
false

说明：
第一个样例：
第一组：5 -5 1
第二组：1 
第二个样例：由于3和5不能放在同一组，所以不存在一种分法。  
*/
// 思路先把3和5的倍数取出来，分成两组，分别求和，剩下的元素怎么分配？枚举每种可能？
#include<stdio.h>
#include<math.h>
int main()
{
  int num;
  while(scanf("%d",&num) != EOF)
  {
    int a[100];
    int i;
    for(i=0;i<num;i++)
    {
      scanf("%d",&a[i]);
    }
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    for(i=0;i<num;i++)
    {
        if(a[i] > 0 && a[i] % 5 == 0)// 5的倍数优先级更高
        {
          sum1 += a[i];
        }
        else if(a[i] > 0 && a[i] % 3 == 0)
        {
          sum2 += a[i];
        }
        else
        {
          sum3 += abs(a[i]);  // 可能分左右两侧，所以用绝对值
        }
    }
    // 这规律找的妙啊！总和大于差值，有实现可能。这个差值为偶数，表示这些数字可以均分？
    if(sum3 > abs(sum1-sum2) && (sum3-abs(sum1-sum2)) % 2 == 0)
    {
      printf("true\n");
    }
    else
    {
      printf("false\n");
    }
  }
}
/**
 * HJ80 整型数组合并
 * 题目标题：

将两个整型数组按照升序合并，并且过滤掉重复数组元素。
输出时相邻两数之间没有空格。
请注意本题有多组样例。

输入描述：
输入说明，按下列顺序输入：
1 输入第一个数组的个数
2 输入第一个数组的数值
3 输入第二个数组的个数
4 输入第二个数组的数值

输出描述：
输出合并之后的数组

示例1
输入：
3
1 2 5
4
-1 0 3 2

输出：
-101235
*/
// 直接大数组排序后输出。可以边输入边排序边插入
#include <stdio.h>

int main()
{
    int m;
    int num[1000];
    while(scanf("%d",&m) != EOF)
    {
        for(int i = 0;i < m;i++)
        {
            scanf("%d",&num[i]);
        }
        int n;
        int tmp;
        scanf("%d",&n);
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&num[m+j]);
        }
        // 冒泡排序
        for(int i = 0;i < m + n -1;i++)
        {
            for(int j = 0;j < m + n -1 - i;j++)
            {
                if(num[j] > num[j+1])
                {
                    tmp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmp;
                }
            }
        }
        printf("%d",num[0]);
        // 打印,重复的不打印,省去了查重去重的麻烦
        for(int i = 1;i < m + n;i++)
        {
            if(num[i] != num[i-1])
            {
                printf("%d",num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
/**
 * 
 * 
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
  char str[100];
  int i=0,count,sum;
  while(gets(str))//用于多次输入
  {
    count=strlen(str);//计算字符串的长度
    sum=0;
    for(i=count-1;i>=0;i--)//从十六进制个位开始，每位都转换成十进制
    {
      if(str[i]>='0'&&str[i]<='9')//数字字符的转换
      {
        sum+=(str[i]-48)*pow(16,count-i-1); //count-i-1表示的是第几位
      }
      else if(str[i]>='A'&&str[i]<='F')//字母字符的转换
      {
        sum+=(str[i]-55)*pow(16,count-i-1);
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}
/**
 * HJ58 输入n个整数，输出其中最小的k个
 * 输入n个整数，输出其中最小的k个。

本题有多组输入样例，请使用循环读入，比如while(cin>>)等方式处理
输入描述：
第一行输入两个整数n和k
第二行输入一个整数数组

输出描述：
输出一个从小到大排序的整数数组

示例1
输入：
5 2
1 3 5 7 2

输出：
1 2
*/
// 直接排序，然后输出就行了
#include "stdio.h"
int main(){
    int x,y;
    while (scanf("%d %d",&x,&y)!=EOF)  {
        int tmp[x];        
        scanf("%d",&tmp[0]);
        for (int i=1;i<x;i++)
        {
            scanf("%d",&tmp[i]);
            for (int j=i;j>0;j--)
            {
                if (tmp[j] < tmp[j-1])
                {
                    int tmp1 = tmp[j];
                    tmp[j] = tmp[j-1];
                    tmp[j-1] = tmp1;
                }
                else
                {
                    break;
                }
            }
        }
        for (int k=0;k<y;k++)
        {
            printf("%d ",tmp[k]);
        }
        printf("\n");
    }
    return 0;
}
/**
 * HJ23 删除字符串中出现次数最少的字符
 * 实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
注意每个输入文件有多组输入，即多个字符串用回车隔开
输入描述：
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。

输出描述：
删除字符串中出现次数最少的字符后的字符串。

示例1
输入：
abcdd
aabcddd

输出：
dd
aaddd
*/
// 计数、统计、删除
#include <stdio.h>
#include <string.h>
int main()
{
    char str[21];
    while(scanf("%s",&str) != EOF){
        int min = 20;
        int num[128] = {0};
        for(int i=0; i<strlen(str); i++){
            num[str[i]]++;
        }
        for(int i=0; i<128; i++){
            if(num[i] != 0 && num[i] < min){
                min = num[i];
            }
        }
        for(int i=0; i<strlen(str); i++){
            if(num[str[i]] != min){
                printf("%c",str[i]);
            }
        }
        printf("\n");
        
    }
    return 0;
}

/**
 * HJ59 找出字符串中第一个只出现一次的字符
 * 找出字符串中第一个只出现一次的字符
输入描述：
输入几个非空字符串

输出描述：
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入：
asdfasdfo
aabb
输出：
o
-1
*/
// 统计，删除
#include<stdio.h>
#include<string.h>
int main()
{
  char str[256]={0};
  while( scanf("%s",str) != EOF)
  {
    int a[256]={0};
    int len = strlen(str);
    for(int i = 0;i < len;i++)
    {
      a[str[i]]++;
    }
    for(int i = 0;i < len;i++)
    {
      if(a[str[i]] == 1)
      {
        printf("%c\n", str[i]);
        break;
      }
      if(i == (len-1))
        printf("-1\n");
    }
  }
  return 0;
}
/**
 * HJ1 字符串最后一个单词的长度
 * 描述
计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。

输入描述：
输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。

示例1
输入：
hello nowcoder

输出：
8

说明：
最后一个单词为nowcoder，长度为8
*/
// 常规思路：strtok挨个去找。
// 下面的优化:输入是自己处理的，可以边处理输入，边标记长度。
#include <stdio.h>

int main()
{
    char  str;
    short int x = -1, i = 0;
    while (scanf("%c", &str) != EOF)
    {

        if (str == ' ')
            x = i;
        i++;
    }
    x=i - x - 2;
    printf("%d", x);
    return 0;
}
/**
 * HJ33 整数与IP地址间的转换
 * 描述
原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001

组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。

本题含有多组输入用例，每组用例需要你将一个ip地址转换为整数、将一个整数转换为ip地址。



输入描述：
输入 
1 输入IP地址
2 输入10进制型的IP地址

输出描述：
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址

示例1
输入：
10.0.3.193
167969729

输出：
167773121
10.3.3.193
*/
// 按照移位等操作。
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(){
    char str_ip[50];
    uint8_t arr_ip[4];
    uint32_t int_ip;
    while(scanf("%s %d", str_ip, &int_ip) == 2){
        for(int i = 0, j = 0; i < strlen(str_ip); i++){
            if(i == 0){
                arr_ip[j] = (uint8_t)atoi(str_ip);
                j++;
            }else{
                if(str_ip[i] == '.'){
                    arr_ip[j] = (uint8_t)atoi(str_ip + i + 1);
                    j++;
                }
            }
        }
        printf("%u\n", (int)(arr_ip[0] << 24) + (int)(arr_ip[1] << 16) + (int)(arr_ip[2] << 8) + (int)arr_ip[3]);
        
        for(int i = 0; i < 4; i++){
            arr_ip[i] = (uint8_t)(int_ip >> ((3 - i) * 8));
        }
        printf("%d.%d.%d.%d\n", arr_ip[0], arr_ip[1], arr_ip[2], arr_ip[3]);
    }
}
/**
 * HJ102 字符统计
 * 输入一个只包含小写英文字母和数字的字符串，按照不同字符统计个数由多到少输出统计结果，
 *  如果统计的个数相同，则按照ASCII码由小到大排序输出。
本题含有多组样例输入

输入描述：
一个只包含小写英文字母和数字的字符串。

输出描述：
一个字符串，为不同字母出现次数的降序表示。若出现次数相同，则按ASCII码的升序输出。

示例1
输入：
aaddccdc
1b1bbbbbbbbb

输出：
cda
b1

说明：
第一个样例里，c和d出现3次，a出现2次，但c的ASCII码比d小，所以先输出c，再输出d，最后输出a.
*/
// 先统计，再输出
#include <stdio.h>
#include <string.h>
typedef struct
{
	int num;
	int ch;
}data;
void swap(data *a, data *b)
{
	data tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	char src[5000];
	data ch[128];
	int i = 0;
	int len = 0;
	int k = 0;

	while (scanf("%s", src) != EOF) {
		memset(ch, 0, 128 * sizeof(data));
		for (i = 0; i<128; i++) {
			ch[i].ch = i;
		}
		len = strlen(src);
		
		for (i = 0; i<len; i++) {
			ch[src[i]].num++;
		}

		for (i = 0; i<128; i++) {
			for (k = 127; k>i; k--) {
				if (ch[k].num>ch[k - 1].num)
					swap(&ch[k], &ch[k - 1]);
			}
		}
		for (i = 0; i<128; i++) {
			if (ch[i].num == 0) {
				printf("\n");
				break;
			}
				
			printf("%c", ch[i].ch);
		}
	}
	return 0;
}
/**
 * HJ81 字符串字符匹配
 * 判断短字符串中的所有字符是否在长字符串中全部出现。
请注意本题有多组样例输入。

输入描述：
输入两个字符串。第一个为短字符串，第二个为长字符串。两个字符串均由小写字母组成。

输出描述：
如果短字符串的所有字符均在长字符串中出现过，则输出true。否则输出false。

示例1
输入：
bc
abc
输出：
true
*/
//  分别统计一下两个字符串中出现过的所有字母，然后比较
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	char s[123]={0}, l[123]={0}, ch;
	for( ; (ch=getchar())!=EOF; ){
		s[ch]=1;
		for( ; (ch=getchar())!='\n'; )
			s[ch]=1;
			
		for( ; (ch=getchar())!='\n'; )
			l[ch]=1;
			
		for(i=97; i<123; i++)
			if(s[i])
				if(!l[i]) break;
		if(i<123) printf("false\n");
		else printf("true\n");
		// Reset, for multiple input
		memset(s+97, 0, 26);
		memset(l+97, 0, 26);
	}
	return 0;
}
/**
 * HJ64 MP3光标位置
 * MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键
 *  才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。

现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：

歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。

光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。

其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。

2. 歌曲总数大于4的时候（以一共有10首歌为例）：

特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，
  屏幕要显示最后一页（即显示第7-10首歌），同时光标放到最后一首歌上。同样的，屏幕显示
  最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。

一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，屏幕从
  当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似。

其他情况，不用翻页，只是挪动光标就行。

输入描述：
输入说明：
1 输入歌曲数量
2 输入命令 U或者D

本题含有多组输入数据！

输出描述：
输出说明
1 输出当前列表
2 输出当前选中歌曲

示例1
输入：
10
UUUU

输出：
7 8 9 10
7
*/
// 队列结构.两个移动方向，两个特殊点（首尾），两个特殊位置（最上、最下）
#include<stdio.h>
typedef struct{
  int currDisp[4];
  int cursor;
  int total;
}MP3; // 正好是要打印的资料
void Init(MP3* mp3, int n){
  mp3->cursor = 1;
  mp3->total = n;
  if (n < 4){ // 只初始已经有的部分
    for (int i = 0; i < n; i++){
      mp3->currDisp[i] = i + 1;
    }
    return;
  }
  for (int i = 0; i < 4; i++){
    mp3->currDisp[i] = i + 1;
  }
}
void up(MP3* mp3){  // 用指针来修改
  if (mp3->total <= 4){// 不动界面，只动cursor
    if (mp3->cursor == 1){
      mp3->cursor = mp3->total;
    }
    else {
      mp3->cursor--;
    }
    return;
  }
  if (mp3->cursor == 1){//要切换整个界面
    mp3->cursor = mp3->total;
    for (int i = 0; i < 4; i++){
      mp3->currDisp[i] = mp3->total - 3 + i;
    }
  } else {
      if (mp3->cursor == mp3->currDisp[0]){//只把界面向上移动
          for (int i = 0; i < 4; i++){
              mp3->currDisp[i]--;
          }
          mp3->cursor = mp3->currDisp[0];
      }
      else {
          mp3->cursor--;
      }
  }
}
void down(MP3* mp3){
    if (mp3->total <= 4){
        if (mp3->cursor == mp3->total){
            mp3->cursor = 1;
        }
        else {
            mp3->cursor++;
        }
        return;
    }
    if (mp3->cursor == mp3->total){
        mp3->cursor = 1;
        for (int i = 0; i < 4; i++){
            mp3->currDisp[i] = i + 1;
        }
    }
    else {
        if (mp3->cursor == mp3->currDisp[3]){
            for (int i = 0; i < 4; i++){
                mp3->currDisp[i]++;
            }
            mp3->cursor = mp3->currDisp[3];
        }
        else {
            mp3->cursor++;
        }
    }
}
int main(){
  MP3* mp3;
  int n;
  char order[100];
  while (scanf("%d", &n) != EOF){
    while (getchar() != '\n');
    gets(order);
    mp3 = (MP3*)malloc(sizeof(MP3));
    Init(mp3, n);
    for (int i = 0; order[i] != '\0'; i++){
      if (order[i] == 'U'){
        up(mp3);
      }
      else {
        down(mp3);
      }
    }
    if (mp3->total < 4){
      for (int i = 0; i < mp3->total; i++){
      printf("%d ", mp3->currDisp[i]);
      }
    }
    else {
      for (int i = 0; i < 4; i++){
        printf("%d ", mp3->currDisp[i]);
      }
    }
    printf("\n%d\n", mp3->cursor);
    free(mp3);
  }
  return 0;
}

/**
 * HJ2 计算某字母出现次数
 * 描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字母，然后输出输入字符串中该字母的出现次数。不区分大小写，字符串长度小于500。

输入描述：
第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字母。

输出描述：
输出输入字符串中含有该字符的个数。

示例1
输入：
ABCabc
A

输出：
2
*/
// 大小写转换，字符统计
#include<stdio.h>
#include<string.h>

int main(void)
{
    char* s[100] = {0};//s是一个字符指针数组，包含100个char类型的指针。同时还有指针数组的初始化。
    char* p = s;//p是指向指针数组的指针
    char input = {0};//定义一个字符变量，并初始化
    int i = 0;
    int j = 0;
    
    gets(s);//这个是获取一行所有的字符，在遇到换行符后返回所有的字符。
    scanf("%c", &input);//获取一个字符，注意scanf获取的停止标志是EOF///这里犯了错，字符应该是%c而不是%d，除了字符串都要&
    
    while (p[i] != '\0')
    {
        if (tolower(p[i]) == tolower(input))//tolower是将字母转换为小写字母的函数
        {
            j++;
        }
        i++;
    }
    printf("%d", j);
    return 0;
}
/**
 * HJ42 学英语
 * Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：

如22：twenty two，123：one hundred and twenty three。


说明：

数字为正整数，长度不超过九位，不考虑小数，转化结果为英文小写；

输出格式为twenty two；

非法数据请返回“error”；

关键字提示：and，billion，million，thousand，hundred。


本题含有多组输入数据。


输入描述：
输入一个long型整数

输出描述：
输出相应的英文写法

示例1
输入：
2356

输出：
two thousand three hundred and fifty six
*/
// 主要就是先把数字分组，然后对应字符匹配
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
void calc(unsigned int n, int *a)
{
  a[0]=n/(1000*1000*1000);//存放billion
  a[1]=(n/(1000*1000))%1000;//存放million
  a[2]=(n/1000)%1000;//存放thousand
  a[3]=n%1000;//存放1000以下的数
  //printf("%u %d %d %d %d\n", n, a[0], a[1], a[2], a[3]);
}
  
void print(int a)
{
    char *x[]={"", "one", "two", "three",
              "four", "five", "six",
              "seven", "eight", "nine",
              "ten", "eleven", "twelve",
              "thirteen", "fourteen", "fifteen",
              "sixteen", "seventeen", "eighteen",
              "nineteen"};
    char *y[]={"", "", "twenty", "thirty",
              "forty", "fifty", "sixty", "seventy",
              "eighty", "ninety"};
    unsigned flag=0;
    if(a>=100)//如果a大于100则输出响应的几百
    {
        printf("%s hundred", x[a/100]);
        flag=1;//百位以上打印标志位置位
    }
    a%=100;//得到十位数
    if(a>=20)//如果大于20
    {
        if(flag)//如果百位已打印
        {
            printf(" and ");//打印and
        }
        printf("%s", y[a/10]);//打印几十
        a%=10;//得到个位数
        if(a>0)//如果大于0
        {
            printf(" %s", x[a]);//打印数值
        }
    }
    else if(a>0)//如果小于20但大于零
    {
        if(flag)//如果百位已打印
        {
            printf(" and ");//打印and
        }
        printf("%s", x[a]);//打印0~19的数
    }
}
  
int main()
{
    unsigned int n;
    while(scanf("%u", &n)!=EOF)//输入数字
    {
        unsigned flag=0;
        int d[4]={0};
        calc(n ,d);
        if(d[0]!=0)//如果十亿位数字不为0
        {
            print(d[0]);//打印十亿位数值
            printf(" billion");//打印百万
            flag=1;
        }
        if(d[1]!=0)//如果百万位不为0
        {
            if(flag)//如果十亿位数字已打印
            {
                printf(" ");//打印空格
            }
            print(d[1]);//打印百万位
            printf(" million");
            flag=1;
        }
        if(d[2]!=0)
        {
            if(flag)
            {
                printf(" ");
            }
            print(d[2]);
            printf(" thousand");
            flag=1;
        }
        if(d[3]!=0)
        {
            if(flag)
            {
                printf(" ");
            }
            print(d[3]);
        }
        printf("\n");
    }
    return 0;
}
/**
 * HJ92 在字符串中找出连续最长的数字串
 * 输入一个字符串，返回其最长的数字子串，以及其长度。若有多个最长的数字子串，则将它们全部输出（按原字符串的相对位置）
本题含有多组样例输入。

输入描述：
输入一个字符串。

输出描述：
输出字符串中最长的数字字符串和它的长度，中间用逗号间隔。如果有相同长度的串，则要一块儿输出（中间不要输出空格）。

示例1
输入：
abcd12345ed125ss123058789
a8a72a6a5yy98y65ee1r2

输出：
123058789,9
729865,2
*/
// 统计数字，标记头地址、指针，然后输出
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[1000]={'\0'};
    while(scanf("%s",str) != EOF)
    {
        int len=strlen(str);
        int num=0,max=0;
        int arr[100]={0};
        int brr[100]={0};
        int k=0;
        int ii=0;
        for(ii=0;ii<len;ii++)
        {
            if(str[ii]>='0'&&str[ii]<='9')
                num++;
            else
            {
                if(num>=max && num>0)
                {
                    max=num;
                    arr[k]=ii-max;
                    brr[k]=max;
                    k++;
                }
                num = 0;
            }
        }
        if(num)
        {
            if(num>=max)
            {
                max=num;
                arr[k]=ii-max;
                brr[k]=max;
                k++;
            }
        }
        if(max==0)
        {
            printf("\n");
            continue;
        }
        int flag=0;
        for(int i=0;i<k;i++)
        {
            if(brr[i]==max)
            {
                for(int j=arr[i];j<arr[i]+max;j++)
                    printf("%c",str[j]);
            }
             
        }
        printf(",%d\n",max);
    }
    return 0;
}

/**
 * HJ107 求解立方根
 * 计算一个数字的立方根，不使用库函数。
保留一位小数。

输入描述：
待求解参数，为double类型（一个实数）

输出描述：
输入参数的立方根。保留一位小数。

示例1
输入：
216

输出：
6.0
*/
// double 输入的scanf格式"lf"
// 不用库函数就用乘法计算喽，找到匹配或者最接近的。
#include<stdio.h>
#include<string.h>

int main(){
    double num;
    while(scanf("%lf",&num) != EOF){
        double a=0;
        int flag=0;
        if(num>=0){ // 标记符号位
            flag=1;
        }
        else{
            flag=-1;
        }
        while(a*a*a<(num*flag)){
            a=a+0.04; // 为什么以0.04为步长？刚好都是在5的两边？
        }
        printf("%.1f\n",a*flag);
    }
}

/**
 * HJ83 二维数组操作
 * 有一个大小的数据表，你会依次进行以下5种操作：
1.输入和，初始化大小的表格。
2.输入x_1x ​
 、y_1y 
1
​
 、x_2x 
2
​
 、y_2y 
2
​
 ，交换坐标在(x_1,y_1)(x 
1
​
 ,y 
1
​
 )和(x_2,y_2)(x 
2
​
 ,y 
2
​
 )的两个数。
3.输入，在第行上方添加一行。
4.输入，在第列左边添加一列。
5.输入、，查找坐标为的单元格的值。
请编写程序，判断对表格的各种操作是否合法。

详细要求:

1.数据表的最大规格为9行*9列，对表格进行操作时遇到超出规格应该返回错误。
2.对于插入操作，如果插入后行数或列数超过9了则应返回错误。如果插入成功了则将数据表恢复至初始化的大小，多出的数据则应舍弃。
3.所有输入坐标操作，对大小的表格，行号坐标只允许0~m-1，列号坐标只允许0~n-1。超出范围应该返回错误。

本题含有多组样例输入！
输入描述：
输入数据按下列顺序输入：
1 表格的行列值
2 要交换的两个单元格的行列值
3 输入要插入的行的数值
4 输入要插入的列的数值
5 输入要查询的单元格的坐标

输出描述：
输出按下列顺序输出：
1 初始化表格是否成功，若成功则返回0， 否则返回-1
2 输出交换单元格是否成功
3 输出插入行是否成功
4 输出插入列是否成功
5 输出查询单元格数据是否成功

示例1
输入：
4 9
5 1 2 6
0
8
2 3
4 7
4 2 3 2
3
3
4 7

输出：
0
-1
0
-1
0
0
-1
0
0
-1

说明：
本组样例共有2组样例输入。
第一组样例：
1.初始化数据表为4行9列，成功
2.交换第5行1列和第2行6列的数据，失败。因为行的范围应该是(0,3)，不存在第5行。
3.在第0行上方添加一行，成功。
4.在第8列左边添加一列，失败。因为列的总数已经达到了9的上限。
5.查询第2行第3列的值，成功。
第二组样例：
1.初始化数据表为4行7列，成功
2.交换第4行2列和第3行2列的数据，失败。因为行的范围应该是(0,3)，不存在第4行。
3.在第3行上方添加一行，成功。
4.在第3列左边添加一列，成功。
5.查询第4行7列的值，失败。因为虽然添加了一行一列，但数据表会在添加后恢复成4行7列的形态，
  所以行的区间仍然在[0,3]，列的区间仍然在[0,6]，无法查询到(4,7)坐标。   
*/
// 苦力活。数组里面没有真实数据，所以其实只是规则判断。
#include <stdio.h>
int main()
{
    int a[9][9];
    int m,n;
    while(scanf("%d %d\n",&m,&n)!=EOF)
    {
        if(m>0&&m<=9&&n>0&&n<=9)
        {
            printf("0\n");
            int a,b,c,d;
            scanf("%d %d %d %d\n",&a,&b,&c,&d);
                if(a>=0&&a<m&&b>=0&&b<n
                   &&c>=0&&c<m&&d>=0&&d<n)
                    printf("0\n");
            else
                printf("-1\n");
            int e,f;
            scanf("%d\n",&e);
            if(e<m)
                printf("0\n");
            else
                printf("-1\n");
            scanf("%d\n",&f);
            if(f<n)
                printf("0\n");
            else
                printf("-1\n");
            scanf("%d %d\n",&a,&b);
            if(a>=0&&a<m&&b>=0&&b<n
                   )
                    printf("0\n");
            else
                printf("-1\n");
        }
        else 
        {
            printf("-1\n");
        }
    }
}
/**
 * HJ95 人民币转换
 * 描述
考试题目和要点：

1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。

2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。

3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如6007.14，应写成“人民币陆仟零柒元壹角肆分“。
4、10应写作“拾”，100应写作“壹佰”。例如，1010.00应写作“人民币壹仟零拾元整”，110.00应写作“人民币壹佰拾元整”
5、十万以上的数字接千不用加“零”，例如，30105000.00应写作“人民币叁仟零拾万伍仟元整”

本题含有多组样例输入。

输入描述：
输入一个double数

输出描述：
输出人民币格式

示例1
输入：
151121.15
10012.02

输出：
人民币拾伍万壹仟壹佰贰拾壹元壹角伍分
人民币壹万零拾贰元贰分
*/
// 同上数字转换，主要是分开匹配
#include <stdio.h>
#include <string.h>
char Big_Ch_Num[][4] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖", "拾" };
char section_unit[][4] = {
  "", "拾", "佰", "仟", 
"万", "拾", "佰", "仟", 
"亿", "拾", "佰", "仟", 
"兆", "拾", "佰", "仟", 
"京", "拾", "佰", "仟", 
"垓", "拾", "佰", "仟", 
"秭", "拾", "佰", "仟", 
"穰", "拾", "佰", "仟", 
"沟", "拾", "佰", "仟", 
"涧", "拾", "佰", "仟", 
"正", "拾", "佰", "仟", 
"载", "拾", "佰", "仟"
};
int main(void)
{
	char i, j, k, ch, s[128], len, zero_cnt, jiao, fen;
	for( ; scanf("%s", s)!=EOF; ){
		printf("人民币");
		len = strlen(s);
		for(i=len-1; i>=0; i--)
			if(s[i] == '.') break;
		jiao = fen = 0;
		if(i == -1) j=len-1;
		else{
			j=i-1;   i++;
			if(i < len){
				jiao = s[i++]-48;
				if(i < len) fen = s[i]-48;
			}
		}
		i=zero_cnt=0;   k=j;
		for( ; k>=0; i++,k--){
			if((ch=s[i]) != '0'){
				if(zero_cnt){ printf("零");   zero_cnt=0; }
				if(ch!='1' || k%4!=1) printf("%s", Big_Ch_Num[ ch-48 ]);
				printf("%s", section_unit[ k ]);
				continue;
			}
			zero_cnt++;
			if(k%4) continue;
			if(zero_cnt != 4) printf("%s", section_unit[ k ]);
			zero_cnt = 0;
		}
		if(j || s[j]!='0') printf("元");
		else{
			if(jiao+fen) goto rpt;
			printf("零元整\n");   continue;
		}
		if(jiao+fen){
rpt:		if(jiao) printf("%s角", Big_Ch_Num[ jiao ]);
			fen ? printf("%s分\n", Big_Ch_Num[ fen ]) : printf("\n");
		}
		else printf("整\n");
	}
	return 0;
}

/**
 * HJ103 Redraiment的走法
 * Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从
 *  低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

本题含有多组样例输入
输入描述：
输入多组数据，1组有2行，第1行先输入数组的个数，第2行再输入梅花桩的高度

输出描述：
一组输出一个结果

示例1
输入：
6
2 5 1 5 4 5 
3
3 2 1

输出：
3
1

说明：
6个点的高度各为 2 5 1 5 4 5
如从第1格开始走,最多为3步, 2 4 5
从第2格开始走,最多只有1步,5
而从第3格开始走最多有3步,1 4 5
从第5格开始走最多有2步,4 5
所以这个结果是3。   
*/
// 从头开始数，后面按顺序比他大的数的最多次数。只能按照次序。
// 需要做一个动态的变化，相当于树结构。
// 优化，预处理，反向，后面有几个数字是连续比他大的。最终找结果最大的值就可以。
// 下面的方法：有一点点类似,不过是从前往后,每次找他前面的能连续的比它小的数的个数.
#include <stdio.h>
#include <string.h>
int main(void)
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int arr[n];
    int dp[n], max = 0;
    for(int  i = 0;i < n;i++)
    {
      scanf("%d",  &arr[i]);
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;  // 表示这个位置之前的，比他小的数的个数
    for(int i = 1;i < n;i++)
    {
      for(int j = 0;j < i;j++)
      {
        if(arr[i] > arr[j] && dp[j]+1 > dp[i])
        {
          dp[i] = dp[j]+1;
        }else
        {
          if(!dp[i])
              dp[i] = 1;
        }
      }
      if(max < dp[i])
        max = dp[i];
    }
    printf("%d\n", max);
  }
  return 0;
}
/**
 * HJ22 汽水瓶
 * 有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，
 *  她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，
 *  喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借
 *  给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个
 *  空汽水瓶，最多可以换多少瓶汽水喝？
输入描述：
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张
  手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。

输出描述：
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

示例1
输入：
3
10
81
0

输出：
1
5
40
*/
// 递归，大于等于3， 则计算除以3的商，累加传入下一组，直到小于3， 如果是2，则最后再加1
int getValid(int number)
{
  int x=0;
  int y=0;
  int rtn=0;
  
  if(number == 1){
    return 0;
  } else if(number == 2){
    return 1;
  } else {
    x=number%3;
    y=number/3;
    rtn = y;
    rtn += getValid(x+y);
    return rtn;
  }
}
void main (void)
{
  int num,result=0;
  while(scanf("%d",&num)&&(num!=0))
  {
    result = getValid(num);
    printf("%d\n",result); 
  }
}
/**
 * HJ32 密码截取
 * Catcher是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，
 *  ABA，A，123321，但是他们有时会在开始或结束时加入一些无关的字符以防止别国破解。比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。因为截获的串太长了，而且存在多种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，他只能向电脑高手求助，你能帮Catcher找出最长的有效密码串吗？

本题含有多组样例输入。

输入描述：
输入一个字符串

输出描述：
返回有效密码串的最大长度

示例1
输入：
ABBA
输出：
4
*/
// 最大回文字符串问题
#include<stdio.h>
#include<string.h>
int max_len(char* str, int step)
{
    //printf("%s",str);
    int len = strlen(str);
    int left = 0;
    int right = 0;
    int max = 0;
    for(int i = 0; i < len; i++)
    {
        left = i;
        right = left + step;
        while(str[left] == str[right] && left >= 0 && right < len)
        {
            left--;
            right++;
        }
        max = max > (right - left -1) ? max : (right - left - 1);
    }
    return max;
}
int main(void)
{
    char str[10000] = {0};
    while(scanf("%s",str) != EOF)
    {
        int len1 = 0;
        int len2 = 0;
        len1 = max_len(&str, 1);
        len2 = max_len(&str, 2);
        int max = len1 > len2 ? len1 : len2;
        printf("%d\n",max);
    }
}
/**
 * HJ94 记票统计
 * 描述
请实现一个计票统计系统。你会收到很多投票，其中有合法的也有不合法的，请统计每个候选人得票的数量以及不合法的票数。
本题有多组样例输入。
输入描述：
输入候选人的人数n，第二行输入n个候选人的名字（均为大写字母的字符串），第三行输入投票人的人数，第四行输入投票。

输出描述：
按照输入的顺序，每行输出候选人的名字和得票数量，最后一行输出不合法的票数。

示例1
输入：
4
A B C D
8
A D E CF A GG A B

输出：
A : 3
B : 1
C : 0
D : 1
Invalid : 3
*/
// 先标记这些input，名字可能不止一个字母，然后对所有数据统计(需要对string分割)，然后
// 比对，统计，输出。
#include<stdio.h>
#include<malloc.h>
#include<string.h>
 
#define maxlenname 12
 
int main()
{
    int i, j, k;
    int numpeople, numvotepeople;
    int totcount, Invalid;
    char *name[100], *vote[100];
    char *point, *point1;
    char str[maxlenname], str1[maxlenname];
    int *count;
    
    while(scanf("%d",&numpeople)!= EOF)
    {
        scanf("%d",&numpeople);
        for(i=0;i<numpeople;i++)
        {
            name[i] = (char *)malloc(maxlenname*sizeof(char));
        }
         
        count = (int *)malloc((numpeople)*sizeof(int));
        *count = 0;
       // for(i=0;i<numpeople+1;i++)
      //  {
      //     printf("d=%d",count[i]);
      //  }
         
        for(i=0;i<numpeople;i++)
        {
           scanf("%s",&str);
           strcpy(name[i], str);
        }
        //printf("numpeople=%d \n",numpeople);
        //for(i=0;i<numpeople;i++)
        //{
        //   printf("%s \n",name[i]);
        //}
         
        scanf("%d", &numvotepeople);
       // printf("numvotepeople=%d \n",numvotepeople);
         
        for(i=0;i<numvotepeople;i++)
        {
            vote[i] = (char *)malloc(maxlenname*sizeof(char));
        }
        for(i=0;i<numvotepeople;i++)
        {
           scanf("%s",&str1);
           strcpy(vote[i], str1);
        }
       // for(i=0;i<numvotepeople;i++)
       // {
       //    printf("%s \n",vote[i]);
       // }
       // printf("olp %d \n", numvotepeople );
        for(i=0;i<numvotepeople;i++)
        {
            //printf("olp11 \n");
           for(j=0;j<numpeople;j++)
            {
               //printf("str=%s %s",name[j],vote[i]);
              if( strcmp(name[j],vote[i]) == 0 )
              {
                count[j]++;
                //printf("str1=%s : %d \n",name[j],count[j]);
                break;
              }
            }
            //printf("olp66 \n");
        }
      
      totcount = 0;
      for(i=0;i<numpeople;i++)
      {
        totcount = totcount + count[i];
      }
        Invalid = numvotepeople - totcount;
        for(i=0;i<numpeople;i++)
        {
            printf("%s : %d \n",name[i],count[i]);
        }
        printf("Invalid : %d \n", Invalid);
    }
    
    return 0;
}
/**
 * HJ6 质数因子
 * 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）

最后一个数后面也要有空格

输入描述：
输入一个long型整数

输出描述：
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。

示例1
输入：
180

输出：
2 2 3 3 5
*/
// 首先找出比他小的所有质数。然后从小到大做除法，商继续做，直到1
// 优化，下面这个比较好，从小到大直接除，已经保证了非质数肯定不能被整除的情况。
// 因为比他小的质数都已经验过了。
#include <stdio.h>
int main(void){
    int n;
    while(scanf("%d", &n) == 1){
        int tmp = n;
        for(int i = 2; i * i <= tmp && n >= i; i++){
            while(n % i == 0){
                printf("%d ", i);
                n /= i;
            }
        }
        if(n - 1) printf("%d ", n);
        putchar('\n');
    }
    return 0;
}
/**
 * HJ101 输入整型数组和排序标识，对其元素按照升序或降序进行排序
 * 输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据）

本题有多组输入，请使用while(cin>>)处理

输入描述：
第一行输入数组元素个数
第二行输入待排序的数组，每个数用空格隔开
第三行输入一个整数0或1。0代表升序排序，1代表降序排序

输出描述：
输出排好序的数字

示例1
输入：
8
1 2 4 9 3 55 64 25
0
5
1 2 3 4 5
1
输出：
1 2 3 4 9 25 55 64
5 4 3 2 1
*/
// 根据第三个输入的元素进行序列选择
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void QuickSort(int *data, int start, int end, int isDis)
{
    int i = start;
    int j = end;
    int target = data[i];
    int sa = isDis == 0 ? 1 : -1;

    if (i >= j) {
        return;
    }
    while (i < j) {
        /* 从右往左找值 */
        /* 升序data[j] - target > 0   降序 target - data[j] > 0*/
        while ((i < j) && ((data[j] - target) * sa > 0)) {
            j--;
        }
        if (i < j) {
            data[i++] = data[j];
        }
        
        /* 从左往右找值 */
        while ((i < j) && ((data[i] - target) * sa) < 0) {
            i++;
        }
        if (i < j) {
            data[j--] = data[i];
        }
    }
    data[i] = target;
    QuickSort(data, start, i - 1, isDis);
    QuickSort(data, j + 1, end, isDis);
}
int main(int argc, const char *argv[])
{
    int num, isDis, i;
    int *data = NULL;

    while (scanf("%d", &num) != EOF) {
        if (num <= 0) {
            printf("input error.\n");
            return -1;
        }
        data = (int *)malloc(sizeof(int) * num);
        if (data == NULL) {
            printf("malloc data fail.\n");
            return -1;
        }
        memset(data, 0, sizeof(int) * num);
        for (i = 0; i < num; i++) {
            scanf("%d", &data[i]);
        }
        scanf("%d", &isDis);
        QuickSort(data, 0, num - 1, isDis);
        for (i = 0; i < num; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        free(data);
        data = NULL;
    }
    return 0;
}
/**
 * HJ30 字符串合并处理
 * 按照指定规则对输入的字符串进行处理。

详细描述：

将输入的两个字符串合并。

对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。
这里的下标意思是字符在字符串中的位置。

对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，则对他们所代表的
  16进制的数进行BIT倒序的操作，并转换为相应的大写字符。如字符为‘4’，为0100b，则翻转后
  为0010b，也就是2。转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。
  转换后的字符为大写‘E’。


举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，分别对“dca”和“efb”进行排序，排序后为“abcedf”，转换后为“5D37BF”

注意本题含有多组样例输入


输入描述：
本题含有多组样例输入。每组样例输入两个字符串，用空格隔开。

输出描述：
输出转化后的结果。每组样例输出一行。

示例1
输入：
dec fab

输出：
5D37BF
*/
// 过程比较复杂，字符中前后颠倒的操作比较麻烦。
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100


int char_cmp(const void* _a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return *a-*b;
}

char turn_bit(int x)
{
    int i=0; int tmp=0; char ret=0;
    for(i=0;i<4;i++)
    {
        tmp=tmp+((x>>i)&1)*pow(2,3-i);
    }
    if(tmp>=0&&tmp<=9)
    {
        tmp=tmp+'0';
        ret=(char)tmp;
        return ret;
    }
    else if(tmp>=10&&tmp<=15)
    {
        tmp=tmp-10+'A';
        ret=(char)tmp;
        return ret;
    }
    ret=(char)x;
    return ret;
}

int main()
{
    char str1[2*MAX]={0};
    char str2[MAX]={0};
    char tmp_str1[MAX]={0};
    char tmp_str2[MAX]={0};
    int tmp=0;int i=0;
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        //合并字符串 -- 用函数来实现
        strcat(str1,str2);
        //字符串分奇偶
        int len=strlen(str1);
        tmp_str1[0]=str1[0];
        int j=0;int k=0;
        for(i=1;i<len;i++)
        {
            if(i%2==0)
            {
                tmp_str1[++j]=str1[i];
            }
            else
            {
                tmp_str2[k++]=str1[i];
            }
        }
        //奇偶字符串排序
        qsort(tmp_str1,j+1,sizeof(char),char_cmp);
        qsort(tmp_str2,k,sizeof(char),char_cmp);
        //还原回去
        str1[0]=tmp_str1[0];
        j=0;k=0;
        for(i=1;i<len;i++)
        {
            if(i%2==0)
            {
                str1[i]=tmp_str1[++j];
            }
            else
            {
                str1[i]=tmp_str2[k++];
            }
        }
        //字符操作
        for(i=0;i<len;i++)
        {
            if(str1[i]>='0'&&str1[i]<='9')
            {
                tmp=str1[i]-'0';
                str1[i]=turn_bit(tmp);
            }
            else if((str1[i]>='A'&&str1[i]<='F')||(str1[i]>='a'&&str1[i]<='f'))
            {
                tmp=toupper(str1[i])-'A'+10;
                str1[i]=turn_bit(tmp);
            }
        }
        printf("%s\n",str1);
    }
    return 0;
}
/**
 * HJ28 素数伴侣
 * 题目描述
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信
  加密。现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成
  “素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能
  得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的
  方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。

输入:
有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。

输出:
输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。

输入描述：
输入说明
1 输入一个正偶数n
2 输入n个整数
注意：数据可能有多组

输出描述：
求得的“最佳方案”组成“素数伴侣”的对数。

示例1
输入：
4
2 5 6 13
2
3 6
输出：
2
0
*/
// 可以做一个素数队列。然后两两做和，看看有几个是素数。总组合数Cn2.
// 下面这个：/这里包含了判断素数的方法
    //小技巧！！！素数不是偶数，那么和是素数的话就是奇数+偶数
    //那么可以分成两堆,一堆偶数，一堆奇数
    //匈牙利算法，先到先得 能让就让，有机会上，没机会创造机会也要上
#include <stdio.h>
#include <string.h>

int n1, n2, m, ans;
int result[101];//记录V2中的点匹配的点的编号
int state[101];//记录V2中的每个点是否被搜索过
int data[101][101];//邻接矩阵true代表有边相连。 表示某两个元素可以匹配成素数
int value[101]; // 所有数
int value1[101];// 奇数分组
int value2[101];// 偶数分组

int zhi_check(int num){ // 质数检查
  int i;
  for(i = 2; i*i <= num; i++){
    if(num%i == 0) return 0;
  }
  return 1;
}

void init(){
  int i;
  memset(result, 0, sizeof(result));
  memset(state, 0, sizeof(state));
  memset(data, 0, sizeof(data));
  memset(value, 0, sizeof(value));
  memset(value1, 0, sizeof(value));
  memset(value2, 0, sizeof(value));
  ans = 0;
  m = 0;
  n1 = 0; // 奇数个数
  n2 = 0; // 偶数个数
  scanf("%d", &m);  // 获得总数
  for(i = 1; i <= m; i++){
    scanf("%d ", &value[i]);//获得数组
  }
}
void ji_ou_part(){  // 奇偶分组
  int i;
  for(i = 1; i <= m; i++){
      if(value[i]%2 == 0){
          n2++;
          value2[n2] = value[i];  // 偶数
      }else{
          n1++;
          value1[n1] = value[i];
      }
  }
}

void fill(){  //检查所有的匹配情况，哪些会匹配成功
  int i, j;
  ji_ou_part();
  for(i = 1; i <= n1; i++){ //奇数
    for(j = 1; j <= n2; j++){//偶数
      //if(i == j) continue;
      if( zhi_check( value1[i]+value2[j] ) ){
        data[i][j] = 1;
      }
    }
  }
}

int find(int a){  //直接查找整个临接矩阵不就好了？
  int i;
  for(i = 1; i <= n2; i++) {
    if(data[a][i] == 1 && !state[i]) {//如果节点i与a相邻并且未被查找过
      state[i] = 1; //标记i为已查找过
      if(result[i] == 0 //如果i未在前一个匹配M中
        || find(result[i])) //i在匹配M中，但是从与i相邻的节点出发可以有增广路
      {
        result[i] = a; //记录查找成功记录
        return 1;//返回查找成功
      }
    }
  }
  return 0;
}

int main(){
  int j = 10, i, k;
  while(j--){
    init();
    if(m <= 0 || m > 100) continue;
    fill();// 检查
    
    for(i = 1; i <= n1; i++){   
      memset(state, 0, sizeof(state)); //清空上次搜索时的标记
      if(k = find(i)){  //是赋值，不是比较。k也没有用。
        ans++;    //从节点i尝试扩展
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

/**
 * HJ25 数据分类处理
 * 信息社会，有海量的数据需要分析处理，比如公安局分析身份证号码、 QQ 用户、手机号码、银行帐号等信息及活动记录。

采集输入大数据和分类规则，通过大数据分类处理程序，将大数据分类输出。

请注意本题有多组输入用例。
输入描述：
﻿一组输入整数序列I和一组规则整数序列R，I和R序列的第一个整数为序列的个数（个数不包含第一个整数）；整数范围为0~0xFFFFFFFF，序列个数不限

输出描述：
﻿从R依次中取出R<i>，对I进行处理，找到满足条件的I： 

I整数对应的数字需要连续包含R<i>对应的数字。比如R<i>为23，I为231，那么I包含了R<i>，条件满足 。 

按R<i>从小到大的顺序:

(1)先输出R<i>； 

(2)再输出满足条件的I的个数； 

(3)然后输出满足条件的I在I序列中的位置索引(从0开始)； 

(4)最后再输出I。 

附加条件： 

(1)R<i>需要从小到大排序。相同的R<i>只需要输出索引小的以及满足条件的I，索引大的需要过滤掉 

(2)如果没有满足条件的I，对应的R<i>不用输出 

(3)最后需要在输出序列的第一个整数位置记录后续整数序列的个数(不包含“个数”本身)

 

序列I：15,123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123（第一个15表明后续有15个整数） 

序列R：5,6,3,6,3,0（第一个5表明后续有5个整数） 

输出：30, 3,6,0,123,3,453,7,3,9,453456,13,453,14,123,6,7,1,456,2,786,4,46,8,665,9,453456,11,456,12,786

说明：

30----后续有30个整数

3----从小到大排序，第一个R<i>为0，但没有满足条件的I，不输出0，而下一个R<i>是3

6--- 存在6个包含3的I 

0--- 123所在的原序号为0 

123--- 123包含3，满足条件 

示例1
输入：
15 123 456 786 453 46 7 5 3 665 453456 745 456 786 453 123
5 6 3 6 3 0

输出：
30 3 6 0 123 3 453 7 3 9 453456 13 453 14 123 6 7 1 456 2 786 4 46 8 665 9 453456 11 456 12 786

*/
// 过程比较复杂。 判断包含，可以转换成string用strstr来判断。
#include <stdio.h>
#include <string.h>

int main() {
	int I[1000] = { 0 }, R[1000] = { 0 };
	int i, j, tmp, cnt, cnt_t, CNT_T[1000] = { 0 }, CNT[1000] = { 0 };
	char tmp1[20] = { 0 }, tmp2[20] = { 0 };
	while (scanf("%d", &I[0]) != EOF) {
		for (i = 1; i <= I[0]; i++)
			scanf("%d", &I[i]);
		scanf("%d", &R[0]);
		for (i = 1; i <= R[0]; i++)
			scanf("%d", &R[i]);
		//R数组排序
		for (i = 1; i<R[0]; i++) {
			for (j = 1; j<R[0] - (i - 1); j++) {
				if (R[j]>R[j + 1]) {
					tmp = R[j];
					R[j] = R[j + 1];
					R[j + 1] = tmp;
				}
			}
		}
		//R数组去重
		for (i = 1; i<R[0];) {
			if (R[i] == R[i + 1]) {
				for (j = i + 1; j<R[0]; j++)
					R[j] = R[j + 1];
				R[0]--;
			}
			else
				i++;
		}
		//把数字转换成字符串，使用strstr函数可以快捷判别是否有子串
		for (i = 1, cnt = 1; i <= R[0]; i++) {//cnt=0,用于存放总的个数
			sprintf(tmp1, "%d\0", R[i]);//把R[I]中的数字传到双引号之中，并赋给字符串tmp1
			for (j = 1, cnt_t = 0; j <= I[0]; j++) {
				sprintf(tmp2, "%d\0", I[j]);
				if (strstr(tmp2, tmp1)) {//如果满足，把I的序号和数值放到CNT_T中
					CNT_T[cnt_t++] = j - 1;
					CNT_T[cnt_t++] = I[j];
				}
			}
			if (cnt_t != 0) {//把R[i]中符合的情况，先把R[i]数值保存，再保存个数，再把CNT_T中相应的成对元素放到CNT中
				CNT[cnt++] = R[i];
				CNT[cnt++] = cnt_t / 2;
				for (j = 0; j<cnt_t; j++) {
					CNT[cnt++] = CNT_T[j];
				}
			}
		}
		CNT[0] = cnt - 1;
		for (i = 0; i<cnt - 1; i++)
			printf("%d ", CNT[i]);
		printf("%d\n", CNT[i]);
	}
	return 0;
}
/**
 * HJ27 查找兄弟单词
 * 定义一个单词的“兄弟单词”为：交换该单词字母顺序（注：可以交换任意次），而不添加、删除、修改原有的字母就能生成的单词。
兄弟单词要求和原来的单词不同。例如：ab和ba是兄弟单词。ab和ab则不是兄弟单词。
现在给定你n个单词，另外再给你一个单词str，让你寻找str的兄弟单词里，按字典序排列后的第k个单词是什么？
注意：字典中可能有重复单词。本题含有多组输入数据。
输入描述：
先输入单词的个数n，再输入n个单词。 再输入一个单词，为待查找的单词x 最后输入数字k
输出描述：
输出查找到x的兄弟单词的个数m 然后输出查找到的按照字典顺序排序后的第k个兄弟单词，没有符合第k个的话则不用输出。
示例1
输入：
3 abc bca cab abc 1

输出：
2
bca

示例2
输入：
6 cab ad abcd cba abc bca abc 1

输出：
3
bca

说明：
abc的兄弟单词有cab cba bca，所以输出3
经字典序排列后，变为bca cab cba，所以第1个字典序兄弟单词为bca  
*/
// 查重，考用用u32来标记字符，相等就可以。但是不能相等（strcmp)
// 字典序,? -- 下面，标准排序就可以，结果就是字典序。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
  return strcmp(*(char**)a, *(char**)b);
}
int main(void){
  int len;
  int i, j;
  int n, k;
  char str[16];
  int cnt[128] = { 0 };
  while(scanf("%d", &n) == 1){
    int top = -1;
    char *pwords[n];  // 保留查证合格的的字符串指针。
    char words[n][16];  // 存储原始字符。
    for(i = 0; i < n; ++i) scanf("%s", words[i]);
    scanf("%s", str);
    scanf("%d", &k);
    len = strlen(str);
    for(i = 0; i < n; ++i){
      if(len == strlen(words[i]) && strcmp(str, words[i])){
        char *p = words[i];
        for(j = 0; j < len; ++j){
            ++cnt[str[j]];
            --cnt[p[j]];
        }
        int add = 1;
        for(j = 0; j < len; ++j){
          if(cnt[str[j]] || cnt[p[j]]){
            cnt[str[j]] = 0;
            cnt[p[j]] = 0;
            if(add == 1) add = 0;
          }
        }
        if(add) pwords[++top] = words[i];
      }
    }
    qsort(pwords, top+1, sizeof(char*), comp);// c标准排序函数
    printf("%d\n", top+1);
    if(k-1 <= top) printf("%s\n", pwords[k-1]);
  }
  return 0;
}
/**
 * HJ19 简单错误记录
 * 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。


处理：


1、 记录最多8条错误记录，循环记录，最后只用输出最后出现的八条错误记录。对相同的错误记录只记录一条，但是错误计数增加。最后一个斜杠后面的带后缀名的部分（保留最后16位）和行号完全匹配的记录才做算是”相同“的错误记录。
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。
4、循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准

输入描述：
每组只包含一个测试用例。一个测试用例包含一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述：
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

示例1
输入：
D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
E:\je\rzuwnjvnuz 633
C:\km\tgjwpb\gy\atl 637
F:\weioj\hadd\connsh\rwyfvzsopsuiqjnr 647
E:\ns\mfwj\wqkoki\eez 648
D:\cfmwafhhgeyawnool 649
E:\czt\opwip\osnll\c 637
G:\nt\f 633
F:\fop\ywzqaop 631
F:\yay\jc\ywzqaop 631

输出：
rzuwnjvnuz 633 1
atl 637 1
rwyfvzsopsuiqjnr 647 1
eez 648 1
fmwafhhgeyawnool 649 1
c 637 1
f 633 1
ywzqaop 631 2
*/
// 用strtok()查找反斜杠，用“\\”
// 只保留8个数据。可以用队列。有了新的，检查，有重复的，次数增加，没有重复的，加入队列。
#include <stdio.h>
#include <string.h>

typedef struct _LIST_STR_T
{
    char name[200];
    int number;
    int times;
}LIST_STR_T;

int main(void)
{
    char in_str[200] = {0};
    int num = 0;
    int head = 0;
    int i = 0;
    int len = 0;
    LIST_STR_T list[100]; // 不用队列，保存所有，只打印最新的。
    char *p = NULL;
    memset(&list, 0, sizeof(list));
    
    while (scanf("%s %d", in_str, &num)!=EOF)
    {
        p = strrchr(in_str, '\\');
        len = strlen(++p);
        p = len>16?p+len-16:p;
        for (i = 0; i < head; i++){
            if ((0 == strcmp(list[i].name, p))
                && (num == list[i].number))
            {
                break;
            }
        }
        if (i == head) {
            strcpy(list[head].name, p);
            list[head].number = num;
            ++list[head].times;
            ++head;
        }
        else
        {
            ++list[i].times;
        }
    }
    for (i = (head-8>0?head-8:0); i < head; i++)
    {
        printf("%s %d %d\n",list[i].name,list[i].number,list[i].times);
    }
}

/**
 * HJ39 判断两个IP是否属于同一子网
 * 子网掩码是用来判断任意两台计算机的IP地址是否属于同一子网络的根据。
子网掩码与IP地址结构相同，是32位二进制数，其中网络号部分全为“1”和主机号部分全为“0”。利用子网掩码可以判断两台主机是否中同一子网中。若两台主机的IP地址分别与它们的子网掩码相“与”后的结果相同，则说明这两台主机在同一子网中。

示例：
I P 地址　 192.168.0.1
子网掩码　 255.255.255.0

转化为二进制进行运算：

I P 地址　  11000000.10101000.00000000.00000001
子网掩码　11111111.11111111.11111111.00000000

AND运算   11000000.10101000.00000000.00000000

转化为十进制后为：
192.168.0.0


I P 地址　 192.168.0.254
子网掩码　 255.255.255.0


转化为二进制进行运算：

I P 地址　11000000.10101000.00000000.11111110
子网掩码  11111111.11111111.11111111.00000000

AND运算  11000000.10101000.00000000.00000000

转化为十进制后为：
192.168.0.0

通过以上对两台计算机IP地址与子网掩码的AND运算后，我们可以看到它运算结果是一样的。
  均为192.168.0.0，所以这二台计算机可视为是同一子网络。

输入一个子网掩码以及两个ip地址，判断这两个ip地址是否是一个子网络。
若IP地址或子网掩码格式非法则输出1，若IP1与IP2属于同一子网络输出0，若IP1与IP2不属于同一子网络输出2。

注:
有效掩码与IP的性质为：
1. 掩码与IP每一段在 0 - 255 之间
2. 掩码的二进制字符串前缀为网络号，都由‘1’组成；后缀为主机号，都由'0'组成



输入描述：
多组输入，一组3行，第1行是输入子网掩码、第2，3行是输入两个ip地址

输出描述：
若IP地址或子网掩码格式非法则输出1，若IP1与IP2属于同一子网络输出0，若IP1与IP2不属于同一子网络输出2

示例1
输入：
255.255.255.0
192.168.224.256
192.168.10.4
255.0.0.0
193.194.202.15
232.43.7.59
255.255.255.0
192.168.0.254
192.168.0.1

输出：
1
2
0

说明：
对于第一个例子:
255.255.255.0
192.168.224.256
192.168.10.4
其中IP:192.168.224.256不合法，输出1

对于第二个例子:
255.0.0.0
193.194.202.15
232.43.7.59
2个与运算之后，不在同一个子网，输出2

对于第三个例子，2个与运算之后，如题目描述所示，在同一个子网，输出0
*/
// str -> int. 然后分别得到与结果，比较。
// 下面：
#include <stdio.h>

int main()
{
  unsigned int a, b, c, d;
  unsigned int mask1, mask2, mask3, mask4;// 子网掩码
  unsigned int and1, and2, and3, and4;
  int current_stage = 0, skip_stages = 0; // 状态机
  // 用.号分隔，直接获得uint数值，不用转化
  while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
      current_stage++;

      if (skip_stages > 0)  {
          skip_stages--;
          current_stage = 0;
          continue;
      }
      // 不合规的ip，直接丢弃这一组
      if (a > 255 || b > 255 || c > 255 || d > 255) {
          printf("1\n");
          skip_stages = 3 - current_stage;
          continue;
      }
      // 子网掩码
      if (current_stage == 1) {
          if (a != 255 || d != 0)// 检查子网掩码
          {
              printf("1\n");
              skip_stages = 3 - current_stage;
              continue;
          }

          mask1 = a;
          mask2 = b;
          mask3 = c;
          mask4 = d;
      }
      // IP1
      if (current_stage == 2)  {
          and1 = a & mask1;
          and2 = b & mask2;
          and3 = c & mask3;
          and4 = d & mask4;
      }
      // IP2
      if (current_stage == 3){
          if (
              and1 - (a & mask1) != 0 ||
              and2 - (b & mask2) != 0 ||
              and3 - (c & mask3) != 0 ||
              and4 - (d & mask4) != 0)
          {
              printf("2\n");
          }
          else
          {
              printf("0\n");
          }
          current_stage = 0;
      }
  }
  return 0;
}
/**
 * HJ55 挑7
 * 输出7有关数字的个数，包括7的倍数，还有包含7的数字（如17，27，37...70，71，72，73...）的个数（一组测试用例里可能有多组数据，请注意处理）

输入描述：
一个正整数N。(N不大于30000)

输出描述：
不大于N的与7有关的数字个数，例如输入20，与7有关的数字包括7,14,17.

示例1
输入：
20
10
输出：
3
1
*/
// 暴力解：循环，整除则符合，否则判断是否含有7.从小到大计算
// 优化：整除直接算一个就可以。其他含有七的怎么直接算总数？
// 下面这个没看懂：
#include <stdio.h>
int main(void){
	char flag, mul;
	int i, j, k, p, scale, num, opt[50], n, arr[50], idx, cnt;
	n = idx = 0;
	for( ; scanf("%d", &num)!=EOF; n+=2){// 收集所有的输入
		if(num<7) { opt[n]=0; opt[n+1]=0; continue; } //不计算
		opt[n] = num; //记录数值
		
		for(i=idx-1; i>=0; i--)
			if(i>=0 && arr[i]<=num) break;
		if(i>=0 && arr[i]==num) continue;
		for(j=idx-1; j>i; j--)
			arr[j+1] = arr[j];
		arr[j+1] = num;
		idx++;
	}
	
	cnt = 0;   j = 7;
	for(i=0; i<idx; i++){
		num = arr[i];
        
		if(k=j%7){
			for(--j; k; --k ,--j){
				if(j%7==0) { cnt--; continue; }
					
				for(p=j; p; p/=10)
					if(p%10==7) { cnt--; break; }
			}
			++j;
		}
        
		for(k=j, mul=0; k; k/=10, mul++)
			if(k%10==7) break;
		if(k && mul){
			for(p=0, scale=1; p<mul; p++)
				k*=10, scale*=10;
			cnt -= j-k;
		}
		flag=0;
		for( ; j<=num; j+=7){
			for(k=j, mul=0; k; k/=10, mul++)
				if(k%10==7) break;
			if(k){
				if(!mul) { cnt++; flag=0; continue; }
				
				for(p=0, scale=1; p<mul; p++)
					k*=10, scale*=10;
				if(num<k+scale) { cnt += num-k+1+flag; j=num+1; goto output; }
				else {
					cnt += scale+flag;
					for(j=k+scale; j<=num; j++){
						if(j%7==0) break;
						
						for(k=j; k; k/=10)
							if(k%10==7) { cnt++; break; }
					}
					if(j<=num) { j-=7; flag=0; continue; }
					goto output;
				}
			}
			
			cnt += flag+1;
			if(j%10<7) flag=1;
			else flag=0;
		}
        
		j-=6;
		for( ; j<=num; j++){
			if(j%7==0) { cnt++; continue; }
			
			for(k=j; k; k/=10)
				if(k%10==7) { cnt++; break; }
		}
				
output:	for(k=0; k<n; k+=2)
			if(opt[k]==num) opt[k+1]=cnt;
	}
	
	for(k=1; k<n; k+=2)
		printf("%d\n", opt[k]);
	return 0;
}
//暴力解法的实现
#include<stdio.h>
int main(){
    int n = 0;
    while(scanf("%d", &n) != EOF){
        int res = 0;
        int tmp = 0;
        for(int i = 7; i <= n; i++){
            if(i%7 == 0)//7的倍数
                res ++;
            else{//包含7
                tmp = i;
                while(tmp > 0){
                    if(tmp%10 == 7){
                        res++;
                        break;
                    }else
                        tmp /= 10;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
/**
 * HJ66 配置文件恢复
 * 有6条配置命令，它们执行的结果分别是：

命   令	执   行
reset	reset what
reset board	board fault
board add	where to add
board delete	no board at all
reboot backplane	impossible
backplane abort	install first
he he	unknown command
注意：he he不是命令。

为了简化输入，方便用户，以“最短唯一匹配原则”匹配：
1、若只输入一字串，则只匹配一个关键字的命令行。例如输入：r，根据该规则，匹配命令reset，执行结果为：reset what；输入：res，根据该规则，匹配命令reset，执行结果为：reset what；
2、若只输入一字串，但本条命令有两个关键字，则匹配失败。例如输入：reb，可以找到命令reboot backpalne，但是该命令有两个关键词，所有匹配失败，执行结果为：unknown command
3、若输入两字串，则先匹配第一关键字，如果有匹配但不唯一，继续匹配第二关键字，如果仍不唯一，匹配失败。例如输入：r b，找到匹配命令reset board 和 reboot backplane，执行结果为：unknown command。
4、若输入两字串，则先匹配第一关键字，如果有匹配但不唯一，继续匹配第二关键字，如果唯一，匹配成功。例如输入：b a，无法确定是命令board add还是backplane abort，匹配失败。
5、若输入两字串，第一关键字匹配成功，则匹配第二关键字，若无匹配，失败。例如输入：bo a，确定是命令board add，匹配成功。
6、若匹配失败，打印“unknown command”

输入描述：
多行字符串，每行字符串一条命令

输出描述：
执行结果，每条命令输出一行

示例1
输入：
reset
reset board
board add
board delet
reboot backplane
backplane abort
 

输出：
reset what
board fault
where to add
no board at all
impossible
install first
*/
// 简化问题：看数量，如果是超过两个，则失败。比较第一个，

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *cmdh[5]={"reset","board","board","reboot","backplane"};
char *cmdl[5]={"board","add","delete","backplane","abort"};
char *cmdout[5]={"board fault",
              "where to add",
              "no board at all",
              "impossible",
              "install first" };
int main(){
  char cmdin[100];

  while(gets(cmdin)){
    int n,len_1,len= strlen(cmdin);;
    int flag=0,pos=0,cnt=0;
    int index_o = 0;

    for(int n=0;n<len;n++){
        if(cmdin[n]==' '){
            // 查找并标记第二个单词位置
            flag=1;
            pos=n;
            break;
        }
    }
    if(flag == 1){
      // 查找并比较两个单词的情况
      for(int n=0;n<5;n++)     {
        if(strncmp(cmdh[n],cmdin,pos)==0 && strncmp(cmdl[n],cmdin+pos+1,len-pos-1)==0)
        {
          cnt++;
          index_o = n;
        }
      }
      if(cnt == 1) printf("%s\n",cmdout[index_o]);
      else printf("unknown command\n");
    }else{ 
      // 只有一个单词的情况
      if(strncmp("reset",cmdin,len)==0){
        printf("reset what\n");
      }
      else{
        printf("unknown command\n");
      }
    }
  }
  return 0;
}

/**
 * HJ52 计算字符串的距离
 * Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。

本题含有多组输入数据。

输入描述：
每组用例一共2行，为输入的两个字符串

输出描述：
每组用例输出一行，代表字符串的距离

示例1
输入：
abcdefg
abcdef
abcde
abcdf
abcde
bcdef

输出：
1
1
2
*/
// 动态规划，构造状态转移方程和状态转移矩阵
#include <stdio.h>
#include <string.h>
int main(void){
  const int sz = 500;
  char rows[sz], cols[sz];
  while(gets(rows) != NULL && gets(cols) != NULL) {
    int line[strlen(rows) + 1];
    for(int i = 0; i <= strlen(rows); ++i) 
      line[i] = i;
    for(int i = 1; i <= strlen(cols); ++i) {
      int prev = line[0];
      line[0] = i;
      for(int j = 1; j <= strlen(rows); ++j){
        int t = line[j];
        if(rows[j-1] == cols[i-1]) 
            line[j] = prev;
        else{
          if(line[j] > prev){
            line[j] = prev;
          }
          if(line[j] > line[j-1]){
            line[j] = line[j-1];
          }
          ++line[j];
        }
        prev = t;
      }
    }
    printf("%d\n", line[strlen(rows)]);
  }
  return 0;
}
/**
 * HJ77 火车进站
 * 给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号，火车站只有一个方向进出，同时停靠在火车站的列车中，只有后进站的出站了，先进站的才能出站。
要求输出所有火车出站的方案，以字典序排序输出。
输入描述：
有多组测试用例，每一组第一行输入一个正整数N（0

输出描述：
输出以字典序从小到大排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。
示例1
输入：
3
1 2 3

输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1

说明：
第一种方案：1进、1出、2进、2出、3进、3出
第二种方案：1进、1出、2进、3进、3出、2出
第三种方案：1进、2进、2出、1出、3进、3出
第四种方案：1进、2进、2出、3进、3出、1出
第五种方案：1进、2进、3进、3出、2出、1出
请注意，[3,1,2]这个序列是不可能实现的。
 * */
// 基本是栈 +穷举的思想。用递归实现回溯算法，挨个找到。
// 只有push和pop的操作，
// 还有dfs的方案，暂时不考虑具体实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10
int idx;
char N, M, arr[MAX_N], push_stk[MAX_N], idx_push, pop_arr[MAX_N], idx_pop, opt[8888][MAX_N+1], **opt_p;
void DG(char k){
	if(k==N){
		char i = idx_pop, j = idx_push;
		memcpy(opt[++idx], pop_arr, (++i)*sizeof(char));
		for( ; j!=-1; opt[idx][i++] = push_stk[j--]) ;
		opt[idx][i] = '\0';
		return ;
	}
	if(idx_push != -1){
		pop_arr[++idx_pop] = push_stk[idx_push--];
		DG(k);
		push_stk[++idx_push] = pop_arr[idx_pop--];
	}
	push_stk[++idx_push] = arr[k]; // push操作
	DG(k+1);
	idx_push--;
}
// 排序，保证字典序
void DG_quick_sort(int start, int end)
{
	if(start < end){
		int i = start, j = end;
		char *p_tmp = opt_p[start];
		
		while(i < j){
			while(i<j && strcmp(opt_p[j], p_tmp)>=0) j--;
			opt_p[i] = opt_p[j];
			while(i<j && strcmp(opt_p[i], p_tmp)<=0) i++;
			opt_p[j] = opt_p[i];
		}
		opt_p[i] = p_tmp;
		DG_quick_sort(start, i-1);
		DG_quick_sort(i+1, end);
	}
}
int main(void)
{
	int i;   char j;
	for( ; scanf("%d", &N)!=EOF; ){
		for(i=0; i<N; i++){
            getchar();
			scanf("%c", arr+i);
        }
		M = N-1;
		
		push_stk[0] = arr[0];
		idx_push = 0;   idx_pop = idx = -1;
		DG(1);
		
		opt_p = (char **)malloc( (idx+1)*sizeof(char *) );
		for(i=0; i<=idx; i++) // idx记录了总共多少种方案
			opt_p[i] = opt[i];
		DG_quick_sort(0, idx);// 保证字典序输出
		for(i=0; i<=idx; i++){
			for(j=0; j<M; j++)
				printf("%c ", opt_p[i][j]);
			printf("%c\n", opt_p[i][j]);
		}
		free( opt_p );
	}
	return 0;
}
/**
 * HJ61 放苹果
 * 题目描述
把m个同样的苹果放在n个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）
  5，1，1和1，5，1 是同一种分法。
数据范围：0<=m<=10，1<=n<=10。
本题含有多组样例输入。
输入描述：
输入两个int整数
输出描述：
输出结果，int型
示例1
输入：
7 3
输出：
8
 * */
/* 也可以用动态规划的方法,递归为逆向思维，动态规划需要确定放置方法数的动态方程：d[i][j]=d[i][j-1]+d[i-j][j].
动态规划需要确定初始状态：d[0][j]=1;d[1][j]=1;d[i][1]=1.
其中：i个苹果，j个篮子：空篮子的放置方法即可生成至d[m][n].
Recursion is a reversed thinking, but dynamic programming needs to make sure 
  the initial states and the state transition matrix.
生成的二维规划数组（横纵分别为苹果和篮子数，从零开始）为：
0 1 1 1 1 1...
0 1 1 1 1 1...
0 1 2 2 2 2...
0 1 2 3 3 3...
0 1 3 4 5 5...
（盘子》苹果） == （盘子==苹果），其他？
*/
// 递归的方法 -- 放苹果分为两种情况，一种是有盘子为空，一种是每个盘子上都有苹果。
// 令(m,n)表示将m个苹果放入n个盘子中的摆放方法总数。
// 1.假设有一个盘子为空，则(m,n)问题转化为将m个苹果放在n-1个盘子上，即求得(m,n-1)即可
// 2.假设所有盘子都装有苹果，则每个盘子上至少有一个苹果，即最多剩下m-n个苹果，问题转化为
//  将m-n个苹果放到n个盘子上, 即求(m-n，n)
#include <stdio.h>
int fun(int m,int n){
    if(m==0||n==1){
        return 1;
    }else if(m<n){  // 苹果少于盘子
        return fun(m,m);
    }else{
        return fun(m-n,n)+fun(m,n-1);
    }
}
int main(){
    int a,b,num;
    while(~scanf("%d%d",&a,&b)){
        num = fun(a,b);
        printf("%d\n",num);
    }
}
/**
 * HJ67 24点游戏算法
 * 问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字。
输出：
true or false

本题含有多组样例输入。
输入描述：
输入4个int整数

输出描述：
返回能否得到24点，能输出true，不能输出false

示例1
输入：
7 2 1 10
输出：
true
 * */
// 暴力解法：穷举。
// 优化：深度优先搜索
#include <stdio.h>
#include <string.h>

int inp[4]={0};
int flag[4]={0};

int dfs(int num){   // 传入的参数即为数值
  if(num==24) //不需要所有数字都用？
    return 1;
  for(int i=0;i<4;i++)
  {
    if(flag[i]==0)
    {
      flag[i]=1;
      if(dfs(num+inp[i])) // 加
        return 1;
      else if(dfs(num-inp[i]))//减
        return 1;
      else if(dfs(num*inp[i]))//乘
        return 1;
      else if(dfs(num/inp[i]) && (num%inp[i]==0))//除
        return 1;
      flag[i]=0;
    }
  }
  return 0;
}

int main()
{
    while(scanf("%d %d %d %d",&inp[0],&inp[1],&inp[2],&inp[3])!=EOF)
    {
        memset(flag,0,sizeof(flag));
        if(dfs(0))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
/**
 * HJ89 24点运算 -- 上一题的进化版，加上了字符运算。-- 不列答案了
 * https://www.nowcoder.com/practice/7e124483271e4c979a82eb2956544f9d?tpId=37&&tqId=21312&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 * 计算24点是一种扑克牌益智游戏，随机抽出4张扑克牌，通过加(+)，减(-)，乘(*), 除(/)四种
 *  运算法则计算得到整数24，本问题中，扑克牌通过如下字符或者字符串表示，其中，
 *  小写joker表示小王，大写JOKER表示大王：

3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER

本程序要求实现：输入4张牌，输出一个算式，算式的结果为24点。

详细说明：

1.运算只考虑加减乘除运算，没有阶乘等特殊运算符号，没有括号，友情提醒，整数除法要当心，
  是属于整除，比如2/3=0，3/2=1；
2.牌面2~10对应的权值为2~10, J、Q、K、A权值分别为为11、12、13、1；
3.输入4张牌为字符串形式，以一个空格隔开，首尾无空格；如果输入的4张牌中包含大小王，则
  输出字符串“ERROR”，表示无法运算；
4.输出的算式格式为4张牌通过+-* /四个运算符相连，中间无空格，4张牌出现顺序任意，只要结果正确；
5.输出算式的运算顺序从左至右，不包含括号，如1+2+3*4的结果为24，2 A 9 A不能变为(2+1)*(9-1)=24
6.如果存在多种算式都能计算得出24，只需输出一种即可，如果无法得出24，则输出“NONE”表示无解。
7.因为都是扑克牌，不存在单个牌为0的情况，且没有括号运算，除数(即分母)的数字不可能为0

输入描述：
输入4张牌为字符串形式，以一个空格隔开，首尾无空格；

输出描述：
输出怎么运算得到24，如果无法得出24，则输出“NONE”表示无解，如果输入的4张牌中包含大小王，
  则输出字符串“ERROR”，表示无法运算；
示例1
输入：
A A A A

输出：
NONE

说明：
不能实现       
示例2
输入：
4 2 K A

输出：
K-A*4/2

说明：
 A+K*2-4也是一种答案，输出任意一种即可       
示例3
输入：
B 5 joker 4

输出：
ERROR
说明：
 存在joker，输出ERROR      
示例4
输入：
K Q 6 K

输出：
NONE

说明：
按一般的计算规则来看，K+K-(Q/6)=24，但是因为这个题目的运算不许有括号，所以只能为K+K-Q/6=2  ，其他情况也不能运算出24点，故不存在，输出NONE
 * */

/**
 *HJ24 合唱队
 * 计算最少出列多少位同学，使得剩下的同学排成合唱队形

说明：

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，
  则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。


注意：不允许改变队列元素的先后顺序 且 不要求最高同学左右人数必须相等
请注意处理多组输入输出！

备注：
1<=N<=3000
输入描述：
有多组用例，每组都包含两行数据，第一行是同学的总数N，第二行是N位同学的身高，以空格隔开

输出描述：
最少需要几位同学出列

示例1
输入：
8
186 186 150 200 160 130 197 200
输出：
4

说明：
由于不允许改变队列元素的先后顺序，所以最终剩下的队列应该为186 200 160 130或150 200 160 130 
 * */
/* 动态规划:思路：
对于题目，所有人都已经站好位，不能再改变位置了，只能从当中去掉人组成合唱队。同时，可以
  考虑中间的人两边没有人的情况（比如两头的两个人，或者这个人太矮周围的人都比他高的情况），
  但是这种情况基本被pass掉。
计算出每个人左边能出现的最多的人数：
比如题中所给出的示例：186 186 150 200 160 130 197 200。首先如果第一个数186在中间，
  左边没有数，就自己一个人，所以是1；第二个数186因为左边那个人跟他一边高，没有比他矮的了，
  所以也是1；第三个数150，左边的人都比他高，他如果是中间的话左边也他自己一个人，所以还是1；
  第四个数200，因为不能换位置，所以只能留186或者150，加上自己，就是2...最后再以197为例，
  左边保留150,160是左边人最多的情况，再加上自己，就是3。所以每个人左边人最多的情况
  （加上自己）就是（186）1 1 1 2 2 1 3 4（200）。同理，看一下每个人右边可能出现最多的人，
  这时我们从后往前看。200在最右面，所以自己一个人，是1；197最右面没有比他矮的，自己，
  是1...160左边一个比他矮的，所以算上自己是2，以此类推。所以每个人右边人做多的情况
  （加上自己）就是（186）3 3 2 3 2 1 1 1（200）
所以将上面两个划横线的对应相加，就可以得到自己如果是中间的那个人，可以得到的最大的合唱队
  人数。当然，自己加了两遍，所以得减掉一个自己。另外题目问的是最少去掉的人，所以最后的结果：
总人数 - 该数所在队列人数 = 需要出队的人数
*/
// 分别实现两个数组,左右两个方向，G[i]=max(G[左边有比它小的数值])+1.最后寻找其中可以完美凑上的，并且最长的即可。
// python实现
// def left_max(l):
//  # 计算每个人左边出现的最多的人数
//  # 186 186 150 200 160 130 197 200
//  dp = [1] * len(l) # 若左边没有比自己小的数，则为自己本身，所以初始值为1
//  for i in range(len(l)): # 从左往右遍历
//      for j in range(i):
//          if l[j]<l[i] and dp[i]<dp[j]+1:
//              dp[i] = dp[j]+1
//        # if l[j]<l[i]:
//        #     dp[i] = max(dp[i],dp[j]+1) 会超时
//  return dp #1 1 1 2 2 1 3 4
//            # 从右往左推每个人右边可以站的最多的人数
//            # 3 3 2 3 2 1 1 1
// while True:
//  try:
//      N = int(input())
//      ss = list(map(int,input().split()))
//      left_s = left_max(ss)
//      right_s = left_max(ss[::-1])[::-1]
//      sum_s = []
//      for i in range(len(left_s)):
//          # left_s[i]+right_s[i]-1表示此人是中间位置的人时，合唱队的人数
//          sum_s.append(left_s[i]+right_s[i]-1)
//      print(str(N-max(sum_s)))
//  except:
//      break
#include <stdio.h>

const int sz = 3072;
int search_binary(int *nums, int top, int tgt){
    int mi;
    int lo = 0;
    int hi = top;
    while(lo <= hi){
        mi = lo + (hi - lo) / 2;
        if(tgt > nums[mi]) lo = mi + 1;
        else hi = mi - 1;
    }
    return lo;
}
void calc_dp(int N, int *nums, int *dp){
    int i;
    int top = 0;
    int stk[sz];
    stk[top] = nums[0];
    for(i = 0; i < N; ++i){
        if(nums[i] > stk[top]){
            stk[++top] = nums[i];
            dp[i] = top;
        }
        else{
            int pos = search_binary(stk, top, nums[i]);
            stk[pos] = nums[i];
            dp[i] = pos;
        }
    }
}
int main(void){
    int max;
    int N;
    int tmp;
    int i, j;
    int nums[sz];
    int dp_d[sz];
    int dp_a[sz];
    while(scanf("%d", &N) == 1){
        for(i = 0; i < N; ++i){
            scanf("%d", nums + i);
            dp_d[i] = dp_a[i] = 1;
        }
        calc_dp(N, nums, dp_a);
        for(i = 0, j = N - 1; i < j; ++i, --j){
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        calc_dp(N, nums, dp_d);
        max = 0;
        for(i = 0, j = N-1; i < N; ++i, --j){
            tmp = dp_a[i] + dp_d[j];
            if(tmp > max) max = tmp;
        }
        printf("%d\n", N - max - 1);
    }
    return 0;
}
/**
 * HJ82 将真分数分解为埃及分数
 * 分子为1的分数称为埃及分数。现输入一个真分数(分子比分母小的分数，叫做真分数)，请将该
 *  分数分解为埃及分数。如：8/11 = 1/2+1/5+1/55+1/110。
注：真分数指分子小于分母的分数，分子和分母有可能gcd不为1！
如有多个解，请输出任意一个。
请注意本题含有多组样例输入！
输入描述：
输入一个真分数，String型
输出描述：
输出分解后的string
示例1
输入：
8/11
2/4
输出：
1/2+1/5+1/55+1/110
1/3+1/6
说明：
第二个样例直接输出1/2也是可以的
 * */
//
//暴力！直接分母变，n个分子相加
#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        string ans;
        int n;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                n = stoi(s.substr(0, i));
                s = "1/" + s.substr(i + 1) + "+";
                break;
            }
        }
        while (n--) {
            ans += s;
        }
        cout << ans.substr(0,ans.size()-1) << endl;
    }
}
// 深度优先搜索？
#include <stdio.h>
int DG(int a, int b)
{
	if(b) return DG(b, a%b);
	return a;
}
int main(void){
	int a, b, tmp;
	for( ; scanf("%d/%d", &a, &b)!=EOF; ){
		if((tmp=DG(a,b))!=1){ a/=tmp;   b/=tmp; }
		if(a==1){ printf("%d/%d\n", a, b);   continue; }
		for( ; a!=1; ){
			tmp = b/a+1;
			printf("1/%d+", tmp);
			a -= b%a;
			b *= tmp;
			if((tmp=DG(a,b))!=1){ a/=tmp;   b/=tmp; }
		}
		printf("1/%d\n", b);
	}
	return 0;
}

/**
 * HJ44 Sudoku
 * 问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。玩家需要根据9X9盘面上的已知数字，
 *  推算出所有剩余空格的数字，并且满足每一行、每一列、每一个3X3粗线宫内的数字均含1-9，
 *  并且不重复。
例如：
输入
输出

输入描述：
包含已知数字的9X9盘面数组[空缺位以数字0表示]

输出描述：
完整的9X9盘面数组

示例1
输入：
0 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
0 4 5 2 7 6 8 3 1
复制
输出：
5 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
9 4 5 2 7 6 8 3 1
 * */
// 三个判断准则，横、竖、3x3方格，都没有
// leetcode https://leetcode-cn.com/problems/sudoku-solver/comments/
// 递归、回溯，穷举所有的方法。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int sudoku(int **p, int depth);

int is_valid(int **p, int i, int j);

int main() {
    int a[9][9] = {0};

    int **p = (int **) malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++) {
        p[i] = a[i];
    }

    int depth = 0;
    for (int i = 0; i < 9 * 9; i++) {
        scanf("%d", &p[i / 9][i % 9]);
        if (p[i / 9][i % 9] == 0) depth++;
    }

    sudoku(p, depth);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", p[i][j]);
        }
    }

    free(p);
    return 0;
}

int sudoku(int **p, int depth) {
    if (depth == 0) {
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (p[i][j] == 0) {
                for (int k = 1; k <= 10; k++) {
                    if (k == 10)
                        return depth;
                    p[i][j] = k;
                    if (is_valid(p, i, j)) {
                        depth--;
                        depth = sudoku(p, depth);
                        if (depth == 0)
                            return 0;
                        depth++;
                    }
                    p[i][j] = 0;
                }
            }
        }
    }
    return depth;
}

int is_valid(int **p, int row, int col) {
    int check[10] = {0};
    for(int i=0; i<10; i++) check[i] = 1;
    for (int i = 0; i < 9; i++) {
        if (check[p[row][i]])
            check[p[row][i]] = 0;
        else if (p[row][i] != 0)
            return 0;
    }

    for(int i=0; i<10; i++) check[i] = 1;
    for (int i = 0; i < 9; i++) {
        if (check[p[i][col]])
            check[p[i][col]] = 0;
        else if (p[i][col] != 0)
            return 0;
    }

    for(int i=0; i<10; i++) check[i] = 1;
    int rowTemp = row - row % 3;
    int colTemp = col - col % 3;
    for (int k = 0; k < 9; k++) {
        int r = rowTemp + k / 3;
        int c = colTemp + k % 3;
        if (check[p[r][c]])
            check[p[r][c]] = 0;
        else if (p[r][c] != 0)
            return 0;
    }
    return 1;
}

/**
 * 
 * 
 * */
/**
 * 
 * 
 * */
