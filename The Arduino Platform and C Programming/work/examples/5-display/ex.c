#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct monome{
float coef ;
int ex ;
struct monome *next ;
};
typedef struct monome Monome ;

typedef struct monome Monome ;
Monome * AjoutFin(Monome *p, float c, int ex){
	Monome *m=malloc(sizeof(Monome));
	m->coef=c;
	m->ex=ex;
	m->next=NULL;
	if(p==NULL)
	return m;
	else{
		Monome *p1=p;
		while(p1->next!=NULL)
		p1=p1->next;
		p1->next=m;
		return p;
	}
}

Monome * saisirPolynome(){
	float c; int ex=0;
	Monome *p=NULL;
	while(ex>=0){
		printf("entrer un coef: ");
		scanf("%f",&c);
		printf("entrer un exp: ");
		scanf("%d",&ex);
		if(ex>=0)
		p=AjoutFin(p,c,ex);
		
	}
	return p;
}


void affichePolynome(Monome *p)
{	if (p == NULL)
    {
        printf("NULL\n");
    }
    else
    while (p != NULL)
        {
            if (p->coef == 0)
            {
			printf("+0 ");
            }
            else
            {
                if (p->coef > 0)
                {
                    if (p->ex != 0)

                        printf("+%.0fx^%d ", p->coef, p->ex);

                    else
                        printf("+%.0f ", p->coef);
                }
                else
                {
                    if (p->ex != 0)
                        printf("%.2fx^%d ", p->coef, p->ex);
                    else
                        printf("%.2f ", p->coef, 'x');
                }
               p = p->next;

            }
        }
 }



float evaluer(Monome *p, float x){
	
	float res=0;
	while(p!=NULL)
	{
		res=res+(p->coef*pow(x,p->ex));
		p=p->next;
	}
	return res;
}

Monome * copiPoly(Monome *p){
	Monome *pc=malloc(sizeof(Monome));
	while(p!=NULL){
		pc=AjoutFin(pc, p->coef, p->ex);
		p=p->next;
	}
	return pc;
}




Monome * derivePolynome(Monome *p){
	Monome *dr=copiPoly(p);
	Monome *p1=dr;
	while(p1!=NULL){
		p1->coef=p1->coef*p1->ex;
		p1->ex=p1->ex-1;
		p1=p1->next;
	}
	return dr;
}

Monome * additionPolynome(Monome *p, Monome * q){
	if(p==NULL)
	return q;
	if(q==NULL)
	return p;
	if(p->ex<q->ex)
	{
		q->next=additionPolynome(p,q->next);
		return q;
	}
	else
	if(p->ex>q->ex)
	{
		p->next=additionPolynome(p->next,q);
		return p;
	}
	else
	p->coef=p->coef+q->coef;
	p->next=additionPolynome(p->next,p->next);
	return p;
	
	
	
}

Monome * produitPolynomeMonome(Monome * p , Monome *m){
	Monome* p1=p;
	while(p1!=NULL){
		p1->coef=p1->coef*m->coef;
		p1->ex=p1->ex+m->ex;
		p1=p1->next;
	}
	return p;
}

Monome * produitPolynomes(Monome *p, Monome *q)
{
	Monome * p1=p;
	Monome *pr=NULL;
	Monome *pa=NULL;
	Monome *tmp=copiPoly(q);
	
	while(p1!=NULL){
		q=copiPoly(tmp);
		pr=produitPolynomeMonome(q,p1);
		pa=additionPolynome(pa,pr);
		p1=p1->next;

	}
	return pa;
	
}