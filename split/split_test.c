#include <stdlib.h>
#include <stdio.h>
#include "munit.h"
#include "split.h"

static MunitResult
test_strdup(const MunitParameter params[], void* data) {

	size_t l;
	char *s;

	s = strdup_n("aholaa", 1, 4);

  munit_assert_string_equal(s, "hola");

	free(s);
  return MUNIT_OK;
}

static MunitResult
test_null_pointers(const MunitParameter params[], void* data) {

	size_t l;
  munit_assert(split("", ',', NULL, &l) == ERROR_NULL_POINTER);
	munit_assert(split(NULL, ',', NULL, NULL) == ERROR_NULL_POINTER);

  return MUNIT_OK;
}

static MunitResult
test_split(const MunitParameter params[], void* data) {

	size_t l;
	char del = ',';
	char **splitted;
  munit_assert(split("hola,mundo,feliz", del, &splitted, &l) == OK);
	munit_assert(l == 3);

	munit_assert_string_equal(splitted[0], "hola");
	munit_assert_string_equal(splitted[1], "mundo");
	munit_assert_string_equal(splitted[2], "feliz");delete_string_array(&splitted,l);

	split("hola", del, &splitted, &l);
	munit_assert(l == 1);
	munit_assert_string_equal(splitted[0], "hola");
	delete_string_array(&splitted,l);

	split(",", del, &splitted, &l);
	munit_assert(l == 2);
	munit_assert_string_equal(splitted[0], "");
	munit_assert_string_equal(splitted[1], "");
	delete_string_array(&splitted,l);

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
	{(char*) "/strdup",test_strdup,NULL,NULL,MUNIT_TEST_OPTION_NONE,NULL},
  {(char*) "/null_pointers",test_null_pointers,NULL,NULL,MUNIT_TEST_OPTION_NONE,NULL},
	{(char*) "/split",test_split,NULL,NULL,MUNIT_TEST_OPTION_NONE,NULL},
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
  (char*) "", test_suite_tests,NULL,1,MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);

}
