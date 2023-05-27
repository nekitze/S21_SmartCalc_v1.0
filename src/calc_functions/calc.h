#ifndef SRC_CALC_H
#define SRC_CALC_H

// #include <gtk/gtk.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COS '0'
#define SIN '1'
#define TAN '2'
#define ACOS '3'
#define ASIN '4'
#define ATAN '5'
#define SQRT '6'
#define LN '7'
#define LOG '8'

typedef struct calc_object_struct {
  double value;
  char operation;
  int priority;  // if priority == 0 it's operand
} calc_object_t;

typedef struct stack_struct {
  calc_object_t object;
  struct stack_struct *next;
} stack_node_t;

/* ------------ STACK ------------ */

stack_node_t *create_node(calc_object_t object);
void push(stack_node_t **node, calc_object_t object);
void push_back(stack_node_t **node, calc_object_t object);
void pop(stack_node_t **node);
void abort_stack(stack_node_t **node);
void transfer(stack_node_t **source, stack_node_t **target);

/* ------------ PARSER ------------ */

int parse_input_string(char *source, stack_node_t **list);
calc_object_t parse_operation(char *source, int *i);
int parse_operand(char *source, int *i, double *result);
int check_correct(char *string);
int is_operator(char c);

/* ------------ CALCULATIONS ------------ */

int calculate(stack_node_t *object_list, double *result);
void calc_remaining(stack_node_t *operators_stack, stack_node_t *output_stack);
calc_object_t calc_operator(stack_node_t *operators_stack,
                            stack_node_t *output_stack);
calc_object_t calc_function(stack_node_t *operators_stack,
                            stack_node_t *output_stack);
void pop_used(stack_node_t **operators_stack, stack_node_t **output_stack);

int init_calc(char *source, double *result);

#endif  // SRC_CALC_H
