typedef char letter;

typedef struct {
    int hour;
    int minutes;
    int seconds;
    letter meridiem[3];
} time;

time time_update(time);
