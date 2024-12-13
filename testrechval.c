#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llc.c"

//craete the list
void create_llc(ptr *h, int n) {
    ptr p, q;
    int i, val,x;

    if ( n == 0 ) //if n == 0 its an empty list
    {
        *h = NULL;
    }
    else 
    {
        allocate(&p); //the first node
        printf("assign a value to the node n-1 : ");
        scanf("%d", &val);
        ass_val(p, val);
        *h = p;
        for ( i = 1; i < n; i++) //from the second node
        {
            allocate(&q);
            printf("assign a value to the node n-%d : ", i+1);
            scanf("%d", &val);
            ass_val(q, val);
            ass_addr(p, q);
            p = q;
        }
        ass_addr(p, NULL); //the end of the list
    }
}

//display the list
void print_llc(ptr h) {
    int i=1;
    printf("\nThe list : \n");
    while ( h != NULL )
    {
        printf("\tnode[%d]= %d \n", i, h->val);
        h = next(h);
        i++;
    }
}

//choice 2 - search by value
void rech_val(ptr l, int v, bool *find, ptr *prec, ptr *p){
    *find = false;
    ptr h = l;
    if ( value(h) == v ) {
        *p = h;
        *prec = NULL;
        *find = true;
    } 
    else 
    {
        while ( ( next(h) != NULL ) && (*find == false))
        {
            if ( value(next(h)) == v )
            {
                *prec = h;
                *p = next(h);
                *find = true;
            }
            h = next(h);
        }
    }
}

void delete_val(ptr *h, int v)
{
    ptr prec, p;
    bool find;

    rech_val(*h, v, &find, &prec, &p);
    
    if ( find = true )
    {
        if ( prec == NULL ) 
        {
            *h = next(p);
        } else {
            ass_addr(prec, next(p));
        }
        free(p);
    } else {
        printf("Node not found.");
    }
}

int main() {
    int n, val;
    ptr p, p1, prec;
    bool find = false;
    //create the list
    printf("Enter the length of the list (number of nodes): ");
    scanf("%d", &n);
    create_llc(&p,n);

    //print the list
    print_llc(p);

    printf("\nenter the value you are looking for : ");
            scanf("%d", &val);
            rech_val(p, val, &find, &prec, &p1);
            if ( find == true )
            {
                if ( prec != NULL ) {
                printf("\nthe node precedent : %d", value(prec));
                }
                printf("\nthe node wanted : %d\n", value(p1));
            } else {
                printf("\nthe node wanted not found");
            }
printf("\nenter the value you are looking for : ");
            scanf("%d", &val);
delete_val(&p, val);
print_llc(p);

            system("pause");
}