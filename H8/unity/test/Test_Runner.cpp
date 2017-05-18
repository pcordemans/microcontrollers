#include "../unity/unity.h"

extern void setUp(void);
extern void tearDown(void);

extern void test(void);

int unity_run_tests(void) {
	printf("Start testing \n");

	UnityBegin("Tests.cpp");

	RUN_TEST(test, 1);

	return(UnityEnd());

}
