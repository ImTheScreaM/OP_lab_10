#include "../include/structure.h"

#include <assert.h>
#include <string.h>

#define BUFFER_SIZE 256

int test()
{
	char buffer[BUFFER_SIZE];
	char result[BUFFER_SIZE];

	assert(
			caesar_encryption("ABC", buffer, 3)
			== ENCRYPT_OK);

	assert(strcmp(buffer, "DEF") == 0);

	assert(
			caesar_decryption(buffer, result, 3)
			== ENCRYPT_OK);

	assert(strcmp(result, "ABC") == 0);

	assert(
			vigener_encryption("HELLO", buffer, "KEY")
			== ENCRYPT_OK);

	assert(
			vigener_decryption("HELLO WORLD", buffer, "KEY")
			== ENCRYPT_OK);

	assert(strcmp(result, "HELLO") == 0);

	return 0;
}