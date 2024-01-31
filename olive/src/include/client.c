#include "client.h"
#include "message.h"
#include <stdio.h>

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

response send_message(message msg) {
  print_message(&msg);
}
