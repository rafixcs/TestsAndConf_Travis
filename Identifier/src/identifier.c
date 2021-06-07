// ----------------------------------------------------------------
// ESPECIFICAÇÃO: O programa deve determinar se um identificador
// é ou não válido. Um identificador válido deve começar com uma
// letra e conter apenas letras ou dígitos. Além disto, deve ter
// no mínimo 1 caractere e no máximo 6 caracteres de comprimento
// ----------------------------------------------------------------

#include "identifier.h"
#include <stdio.h>
#include <string.h>

int valid_s(char ch) {
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		return 1;
	else
		return 0;
}

int valid_f(char ch) {
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
		return 1;
	else
		return 0;
}

int valid_string(char *string) {
	char achar;
	int length, valid_id;
	length = 0;
	achar = string[0];
	valid_id = valid_s(achar);
	length++;
	if (!valid_id) {
		return 0;
	}
	while (length < (int)strlen(string)) {
		if (!(valid_f(achar))) {
			valid_id = 0;
		}
		achar = string[length];
		length++;
	}
	if (valid_id && (length >= 1) && (length <= 6)) {
		return 1;
	}
	else {
		return 0;
	}
}