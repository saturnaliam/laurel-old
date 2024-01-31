#ifndef MESSAGE_H
#define MESSAGE_H

#include "utils.h"

#define BODY_SIZE 127

typedef struct {
  char magic_number[3];
  u8 version;
  char command_type;
  u8 body_length;
  u16 padding_bytes;
} message_header;

typedef struct {
  message_header header;
  char body[BODY_SIZE];
} message;

#endif