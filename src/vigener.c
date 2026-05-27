#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../include/structure.h"
#include "../include/predicate.h"


static int get_shift(char key_char)
{
	return tolower(key_char) - 'a';
}

encrypt_status vigener_encryption (
												const char *input,
												char *output,
												size_t output_size,
												const char *key)
{
	uint8_t ret_res = ENCRYPT_OK;

	ret_res = !input ?
					ERR_ENCRYPT_NULL_STR
					: (!is_valid_key(key)) ?
					ERR_ENCRYPT_INVALID_KEY
					: ENCRYPT_OK;

	switch (ret_res) {
		case ENCRYPT_OK:
			size_t ind = 0;
			size_t key_pos = 0;
			size_t key_len = strlen(key);

			for (ind;
				  input[ind] != '\0';
				  ind++) {
				if (isalpha(input[ind])) {
					int shift = get_shift(key[key_pos % key_len]);

					if (isupper(input[ind])) {
						output[ind] = (char)((input[ind] - 'A' + shift) % 26) + 'A';
					} else {
						output[ind] = (char)((input[ind] - 'a' + shift) % 26) + 'a';
					}
					key_pos++;

				} else {
					output[ind] = input[ind];
				}
			}
			output[ind] = '\0';
			break;
		case ERR_ENCRYPT_NULL_STR:
			printf("Строка для сдвига должна быть вписана\n");
			break;
		case ERR_ENCRYPT_INVALID_KEY:
			printf("Ключ для сдвига должен быть указан \n");
			break;
		default:
			printf("Неизвестная ошибка \n");
	}

	return ret_res;
}

encrypt_status vigener_decryption (
												const char *input,
												char *output,
												size_t output_size,
												const char *key)
{
	uint8_t ret_res = ENCRYPT_OK;

	ret_res = !input ?
					ERR_ENCRYPT_NULL_STR
					: (!is_valid_key(key)) ?
					ERR_ENCRYPT_INVALID_KEY
					: ENCRYPT_OK;


	switch (ret_res) {
		case ENCRYPT_OK:
			size_t ind = 0;
			size_t key_pos = 0;
			size_t key_len = strlen(key);

			for (ind;
					input[ind] != '\0';
					ind++) {
				if (isalpha(input[ind])) {
					int shift = get_shift(key[key_pos % key_len]);

					if (isupper(input[ind])) {
						output[ind] = (char)((input[ind] - 'A' - shift + 26) % 26) + 'A';
					} else {
						output[ind] = (char)((input[ind] - 'a' - shift + 26) % 26) + 'a';
					}
					key_pos++;

				} else {
					output[ind] = input[ind];
				}
					}
			output[ind] = '\0';
			break;
		case ERR_ENCRYPT_NULL_STR:
			printf("Строка для сдвига должна быть вписана\n");
			break;
		case ERR_ENCRYPT_INVALID_KEY:
			printf("Ключ для сдвига должен быть указан \n");
			break;
		default:
			printf("Неизвестная ошибка \n");
	}

	return ret_res;
}