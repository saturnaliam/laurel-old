#ifndef MESSAGE_H
#define MESSAGE_H

#include "utils.h"

#define BODY_SIZE 127
#define RESPONSE_SIZE 255

typedef enum {
OK = 200,
BAD_REQUEST = 400,
UNAUTHORIZED = 401,
PRECONDITION_FAILED = 412,
PAYLOAD_TOO_LARGE = 413,
NOT_IMPLEMENTED = 501,
} response_code;

typedef struct {
  char magic_number[3];
  u8 version;
  char command_type;
  u8 body_length;
  u16 padding_bytes;
} message_header;

typedef struct {
  message_header header;
  char *body;
} message;

typedef struct {
  response_code code;
  char *body;
} response;

#endif
