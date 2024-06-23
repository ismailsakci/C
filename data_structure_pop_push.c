#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define totalcard 13
#define card_perplayer 3
#define players 4

struct stack{
    char item[totalcard];
    int count;
};


void initialize(struct stack *s){
    s->count=0;
}

void push(struct stack *s,char newvalue){
    if(s->count==totalcard){
        printf("stack is full\n");
        return;
    }
    else{
         s->item[s->count]=newvalue;
         s->count++;
    }
}
char pop(struct stack *s){
    char element;
    if(s->count==0){
        printf("stack is empty\n");
        exit(1);
    }
    else{
        s->count--;
        element=s->item[s->count];
        return element;
    }
}

void shufflecards(struct stack *deck,int n){
    srand(time(NULL));
    struct stack tempa;
    // char  deck[10];
    //struct Deck deck2;
   // struct Deck deck3;

    for(int i=0;i<n;i++){
        int j=i +rand()%(n-i);
         tempa =deck[j];
        deck[j]=deck[i];
        deck[i]=tempa;
    }
}


void dealcards( struct stack *s[]){
    char values[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};



//shufflecards(s,totalcard);


}
// printcards to screen 
void displaycard(struct Stack *s,int size){

}
void playercard(struct Stack *s,int size){

}

int main (){
 struct Stack s;
    char c;
    char str[50];
  
  
    struct stack *playerstack[players];
    for(int i=0;i<=players;i++);
    playerstacks[i]=(stack *malloc(sizeof));
    initialize(playerstakcs[i]);


dealcards(playerstacks);
displaycards(playercards);
checkwinner(playerstcaks);
for(int i=0;i<players;i++){
    free(playerstcaks[i]);
}
push(&s,10);
pop(&s);
return 0;

}
