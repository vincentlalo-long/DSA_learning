//Up coming
bool isValid(char* s) {
    char stack[10000];
    int top=-1;
    // Code để push phần tử vào stack : 
    //int len=strlen(s);
    for(int i=0;s[i]!='\0';i++){
        //stack[++top]=char[i];
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            stack[++top]=s[i];
        }
        else{
            if(top==-1) return false;
            char open=stack[top--];
            if(open=='('&&s[i]!=')'||
               open=='{'&&s[i]!='}'||
               open=='['&&s[i]!=']'){
                return false;
               }
        }
    }
    return (top==-1);

}
