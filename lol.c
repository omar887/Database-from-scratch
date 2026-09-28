#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
typedef struct{
    char* buffer; //to hold the input
    size_t blength; //length of buffer
    int ilength; //actual inpuit length
}inputbuffer;


ssize_t getline(char **lineptr, size_t *n, FILE *stream);
inputbuffer* read_inputb(){
inputbuffer* input = (inputbuffer*)malloc(sizeof(inputbuffer));//creates object and when malloc returns a (void*) we cast it to inputerbuffer pointer 
input->buffer = NULL;//
input->blength=0;//
input->ilength=0;//
return input;//returns the poitner that point to the inputbuffer object
}


void printspecial(){
    printf("|db ");
}


void read_input(inputbuffer* inputbuffer){
    int ilength= getline(&(inputbuffer->buffer),&(inputbuffer->blength),stdin);  //makes the object and also puts the actual input in it
    if(ilength<=0){
    printf("invalid\n");
    exit(1);
    }
    inputbuffer->ilength=ilength-1; //to remove getline inserted character
    inputbuffer->buffer[ilength-1]=0; // 0 acts as terminator
}
void closeinput(inputbuffer* inputbuffer){ //free up the space
    free(inputbuffer->buffer);
    free(inputbuffer);
}


int main(){
    inputbuffer* input = read_inputb();//placeholder for the input
    while(1){
        printspecial();//print |db
        read_input(input);//takes the input that got put into the buffer
        if(strcmp(input->buffer,"#exit")==0){
            closeinput(input);
            exit(0);
        }
        else{
                printf("not in the list of commands '%s'\n",input->buffer);
        }
    }
}