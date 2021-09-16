// https://www.nowcoder.com/ta/huawei

/**
 * 描述
输入一个表达式（用字符串表示），求这个表达式的值。
保证字符串中的有效字符包括[‘0’-‘9’],‘+’,‘-’, ‘*’,‘/’ ,‘(’， ‘)’,‘[’, ‘]’,‘{’ ,‘}’。
且表达式一定合法。

输入描述：
输入一个算术表达式

输出描述：
得到计算结果

示例1
输入：
3+2*{1+2*[-4/(8-6)+7]}
输出：
25
 * 
*/
/**
 * 思路：递归解法，又称消消乐解法。
1）无括号的四则运算，优先级 乘除 > 加减。 用栈来解决。
	如果是乘除，出栈对两个数运算，运算完再加减。
2）括号用递归来解。遇到左括号则递归执行，遇到右括号，退出函数，运算结果作为返回值压入栈。
-------
大佬的递归解法，也可以称为消消乐解法，这是我见过最简洁的表达式求值代码。看到这种解法之后
  我都不想去看什么逆波兰了。。。首先声明，我只是个搬运工。
第一步，先考虑无括号的情况，先乘除后加减，这个用栈很容易解决，遇到数字先压栈，如果下一个
  是乘号或除号，先出栈，和下一个数进行乘除运算，再入栈，最后就能保证栈内所有数字都是加数，
  最后对所有加数求和即可。
第二步，遇到左括号，直接递归执行第一步即可，最后检测到右括号，返回括号内的计算结果，退出
  函数，这个结果作为一个加数，返回上一层入栈。
*/
// this implementation comes from newcoder.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pos;    // use global position and char pointer query data

int compute(char* data)
{
    int len = strlen(data);
    int stack[1000];
    int top = -1;
    int num = 0;
    char flag = '+';

    while (pos < len) {
        // 括号，递归
        if (data[pos] == '{' || data[pos] == '[' || data[pos] == '(') {
            pos++;
            num=compute(data);
        }
        // string(char[]) to int
        while (pos < len && isdigit(data[pos])) {
            num = num*10 + data[pos] -'0';
            pos++;
        }

        switch (flag) {
        case '+':
            stack[++top] = num;
            break;
        case '-':
            stack[++top] = -num;
            break;
        case '*':
            stack[top] *= num;
            break;
        case '/':
            stack[top] /= num;
            break;
        }

        num = 0;
        flag = data[pos]; // log next operation arithmetic
        if (data[pos] == '}' || data[pos] == ']'|| data[pos] == ')') {
            pos++;
            break; // 跳出递归
        }
        pos++;
    }
    // 运算结束，计算结果
    int res = 0;

    for (int i = 0; i <= top; i++) {
        res += stack[i];
    }
    return res;
}

int main()
{
    char data[1000];

    while (scanf("%s", data) != EOF) {
        pos = 0;
        int res = compute(data);
        printf("%d\n", res);
    }
    return 0;
}