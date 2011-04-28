#ifndef __QUIKEE_H__
#define __QUIKEE_H__

#include <stddef.h>
#include "quikee/url.h"

// A key/value pair specifically for chaining HTTP headers in a linked list
typedef struct qkHttpHeader_s qkHttpHeader;

// The structure that represents a single HTTP header
struct qkHttpHeader_s {
	char *key;
	char *value;

	qkHttpHeader* next;
};

// Describes a generic request.
typedef struct {
	char *body;

	qkHttpHeader *first_header; // First node in a linked-list of HttpHeader
} qkHttpRequest;

void quikee_real_url(const qkURL url, char *buffer);

#endif
