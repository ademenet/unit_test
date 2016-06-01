#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define DEBUG 1

int		test_run = 0;

#define MY_TEST(name, ft) printf("%-15s -- ", name); ft();

#define MY_UNIT_TEST(name) void name()

#define ALL_TESTS void run_all_tests(void)

#define RUN_TEST	int main()\
					{\
						setbuf(stdout, NULL);\
						run_all_tests();\
						fprintf(stdout, "\nTESTS RUN: %d\n", test_run);\
						return (0);\
					}\

#define UT_ASS(msg, test) test_run++; do { if (!(test)) printf("%s", msg); else printf("."); } while (0);

/*
** HOW TO USE THIS UNIT TEST?
**
** Create a new file:
** #include "u-test.h"
** #include "foo.h"
**
** MY_UNIT_TEST(test_foo)
** {
** 		UT_ASS("Error", foo == value)
** }
**
** ALL_TESTS
** {
** 		MY_TEST("foo", test_foo)
** }
**
** RUN_TEST
**
** And, compile with sources... That's it!
*/
