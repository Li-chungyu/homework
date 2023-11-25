#include<stdio.h>
#include<string.h>

void PrintLongestSubstring(char s[],int start,int end){
    for(int i=start;i<=end;i++){
        printf("%c",s[i]);
    }
}

void LengthOfSubstring(char s[]){
    int n=strlen(s);
    int MaxLength = 0;
    int Start = 0;
    int ResultStart = 0;//保存最長字串起始位置
    int ResultEnd = 0;//保存最長字串結束位置
    int CharIndex[128];

    memset(CharIndex, -1 ,sizeof(CharIndex));//將CharIndex的每個元素都初始化為-1

    for(int end=0;end<n;end++){
        if(CharIndex[s[end]]>=Start){
            //若字符出現過則更新起始位置
            Start = CharIndex[s[end]]+1;
        }

        CharIndex[s[end]]=end;
        int CurrentLength = end - Start + 1;
        if(CurrentLength>MaxLength){
            MaxLength = CurrentLength;
            ResultStart = Start;
            ResultEnd = end;
        }
    }

    PrintLongestSubstring(s , ResultStart , ResultEnd);   

    return;
} 

int main(){
    char input[1000];
    scanf("%s",input);
    
    LengthOfSubstring(input);
    
    return 0;
}
