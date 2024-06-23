#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define MAX_LENGTH 50
const char *c[N] ;
const char *d[N] ;

struct Node {
    char c_code[MAX_LENGTH];    

    char cources[MAX_LENGTH];  
    struct Node *next;
};

struct Node *node_head = NULL;  


void insert_front(int c_select) {
    struct Node *yeniNode = (struct Node*)malloc(sizeof(struct Node));
    if (yeniNode == NULL) {
        printf("does not working!\n");
        exit(1);
    }
    strcpy(yeniNode->c_code, c[c_select ]);
    strcpy(yeniNode->cources, d[c_select ]);
    yeniNode->next = node_head;
    node_head = yeniNode;
}

void insert_rear(int c_select) {
    struct Node *yeniNode = (struct Node*)malloc(sizeof(struct Node));
    if (yeniNode == NULL) {
        printf("does not working!\n");
        exit(1);
    }
    strcpy(yeniNode->c_code, c[c_select ]);
    strcpy(yeniNode->cources, d[c_select ]);
    yeniNode->next = NULL;
    if (node_head == NULL) {
       node_head= yeniNode;
        return;
    }
    struct Node *last = node_head;
    while (last->next != NULL)
        last = last->next;
    last->next = yeniNode;
}
int course_check(int c_select){
    struct Node *temp = node_head;
    while(temp!=NULL){
    if(strcmp(c[c_select],temp->c_code)==0){
        printf("kurs var.\n");
        return 0;
       
    }
    temp=temp->next;
    
}
    return 1;
}

void print_cl() {
    struct Node *temp = node_head;
    if (temp == NULL) {
        printf("The Favorite List is empty.\n");
        return;
    }
    printf("The updated Favorite List is:\n");
    while (temp != NULL) {
        printf("%s - %s\n", temp->c_code, temp->cources);
        temp = temp->next;
    }
}

int main() {


c[0]="EE311";  d[0]="digital Electronics";
c[1]="EE411";   d[1]="fundamental of fotonıc ";
c[2]="EE425";     d[2]="mıcrowave engıneering";
c[3]="EE443";    d[3]="embeded systems";
c[4]="EE455";    d[4]="mobıle comunıcatıon";
c[5]="EE461";    d[5]="nonlınear control system";

    int oSel, CSel;
    int i;
    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Add a course at the front of the Favorite List\n");
        printf("2. Add a course at the end of the Favorite List\n");
        scanf("%d",&oSel); 
        printf("select a course\n");
        
        
            for (int i = 0; i < N; i++) {
                printf("%d. %s - %s\n", i + 1, c[i], d[i]);
            }

            scanf("%d", &CSel); 
            
           
         if (course_check(CSel-1) == 0) 
          
           continue;

            switch (oSel)
            {
            case 1: insert_front(CSel-1);
           
                break;
            case 2: insert_rear(CSel-1);
                break;
            default:
                printf("please select either add_front or add_end option)(1 or 2)");
                   break;
            }
            printf("/n the uptaded courselist is:\n");
                print_cl();
            }
         
    return 0;
}

