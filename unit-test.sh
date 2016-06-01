#!/bin/sh

if [ "$1" == "create" ] && [ ! -f unit-test.c ]
then
	echo  "#include "u-test.h"\n#include "foo.h"\n\nMY_UNIT_TEST(test_foo)\n{\n\tUT_ASS("Error", foo == value)\n}\n\nALL_TESTS\n{\n\tMY_TEST("foo", test_foo)\n}\n\nRUN_TEST" > unit-test.c
fi

gcc -Wall -Wextra -Werror	unit-test.c\
							foo.c
