#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_SIZE 100

template <class T = int>
class Queue {
private:
	T data[MAX_SIZE];
	int frontIndex;
	int endIndex;
	
public:
	Queue();
	~Queue();
	T front();
	void enqueue(T element);
	void dequeue();
	bool isFull();
	bool isEmpty();
	void printQueue();
};

#endif //QUEUE_H_INCLUDED
