#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "../include/shift.h"
#include "../include/structure.h"

encrypt_status caesar_encryption(
	                    const char *input,
                      char *output,
                      int shift)
{
	uint8_t ret_res = ENCRYPT_OK;

	ret_res = !input ?
	          ERR_ENCRYPT_NULL_STR
						:  ENCRYPT_OK;


	switch (ret_res) {
		case ENCRYPT_OK:
			size_t ind = 0;

			for (; input[ind] != '\0'; ind++) {
				output[ind] = (char)shift_encrypt_char(input[ind],shift);
			}
			output[ind] = '\0';
			break;
		case ERR_ENCRYPT_NULL_STR:
			printf("Строка для сдвига должна быть вписана\n");
		 	break;
		case ERR_ENCRYPT_INVALID_ARG:
			printf("Сдвиг должен быть указан \n");
			break;
		default:
			printf("Неизвестная ошибка \n");
	}

	return ret_res;
}

encrypt_status caesar_decryption(
                    const char *input,
										char *output,
										int shift)
{
	uint8_t ret_res = ENCRYPT_OK;

	ret_res = !input ?
						ERR_ENCRYPT_NULL_STR
						: ENCRYPT_OK;



	switch (ret_res) {
		case ENCRYPT_OK:
			size_t ind = 0;

			for (;input[ind] != '\0';ind++) {
				output[ind] = (char)shift_decrypt_char(input[ind],shift);
					}
			output[ind] = '\0';
			break;
		case ERR_ENCRYPT_NULL_STR:
			printf("Строка для сдвига должна быть вписана\n");
			break;
		case ERR_ENCRYPT_INVALID_ARG:
			printf("Сдвиг должен быть указан \n");
			break;
		default:
			printf("Неизвестная ошибка \n");
	}

	return ret_res;
}

