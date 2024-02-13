#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float findaveragefloat(float, float);
int findaverageint(int, int);
void sayhi();
void squares();

int main() {
   float al=435,bl=18,result;
   int an=5,bn=18;

   result=findaveragefloat(al,bl);

   printf("average=%10.2f\n", result); // Printf format 10 right justified
   printf("average=%-10.2f\n", result); // Printf format 10 left justified
   printf("average=%2.2f\n", result); // Printf will not chop off value
   printf("\n");

   sayhi();
   printf("\n");
   if (findaverageint(an,bn) > 20) {
      printf("The average is larger than 20.\n");
   }

   printf("average=%d\n", findaverageint(an,bn));
   printf("average=%d\n", findaverageint(43,22));
   printf("\n");
   squares();
   printf("\n");
   return 0;
}

// Function is returning a float
float findaveragefloat(float a, float b) {
   float average;
   average = (a+b)/2.0;
   return(average);
}

// Function is returning an int
int findaverageint(int a, int b) {
   return((a+b)/2);
}

// Function doesn't return any values, so use void
void sayhi() {
   printf("HI THERE!\n");
}

// Function doesn't return any values, so use void
void squares()
{
   int loop;
   for (loop=1;loop<10;loop++) {
      printf("%d\n",loop*loop);
   }
}
