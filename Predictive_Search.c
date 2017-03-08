#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Alph 28

struct Word_list {
    char * string;
	struct Word_list *next;
    struct Word_list *count[Alph];
} * head[Alph]={NULL};



struct result{
	char *r_string;
	struct result *next1;
}*r_head=NULL;



int Cal_index(char a)
{
    if(a=='\'')
		return 26;
	else if(a-97<0)
		return 27;
	else
	  return a-97;
}


void free_Word1(struct result *bnp){
    if(bnp == NULL) return;
    free(bnp->r_string);
	free_Word1(bnp->next1);
	free(bnp);	   
}

void addEntry(char * T, int i,int j){
    struct Word_list * tempNode, * iterator;
    tempNode = (struct Word_list *)malloc(sizeof(struct Word_list));
    tempNode->string = (char *)malloc(strlen(T)+1);
    strcpy(tempNode->string, T);
    tempNode->next = NULL;
    iterator = head[i]->count[j];
    if (head[i]->count[j] == NULL){
        head[i]->count[j] = tempNode;
    } else {
        while(iterator->next != NULL){
            iterator = iterator->next;
        }
        iterator->next = tempNode;
    }
}


struct result * r_addEntry(char * T){
    struct result* tempNode, * iterator;
    tempNode = (struct result *)malloc(sizeof(struct result));
    tempNode->r_string = (char *)malloc(strlen(T)+1);
    strcpy(tempNode->r_string, T);
    tempNode->next1 = NULL;
    iterator = r_head;
    if (r_head == NULL){
        r_head = tempNode;
    } else {
        while(iterator->next1 != NULL){
            iterator = iterator->next1;
        }
        iterator->next1 = tempNode;
    }
}


struct Word_list* createnode()
{
	struct Word_list * tempnode;
    tempnode = (struct Word_list *)malloc(sizeof(struct Word_list));
	int j;
	for(j=0;j<Alph;j++)
	{	
	tempnode->count[j]=NULL;
	}
	tempnode->next=NULL;
	tempnode->string=NULL;
	return tempnode;
}



void search(char *check)
{
	

	if(strlen(check)==1)
	{
		for(int i=0;i<Alph;i++)
		{
			struct Word_list* temp=head[Cal_index(*(check+0))]->count[i];
			while(temp!=NULL)
			{
				r_addEntry(temp->string);
				temp=temp->next;
	}}}
	else if(strlen(check)==2)
	{
		struct Word_list* temp=head[Cal_index(*(check+0))]->count[Cal_index(*(check+1))];
			while(temp!=NULL)
			{
				r_addEntry(temp->string);
				temp=temp->next;
	}}
	else if(strlen(check)>2)
	{
		struct Word_list* temp=head[Cal_index(*(check+0))]->count[Cal_index(*(check+1))];
		while(temp!=NULL)
			{
				int count=0;
				for(int i=2;i<strlen(check);i++)
				{
					if(*(check+i)==*(temp->string+i))
						count++;
					else
						continue;
				}
				if(count==(strlen(check)-2))
				   r_addEntry(temp->string);
				temp=temp->next;
	}}
	

}


int main() 
   {
    FILE * fpointer;
    fpointer=fopen("word_list.txt","r");
    if(fpointer == NULL){
        printf("Booklist could not be opened.\n");
        exit(EXIT_FAILURE);
    }
    char title[40];
	for(int i=0;i<Alph;i++){
		head[i]=createnode();
	}
    while (EOF!=fscanf(fpointer, "%s", title)){
         addEntry(title,Cal_index(title[0]),Cal_index(title[1]));
    }
	   fclose(fpointer);
	
	char *check=(char *)malloc(sizeof(char )*20);
		scanf("%s",check);
		search(check);
		struct result *result_print=r_head;
		if(result_print==NULL)
			printf("Words doesnot exist");
		while(result_print)
		{
			printf("%s \n", result_print->r_string);
			result_print=result_print->next1;
		}
	    free_Word1(r_head);	
		free(check);
    return 0;
}

