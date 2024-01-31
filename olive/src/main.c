#include <stdio.h>
#include "include/message.h"

void print_header(message_header *header);

int main(void) {
  message_header h = { .magic_number = "LRL",  .version = 0, .command_type = 'c', .body_length = 4};
  print_header(&h);
  return 0;
}

void print_header(message_header *header) {
  printf("Magic Number: %s\n", header->magic_number);
  printf("Version: %d\n", header->version);
  printf("Command Type: %c\n", header->command_type);
  printf("Body Length: %d\n", header->body_length);
}