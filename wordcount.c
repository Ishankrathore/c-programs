#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[1000];  
    int i,words=0;
 
    printf("Enter  the string : ");
    gets(s);
     
    for(i=0;s[i]!=NULL;i++)  
    {
    	if(s[i]==32)
    	 words++;
 
 	}
 	if(i>0)
 	 words++;
 	 
 	
     
    printf("no of words in string = %d\n",words);
    
    return 0;
}