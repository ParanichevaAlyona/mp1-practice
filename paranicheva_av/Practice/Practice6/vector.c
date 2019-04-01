#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Header.h"
#define P 3.14

Vector* Add(int nn)
{
	Vector *el = (Vector*)malloc(sizeof(Vector)); 
	(el)->n = nn;
	(el)->a = (double*)malloc(sizeof(double) * nn);
	return el;
}

Vector* Fill(Vector *v)
{
	int i;
	printf("Enter koordinaty\n");
	for(i = 0; i < (v)->n; i++)
	{
		scanf ("%lf", &(v->a[i]));
	}
	printf("Entered koordinaty is\n");
	for(i = 0; i < (v)->n; i++)
	{
		printf ("%lf  ", v->a[i]);
	}
	printf ("\n");
	return v;
}

void Sum(Vector *v, Vector *vv, Vector *s)
{
	int i;
	for(i = 0; i < (v)->n; i++)
	{
		s->a[i] = v->a[i] + vv->a[i];
	}
		for(i = 0; i < (v)->n; i++)
	{
		printf ("%lf ", s->a[i] );
	}
	printf("\n");
}

void Sub(Vector *v, Vector *vv, Vector *ss)
{
	int i;
	for(i = 0; i < (v)->n; i++)
	{
		ss->a[i] = v->a[i] - vv->a[i];
	}
		for(i = 0; i < (v)->n; i++)
	{
		printf ("%lf ", ss->a[i] );
	}
	printf("\n");
}

double Com(Vector *v, Vector *vv)
{
	int i;
	double c = 0;
	for(i = 0; i < (v)->n; i++)
	{
		c += v->a[i] * vv->a[i];
	}
		for(i = 0; i < (v)->n; i++)
	{
		printf ("%lf ", c );
	}
	return c;
	printf("\n");
}

int Length(Vector *v, Vector *vv)
{
	int k, i;
	double sum = 0.0, len;
	printf("Vybery vector dlinu kotorogo hochesh naiti 1) v   2) vv\n");
	scanf("%d", &k);
	switch (k)
	{
	case 1:
		for(i = 0; i < v->n; i++)
		{
			sum += (v->a[i]) * (v->a[i]);
		}
		len = sqrt(sum);
		printf("Dlina vectora v %lf", len);
		break;
	case 2:
		for(i = 0; i < vv->n; i++)
		{
			sum += (vv->a[i]) * (vv->a[i]);
		}
		len = sqrt(sum);
		printf("Dlina vectora vv %lf", len);
		break;
	}
	return len;
}

void Angle(Vector *v, Vector *vv)
{
	double l1, l2, c, u;
	l1 = Length(v, vv);
	l2 = Length(v, vv);
	c = Com(v, vv);
	u = acos(c / (l1 * l2)); 
	u = u / P * 180; 
	printf("\nUgol mezhdu v i vv = %lf", u);
}

 void Delete (Vector *v, Vector *vv)
{
	free((*v).a); 
    (*v).n = 0; 
	free((*vv).a); 
	(*vv).n = 0; 
}