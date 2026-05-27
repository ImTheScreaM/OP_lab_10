
#include <stdint.h>
#include <string.h>

#include "../include/predicate.h"

#include <ctype.h>

bool is_valid_key(const char *key) {
	uint8_t ret_res = 1;
	size_t ind = 0;

	if (!key || strlen(key) == 0) {
		ret_res = 0;
	}

	for (;key[ind] != '\0';ind++) {
		if (!isalpha(key[ind])) {
			ret_res = 0;
		}
	}

	return ret_res;
}