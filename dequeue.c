#include "list.h"
#include "helpers.h"
#include "dequeue.h"

dequeue_t init_deq(void) {
  dequeue_t q = {
      .front = NULL,
      .back = NULL,
      .length = 0
  };
  return q;
}

dequeue_t *alloc_deq(void) {
  dequeue_t *q = (dequeue_t *)calloc(1, sizeof(*q));
  *q = init_deq();
  return q;
}

// acceseaza primul element
int front(dequeue_t *deq, double *value) {
  IF_IS_NULL(value)RETURN(ERROR_DEQUEUE_INTERNAL);
  IF_IS_NULL(deq)RETURN(ERROR_DEQUEUE_EMPTY);
  IF_IS_NULL(deq->front)RETURN(ERROR_DEQUEUE_EMPTY);
  IF_IS_NULL(deq->front->data)RETURN(ERROR_DEQUEUE_INTERNAL);

  *value = AS(double, deq->front->data);
  return ERROR_SUCCESS;
}

// acceseaza ultimul element
int back(dequeue_t *deq, double *value) {
  IF_IS_NULL(value)RETURN(ERROR_DEQUEUE_INTERNAL);
  IF_IS_NULL(deq)RETURN(ERROR_DEQUEUE_EMPTY);
  IF_IS_NULL(deq->back)RETURN(ERROR_DEQUEUE_EMPTY);
  IF_IS_NULL(deq->back->data)RETURN(ERROR_DEQUEUE_INTERNAL);

  *value = AS(double, deq->back->data);
  return ERROR_SUCCESS;
}

// insereaza un element in fata
int push_front(dequeue_t *deq, double value) {
  IF_IS_NULL(deq)RETURN(ERROR_DEQUEUE_EMPTY);
  node_t *node = new_node(&value, sizeof(value));
  IF_IS_NULL(node)RETURN(ERROR_DEQUEUE_INTERNAL);
  push_list_front(&deq->front, node);
  if (!deq->back)
    deq->back = deq->front;
  deq->length++;
  return ERROR_SUCCESS;
}

// insereaza un element in spate
int push_back(dequeue_t *deq, double value) {
  IF_IS_NULL(deq)RETURN(ERROR_DEQUEUE_EMPTY);
  node_t *node = new_node(&value, sizeof(value));
  IF_IS_NULL(node)RETURN(ERROR_DEQUEUE_INTERNAL);

  if (deq->back) {
    node->prev = deq->back;
    deq->back->next = node;
  }
  deq->back = node;

  if (!deq->front)
    deq->front = deq->back;
  deq->length++;
  return ERROR_SUCCESS;
}

// scoate primul element
void pop_front(dequeue_t *deq) {
  RETURN_VOID_IF_NULL(deq);
  RETURN_VOID_IF_NULL(deq->front);
  node_t *to_free = deq->front;

  deq->front = deq->front->next;
  if (deq->front)
    deq->front->prev = NULL;
  else
    deq->back = NULL;
  free(to_free->data);
  free(to_free);
  deq->length--;
}

// scoate ultimul element
void pop_back(dequeue_t *deq) {
  RETURN_VOID_IF_NULL(deq);
  RETURN_VOID_IF_NULL(deq->back);
  node_t *to_free = deq->back;

  deq->back = deq->back->prev;
  if (deq->back)
    deq->back->next = NULL;
  else
    deq->front = NULL;

  free(to_free->data);
  free(to_free);
  deq->length--;
}

// intoarce numarul de elemente stocate in deq
size_t size(dequeue_t *deq) {
  IF_IS_NULL(deq)RETURN(0);
  IF_IS_NULL(deq->front)RETURN(0);
  return deq->length;
}
