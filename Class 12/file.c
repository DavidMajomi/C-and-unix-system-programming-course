#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char ch;

  printf("Creating file.txt...");
  file = fopen("file.txt","w"); /* Write to a file */
  fprintf(file, "This is just an example :)\n"); /* writes */
  fclose(file); /* close the file */
  printf("done\n");
  printf("\nPress a key to continue...\n");
  getchar(); /* pause and wait for key */

  printf("Appending to file.txt...");
  file = fopen("file.txt","a"); /* append to a file */
  fprintf(file, "This is another example.\n"); /* writes */
  fclose(file); /* close the file */
  printf("done\n\n");

  printf("Reading file.txt:\n");
  file = fopen("file.txt","r"); /* read a file */
  while((ch = fgetc(file)) != EOF)
  { printf("%c", ch); }
  fclose(file); /* close the file */
  printf("\n");
  
  exit(0);
}