#ifndef S21_GREP
#define S21_GREP
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int numFiles;
  int noFlags;
  int misFlag;
  char* temp;
} options;

int scanOptions(int argc, char** argv, options* config);
void printData(options* config, FILE* file, char* fileName);
int printOne(int filePrinted, options* config, char* fileName, int ind_n,
             char* buffer);
int printMore(int filePrinted, options* config, char* fileName, int ind_n,
              char* buffer);

#endif