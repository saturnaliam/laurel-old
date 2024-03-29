#include "repl.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INPUT_LENGTH 255

void sanitize_string(char **input);
void run_input(char *input);

void run_repl() {
  while (1) {
    char *input = (char*)malloc(INPUT_LENGTH* sizeof(char));
    printf(">> ");

    fgets(input, INPUT_LENGTH, stdin);
    sanitize_string(&input);

    run_input(input);
    free(input);
  }
}

void sanitize_string(char **input) {
  char *buffer = (char*)calloc(INPUT_LENGTH, sizeof(char));

  for (size_t i = 0; i < strlen(*input); i++) {
    char c = (*input)[i];
    if (iscntrl(c)) continue;
    sprintf(buffer, "%s%c", buffer, c);
  }

  strcpy(*input, buffer);

  free(buffer);
}

void run_input(char *input) {
  char *command = strtok(input, " ");
  char *argument = strtok(NULL, " ");
  if (command == NULL) return;

  message_header_t header = { .magic_number = "LRL", .version = 0 };

  if (strcmp(command, "exit") == 0) {
    exit(0);
  } else if (strcmp(command, "pause") == 0) {
    header.command_type = 's';
    send_message((message_t){ .header = header });
    return;
  }

  if (argument != NULL && strlen(argument) > BODY_SIZE) {
    char *err = (char*)malloc((strlen("maximum command length is  !") + 3) * sizeof(char));
    strcpy(err, "maximum command length is ");
    sprintf(err, "%s%d!", err, BODY_SIZE);
    panic(err);
    free(err);
    return;
  }

  if (strcmp(command, "play") == 0) {
    if (argument == NULL) {
      panic("argument required!");
      return;
    }

    header.body_length = strlen(argument);
    header.command_type = 'p';
  } else {
    panic("unknown command!");
    return;
  }

  message_t msg = { .header = header, .body = argument };
  send_message(msg);
}
