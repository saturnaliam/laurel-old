#include "serialization.h"

char* serialize_message(const message_t *message) {
  // sizes of what the value array will be, could be cleaner, but w/e
  size_t char_field_sizes = (3 + 1 + BODY_SIZE) * sizeof(char);
  size_t u8_field_sizes = 2 * sizeof(u8);
  size_t u16_field_sizes = sizeof(u16); // could be removed, but more u16 values could be added later.
  
  char *serialized = (char*)malloc(char_field_sizes + u8_field_sizes + u16_field_sizes);
  strcpy(serialized, ""); // not too sure why, but without this id get garbage

  // serializing the header!!
  sprintf(serialized, "%s\t%u\t%c\t%u", 
    message->header.magic_number,
    message->header.version,
    message->header.command_type,
    message->header.body_length );

  // serializing the body
  if (message->body != NULL) sprintf(serialized, "%s\t%s",
    serialized,
    message->body);

  return serialized;
}

// TODO add limits to make sure the message doesn't go over the allowed limit
message_t deserialize_message(const char *input) {
  char *buffer = (char*)malloc(sizeof(input));
  strcpy(buffer, input);

  message_t message;

  char* token = strtok(buffer, "\t");
  strcpy(message.header.magic_number, token);

  size_t itr = 0;
  while (token != NULL) {
    token = strtok(NULL, "\t");

    // silly hardcoded stuff
    switch (itr) {
      case 0:
        message.header.version = atoi(token);
        break;
      case 1:
        message.header.command_type = token[0];
        break;
      case 2:
        message.header.body_length = atoi(token);
        break;
      case 3:
        strcpy(message.body, token);
        break;

      default:
        break;
    }

    itr++;
  }

  return message;
}