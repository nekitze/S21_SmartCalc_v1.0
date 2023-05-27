#include "calc.h"

int calculate(stack_node_t *object_list, double *result) {
  calc_object_t end;
  end.operation = '\0';
  end.priority = -1;
  end.value = 0;

  calc_object_t res;
  res.operation = '\0';
  res.priority = 0;
  res.value = 0;

  stack_node_t *output_stack = create_node(end);
  stack_node_t *operators_stack = create_node(end);

  while (object_list->object.priority != -1) {
    if (object_list->object.priority == 0) {
      push(&output_stack, object_list->object);
      object_list = object_list->next;

    } else if (object_list->object.priority > 0 &&
               object_list->object.priority < 4) {
      if ((object_list->object.priority > operators_stack->object.priority) ||
          operators_stack->object.priority == 4) {
        push(&operators_stack, object_list->object);
        object_list = object_list->next;
      } else {
        res = calc_operator(operators_stack, output_stack);
        pop_used(&operators_stack, &output_stack);
        push(&output_stack, res);
      }

    } else if (object_list->object.priority == 4) {
      if (object_list->object.operation == ')') {
        while (operators_stack->object.priority != 4) {
          res = calc_operator(operators_stack, output_stack);
          pop_used(&operators_stack, &output_stack);
          push(&output_stack, res);
        }
        res = calc_function(operators_stack, output_stack);
        pop(&operators_stack);
        pop(&output_stack);
        push(&output_stack, res);
        object_list = object_list->next;

      } else if (object_list->object.operation == '~') {
        object_list = object_list->next;
        object_list->object.value = -object_list->object.value;
      } else {
        push(&operators_stack, object_list->object);
        object_list = object_list->next;
      }
    }
  }

  while (operators_stack->object.priority != -1) {
    if (operators_stack->object.priority != 4) {
      res = calc_operator(operators_stack, output_stack);
      pop_used(&operators_stack, &output_stack);
      push(&output_stack, res);
    } else {
      res = calc_function(operators_stack, output_stack);
      pop(&operators_stack);
      pop(&output_stack);
      push(&output_stack, res);
    }
  }

  *result = output_stack->object.value;

  abort_stack(&object_list);
  abort_stack(&output_stack);
  abort_stack(&operators_stack);

  return 0;
}

calc_object_t calc_operator(stack_node_t *operators_stack,
                            stack_node_t *output_stack) {
  calc_object_t result;
  result.operation = '\0';
  result.priority = 0;

  if (operators_stack->object.operation == '+') {
    result.value =
        output_stack->next->object.value + output_stack->object.value;
  } else if (operators_stack->object.operation == '-') {
    result.value =
        output_stack->next->object.value - output_stack->object.value;
  } else if (operators_stack->object.operation == '*') {
    result.value =
        output_stack->next->object.value * output_stack->object.value;
  } else if (operators_stack->object.operation == '/') {
    result.value =
        output_stack->next->object.value / output_stack->object.value;
  } else if (operators_stack->object.operation == '%') {
    result.value =
        fmod(output_stack->next->object.value, output_stack->object.value);
  } else if (operators_stack->object.operation == '^') {
    result.value =
        pow(output_stack->next->object.value, output_stack->object.value);
  }

  return result;
}

calc_object_t calc_function(stack_node_t *operators_stack,
                            stack_node_t *output_stack) {
  calc_object_t result;
  result.operation = '\0';
  result.priority = 0;

  if (operators_stack->object.operation == '(') {
    result.value = output_stack->object.value;
  } else if (operators_stack->object.operation == '~') {
    result.value = output_stack->object.value * -1.;
  } else if (operators_stack->object.operation == COS) {
    result.value = cos(output_stack->object.value);
  } else if (operators_stack->object.operation == SIN) {
    result.value = sin(output_stack->object.value);
  } else if (operators_stack->object.operation == TAN) {
    result.value = tan(output_stack->object.value);
  } else if (operators_stack->object.operation == ACOS) {
    result.value = acos(output_stack->object.value);
  } else if (operators_stack->object.operation == ASIN) {
    result.value = asin(output_stack->object.value);
  } else if (operators_stack->object.operation == ATAN) {
    result.value = atan(output_stack->object.value);
  } else if (operators_stack->object.operation == SQRT) {
    result.value = sqrt(output_stack->object.value);
  } else if (operators_stack->object.operation == LN) {
    result.value = log(output_stack->object.value);
  } else if (operators_stack->object.operation == LOG) {
    result.value = log10(output_stack->object.value);
  }

  return result;
}

void pop_used(stack_node_t **operators_stack, stack_node_t **output_stack) {
  pop(output_stack);
  pop(output_stack);
  pop(operators_stack);
}
