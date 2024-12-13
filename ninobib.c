//     bibliotheque TD1
//     #include "ramibib.c"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 1000

typedef struct
{
    char name[25]; 
    float grade;
} student;

//Read the elements of the table
int read1D(int *T, int *Tai) {
    int i;
    printf("Enter the size of the table : ");
    scanf( "%d", Tai);
    for ( i=0; i<(*Tai); i++) {
        printf("T[%d] : ", i);
        scanf( "%d", &T[i]);
    }
}
//-----------------------------------

//Write the elements of the table
int write1D(int *T,int Tai) {
    int i;
    for ( i=0; i<(Tai); i++) {
        printf("%d | ", T[i]);
    }
}
//-----------------------------------

//Read the elements of the 2D table
void write2D (int T[][MAX], int nblig, int nbcol) {
    int i, j;
    for (i=0; i<(nblig); i++) {
        for ( j=0; j<(nbcol); j++) {
            printf("%d | ", T[i][j]);
        }
        printf("\n");
    }
}
//-----------------------------------

//Write the elements of the 2D table
void read2D (int T[][MAX], int *nblig, int *nbcol) {
    int i, j;
    printf("Enter the number of lines : ");
    scanf("%d", nblig);
    printf("Enter the number of columns : ");
    scanf("%d", nbcol);
    for (i=0; i<(*nblig); i++) {
        for ( j=0; j<(*nbcol); j++) {
            printf("T[%d][%d] : ", i, j);
            scanf("%d", &T[i][j]);
        }
    }
}
//-----------------------------------


//First question of the TD1_EXO01
int minmax(int *T, int Tai, int *min, int *max) {
    int i;
    *min = T[0];
    *max = T[0];
    for ( i = 0; i < (Tai-1); i++)
    {
        if (*min > T[i])
        {
            *min = T[i];
        }
        else { if (*max < T[i])
        {
            *max = T[i];
        }
        }
    }
}
//------------------------------------

//second question of the TD1_EXO01
int student1D(student *students, int *Tai) {
    int i;
    printf("Enter the number of students : ");
    scanf( "%d", Tai);
    for ( i=0; i<(*Tai); i++) {
        printf("student[%d] : ", i);
        scanf("%s", students[i].name); 
        printf("grade[%d] : ", i);
        scanf("%f", &students[i].grade);
    }
}

float average(student *students, int Tai) {
    int i;
    float sum = 0;
    for ( i=0; i<(Tai); i++) {
        sum += students[i].grade;
    }
    return (sum/Tai);
}
//-----------------------------------

//third question of the TD1_EXO01
int power(int x, int n) {
    int i, p = 1;
    for ( i = 1; i <= n; i++)
    {
        p *= x;
    }
    return p;
}

int calcpolynome(int *T, int Tai, int x) {
    int i, sum = 0;
    for ( i = 0; i < (Tai); i++)
    {
        sum += T[i] * pow(x, i);
    }
    return sum;
}
//------------------------------------

//Recherche dichotomique
bool rechdichotomique(int *T, int Tai, int x) {
    int i, j, m;
    bool trouv = false;
    //Initialisation des variables
    i = 0;
    j = Tai-1;
    //tant que l'élément recherché n'est pas trouvé 
    while ((i <= j)&&(trouv==false))
    {
        m = (i+j)/2;
        if (T[m] == x)
        {
            trouv = true;
        }
        else { if (T[m] < x)
        {
            i = m+1;
        }
        else
        {
            j = m-1;
        }
        }
    }
    return trouv;
}
//------------------------------------

//decadage - shift
void shift(int *T, int tai, int pos) {
    int i;
        for (i = pos; i < (tai); i++)
        {
            T[i] = T[i+1];
        }
}
//-----------------------------------

//permutation - swap
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//-----------------------------------

//tri par bulle - bubble sort
void tri_bulle(int *T, int Tai) {
    bool tri = false;
    int temp;
    do {
        tri = false;
        for (int i = 0 ; i < ((Tai)-1); i++)
        {
            if (T[i] > T[i+1])
            {
                swap(&T[i], &T[i+1]);
                tri = true;
            }
        }
    } while (tri == true);
}
//-----------------------------------
