#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stddef.h>


typedef enum {
	ENCRYPT_OK = 0,
	ERR_ENCRYPT_NULL_STR,
	ERR_ENCRYPT_INVALID_ARG,
	ERR_ENCRYPT_INVALID_KEY,
} encrypt_status;

encrypt_status caesar_encryption (
	const char *input,
	char *output,
	size_t output_size,
	int shift
);

encrypt_status caesar_decryption (
	const char *input,
	char *output,
	size_t output_size,
	int shift
);

encrypt_status vigener_encryption (
	const char *input,
	char *output,
	size_t output_size,
	const char *key
);

encrypt_status vigener_decryption (
	const char *input,
	char *output,
	size_t output_size,
	const char *key
);


#endif //STRUCTURE_H