#include "../test.h"

START_TEST(parse_and_calc_default) {

  double result = 0;
  
  char *source = "2 + 2\0";

  init_calc(source, &result);

  ck_assert_double_eq(result, 4);

}
END_TEST

START_TEST(parse_and_calc_float) {

  double result = 0;
  
  char *source = "2.2 + 2.2\0";

  init_calc(source, &result);

  ck_assert_double_eq(result, 4.4);

}
END_TEST

START_TEST(parse_and_calc_unary) {

  double result = 0;
  
  char *source = "(-2.2) + (-2.2)\0";

  init_calc(source, &result);

  ck_assert_double_eq(result, -4.4);

}
END_TEST

START_TEST(logic_case) {

  double result = 0;
  
  char *source = "(2 + 2) * 2\0";

  init_calc(source, &result);

  ck_assert_double_eq(result, 8);

}
END_TEST

START_TEST(sin_case) {

  double result = 0;
  
  char *source = "sin(0)*5";

  init_calc(source, &result);

  ck_assert_double_eq(result, 0);

}
END_TEST

START_TEST(cos_case) {

  double result = 0;
  
  char *source = "cos(0)*5";

  init_calc(source, &result);

  ck_assert_double_eq(result, 5);

}
END_TEST

START_TEST(complex_case) {

  double result = 0;
  
  char *source = "(cos(0)*5)^2";

  init_calc(source, &result);

  ck_assert_double_eq(result, 25);

}
END_TEST

START_TEST(unary_dobule) {

  double result = 0;
  
  char *source = "(-0.3)*(-0.3)";

  init_calc(source, &result);

  ck_assert_double_eq(result, 0.09);

}
END_TEST

START_TEST(dobule_int) {

  double result = 0;
  
  char *source = "(-0.6)^2";

  init_calc(source, &result);

  ck_assert_double_eq(result, 0.36);

}
END_TEST

START_TEST(credit_ann) {

  double result = 0;
  
  char *source = "2000*((0.04*(1+0.04)^48)/((1+0.04)^(48-1)))";

  init_calc(source, &result);

  ck_assert_double_eq_tol(result, 83.2, 0.0000001);

}
END_TEST

START_TEST(onemore) {

  double result = 0;
  
  char *source = "3/3/3";

  init_calc(source, &result);

  ck_assert_double_eq_tol(result, 0.333333, 0.1);

}
END_TEST

START_TEST(buggy_plus) {

  double result = 0;
  
  char *source = "+1+2";

  init_calc(source, &result);

  ck_assert_double_eq(result, 3);

}
END_TEST

START_TEST(other_functions) {

  double result = 0;
  
  char *source = "-sqrt(4)*acos(0)-ln(2^3)+tan(2)mod(1)-asin(0.4)/atan(2)*log(1)";

  init_calc(source, &result);

  ck_assert_double_eq_tol(result, 0.877111, 0.0001);

}
END_TEST

Suite *integration() {
  Suite *suite = suite_create("integration");

  TCase *tcase_add = tcase_create("integration");

  tcase_add_test(tcase_add, parse_and_calc_default);
  tcase_add_test(tcase_add, parse_and_calc_float);
  tcase_add_test(tcase_add, parse_and_calc_unary);
  tcase_add_test(tcase_add, logic_case);
  tcase_add_test(tcase_add, sin_case);
  tcase_add_test(tcase_add, cos_case);
  tcase_add_test(tcase_add, complex_case);
  tcase_add_test(tcase_add, unary_dobule);
  tcase_add_test(tcase_add, dobule_int);
  tcase_add_test(tcase_add, credit_ann);
  tcase_add_test(tcase_add, onemore);
  tcase_add_test(tcase_add, buggy_plus);
  tcase_add_test(tcase_add, other_functions);

  suite_add_tcase(suite, tcase_add);

  return suite;
}
