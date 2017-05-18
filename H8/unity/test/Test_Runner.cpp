#include "../unity/unity.h"
#include "Test_Runner.h"

extern void setUp(void);
extern void tearDown(void);

extern void test(void);

int unity_run_tests() {
	printf("Start testing \n");

	UnityBegin("Tests.cpp");

	RUN_TEST(test, 1);

	return(UnityEnd());

}
