#define MAX 5
//Deklarasi Circular Queue
class CirQueue
{
 private:
 int front ;
 int rear ;
 int count ;
 int ele[MAX] ;
 public:
 CirQueue();
 int isFull();
 int isEmpty();
 void insertQueue(int item);
 int deleteQueue(int *item);
};
