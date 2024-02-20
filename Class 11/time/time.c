#include <stdio.h>
#include <stdlib.h>
#include "time.h"
 
/* function to update time by one second */
time time_update(time new_time)
{
   ++new_time.seconds;
   if ( new_time.seconds == 60)
   {
      new_time.seconds = 0;
      ++new_time.minutes;
      if(new_time.minutes == 60)
      {
        new_time.minutes = 0;
        ++new_time.hour;
        if(new_time.hour == 13)
        { new_time.hour = 1; }
      }
      if (new_time.hour == 12 && new_time.minutes == 0 && new_time.seconds == 0)
      {
         if (new_time.meridiem[0] == 'a')
         { new_time.meridiem[0] = 'p'; }
         else
         { new_time.meridiem[0] = 'a'; }
      }
   }
   return(new_time);
}
