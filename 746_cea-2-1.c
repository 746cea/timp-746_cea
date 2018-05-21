#include <stdio.h>
void main()
{
int n,i;
double m;
scanf("%i", &n);
double x[n];
for (i=1; i<=n; i++)
{
scanf ("%lf", &x[i]);
}
m=x[1];
for (i=1; i<=n; i++)
{
if (x[i]>m)
m=x[i];
}
printf ("%g\n", m);
} 
