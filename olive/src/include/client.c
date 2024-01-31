#include "client.h"
#include "message.h"
#include <stdio.h>

response send_to_server(u64 *data);
bool response_handler(response res);

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

void send_message(message msg) {
// TODO serialize message
// TODO ensure server connection
// TODO send data
// TODO parse response
  response res = { .code = UNAUTHORIZED, .body = "unauthed" };
  if (!response_handler(res)) return;
  print_message(&msg);
}

bool response_handler(response res) {
  if (res.code == OK) return true;

  panic(res.body);
  return false;
}
