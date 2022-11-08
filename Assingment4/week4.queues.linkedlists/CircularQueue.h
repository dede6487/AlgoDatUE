#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED
#define MAX_SIZE 100

template <class T = int>
class CircularQueue {
private:
	T data[MAX_SIZE];
	int frontIndex;
	int endIndex;
	
public:
	CircularQueue();
	~CircularQueue();
	T front();
	void enqueue(T element);
	void dequeue();
	bool isFull();
	bool isEmpty();
	void printQueue();
};

#endif //CIRCLEQUEUE_H_INCLUDED
