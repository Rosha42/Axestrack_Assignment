#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Queue
{
	char info;
	struct Queue *next;
}*top=NULL,*rear=NULL;

int Hex2decimal(char * s) {
             char * digits = "0123456789abcdef";
             int val = 0;int i=0;
             while (i<2) 
			 {
				 int d=0;
			     tolower(*(s+i));
				 while(*(digits+d)!=*(s+i)){
				 d++;
				 }
                 val = 16*val + d;
				
				 i++;
             }
             return val;
         }
		 
		 
void En_Queue(char data)
{
    if (rear == NULL)
    {
        rear = (struct Queue*)malloc(1*sizeof(struct Queue));
        rear->next = NULL;
        rear->info = data;
        top = rear;
    }
    else
    {
        struct Queue *temp=(struct Queue *)malloc(1*sizeof(struct Queue));
        rear->next = temp;
        temp->info = data;
        temp->next = NULL;
 
        rear = temp;
    }

}


void Deque()
{
    struct Queue *front1 = top;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else{
		while(front1->next!=NULL)
		{
            front1 = front1->next;
            printf("%c", top->info);
            free(top);
            top = front1;
            
	    }
	if (front1->next == NULL)
			{	printf("%c", top->info);
				free(top);
				rear = NULL;
			top = NULL;
			}
	}
	printf("\n");
}
	  
void Hex_Stream(char * start,char *end,char *hex_string)
{
    int i=0;
	while(*(hex_string+i))
	{
		int j=0;
	   while (*(start+j))
	   {
		   if(*(start+j)==*(hex_string+(i)))
		   {
			   En_Queue(*(hex_string+(i++)));
		       j++;
		   }
		  else break;		   
	   } 
	   char *hex_length=NULL;
	   hex_length=(char *)malloc(sizeof(char)*2);
	   *(hex_length+0)=*(hex_string+(i++));
	   *(hex_length+1)=*(hex_string+(i++));
	   int Dec_length = Hex2decimal(hex_length);
	   for(j=i-2;j<(i+(2*Dec_length));j++)
	          En_Queue(*(hex_string+(j)));   
	   i+=2*Dec_length;
	   
	   j=0;
	   while (*(end+j))
	   {
		   if(*(end+j)==*(hex_string+(i))){
			     En_Queue(*(hex_string+(i++)));
		   j++;}
		  else break;		   
	   } 
	   if(j==4)
	   Deque();
       else break;
	}   
}	

int main()
{
char *start="0x900x00";
char *end="0x0d0x0a";
char *start_bits=NULL;
char *end_bits=NULL;
start_bits=(char *)malloc(sizeof(char)*4);
end_bits=(char *)malloc(sizeof(char)*4);
int i=0;int j=0,k=0;
char *s="90000d01035889905270194601894e590d0a90000a134406040002018b8f5e0d0a90001f12100c1b060a17ca033619bc086213e016554701946100c90032fc017c8b6e0d0a90001f12100c1b060a21ca03361cf8086211a012554901946100c90032fc017da1e60d0a90001f12100c1b060a2bc80336206408620f201a554701946100c90078d4017e07d80d0a90001f12100c1b060a35c9033623a408620cb015554801946100c90078d4017f73470d0a90001f12100c1b060b03c90336265c08620ad00e554901946100c90078d4018079a40d0a90001f12100c1b060b17c903362840086208900f552101946100c90078d40183de740d0a90001f12100c1b060b21c903362bbc086205201e553701946100c90078d4018411c50d0a90001f12100c1b060b2bc903362e3c086202700c554001946100c90078d40185fd5a0d0a90001f12100c1b060b35c903363050086200a00f554501946100c900a840018742d80d0a90001f12100c1b060c11c90336313c0861ff8000553101946100c900a840018ac61b0d0a90002516100c1b060c1ec90336313c0861ff800055310901946100c900a8404406040e02018c6edf0d0a";
while (*(start+i))
{
	if(i%4==2 || i%4==3 ){
	*(end_bits+(k++))=*(end+i);
	*(start_bits+(j++))=*(start+i);
	}
	i++;
}
Hex_Stream(start_bits,end_bits,s);
return 0;
}