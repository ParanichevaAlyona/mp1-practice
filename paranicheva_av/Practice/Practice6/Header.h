#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

 typedef struct 
{
	int n;
	double *a;
}Vector;

Vector* Add(int nn);
Vector* Fill(Vector *v);
Vector* Add(int nn);
Vector* Fill(Vector *vv);
void Sum(Vector *v, Vector *vv, Vector *s);
void Sub(Vector *v, Vector *vv, Vector *ss);
double Com(Vector *v, Vector *vv);
int Length(Vector *v, Vector *vv);
void Angle(Vector *v, Vector *vv);
void Delete(Vector *v, Vector *vv);