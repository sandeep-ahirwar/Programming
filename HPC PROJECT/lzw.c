#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>

char *randstring(int length) {    
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    size_t stringLen = strlen(string);        
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {            
            key = rand() % stringLen;          
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;        
    }
    else {
        printf("No memory");
        exit(1);
    }
}
struct input{
   int indexValue;
   char word[10];
};
struct input table[300];
struct input output_code[50];

int search(char key[10])
{ 
int i;
    for(i=0; i<=300; i++)
    {
        if(0==strcmp(table[i].word,key))
        {
             return 1;		 
        }
    }
return 0;  
}

int searchIndex(char key[10])
{ 
int i;
    for(i=0; i<=300; i++)
    {
        if(0==strcmp(table[i].word,key))
        {
             return i;		 
        }
    }
return 0;  
}

int encoding(char seq[]){
	int i,r=0,lastIndex;
	for (i = 0; i <= 255; i++) {
        table[i].indexValue=i;
        table[i].word[0]=i;
    }
    char p[10]={'\0'};
	char c[10]={'\0'};
    memcpy(p,seq,1);
    int code = 255;
    for (i = 0; i < strlen(seq); i++) {
        if (i != strlen(seq) - 1){
		   c[0]=seq[i+1];
        }
        
        char combo[10]={'\0'};
		strcpy(combo,p); 
        if (search(strcat(combo,c))) {
            strcat(p,c);
        }
        else {
        
			strcpy(output_code[r].word,p);
			output_code[r].indexValue = searchIndex(p);
			lastIndex = code+1;
        	strcpy(table[lastIndex].word,strcat(p,c));
        	table[lastIndex].indexValue=code;
        	code= code+1;
        	r=r+1;
        	strcpy(p, c);
        }
        c[0]='\0';
    }
    strcpy(output_code[r].word,p);
    output_code[r].indexValue = searchIndex(p);
    
    printf("Segmented words are: ");
    for (i = 0; i <=r; i++){
    	printf("%s  ",output_code[i].word);
	 }
	 
	printf("\n\nFinal encoded output is: ");
    for (i = 0; i <=r; i++){
    	printf("%d  ",output_code[i].indexValue);
	 }
    return 0;
}
int main(){
    char seq = randstring(100);
    printf("\nEntered sequence is %s\n",seq);
    printf("Started Encoding.......................................\n");
    encoding(seq);
    return 0;
}