link : https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=problem-list-v2&envId=greedy
//code C : 
//#include<string.h>
char* maximumOddBinaryNumber(char* s) {
    int len=strlen(s);
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]=='1') cnt++;
    }
    char *res=(char*)malloc((len+1)*sizeof(char));
    if (!res) return NULL; // kiểm tra cấp phát thành công
    res[len]='\0';
    res[len-1]='1';
    for(int i=0;i<len-1;i++){
        if(i<cnt-1) res[i]='1';
        else res[i]='0';
        
    }
    return res;    
}
