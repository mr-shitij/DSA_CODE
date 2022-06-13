typedef struct queue
{
	int *arr, front, rear;
}queue;

void init_q(queue *q, int n);

void enqueue(queue *q, int n);

int dequeue(queue *q);

int is_empty(queue q);

void delete_queue(queue *q);
