#include <stdlib.h>
#include <stdio.h>
#include "munit.h"
#include "read_line.h"

static MunitResult
test_read_line(const MunitParameter params[], void* data) {

	FILE *fi;
	char *s;
	bool_t eof;

	fi = fopen("test_read_line.txt", "rt");
	if(fi == NULL) {
		return MUNIT_ERROR;
	}

	munit_assert(read_line(fi, &s, &eof) == OK );
	munit_assert( eof == FALSE );
	munit_assert_string_equal(s, "Hi, how are you?");
	free(s);

	munit_assert(read_line(fi, &s, &eof) == OK );
	munit_assert( eof == FALSE );
	munit_assert_string_equal(s, "");
	free(s);

  munit_assert(read_line(fi, &s, &eof) == OK );
	munit_assert( eof == TRUE );
	munit_assert_string_equal(s, "We're all good, thank you!");
	free(s);

	fclose(fi);
  return MUNIT_OK;

}

static MunitTest test_suite_tests[] = {
	{(char*) "/read_line",test_read_line,NULL,NULL,MUNIT_TEST_OPTION_NONE,NULL},
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
  (char*) "", test_suite_tests,NULL,1,MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);

}
