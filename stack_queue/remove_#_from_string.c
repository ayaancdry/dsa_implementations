/* 
You are given a string s, which contains hashtags #.
In one operation, you can:
1. Choose a hashtag # in s.
2. Remove the closest non-hashtag character to its left and remove the hashtag itself.
Return the string after all hashtags have been removed.

Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Input Format:
A string s, consisting of lowercase English letters and hashtags #

Output Format:
A string, representing the final string after performing all the operations.
 
Sample Input 1 :
abc###def#g##

Sample Output 1:
d

Sample Input 2 :
pqr#stu##vw###

Sample Output 2:
pq*/

#include <stdio.h>
#include <string.h>

char* removeHashtags(char* s) {
    //Write  your Code Here
    int length = strlen(s);
    char* stack = (char*)malloc(length + 1); //allocate stack dynamically
    int top = -1;

    for (int i = 0; i < length; i++) {
        if (s[i] == '#') {
            if (top >= 0) {
                top--;
            }
        } else {
            stack[++top] = s[i];
        }
    }

    //allocate result and copy the stack contents
    char* result = (char*)malloc(top + 2); //+1 for characters, +1 for null terminator
    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0';
    free(stack); //free the temporary stack
    return result;
    
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%s", removeHashtags(s));
    return 0;
}