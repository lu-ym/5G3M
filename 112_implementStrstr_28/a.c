#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
 * 实现 strStr() 函数。
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串
    出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 
    Java 的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
/**
 * 朴素法
 * leetcode time:856ms. memory 6.2MB.
 * */
// int strStr(char * haystack, char * needle){
//     if (*needle == '\0') return 0;
//     if (*haystack == '\0') return -1;
//     int id = 0;
//     char *all = haystack;
//     char *mode = needle;
//     while (*all != '\0') {
//         if (*all == *mode){  // 这两行可以用strchr来替代
//             while ((*mode != '\0') && (*all != '\0') && (*all == *mode)){
//                 mode++;
//                 all++;
//             }
//             if (*mode == '\0'){
//                 return id;
//             }else if(*all == '\0'){
//                 return -1;
//             }else{
//                 all = haystack+id;
//                 mode = needle;
//             }
//         }
//         all++;
//         id++;
//     }
//     return -1;
// }

/**
 * KMP法
 * */
// leetcode 官方的KMP算法实现
// int strStr(char* haystack,char* needle){
//     int n = strlen(haystack), m = strlen(needle);
//     if (m == 0) {
//         return 0;
//     }
//    // preprocessing. 
//     int pi[m];
//     pi[0] = 0;
//     for (int i = 1, j = 0; i < m; i++) {
//         while (j > 0 && needle[i] != needle[j]) {
//             j = pi[j - 1];
//         }
//         if (needle[i] == needle[j]) {
//             j++;
//         }
//         pi[i] = j;
//     }
//     // matching. find the first match and return.
//     for (int i = 0, j = 0; i < n; i++) {
//         while (j > 0 && haystack[i] != needle[j]) {
//             j = pi[j - 1];
//         }
//         if (haystack[i] == needle[j]) {
//             j++;
//         }
//         if (j == m) {
//             return i - m + 1;
//         }
//     }
//     return -1;
// }

/**
 * Sunday算法
 * leetcode time consuming: 500ms. memory: 6MB.
 * */
#define LETTERNUM 26
int strStr(char * haystack, char * needle){
    int n = strlen(haystack);
    int m = strlen(needle);
    if (m==0) return 0;    
    int letterTable[LETTERNUM];
    for (size_t i = 0; i < LETTERNUM; i++) {
        letterTable[i] = m+1;
    }
    // memset(letterTable,0,sizeof(int)*LETTERNUM);//int不能用memset值非0的数
    for (size_t i = 0; i < m; i++){
        int temp = needle[i] - 'a';
        letterTable[needle[i] - 'a'] = m-i; // offset
    }
    for (size_t i = 0; i < n; ){
        for (size_t i = 0; i < n; ){
        size_t j = 0;
        for (; j < m && (j <n-i); j++){
            if(haystack[i+j]!=needle[j]) break;
        }
        if (j == m) return i;
        if ((i+j)>=n) break;        
        if ((i+m)>=n) break;        
        i += letterTable[haystack[i+m]-'a'] ;
    }
    }
    return -1;
}
void main(){
    // char *haystack = "hello";
    // char *needle = "ll";
    // char *haystack = "aaa";
    // char *needle = "aaaa";
    // char *haystack = "";
    // char *needle = "";
    char *haystack ="mississippi";
    char *needle ="issip"; // result = 4
    // char *haystack ="aaaaa";
    // char *needle ="bba"; // -1
    // char *haystack ="abc";
    // char *needle ="c"; // 2
    int result;
    result = strStr(haystack,needle);
    printf("%d ",result);
    printf("\r\n");
    return;
}