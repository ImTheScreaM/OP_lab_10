#include "../include/shift.h"
#define ALPHABET_SIZE 26

int shift_encrypt_char(int ch,int shift) {
	int result = ch;
	if (ch >= 'a' && ch <= 'z') {
		result = ((ch - 'a' + shift) % ALPHABET_SIZE + 'a') ;
	} else if (ch >= 'A' && ch <= 'Z') {
		 result = ((ch - 'A' + shift) % ALPHABET_SIZE + 'A') ;
	} else {
		result = ch;
	}
	return result;
}

int shift_decrypt_char(int ch,int shift) {
	return shift_encrypt_char(ch,26 - (shift % 26));
}