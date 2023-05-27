#include "test.h"

void run_suite(Suite *suite) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    exit(1);
  }
}

int main() {
  const int suites_cnt = 2;
  Suite *suites[] = {calc_functions(), integration()};
  for (int i = 0; i < suites_cnt; i++) {
    run_suite(suites[i]);
  }
}

