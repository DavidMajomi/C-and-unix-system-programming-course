#include <stdio.h>
#include <stdlib.h>
#include "time.h"
 
int main()
{
   time current_time;
   int loop = 0;
   printf("Enter the time (hh:mm:ssMM):\n");

   scanf("%d:%d:%d%c%s", &current_time.hour,&current_time.minutes,&current_time.seconds,&current_time.meridiem[0],&current_time.meridiem[1]);

   current_time.meridiem[2]='\0';

   while (loop < 20)
   {
      current_time = time_update(current_time);
      printf("The new time is %02d:%02d:%02d%s\n",current_time.hour, current_time.minutes, current_time.seconds, current_time.meridiem);
      loop++;
   }

   exit(0);
}
