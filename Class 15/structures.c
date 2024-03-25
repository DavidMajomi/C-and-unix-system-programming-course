/* TIME.C  Program updates time by 1 second using functions */
#include <stdio.h>
#include <stdlib.h>

struct time {
    int hour;
    int minutes;
    int seconds;
    char meridiem[3];
};

struct time time_update(struct time);

int main()
{
  struct time current_time;
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
/* function to update time by one second */
}

struct time time_update(struct time new_time)
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
