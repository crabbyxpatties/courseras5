#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>

// create the structure :

typedef struct monome
{
    float coef;
    int ex;
    struct monome *next;
} monome, *node;

// fonction de remplissage :

node ajouter(float coef, int ex)
{
    node new_node = (node)malloc(sizeof(monome));
    new_node->coef = coef;
    new_node->ex = ex;
    new_node->next = NULL;
    return new_node;
}

node saisirPolynome(node head)
{

    // create new node :
    float coef;
    int ex;

    printf("\n__________________\n");
    do
    {

        printf("saisir coef : ");
        scanf("%f", &coef);

        printf("saisir le  exp  : ");
        scanf("%d", &ex);

        printf("__________________\n");

        if (ex < 0)
            continue;

        node new_node = ajouter(coef, ex);

        if (head == NULL)
        {

            head = new_node;
        }
        else
        {

            node last = head;
            while (last->next != NULL)
                last = last->next;

            last->next = new_node;
        }

    } while (ex >= 0);

    return head;
}

// affiche polynome :

void affiche(node head)
{

    if (head == NULL)
        printf("the linked list is empty : \n ");

    else
    {

        node explore = head;

        while (explore != NULL)
        {

            // the case when the coef is positive  :

            if (explore->coef == 0)
            {
                if (explore == head)
                    printf("0 ");
                else
                    printf("+0 ");
            }

            else if (explore->coef > 0)
            {

                if (explore->ex == 0 && explore == head)
                    printf("%.0f ", explore->coef);

                else if (explore->ex == 0 && explore != head)
                    printf("+%.0f ", explore->coef);

                else if (explore->ex > 0 && explore == head)
                    printf("%.0fX^%d ", explore->coef, explore->ex);

                else
                    printf("+%.fX^%d ", explore->coef, explore->ex);
            }

            else
            {

                if (explore->ex == 0)
                    printf("%.0fX ", explore->coef);

                else
                    printf("%.0fX^%d ", explore->coef, explore->ex);
            }
            explore = explore->next;
        }
    }
}

// 3-
float evaluer(node head, int img)
{

    if (head == NULL)
    {
        printf("the linked list is empty : \n");
        return 0.0;
    }

    else
    {
        float result = 0.0;
        node explore = head;

        while (explore != NULL)
        {

            if (explore->coef != 0)
                result = result + explore->coef * pow(img, explore->ex);

            explore = explore->next;
        }
        return result;
    }
}

// 4 derive polynome  :

// i need  another function  for insert :

node insert(node head, float coef, int ex)
{

    // create new node :

    if (ex >= 0)
    {
        node new_node = ajouter(coef, ex);

        if (head == NULL)
        {

            head = new_node;
        }
        else
        {

            node last = head;
            while (last->next != NULL)
                last = last->next;

            last->next = new_node;
        }
    }

    return head;
}

node derivie(node head)
{
    if (head == NULL)
        printf("the linked list is empty : ");

    else
    {
        node dr_head = NULL;

        node explore = head;

        // copy  le  primitive poly in the new poly
        while (explore != NULL)
        {

            dr_head = insert(dr_head, explore->coef, explore->ex);
            explore = explore->next;
        }

        // then  calculate  the derivative  of the primitive  poly:
        explore = dr_head;

        while (explore != NULL)
        {

            if (explore->ex == 0)
            {
                explore->coef = 0;
            }
            else
            {

                explore->coef = explore->coef * explore->ex;
                explore->ex = explore->ex - 1;
            }

            explore = explore->next;
        }

        return dr_head;
    }
}

node addition_polynome(node p, node q)
{

    if (p == NULL || q == NULL)
        printf("the linked list is empty : ");

    else
    {

        node result = NULL;
        node explore1 = p, explore2 = q;
        int x = 1;
        while (explore1 != NULL || explore2 != NULL)
        {

            if (explore1 == NULL && explore2 != NULL)
            {
                result = insert(result, explore2->coef, explore2->ex);
                explore2 = explore2->next;
            }

            else if (explore1 != NULL && explore2 == NULL)
            {
                result = insert(result, explore1->coef, explore1->ex);
                explore1 = explore1->next;
            }

            else if (explore1->ex == explore2->ex)
            {

                int k = explore1->coef + explore2->coef;
                result = insert(result, k, explore1->ex);
                explore1 = explore1->next;
                explore2 = explore2->next;
            }

            else if (explore1->ex > explore2->ex)
            {
                result = insert(result, explore1->coef, explore1->ex);
                explore1 = explore1->next;
            }
            else
            {
                result = insert(result, explore2->coef, explore2->ex);
                explore2 = explore2->next;
            }
        }
        return result;
    }
}

node produitM(node p, monome m)
{

    if (p== NULL)
        printf("the linked list is empty : ");

    else
    {
        node p_head = NULL;

        node explore = p;

        // copy  le  primitive poly in the new poly
        while (explore != NULL)
        {

            p_head = insert(p_head, explore->coef * m.coef, explore->ex + m.ex);
            explore = explore->next;
        }

        return p_head;
    }
}

node produitP(node p, node q)
{

    if (p == NULL || q == NULL)
        printf("the linked list is empty : ");

    else
    {

        node result[10];
        result[1]=result[2]=NULL;
        node explore = p;
        int c = 0;
        node final = NULL;
        while (explore != NULL)
        {

            monome mono;
            mono.coef = explore->coef;
            mono.ex = explore->ex;
            result[c] = produitM(q, mono);

            c++;
            explore = explore->next;
        }
    
        for (int i = 0; i <c-1; i++){
           final = addition_polynome(result[i], result[i+1]);
        
        }
          
            if(final==NULL) printf("hi\n");
        return final;
    }
}

void wait_timer(){
char c; 
     fflush(stdin);
        printf("\npresses entre to continue  : ");
        scanf("%c", &c);
    
}
int main()
{

    node head = NULL;
    

    /*
     float result = evaluer(head, 5);

     printf("\nthe value is : %.2f\n ", result);

     node dr_head = derivie(head);

     printf("the derivate of poly :  ");

     affiche(dr_head);
     node Q=NULL;
     printf("\n_______________\n");
     printf("\nENTRE THE SECOND POLY \n ");

     Q=saisirPolynome(Q);
       printf("the poly : ");
     affiche(Q);

   node  add_result  = addition_polynome(head,Q);

 printf("the result of add two polynome  : \n");
   affiche(add_result);


 printf("saisir le monome :  \n");
 monome mono;

 printf(" saisir  le coef : ");
 scanf("%f",&mono.coef);

 printf(" saisir  le ex : ");
 scanf("%d",&mono.ex);

 node pM_result=produitM(head,mono);
 affiche(pM_result);





 printf("\n pour le produit : ");
 node q=NULL;
 q=saisirPolynome(q);
 printf("le poly 2 :\n");
 affiche(q);
 node pP_result=produitP(head,q);
 printf("le result de produit : ");
 affiche(pP_result);

 */

    system("cls");

    int x = 0;
    char c;
   

    do
    {
        do
        {
         
            printf("_________________________❤💖_welcome in this programme I hope you doing well : ❤💖__________________________ \n");
             if(head!=NULL); printf("le polynome principale : ");affiche(head);printf("\n");
            printf("\n\tpour saisir une  polynome :                              1   \n");
            printf("\tpour affiche  le polynome :                              2 \n");
            printf("\tpour evaluer le polynome :                               3 \n");
            printf("\tpour calculer le derivie d'une polynome :                4  \n");
            printf("\tpour calculer  la somme de deux ploynome P et Q :        5 \n");
            printf("\tpour calculer le produit de polynome  avec  un monome :  6 \n");
            printf("\tpour calculer le produit de deux polynome :              7 \n ");
            printf("\n\texit CLICK  :  0 \n\n");
            printf("\nchoix : "); 
            scanf("%d", &x);

        } while (x > 7 || x < 0);
         system("cls");
        switch (x)
        {
        case 1:
        {
           printf("1- saisir une  polynome : \n "); 
            head = saisirPolynome(head);
            printf("the poly : ");
            affiche(head);
            break;
        }

        case 2:
        {
            printf("2- affiche  le polynome : \n ");
            affiche(head);
            break;
        }

        case 3:
        {
            printf("3- evaluer le polynome: \n\n");
            printf("le poly : ");
            affiche(head);
            int f; 
             printf("\nentrer l'image : ");
             scanf("%d",&f);
            float result = evaluer(head,f);

            printf("\nthe value is : %.2f\n ", result);
            break;
        }

        case 4:
        {
             printf("4- calculer le derivie d'une polynome :\n\n");
              node Q=NULL;
              printf("saisir le  polynome : ");
              Q=saisirPolynome(Q);
            affiche(Q);
         
            node dr_head = derivie(Q);

            printf("\nle derivie de polynome  :  ");

            affiche(dr_head);
            break;
        }

        case 5:
        {
            printf("5- calculer  la somme de deux ploynome P et Q \n\n");
            node Q = NULL, p = NULL;
            
           printf("saisir le polynome 1 : ");
            p = saisirPolynome(p);
            printf("le premiere polynome : "); 
            affiche(p);
            wait_timer();
            system("cls");
          printf("\nsaisir le polynome 2 : ");
            Q = saisirPolynome(Q);
            system("cls"); 
            printf("le deuxieme polynome : "); 
            affiche(p);
            printf("\n");
                
            node add_result = addition_polynome(p,Q);
            printf("\nle resultat d'addition des deux polynome   : ");
            affiche(add_result);
            
            break;
        }

        case 6:
        {
            printf("6- produit de polynome  avec  un monome \n\n");
           
            node Q = NULL;
               printf(" saisir le polynome  : ");
            Q = saisirPolynome(Q);
            printf(" le polynome :  "); 
            affiche(Q);
            wait_timer();
           system("cls");
            printf(" \nsaisir le monome :  \n");
            monome mono;

            printf(" saisir  le coef : ");
            scanf("%f", &mono.coef);

            printf(" saisir  le ex : ");
            scanf("%d", &mono.ex);
            
            node pM_result = produitM(Q, mono);
             printf("\nle resultat de produit d'un polynome avec une monome  : \n"); 
            affiche(pM_result);

            break;
        }
        case 7:
        {
            printf("7- produit de deux polynome \n\n : ");
            node q = NULL;
             node p=NULL; 
               printf("saisir le polynome 1 : ");
            q = saisirPolynome(q);
          printf("le premiere polynome :   "); 
             affiche(q);
             wait_timer();

           system("cls");
          printf("\nsaisir le polynome 2 : ");
           
            p= saisirPolynome(p);
            printf("le dexiemme  polynome : ");
            affiche(p);
            node pP_result = produitP(p,q);
            printf("\nle resultat de produit : \n");
            affiche(pP_result);

            break;
        }

        default:
            printf("by by \n ");
            break;
        }

        char c;
        fflush(stdin);
        printf("\npresses here to return to the menu : ");
        scanf("%c", &c);
    

    } while (x != 0);

printf("\n");
system("pause");
    return 0;
}
