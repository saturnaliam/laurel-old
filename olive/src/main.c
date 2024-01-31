#include <stdio.h>
#include <stdlib.h>
#include "include/message.h"

#define INPUT_SIZE 255

void print_header(message_header *header);
void print_message(message *msg);
void remove_special_characters(char **input);

int main(void) {
  char* input = (char*)malloc(INPUT_SIZE);
  while (1) {
    printf(">> ");
    fgets(input, INPUT_SIZE, stdin);

    remove_special_characters(&input);

    printf("%s\n", input);
  }  

  free(input);
  // message_header h = { .magic_number = "LRL",  .version = 0, .command_type = 'c', .body_length = 4};
  // message m = { .header = h, .body = "gefrg" };
  // print_message(&m);
  return 0;
}

void print_header(message_header *header) {
  printf("Magic Number: %s\n", header->magic_number);
  printf("Version: %d\n", header->version);
  printf("Command Type: %c\n", header->command_type);
  printf("Body Length: %d\n", header->body_length);
}

void print_message(message *msg) {
  print_header(&msg->header);
  printf("Body: %s\n", msg->body);
}

// TODO: fully sanitize characters not allowed in a file path
void remove_special_characters(char **input) {
  for (int i = 0; i < INPUT_SIZE - 1; i++) {
    if ((*input)[i] < 32 && (*input)[i] != 0) (*input)[i] = 32;
  }
}