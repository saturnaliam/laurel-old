#include "client.h"
#include "message.h"
#include <c++/13.2.1/bits/fs_fwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

response_t send_to_server(u64 *data);
bool response_handler(response_t res);
char* serialize(message_t message);

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
  char *serialized = serialize(message);
  printf("%s\n", serialized);
  free(serialized);
}

bool response_handler(response_t res) {
  if (res.code == OK) return true;

  panic(res.body);
  return false;
}

char* serialize(message_t message) {
  size_t char_field_sizes = (3 + 1 + 127) * sizeof(char);
  size_t u8_field_sizes = 2 * sizeof(u8);
  char *values = (char*)malloc(char_field_sizes + u8_field_sizes + sizeof(u16));
  strcpy(values, "");
  // TODO unhardcode

  // serializing header
  sprintf(values, "%s%s\t", values, message.header.magic_number);
  sprintf(values, "%s%u\t", values, message.header.version);
  sprintf(values, "%s%c\t", values, message.header.command_type);
  sprintf(values, "%s%u", values, message.header.body_length);

  // serializing body
  if (message.body != NULL) sprintf(values, "%s\t%s", values, message.body);

  return values;
}
