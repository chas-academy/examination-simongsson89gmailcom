//Write your code in this file
#include<stdio.h>
#define MAX_PERSON 5

int main()
{
    
    char name[MAX_PERSON][10];
    char personBelowAvg[MAX_PERSON][10];
    char k=0;
    char j=0;
    char trigg=0;
    unsigned int sum_avg[MAX_PERSON];
    unsigned int tot_sum=0;
    char c=0;
    unsigned int highest_avg=0; 
    unsigned int group_avg=0;   
    char person=0;  
    while(c!='\n' && j<=MAX_PERSON)
    {   
        scanf("%c", &c);
        if((c>='A' && c<='Z') || c>='a' && c<='z') 
        {
            name[j][k++]=c;
            if(name[j][0]>='a' && name[j][0]<='z')
            {
                name[j][0]=c-32;
            }          
             
            trigg=1; 
        }        
        else if(c==' ' && trigg==1)
        {   
            sum_avg[j++]=0;
            trigg=0;
            k=0;
        }
        else if(c>='0' && c<='9')
        {
            tot_sum=tot_sum*10+(c-'0'); 
        }
        else if(c==' ')
        {
            sum_avg[j-1]+=tot_sum; 
            tot_sum=0;
        }        
    }
    sum_avg[j-1]+=tot_sum;
    for(int i=0; i<j; i++)
    {
        
        sum_avg[i]=sum_avg[i]/13;
        group_avg+=sum_avg[i]; 
    }
    group_avg=group_avg/5;
    for(int i=0; i<j; i++)
    {   
        if(highest_avg<sum_avg[i])
        { 
            highest_avg=sum_avg[i];
            person=i;
        }

    }
    printf("%s\n", name[person]);   
    for(int i=0; i<MAX_PERSON;i++)
    {
        if(sum_avg[i]<group_avg)
        { 
            printf("%s\n", name[i]);                                          
        }    
    }
}
