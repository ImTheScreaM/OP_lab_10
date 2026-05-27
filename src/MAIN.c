/*----------------------------------------------------------------------------------------|
|  MAIN.c                                                                                 |
|  version 0.0.1                                                                          |
|                                                                                         |
|                                                                                         |
|  Назначение:                                                                            |
|    Разработать библиотеку для шифрования и дешифрования текста классическими шифрами.   |
|     Шифр Цезаря — это шифр подстановки, в котором каждая буква сдвигается по алфавиту на|
|     фиксированное число позиций. Шифр Виженера — это шифр, в котором величина сдвига    |
|     каждой буквы задаётся символами ключевого слова. Реализовать прямое и обратное      |
|     преобразование строки шифром Цезаря и шифром Виженера с сохранением символов, не    |
|     входящих в алфавит, и проверку того, что дешифрование восстанавливает исходный текст|
|                                                                                         |
|  Входные данные:                                                                        |
|   Строка                                                                                |
|                                                                                         |
|  Выходные данные:                                                                       |
|    1) Строка после шифрования                                                           |
|    2) Строка после дешифрования                                                         |
|  Автор:                                                                                 |
|    ст. Старов А.В                                                                       |
|    Белгород: 23.05.2026                                                                 |
|                                                                                         |
|  Пример использования:                                                                  |
|    ./app                                                                                |
|-----------------------------------------------------------------------------------------*/

#include "../include/structure.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define OK 0
#define MAX_STR_SIZE 1024
#define MAX_KEY_SIZE 26

int main() {
	uint8_t ret_res = ENCRYPT_OK;

	char entered_str[MAX_STR_SIZE];
	char caesar_encrypt[MAX_STR_SIZE];
	char caesar_decrypt[MAX_STR_SIZE];
	char vigener_encrypt[MAX_STR_SIZE];
	char vigener_decrypt[MAX_STR_SIZE];

	int shift;
	char key[MAX_KEY_SIZE];


	printf("Введите строку \n");
	fgets(entered_str,sizeof(entered_str),stdin);
	entered_str[strcspn(entered_str, "\n")] = '\0';

	printf("Введите сдвиг \n");
	scanf("%d",&shift);
	getchar();

	printf("Введите ключ \n");
	fgets(key,sizeof(key),stdin);
	key[strcspn(key, "\n")] = '\0';

	printf("Исходня строка: %s\n",entered_str);



	printf("----- Шифр Цезаря -----\n");
	ret_res = caesar_encryption(entered_str, caesar_encrypt, shift);
	if (ret_res == ENCRYPT_OK) {
		printf("Зашифрованная строка с помощью шифра Цезаря: %s\n",caesar_encrypt);

		ret_res = caesar_decryption(caesar_encrypt, caesar_decrypt, shift);

		if (ret_res == ENCRYPT_OK) {
			printf("Расшифровано: %s\n",caesar_decrypt);

			if (strcmp(entered_str,caesar_decrypt) == 0) {
				printf("Текст успешно восстановлен\n");
			} else {
				printf("Текст не был восстановлен");
			}

		}
	}

	printf("----- Шифр Винжера -----\n");
	ret_res = vigener_encryption(entered_str, vigener_encrypt, key);
	if (ret_res == ENCRYPT_OK) {
		printf("Зашифрованная строка с помощью шифра Вижера: %s\n",vigener_encrypt);

		ret_res = vigener_decryption(vigener_encrypt, vigener_decrypt, key);

		if (ret_res == ENCRYPT_OK) {
			printf("Расшифровано: %s\n",vigener_decrypt);

			if (strcmp(entered_str,vigener_decrypt) == 0) {
				printf("Текст успешно восстановлен\n");
			} else {
				printf("Текст не был восстановлен\n");
			}
		}
	}


	return OK;
}