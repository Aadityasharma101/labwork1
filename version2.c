#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
struct product

{
    int pId;
    char pName[50];
float price;
int stockQty;
};
struct list
{
    int count;
    struct product items[MAX];
};
int isEmpty(struct list*);
int isFull(struct list*);
int insertAtFront(struct list*,struct product);
int insertAtEnd(struct list*, struct product);
int insertBeforeFront(struct list*,struct product,int);
int insertBeforeEnd(struct list *,struct product,int);

int removeFromFront(struct list*);
int removeFromLst(struct list*);
int removeAnyO(struct list*,int);



void display(struct list*);


int saveToDisk(struct list*,char*);

int readFromDisk(struct list*,char*);
void main()

    char choice;
    int x,y
    do{
        x=15;y=7
        gotoxy(15,y++);
        printf("Select your choice:\n");
        gotoxy(15,y++);
        printf("[1]insert");
        gotoxy(15,y++);
        printf("[2]remove");
        gotoxy(15,y++);
        printf("[3]list")
        gotoxy()
        fflush(stdin);
        choice=getch();
        switch(choice)
        {
            case'1' :
                     break;
                     case'2' : 
                                break;
                                case'3': 
                                        break;
                                        case'4'  :
                                          break;

        }
    }
}