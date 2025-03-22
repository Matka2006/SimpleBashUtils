#ifndef CAT_H
#define CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int misFlag;
  int numFiles;
} options;

int scanOptions(int argc, char** argv, options* config);
void printData(options* config, FILE* file);

#endif