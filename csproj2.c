#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define SIZE 20
struct node {
    int key;
    char name[100];
    char number[100];
    char mail[100];
    struct node * next;
};
typedef struct node * NODE;
struct hash {
    struct node * head;
    int count;
};
struct hash * hashTable = NULL; //initialising all pointers in Hash Table to NULL
NODE createNode(int key, char * name, char * number, char * mail) {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct node));
    temp -> key = key;
    strcpy(temp -> number, number);
    strcpy(temp -> name, name);
    strcpy(temp -> mail, mail);
    temp -> next = NULL;
    return temp;
}
void insertToHash(int key, char * name, char * number, char * mail) {
    int hashIndex = key % SIZE;
    NODE newnode = createNode(key, name, number, mail); // head of list for the array element with index "hashIndex"
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    newnode -> next = (hashTable[hashIndex].head); // adding new node to the list
    hashTable[hashIndex].head = newnode; //incrementing number of nodes in List
    hashTable[hashIndex].count++;
    return;
}
void deleteFromHash(int key, char * name) {
    int hashIndex = key % SIZE, flag = 0; // finding the index using hash key
    NODE temp, cur;
    cur = hashTable[hashIndex].head; // cur pointing to first node of the hash index
    if (!cur) {
        printf("Given data is not present in hash Table!!\n");
        return;
    }
    temp = cur;
    while (cur != NULL) {
        if (cur -> key == key && strcmp(cur -> name, name) == 0) // delete the node with given key and name
        {
            flag = 1;
            if (cur == hashTable[hashIndex].head)
                hashTable[hashIndex].head = cur -> next;
            else
                temp -> next = cur -> next;
            hashTable[hashIndex].count--;
            free(cur);
            break;
        }
        temp = cur;
        cur = cur -> next;
    }
    if (flag)
        printf("Data deleted successfully from Hash Table\n");
    else
        printf("Given data is not present in hash Table!!!!\n");
    return;
}
void searchInHash(int key) {
    int hashIndex = key % SIZE, flag = 0;
    NODE myNode;
    myNode = hashTable[hashIndex].head;
    if (myNode == NULL) {
        printf("Search element unavailable in hash table\n");
        return;
    }
    while (myNode != NULL) {
        if (myNode -> key == key) {
        	printf("Searched element available in hash table\n");
            printf("Name : %s\n", myNode -> name);
            printf("Number : %s\n", myNode -> number);
            printf("Mail ID : %s\n", myNode -> mail);
            flag = 1;
            break;
        }
        myNode = myNode -> next;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}
void display() {
    NODE myNode;
    int i;
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        printf("\nData at index %d in Hash Table:\n", i);
        printf("Name Number Mail ID \n");
        printf("--------------------------------------------\n");
        while (myNode != NULL) {
            printf("%-15s", myNode -> name);
            printf("%s\t\t", myNode -> number);
            printf("%s\n", myNode -> mail);
            myNode = myNode -> next;
        }
    }
    return;
}
int main() 
{ 
    int i;
    char name[20], number[20];
    int c;
    char input[100], mail[100];
    char choice = 'y', d;
    hashTable = (NODE) calloc(SIZE, sizeof(struct hash));
    char name_select[20], e, f = 'y';
    int ch;
    for (;;) {
        printf("\n 1.Add New Contact\n 2.View all the contacts\n 3.Search the contact \n 4.Delete the contact\n 5.Modify the contact\n");
        scanf("%d", & ch);
        switch (ch) 
        {
            case 1:
                printf("\nEnter new contact name: ");
                scanf("%s", name);
                int key = 0;
                for (i = 0; name[i] != '\0'; i++) {
                    key = key + (name[i] - '0');
                }
                printf("Enter new contact number: ");
                scanf("%s", number);
                printf("Enter the mail ID\n");
                scanf("%s", mail);
                insertToHash(key, name, number, mail);
                break;
            case 2:
                display();
				break;
            case 3:
                printf("\nSelect the contact you want to access \n");
                scanf("%s", name_select);
                int c;
                int key1 = 0;
                for (c = 0; name_select[c] != '\0'; c++)
                    key1 = key1 + (name_select[c] - '0');
                searchInHash(key1);
                break;
            case 4:
            	printf("\nSelect the contact you want to access \n");
                scanf("%s", name_select);
                int a;
                int key2 = 0;
                for (a = 0; name_select[a] != '\0'; a++)
                    key2 = key2 + (name_select[a] - '0');
                deleteFromHash(key2, name_select);
                break;
            case 5:
                exit(0);
    }
    }
    return 0;
}
