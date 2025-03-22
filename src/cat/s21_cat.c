#include "s21_cat.h"

int main(int argc, char **argv) {
  int flag = 1;
  if (argc < 2 && flag) {
    printf("Usage: %s [options] [file...]\n", argv[0]);
    flag = 0;
  }
  options config = {0};
  int status = scanOptions(argc, argv, &config);
  if (!status && flag) {
    printf("Invalid option detected.\n");
    flag = 0;
  }
  if (flag) {
    int startIndex = argc - config.numFiles;
    for (int i = startIndex; i < argc; i++) {
      FILE *file = fopen(argv[i], "r");
      if (file == NULL) {
        perror("Error opening file");
        flag = 0;
      }
      if (flag) {
        printData(&config, file);
        fclose(file);
      }
    }
  }
  return flag;
}

int scanOptions(int argc, char **argv, options *config) {
  int x = 1, indexStartFiles = 1, status = 1, f = 0;
  for (; x < argc && argv[x][0] == '-'; indexStartFiles = (x++)) {
    if (!strcmp(argv[x], "-b") || !strcmp(argv[x], "--number-nonblank")) {
      config->b = 1;
      config->n = 0;
      f = 1;
    } else if (!strcmp(argv[x], "-e")) {
      config->e = 1;
      config->v = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-n") || !strcmp(argv[x], "--number")) {
      config->n = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-s") || !strcmp(argv[x], "--squeeze-blank")) {
      config->s = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-v")) {
      config->v = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-E")) {
      config->e = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-T")) {
      config->t = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-t")) {
      config->t = 1;
      config->v = 1;
      f = 1;
    }
    if (argv[x][0] == '-' && !f) {
      config->misFlag = 1;
      status = 0;
    }
  }
  config->numFiles = argc - indexStartFiles - 1;
  if (!f && argc >= 2 && !config->misFlag) {
    config->numFiles = argc - indexStartFiles;
    status = 1;
  }
  return status;
}

