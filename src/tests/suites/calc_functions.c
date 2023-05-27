#include "../test.h"

START_TEST(calc_default_brackets) {
  double result = 0;

  calc_object_t object0;

  object0.operation = '\0';
  object0.priority = -1;
  object0.value = 0;

  calc_object_t object1;

  object1.operation = '(';
  object1.priority = 4;
  object1.value = 0;

  calc_object_t object2;

  object2.operation = '\0';
  object2.priority = 0;
  object2.value = 2;

  calc_object_t object3;

  object3.operation = '+';
  object3.priority = 1;
  object3.value = 0;

  calc_object_t object4;

  object4.operation = '\0';
  object4.priority = 0;
  object4.value = 2;

  calc_object_t object5;

  object5.operation = ')';
  object5.priority = 4;
  object5.value = 0;

  calc_object_t object6;

  object6.operation = '*';
  object6.priority = 2;
  object6.value = 0;

  calc_object_t object7;

  object7.operation = '\0';
  object7.priority = 0;
  object7.value = 2;

  stack_node_t *list = create_node(object0);
  
  push_back(&list, object1);
  push_back(&list, object2);
  push_back(&list, object3);
  push_back(&list, object4);
  push_back(&list, object5);
  push_back(&list, object6);
  push_back(&list, object7);
  pop(&list);

  push_back(&list, object0);

  calculate(list, &result);

  ck_assert_double_eq(result, 8);

}
END_TEST

Suite *calc_functions() {
  Suite *suite = suite_create("calc_functions");

  TCase *tcase_add = tcase_create("calc_functions");

  tcase_add_test(tcase_add, calc_default_brackets);

  suite_add_tcase(suite, tcase_add);

  return suite;
}
