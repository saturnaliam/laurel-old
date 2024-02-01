#include "client.h"
#include "message.h"
#include <stdio.h>

response_t send_to_server(u64 *data);
bool response_handler(response_t res);

void print_header(message_header_t *header) {
  printf("Magic Number: %s\n", header->magic_number);
  printf("Version: %d\n", header->version);
  printf("Command Type: %c\n", header->command_type);
  printf("Body Length: %d\n", header->body_length);
}

void print_message(message_t *message) {
  print_header(&message->header);
  printf("Body: %s\n", message->body);
}

void send_message(message_t message) {
// TODO serialize message
// TODO ensure server connection
// TODO send data
// TODO parse response
  print_message(&message);
}

bool response_handler(response_t res) {
  if (res.code == OK) return true;

  panic(res.body);
  return false;
}
