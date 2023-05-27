#include "calc.h"

stack_node_t *create_node(calc_object_t object) {
  stack_node_t *node = (stack_node_t *)malloc(sizeof(stack_node_t));
  node->object = object;
  node->next = NULL;
  return node;
}

void push(stack_node_t **node, calc_object_t object) {
  stack_node_t *new_node = create_node(object);
  new_node->next = *node;
  *node = new_node;
}

void push_back(stack_node_t **node, calc_object_t object) {
  stack_node_t *new_node = create_node(object);
  stack_node_t *temp = *node;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
}

void pop(stack_node_t **node) {
  stack_node_t *temp = *node;
  *node = temp->next;
  free(temp);
}

void abort_stack(stack_node_t **node) {
  stack_node_t *temp = *node;

  while (temp != NULL) {
    temp = temp->next;
    pop(node);
    *node = temp;
  }
}
