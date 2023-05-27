#include "calc.h"

int parse_input_string(char *source, stack_node_t **list) {
  int res = 0;
  calc_object_t object;

  object.operation = '\0';
  object.priority = 0;
  object.value = 0;

  int i = 0;

  res = check_correct(source);

  while (source[i] != '\0') {
    if (source[i] != ' ' && (source[i] < 48 || source[i] > 57)) {
      object = parse_operation(source, &i);

      if (object.operation != '\0')
        push_back(list, object);
      else if (object.operation == 'M') {
      } else {
        res = 1;
      }

    } else if (source[i] != ' ' && (source[i] >= 48 && source[i] <= 57)) {
      object.operation = '\0';
      object.priority = 0;
      if (parse_operand(source, &i, &object.value)) res = 1;
      push_back(list, object);
    }

    i++;
  }

  return res;
}

int parse_operand(char *source, int *i, double *result) {
  int res = 0;
  char number[256];
  int j = 0;
  int mantisa = 0;

  while ((source[*i] > 47 && source[*i] < 58) || source[*i] == '.') {
    if (source[*i] == '.' && !mantisa)
      mantisa = 1;
    else if (source[*i] == '.' && mantisa)
      res = 1;

    number[j] = source[*i];
    j++;
    number[j] = '\0';
    *i += 1;
  }

  *i -= 1;

  *result = strtod(number, NULL);

  return res;
}

calc_object_t parse_operation(char *source, int *i) {
  calc_object_t res;
  res.operation = '\0';
  res.priority = 0;
  res.value = 0;

  switch (source[*i]) {
    case '+':
      if (*i > 0) {
        if (source[*i - 1] == '(') {
        } else {
          res.operation = '+';
          res.priority = 1;
        }
      } else if (*i == 0) {
        res.operation = 'M';
      }
      break;
    case '-':
      if (*i > 0) {
        if (source[*i - 1] == '(') {
          res.operation = '~';
          res.priority = 4;
        } else {
          res.operation = '-';
          res.priority = 1;
        }
      } else if (*i == 0) {
        res.operation = '~';
        res.priority = 4;
      }
      break;
    case '*':
      res.operation = '*';
      res.priority = 2;
      break;
    case '/':
      res.operation = '/';
      res.priority = 2;
      break;
    case 'm':
      if (source[*i + 1] == 'o' && source[*i + 2] == 'd') {
        *i += 2;
        res.operation = '%';
        res.priority = 2;
      }
      break;
    case '^':
      res.operation = '^';
      res.priority = 3;
      break;
    case 'c':
      if (source[*i + 1] == 'o' && source[*i + 2] == 's' &&
          source[*i + 3] == '(') {
        *i += 3;
        res.operation = COS;
        res.priority = 4;
      }
      break;
    case 's':
      if (source[*i + 1] == 'i' && source[*i + 2] == 'n' &&
          source[*i + 3] == '(') {
        *i += 3;
        res.operation = SIN;
        res.priority = 4;
      } else if (source[*i + 1] == 'q' && source[*i + 2] == 'r' &&
                 source[*i + 3] == 't' && source[*i + 4] == '(') {
        *i += 4;
        res.operation = SQRT;
        res.priority = 4;
      }
      break;
    case 't':
      if (source[*i + 1] == 'a' && source[*i + 2] == 'n' &&
          source[*i + 3] == '(') {
        *i += 3;
        res.operation = TAN;
        res.priority = 4;
      }
      break;
    case 'a':
      if (source[*i + 1] == 'c' && source[*i + 2] == 'o' &&
          source[*i + 3] == 's' && source[*i + 4] == '(') {
        *i += 4;
        res.operation = ACOS;
        res.priority = 4;
      } else if (source[*i + 1] == 's' && source[*i + 2] == 'i' &&
                 source[*i + 3] == 'n' && source[*i + 4] == '(') {
        *i += 4;
        res.operation = ASIN;
        res.priority = 4;
      } else if (source[*i + 1] == 't' && source[*i + 2] == 'a' &&
                 source[*i + 3] == 'n' && source[*i + 4] == '(') {
        *i += 4;
        res.operation = ATAN;
        res.priority = 4;
      }
      break;
    case 'l':
      if (source[*i + 1] == 'n' && source[*i + 2] == '(') {
        *i += 2;
        res.operation = LN;
        res.priority = 4;
      } else if (source[*i + 1] == 'o' && source[*i + 2] == 'g' &&
                 source[*i + 3] == '(') {
        *i += 3;
        res.operation = LOG;
        res.priority = 4;
      }
      break;
    case '(':
      res.operation = '(';
      res.priority = 4;
      break;
    case ')':
      res.operation = ')';
      res.priority = 4;
      break;
    default:
      res.operation = '\0';
      res.priority = 99;
      break;
  }

  return res;
}

int check_correct(char *string) {
  int res = 0;
  int check_last = 0;
  int open_count = 0;
  int close_count = 0;

  for (int i = 0; string[i] != '\0'; i++) {
    if (check_last && is_operator(string[i])) res = 1;

    check_last = is_operator(string[i]);
  }

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '(') open_count++;
    if (string[i] == ')') close_count++;
  }

  if (open_count != close_count) res = 1;

  return res;
}

int is_operator(char c) {
  if (strchr("+-/*.^%", c))
    return 1;
  else
    return 0;
}