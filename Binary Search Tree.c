#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct dugum {

	int v;
	struct dugum *sol, *sag;
}*agac=NULL, *root=NULL, *yd=NULL, *lroot=NULL;

void ekle(int);
void gosterinorder(struct dugum *);
void gosterpostorder(struct dugum *);
void gosterpreorder(struct dugum *);


struct dugum * dugumal()
{
	yd = (struct dugum *)malloc(sizeof(struct dugum));
	yd->sol = NULL;
	yd->sag = NULL;
	return yd;
}

void ekle(int veri)
{
	agac = root;
	if (agac == NULL)
	{
		agac = dugumal();
		agac->v = veri;
		root = agac;
	}
	else
	{
		while (agac != NULL)
		{
			lroot = agac;
			if (veri < agac->v) 
			agac = agac->sol;
			else	
			agac = agac->sag;
		}
		if (veri < lroot->v)
		{
			lroot->sol = dugumal();
			lroot = lroot->sol;
			lroot->v = veri;
		}
		else
		{
			lroot->sag = dugumal();
			lroot = lroot->sag;
			lroot->v = veri;
		}


	}


}


void inorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		inorder(a->sol);
		printf("%d", a->v);
		inorder(a->sag);
	}
}


void postorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		postorder(a->sol);
		postorder(a->sag);
		printf("%d", a->v);
	}
}


void preorder( struct dugum *a)
{
	if (a == NULL) return;
	else
	{
		printf("%d", a->v);
		preorder(a->sol);
		preorder(a->sag);
	}
}


int main() {
	agac = NULL;
	char c='x';
	int sayi;
	while (c != 'e' || c != 'E') {

	printf("1.ekle\n");
	printf("2.inorder\n");
	printf("3.preorder\n");
	printf("4.postorder\n");
		c = getchar();
		if (c == '1')
		{
			printf("Yeni sayi giriniz:");
			scanf("%d", &sayi); 
			ekle(sayi);
			printf("%d\n  ");
		}
		if (c == '2')
		{
			agac = root;
			printf("-------\n");
			inorder(agac);
		}
			if (c == '3')
		{
			agac = root;
		    printf("------\n"); 
			preorder(agac);
		}
			if (c == '4')
		{
			agac = root;
			printf("------\n");
			postorder(agac);
		}
	printf("Cikmak istiyormusunuz-(e/h):\n");
		c = getchar();		
	}
       
		
		
	return 0;

}
