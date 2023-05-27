#include "calc.h"

int init_calc(char *source, double *result) {
  int res = 0;

  calc_object_t init_object;

  init_object.operation = '\0';
  init_object.priority = -1;
  init_object.value = 0;

  stack_node_t *list = create_node(init_object);

  res = parse_input_string(source, &list);

  if (!res) {
    pop(&list);
    push_back(&list, init_object);
    calculate(list, result);
  } else {
    abort_stack(&list);
  }

  return res;
}
