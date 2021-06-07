#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Identifier)
{
  RUN_TEST_CASE(Identifier, unitaryCharTest);
  RUN_TEST_CASE(Identifier, unitaryIntTest);
  RUN_TEST_CASE(Identifier, charIntTest);
  RUN_TEST_CASE(Identifier, stringTest);
  RUN_TEST_CASE(Identifier, intCharTest);
  RUN_TEST_CASE(Identifier, maxSizeString);
  RUN_TEST_CASE(Identifier, largerSizeString);
  RUN_TEST_CASE(Identifier, specialCharUnitary);
  RUN_TEST_CASE(Identifier, specialStringTest);
  RUN_TEST_CASE(Identifier, mixedStringTest);
}

