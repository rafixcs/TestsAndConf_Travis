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
	const char teste = 'a';
	TEST_ASSERT(valid_s(teste));
}

TEST(Identifier, unitaryIntTest)
{
	const char teste = '5';
	TEST_ASSERT_FALSE(valid_s(teste));
}

TEST(Identifier, charIntTest)
{
	const char *teste = "a5";
	TEST_ASSERT(valid_string(teste));
}

TEST(Identifier, stringTest)
{
	const char *teste = "aabb";
	TEST_ASSERT(valid_string(teste));
}

TEST(Identifier, intCharTest)
{
	const char *teste = "5a";
	TEST_ASSERT_FALSE(valid_string(teste));
}

TEST(Identifier, maxSizeString)
{
	const char *teste = "Teste";
	TEST_ASSERT(valid_string(teste));
}

TEST(Identifier, largerSizeString)
{
	const char *teste = "MaisUmTeste";
	TEST_ASSERT_FALSE(valid_string(teste));
}

TEST(Identifier, specialCharUnitary)
{
	const char teste = '$';
	TEST_ASSERT_FALSE(valid_s(teste));
}

TEST(Identifier, specialStringTest)
{
	const char *teste = "$&!";
	TEST_ASSERT_FALSE(valid_string(teste));
}

TEST(Identifier, mixedStringTest)
{
	const char *teste = "a\%5s";
	TEST_ASSERT_FALSE(valid_string(teste));
}