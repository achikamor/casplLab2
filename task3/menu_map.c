#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char censor(char c) {
    if(c == '!')
        return '.';
    else
        return c;
}

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    int i;
    for(i=0;i<array_length;i++)
        mapped_array[i]=f(array[i]);
    free(array);
    return mapped_array;
}

char encrypt(char c){
    if(c>=32 && c<=126)
        c=c+3;
    return c;
}

char decrypt(char c){
    if(c>=32 && c<=126)
        c=c-3;
    return c;
}

char xprt(char c){
    printf("0x%X \n",c);
    return c;
}

char cprt(char c){
    if(c>=32 && c<=126)
        printf("%c \n",c);
    else
        printf("%c \n",'.');
    return c;
}

char my_get(char c){
    char x=fgetc(stdin);
    return x;
}
char quit(char c){
    exit(0);
    return c;
}

struct fun_desc {
    char *name;
    char (*fun)(char);
};



int main(int argc, char **argv){
    char* emptyString = (char*)(malloc(5*sizeof(char)));
    emptyString[0]='\0';
    char* carray=&emptyString[0];
    char* temp;
    struct fun_desc farray[]={{"censor",censor},{"encrypt",encrypt},{"decrypt",decrypt},{"xprt",xprt},{"cprt",cprt},{"my_get",my_get},{"quit",quit},{NULL,NULL}};
    int i;
    int choosen;
    int size=(sizeof(farray))/(sizeof(farray[0]));
    while(1){
        printf("Please choose a function: \n");
        for(i=0;i<size-1;i++)
            printf("%d" "%s" "%s \n",i,") ", farray[i].name);
        printf("%s","Option: ");
        scanf("%d",&choosen);
        fgetc(stdin);       //to avoid the enter that enters after the numbers
        if(choosen<=size-1)
            printf("%s","Within bounds\n");
        else{
            printf("%s","Not within bounds\n");
            free(carray);
            quit('c');
        }
        temp=map(carray,5,farray[choosen].fun);
        carray=temp;
        printf("%s","DONE.\n");
    }
}
