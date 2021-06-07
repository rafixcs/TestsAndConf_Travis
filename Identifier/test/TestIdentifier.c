#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, unitaryCharTest)
{
	char teste = 'A';
	while (teste != 'Z') {
		TEST_ASSERT(valid_s(teste));
		teste++;
	}
	teste = 'a';
	while (teste != 'z') {
		TEST_ASSERT(valid_s(teste));
		teste++;
	}
}

TEST(Identifier, unitaryIntTest)
{
	char teste = '0';
	while (teste != '9') {
		TEST_ASSERT_FALSE(valid_s(teste));
		teste++;
	}
}

TEST(Identifier, charIntTest)
{
	char teste[] = "a0";
	while(teste[1] != '9') {
		TEST_ASSERT(valid_string(teste));
		teste[1]++;
	}
}

TEST(Identifier, stringTest)
{
	char teste[] = "AaA";

	while(teste[1] != 'z') {
		TEST_ASSERT(valid_string(teste));
		teste[1]++;		
	}
	
	while (teste[2] != 'Z') {
		TEST_ASSERT(valid_string(teste));
		teste[2]++;
	} 
}

TEST(Identifier, intCharTest)
{
	char teste[] = "0a";	
	TEST_ASSERT_FALSE(valid_string(teste));
}

TEST(Identifier, maxSizeString)
{
	const char *teste = "Te5te9";
	TEST_ASSERT(valid_string(teste));
}

TEST(Identifier, largerSizeString)
{
	const char *teste = "MaisUmTeste";
	TEST_ASSERT_FALSE(valid_string(teste));
}

TEST(Identifier, specialCharUnitary)
{
	char teste = 0;
	while (teste < 127) {
		if (teste < '0' && teste > '9' && teste < 'a' && teste > 'z' && teste < 'A' && teste >'Z')
			TEST_ASSERT_FALSE(valid_s(teste));
		teste++;
	}
}

TEST(Identifier, specialStringTest)
{
	char teste[] = {33,33,33};	
	for (int i=0; i<2; i++) {
		while(teste[i] < 127) {
			if (teste[i] < '0' && teste[i] > '9' && teste[i] < 'a' && teste[i] > 'z' && teste[i] < 'A' && teste[i] >'Z')
				TEST_ASSERT_FALSE(valid_string(teste));
			teste[i]++;
		}
	}
	
}

TEST(Identifier, mixedStringTest)
{
	unsigned char *teste = "a&";
	TEST_ASSERT_FALSE(valid_string(teste));
}