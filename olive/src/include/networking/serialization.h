#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "../utils.h"
#include "message.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* serialize_message(const message_t *message);
message_t deserialize_message(const char *input);

char* serialize_response(const response_t *response);
response_t deserialize_response(const char *input);

#endif