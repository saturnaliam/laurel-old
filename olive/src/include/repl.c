#include "repl.h"
#include "client.h"
#include "message.h"
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

  message_header header = { .magic_number = "LRL", .version = 0 };

  if (strcmp(command, "exit") == 0) {
    exit(0);
  } else if (strcmp(command, "pause") == 0) {
    header.command_type = 's';
    send_message((message){ .header = header });
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

  message msg = { .header = header, .body = argument };
  send_message(msg);
}
