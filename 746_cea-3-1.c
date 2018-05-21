#include <stdio.h> 
#include <stdlib.h> 
typedef struct node 
{ 
int value; 
struct node *next; 
struct node *prev; 
} 
node;

typedef struct spisok
{
node *head;
node *tail;
}
spisok;
  

int init(spisok *sps) 
{ 
sps->head=NULL;
sps->tail=NULL;
} 

int isEmpty(spisok *sps)
{
if ((sps->head==NULL)&&(sps->tail==NULL)) return 1;
else return 0;
}

int zapoln(spisok *sps, int value)
{ 
if (isEmpty(sps))
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                sps->head = tmp;
                sps->tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
                return 1;
        }
        else
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                tmp->next = NULL;
                tmp->prev = sps->tail;
                sps->tail->next = tmp;
                sps->tail = tmp;
                return 1;
        }
        return 0; 
} 

int print(spisok *sps) 
{ 
if (isEmpty(sps))
return 0;
node *ptr = sps->head;
while (ptr->next)
{
  printf("%d ", ptr->value);
  ptr = ptr->next;
}
  printf("%d\n", ptr->value);
  return 1;
} 

int udalelem(spisok*sps, int k) 
{ 
node *ptr = sps->head;
        while (k !=1)
        {
                ptr = ptr->next;
                k--;
        }
        if (ptr == sps->head)
        {
                ptr->next->prev = NULL;
                sps->head = ptr->next;
                free(ptr);
                return 1;
        }
        else if (ptr == sps->tail)
        {
                ptr->prev->next = NULL;
                sps->tail = ptr->prev;
                free(ptr);
                return 1;
        }
        else
        {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                return 1;
        }
        return 0; 
} 

int udalznach(spisok *sps, int value) 
{ 
node *ptr = sps->head;
        while (ptr->value != value )
        {
                ptr = ptr->next;
        }
        if (ptr == sps->head)
        {
                ptr->next->prev = NULL;
                sps->head = ptr->next;
                free(ptr);
                return 1;
        }
        else if (ptr == sps->tail)
        {
                ptr->prev->next = NULL;
                sps->tail = ptr->prev;
                free(ptr);
                return 1;
        }
        else
        {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                return 1;
        }
        return 0;
}

int append(spisok *sps, int a, int value)
{
if(isEmpty(sps))
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                sps->head = tmp;
                sps->tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
                return 1;
        }
        else
        {
                node *ptr = sps->head;
                node *tmp = malloc (sizeof(node));
                while(a !=1)
                {
                        ptr=ptr->next;
                        a--;
                       
                }
                tmp->value = value;
                tmp->prev = ptr;
                if (ptr == sps->tail)
                {
                        sps->tail = tmp;
                        tmp->next = NULL;
                        ptr->next = tmp;
                }
                else
                {
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                        ptr = ptr->next;
                        ptr->next->prev = ptr->prev;
                }
                return 1;
        }
        return 0;
}

int prepend(spisok*sps, int c, int value) 
{
if(isEmpty(sps)==1)
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                sps->head = tmp;
                sps->tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
        }
        else
        {
                node *ptr = sps->head;
                node *tmp = malloc (sizeof(node));
                while(c !=1)
                {
                        ptr=ptr->next;
                        c--;
                }
                tmp->value = value;
                if (ptr == sps->head)
                {
                        tmp->prev = NULL;
                        tmp->next = ptr;
                        ptr->prev = tmp;
                        sps->head = tmp;
                }
                else
                {
                        tmp->prev = ptr->prev;
                        tmp->next = ptr;
                        ptr->prev = tmp;
                        ptr = ptr->prev;
                        ptr->prev->next = ptr;
                }
        }
} 

int main() 
{ 
spisok SpisokD;
init (&SpisokD);
int n, i, el, k, m, a, b, c, d;  
scanf ("%d", &n);    
for (i=0; i<n; i++) 
{ 
scanf ("%d", &el);
zapoln(&SpisokD, el); 
} 
print(&SpisokD); 
scanf("%d", &k); 
udalelem(&SpisokD, k); 
print(&SpisokD); 
scanf("%d", &m); 
udalznach(&SpisokD, m); 
print(&SpisokD);
scanf("%d", &a);
scanf("%d", &b);
append(&SpisokD, a, b);
print(&SpisokD); 
scanf("%d", &c);  
scanf("%d", &d); 
prepend(&SpisokD, c, d); 
print(&SpisokD);
return 0;
}
