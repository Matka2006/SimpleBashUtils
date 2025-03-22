#include "s21_grep.h"

int main(int argc, char **argv) {
  options config = {0};
  int flag = 1;
  if (argc < 2 && !config.s) {
    printf("Usage: %s [options] <pattern> [file...]\n", argv[0]);
    flag = 0;
  } else if (argc < 2 && config.s) {
    flag = 0;
  }
  int status = scanOptions(argc, argv, &config);
  if (!status && !config.s && flag) {
    printf("Invalid option detected.\n");
    flag = 0;
  } else if (!status && config.s && flag) {
    flag = 0;
  }

  if (config.temp == NULL && !config.s && flag) {
    printf("Error: No search pattern provided.\n");
    flag = 0;
  } else if (config.temp == NULL && config.s && flag) {
    flag = 0;
  }
  if (flag) {
    int startIndex = argc - config.numFiles;
    for (int i = startIndex; i < argc; i++) {
      FILE *file = fopen(argv[i], "r");
      if (file == NULL && !config.s) {
        perror("Error opening file");
        flag = 0;
      } else if (file == NULL && config.s) {
        flag = 0;
      }
      if (flag) {
        printData(&config, file, argv[i]);
        fclose(file);
      }
    }
  }
  return flag;
}

int scanOptions(int argc, char **argv, options *config) {
  int x = 1, indexStartFiles = 1, status = 1, f = 0;
  for (; x < argc && argv[x][0] == '-'; indexStartFiles = x++) {
    if (!strcmp(argv[x], "-e")) {
      config->e = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-i")) {
      config->i = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-v")) {
      config->v = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-c")) {
      config->c = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-l")) {
      config->l = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-n")) {
      config->n = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-h")) {
      config->h = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-s")) {
      config->s = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-f")) {
      config->s = 1;
      f = 1;
    } else if (!strcmp(argv[x], "-o")) {
      config->o = 1;
      f = 1;
    }
    if (argv[x][0] == '-' && !f) {
      config->misFlag = 1;
      status = 0;
    }
  }
  config->numFiles = argc - indexStartFiles - 2;
  if (!f && argc >= 3 && !config->misFlag) {
    config->noFlags = 1;
    config->numFiles = argc - indexStartFiles - 1;
    status = 1;
  }
  if (x < argc) {
    config->temp = argv[x];
    indexStartFiles++;
  }
  return status;
}

int printOne(int filePrinted, options *config, char *fileName, int ind_n,
             char *buffer) {
  if (!filePrinted && config->l) {
    printf("%s\n", fileName);
    filePrinted = 1;
  } else if (config->n && !filePrinted) {
    printf("%d:%s", ind_n, buffer);
  } else if (!config->c && !filePrinted) {
    printf("%s", buffer);
  }
  return filePrinted;
}

int printMore(int filePrinted, options *config, char *fileName, int ind_n,
              char *buffer) {
  if (!filePrinted && config->l) {
    printf("%s\n", fileName);
    filePrinted = 1;
  } else if (config->h && !filePrinted) {
    printf("%s", buffer);
  } else if (config->n && !filePrinted) {
    printf("%s:%d:%s", fileName, ind_n, buffer);
  } else if (!config->c && !filePrinted) {
    printf("%s:%s", fileName, buffer);
  }
  return filePrinted;
}

void printData(options *config, FILE *file, char *fileName) {
  char *buffer = malloc(1000);
  int cnt_c = 0, ind_n = 0, f = 1;
  regex_t regex;
  int reti;
  if (config->temp == NULL || strlen(config->temp) == 0) {
    free(buffer);
    f = 0;
  }
  reti =
      regcomp(&regex, config->temp, REG_EXTENDED | (config->i ? REG_ICASE : 0));
  if (reti) {
    fprintf(stderr, "Не удалось скомпилировать регулярное выражение\n");
    free(buffer);
    f = 0;
  }
  int filePrinted = 0;
  if (f) {
    while (fgets(buffer, 1000, file)) {
      ind_n++;
      reti = regexec(&regex, buffer, 0, NULL, 0);
      if (reti == 0 && !config->v) {
        cnt_c++;
        if (config->numFiles == 1)
          filePrinted = printOne(filePrinted, config, fileName, ind_n, buffer);
        else
          filePrinted = printMore(filePrinted, config, fileName, ind_n, buffer);
      } else if (config->v && reti == REG_NOMATCH) {
        if (config->numFiles == 1)
          printf("%s", buffer);
        else
          printf("%s:%s", fileName, buffer);
      }
    }
    if (config->c == 1) {
      if (config->numFiles == 1) {
        printf("%d\n", cnt_c);
      } else {
        printf("%s:%d\n", fileName, cnt_c);
      }
    }
  }
  regfree(&regex);
  free(buffer);
}