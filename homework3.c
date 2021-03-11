#include<stdio.h>
#define FALSE 0
#define TRUE 1
int main(){
    int c,flag=FALSE,flag2=FALSE,flag3=FALSE;

    while((c=getchar())!=EOF){

        if(c=='(' || c=='[' || c=='{' || c=='<' || c=='"' && flag3==FALSE){
            if(c=='"'){
                flag3=TRUE;
            }
            flag2=TRUE;
        }else if(c==')' || c==']' || c=='}' || c=='>' || c=='"'){
            flag3=FALSE;
            flag2=FALSE;
        }

        if(c=='.' || c==',' || c==';' || c==':' || c=='?' || c=='!' || c=='-' || c=='_'){
            continue;
        }
        else if(c>='0' && c<='9' && flag2==FALSE){
            if(flag==FALSE){
            putchar('X');
            }
            flag=TRUE;
        }
        else {
            putchar(c);
            flag=FALSE;
            }
    }
    return 0;   // I Support me in the book "Fundamentals of programming, Think in C" by Osvaldo Cairó Battistotti
}