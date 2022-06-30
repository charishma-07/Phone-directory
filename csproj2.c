#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{ char Name[15];
  char Phnum[11];
  struct Node* next;
};


     //size of hash table is 26
struct Node** arr; // To globally declare this array , used concept of pointer to a pointer


void Arr() //  Intialise all pointers in the array to NULL
 {
 	int j;
    for(j=0; j<26 ; j++) 
        arr[j] = NULL;
 }

int getkey(char ch)//a funtion that returns its position among all alphabets
{
     int count =0;
     char var;
  for(var = 'a' ;var <= 'z';var++)
   {
      if(var == ch)
         { 
          return count;
         }
      count++;
   }
    
}

void Insert()
 {
    struct Node* t = malloc(sizeof(struct Node));
    printf("\nEnter the name: ");
    scanf("%s",t->Name);
    printf("\nEnter the phone number: ");
    scanf("%s",t->Phnum);
    t->next =NULL;
    
    int index = getkey(t->Name[0]);
    if(arr[index] == NULL)
          arr[index] = t;
     else
     {
         t->next = arr[index];
         arr[index] =t;
     }
 }

void Search()
{
   char name[15];
   printf("Enter the name of contact You want to search: \n");
   scanf("%s",name);
   int index = getkey(name[0]);
   
   struct Node* tmp = arr[index];
    while(tmp != NULL)
    {
       if(strcmp(tmp->Name,name) == 0) 
        { 
            printf("                                Contact Details\n");
            printf("  Name         : %s\n  Phone Number : %s\n",tmp->Name,tmp->Phnum);
            return;
        }
        tmp =tmp->next;
    }
    printf("Contact not found! ");
    
}

void Display()
{
  printf("\n                                All Contacts\n");
  int total =0;
  for(int i =0;i<26;i++)
   {  
       struct Node* tmp = arr[i];
            
             while(tmp != NULL)
                   {
                       printf("  %s - %s\n",tmp->Name,tmp->Phnum);
                       tmp = tmp->next;
                       total++;
                   }
          
   }
   printf("\n       Total  %d contacts\n",total);
   
   if(total == 0)
    printf("   NO CONTACTS \n");
}

void Delete()
{
    char name[15];
    printf("Enter the name of contact You want to delete: ");
    scanf("%s",name);
    int index = getkey(name[0]); 
    
     struct Node*tmp = arr[index];
     struct Node*p = tmp;
     
     while(tmp != NULL)
     {
          if(strcmp(tmp->Name,name) == 0) 
          {
              if(tmp == arr[index])
                {
                    if(tmp->next == NULL)
                         arr[index] = NULL;
                     else
                     {
                         arr[index] = tmp->next;
                         tmp->next = NULL;
                     }
                }
              
              else if(tmp->next == NULL)
              {
                   while(p->next != tmp)
                      p = p->next;
                    p->next = NULL;
                 
              }
              
              else
              { 
                  while(p->next != tmp)
                      p = p->next;
                   p->next = tmp->next;
                   tmp->next = NULL;
              }
          }
         tmp = tmp->next;
     }

}

void Edit()
{
    char name[15];
    printf("Enter the name of contact You want to edit: ");
    scanf("%s",name);
    int index = getkey(name[0]); 
    
    struct Node* tmp = arr[index];
        while(tmp != NULL)
    {
       if(strcmp(tmp->Name,name) == 0) 
        { 
           printf("                                Contact Details\n");
           printf("  Name         : %s\n  Phone Number : %s\n",tmp->Name,tmp->Phnum);
           
           printf("\nEnter the Name: ");
           scanf("%s",tmp->Name);
           printf("\nEnter the phone number: ");
           scanf("%s",tmp->Phnum);
            return;
        }
        tmp =tmp->next;
    }
    
}


int main()
{
    arr = malloc(26*sizeof(struct Node*)); // Dynamically allocates an array of size 26
    Arr();
    
    int a;
    printf("                               Welcome to Phone Directory\n");
    printf("\n\n");
    printf("                  { ENTER THE NAME IN SMALL LETTERS WITHOUT SPACES IN BETWEEN!} \n");
    while(1)  
  {
        printf("\n1. To Save a New contact\n2. View all contacts\n3. Search for a contact\n4. To Delete a contact\n5. To Edit Contact details\n6. Quit\n ");
        printf("Enter your choice: ");
        scanf("%d",&a);
    switch(a)
    {
        case 1:     
          Insert();
          break;

        case 2:
          Display();
          break;
          
        case 3:
          Search();
          break;
          
        case 4:
          Delete();
          break;
          
        case 5:
          Edit();
          break;
          
        case 6:
          exit(0);

        default:
          printf("ENTER THE OPTION AMONG ABOVE ONES!!!\n");
          break;
    }
     
  }
    free(arr);
    return 0;
}
