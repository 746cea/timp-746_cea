#include <stdio.h>
void main()
{
int n,i;
double s;
scanf("%i", &n);
double x[n];
for (i=1; i<=n; i++)
{
scanf ("%lf", &x[i]);
}
s=0;
for (i=1; i<=n; i++)
{
s=s+(x[i]-i);
}
printf ("%g\n", s);
}



