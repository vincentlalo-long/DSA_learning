// viết hàm để sỉnh ra các xâu hoán vị của chuỗi 
// COde C++ : 

#include <stdio.h>
#include<string.h>
#include<stdbool.h>
// Bài toán liệt kê hoán vị xâu
void swap(char *a,char*b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void generate_string(char *str,int left , int right){
    if(left==right) {
        printf("%s",str);
        printf("\n");
    }
    else{
        bool visited[256]={false};
        for(int i=left;i<=right;i++){
            if(!visited[(unsigned char)str[i]]){ // ép kiểu str[i] về chữ số có dấu nên đổi sang hệ ACSII sẽ là số dương
                visited[(unsigned char)str[i]]=true;        
            
                swap(&str[i],&str[left]);
            
                generate_string(str,left+1,right);
                swap(&str[left],&str[i]);
        }   
        }
    }
    
}
int main() {
	// your code goes here
	char str[1000];
	scanf("%s",str);
	int strle=strlen(str);
	generate_string(str,0,strle-1);

}

