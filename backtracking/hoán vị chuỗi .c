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

// cây tìm kiếm cho TH ABCA 
Level 0 (left = 0)
|
|-- swap(0,0): A B C A
|    |
|    |-- Level 1 (left = 1)
|         |
|         |-- swap(1,1): A B C A
|         |    |
|         |    |-- Level 2 (left = 2)
|         |         |
|         |         |-- swap(2,2): A B C A
|         |         |    |
|         |         |    |-- Level 3 (left = 3): In ra ABCA
|         |         |
|         |         |-- swap(2,3): A B A C
|         |              |
|         |              |-- Level 3 (left = 3): In ra ABAC
|         |
|         |-- swap(1,2): A C B A
|         |    |
|         |    |-- Level 2 (left = 2)
|         |         |
|         |         |-- swap(2,2): A C B A
|         |         |    |
|         |         |    |-- Level 3 (left = 3): In ra ACBA
|         |         |
|         |         |-- swap(2,3): A C A B
|         |              |
|         |              |-- Level 3 (left = 3): In ra ACAB
|         |
|         |-- swap(1,3): A A C B
|              |
|              |-- Level 2 (left = 2)
|                   |
|                   |-- swap(2,2): A A C B
|                   |    |
|                   |    |-- Level 3 (left = 3): In ra AACB
|                   |
|                   |-- swap(2,3): A A B C
|                        |
|                        |-- Level 3 (left = 3): In ra AABC
|
|-- swap(0,1): B A C A
|    |
|    |-- Level 1 (left = 1)
|         |
|         |-- swap(1,1): B A C A
|         |    |
|         |    |-- Level 2 (left = 2)
|         |         ...
|         ... (và tương tự tiếp tục)
|
|-- swap(0,2): C B A A
|    |
|    |-- Level 1 (left = 1)
|         ...
|
|-- swap(0,3): A B C A (swap chữ A cuối)
|    |
|    |-- Level 1 (left = 1)
|         ...


