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
} response_code_t;

typedef struct {
  char magic_number[3];
  u8 version;
  char command_type;
  u8 body_length;
  u16 padding_bytes;
} message_header_t;

typedef struct {
  message_header_t header;
  char *body;
} message_t;

typedef struct {
  response_code_t code;
  char *body;
} response_t;

#endif
