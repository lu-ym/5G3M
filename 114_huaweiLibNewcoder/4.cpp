#include <iostream>
// #include <string>
// #include <vector>
#include <algorithm>
// #include <cmath>
#include <cstdio>
using namespace std;

/**
 * 福尔摩斯的约会
 * 大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 
 * 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。
 * 大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为
 * 前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；
 * 第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 
 *  点到 23 点由数字 0 到 9、以及大写字母 A到 N 表示）；
 * 后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。
 * 现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 
  表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示
  星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。
//注意小时或者分钟不满足两位的要记得补零。 
//再者注意，每一次判断的字母范围，第一次与第二次的范围不一样通过题意隐含得出。

*/
/**
 * 
 * */

int main(){
	char a1[61],a2[61],b1[61],b2[61];
	int times=0;
  //每个星期由三个字母组成所以设置数组时长度应为4，因为还有结束符 
	char Weekday[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	if((scanf("%s%s%s%s",a1,a2,b1,b2))!=EOF){
		for(int i=0;times<2 && i<=60;i++){
      //找第一次出现相同的大写字母。居然在同一个位置。不是的话，要首尾依次看
			if((a1[i]==a2[i]) && (a1[i]>='A'&&a1[i]<='G')&& times==0){  
				times++;
				int num=a1[i]-'A';
				printf("%s ",Weekday[num]);
				continue;
			}	
      // 第一个相同的全大写的字母或者数字（用times保证）万一在另一个前面出现怎么办？-- 用数组存。
			if((((a1[i]==a2[i])&&(a1[i]>='A'&&a1[i]<='N'))||((a1[i]==a2[i])&&(a1[i]>='0'&&a1[i]<='9')))&&times==1){
				times++;
				if(a1[i]>='0'&&a1[i]<='9'){
					printf("0%c:",a1[i]); // 用%c来省掉 转化为int的过程
				}
				if(a1[i]>='A'&&a1[i]<='N'){
					int num=a1[i]-'A'+1;
					printf("%d:",9+num);
				}
				break;
      }
		}
		times=0;
    // 寻找分钟数
		for(int i=0;times<1;i++){
			if(b1[i]==b2[i]&&((b1[i]>='A'&&b1[i]<='Z')||(b1[i]>='a'&&b1[i]<='z'))){
				times++;
				// if(i<10){
				// 	printf("0%d",i);
				// }else{
				// 	printf("%d",i);
				// }
        printf("%02d",i);
			}
		}
	}
  cout <<endl;
	return 0;
} 

