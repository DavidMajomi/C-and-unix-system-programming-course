#include <stdio.h>
#include <string.h>

int main() {
   // Pointer to a Pointer
   int num = 45 , *nptr , **nptr2ptr;
   nptr = &num;
   nptr2ptr = &nptr;

   char ch = 't';
   char *pch;
   char **ppch;
   pch = &ch;
   ppch = &pch;

   printf("CH %p ch ad\n",&ch);
   printf("CH %c ch\n",ch);
   printf("CH %p pch ad\n",pch);
   printf("CH %c ch pch\n",*pch);
   printf("CH %p ppch ad\n",&ppch);
   printf("CH %c ppch\n\n",**ppch);

   int i;
   char *arr[4] = {"C", "C++", "Java", "Ruby"};
   char *(*ptr)[4] = &arr;
   for(i = 0; i < 4; i++) {
       printf("String %d : %s\n",i+1,(*ptr)[i]);
   }

   printf("\n");
   char newch[]="hello";
   char *pnewch;
   char **ppnewch;
   pnewch = newch;
   ppnewch = &pnewch;

   printf("ch string address %x \n",&newch);
   printf("ch string value %s\n",newch);
   printf("ch string ptr value %x\n",pnewch);
   printf("ch string deference %s\n",pnewch);
   printf("ch string ptr value %x\n",&pnewch);
   printf("ch string ptr ptr value %x\n",ppnewch);
   printf("ch string double deference %s\n\n",*ppnewch);

   int x[] = {1,2,3,4,5};
   int *xptr;
   xptr = x;
   for(i = 0; i < 5; i++) {
       printf("Address : %p\n",&x[i]);
       printf("Element : %d\n",x[i]);
       printf("Element : %u\n",*(x+i));
       printf("Element : %d\n",i[x]);
       printf("Element : %d\n\n",*(xptr+i));
   }

   char *parrayst[3][3] = {"hello", "ciao", "bye"};
   char **pparrayst;
   pparrayst = parrayst[0];

   for(i=0;i<3;i++) {
       printf("String %d : %s\n",i+1,(*parrayst)[i]);
       printf("String address %p\n",parrayst[i]);
       printf("String %p\n",pparrayst);
       printf("String %p\n",pparrayst+i);
       printf("String %s\n",*(pparrayst+i));
   }
   return 0;
} 
