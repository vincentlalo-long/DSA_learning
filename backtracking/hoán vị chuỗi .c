// viết hàm để sỉnh ra các xâu hoán vị của chuỗi 
// COde C++ : 

#include <stdio.h>
#include<string.h>
// Bài toán liệt kê hoán vị xâu
void swap(char *a,char*b){
    char temp=*a;
    *a=*b;
    *b=temp;
} // Hoán đổi 2 kí tự
void generate_string(char *str,int left , int right){
    if(left==right) {
        printf("%s",str);
        printf("\n");
    }
    else{
        for(int i=left;i<=right;i++){
            swap(&str[i],&str[left]);
            generate_string(str,left+1,right);
            swap(&str[left],&str[i]); // Hoán đổi lại để tiếp tục backtrack 
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
// T(n)=n.O(n!)

