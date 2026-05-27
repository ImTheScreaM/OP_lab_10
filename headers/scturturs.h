#ifndef SCTURTURS_H
#define SCTURTURS_H

#include <stddef.h>


typedef enum {
	ENCRYPT_OK = 0,
	ERR_ENCRYPT_NULL_POINTER,
	ERR_ENCRYPT_INVALID_ARG,
} encrypt_status;

ecrypt_status caesar_encryption (
	const char *input,
	char *output,
	size_t output_size,
	int shift
);

ecrypt_status caesar_decryption (
	const char *input,
	char *output,
	size_t output_size,
	int shift
);

ecrypt_status vigener_encryption (
	const char *input,
	char *output,
	size_t output_size,
	const char *key
);

ecrypt_status vigener_decryption (
	const char *input,
	char *output,
	size_t output_size,
	const char *key
);


#endif //SCTURTURS_H