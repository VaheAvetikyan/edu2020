/*
    10: Ծայրից ծայր
    Մուտքում տրվում է 10x10 չափերով մատրից՝ բաղկացած զրոներից և մեկերից, 
    պահանջվում է արտածել YES, եթե հնարավոր է վերևի ձախ անկյունից հասնել ներքևի աջ անկյունը՝ 
    ամեն քայլին շարժվելով 1 վանդակ վերև, ներքև, ձախ կամ աջ և չանցնելով մեկերի վրայով, և NO՝ հակառակ դեպքում։ 
    Հայտնի է որ վերևի ձախ և ներքևի աջ անկյունների վանդակները միշտ 0 են։ Խնդիրը լուծելիս կարելի է կիրառել ալիքի ալգորիթմը։ 
*/

#include <iostream>
#include <cassert>

class Coordinates
{
public:
    int x;
    int y;
    Coordinates() : x(0), y(0) {}
    Coordinates(int i, int j) : x(i), y(j) {}
    ~Coordinates() {}
};

class Queue
{
public:
    Queue(int n);
    Queue(Queue &q);
    ~Queue();
    bool empty();
    Coordinates front();
    void enqueue(Coordinates obj);
    void dequeue();

private:
    int queue_size;
    int front_index; // first element index
    int back_index;  // last element index
    int array_capacity;
    Coordinates *array;
};

// n should be greater than 0
Queue::Queue(int n) : queue_size(0),
                      front_index(0),
                      back_index(-1),
                      array_capacity(n),
                      array(new Coordinates[array_capacity]) {}

Queue::Queue(Queue &q) : queue_size(q.queue_size),
                         front_index(q.front_index),
                         back_index(q.back_index),
                         array_capacity(q.array_capacity),
                         array(new Coordinates[array_capacity])
{
    if (q.empty())
    {
        return;
    }
    int i = front_index;
    do
    {
        array[i] = q.array[i];
        i++;
        if (i == array_capacity)
        {
            i = 0;
        }
    } while (i != back_index);
}

Queue::~Queue()
{
    delete[] array;
}

bool Queue::empty()
{
    return queue_size == 0;
}

Coordinates Queue::front()
{
    assert(!empty());
    return array[front_index];
}

void Queue::enqueue(Coordinates obj)
{
    if (queue_size == array_capacity)
    {
        return;
    }
    ++back_index;
    if (back_index == array_capacity)
    {
        back_index = 0;
    }
    array[back_index] = obj;
    ++queue_size;
}

void Queue::dequeue()
{
    if (empty())
    {
        return;
    }
    --queue_size;
    ++front_index;
    if (front_index == array_capacity)
    {
        front_index = 0;
    }
}

int main()
{
    int rows = 10;
    int cols = 10;
    int **road = new int *[rows];
    bool **steps = new bool *[rows];

    // Input matrix
    for (int i = 0; i < rows; i++)
    {
        steps[i] = new bool[cols];
        road[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> road[i][j];
            steps[i][j] = false;
        }
    }

    Queue *roadQueue = new Queue(rows * cols);

    // Starting coordinates
    roadQueue->enqueue(Coordinates(0, 0));
    steps[0][0] = true;

    while (!roadQueue->empty())
    {
        if (roadQueue->front().x == rows - 1 && roadQueue->front().y == cols - 1)
        {
            // Delete matrix
            for (int i = 0; i < rows; i++)
            {
                delete[] road[i];
                delete[] steps[i];
            }
            delete[] road;
            delete[] steps;
            delete roadQueue;
            std::cout << "YES\n";
            return 0;
        }

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((i == 0 || j == 0) && (roadQueue->front().x + i >= 0 && roadQueue->front().x + i < rows) && (roadQueue->front().y + j >= 0 && roadQueue->front().y + j < cols))
                {
                    if (road[roadQueue->front().x + i][roadQueue->front().y + j] == 0 && !steps[roadQueue->front().x + i][roadQueue->front().y + j])
                    {
                        roadQueue->enqueue(Coordinates(roadQueue->front().x + i, roadQueue->front().y + j));
                        steps[roadQueue->front().x + i][roadQueue->front().y + j] = true;
                    }
                }
            }
        }
        roadQueue->dequeue();
    }
    std::cout << "NO\n";

    // Delete matrix
    for (int i = 0; i < rows; i++)
    {
        delete[] road[i];
        delete[] steps[i];
    }
    delete[] road;
    delete[] steps;
    delete roadQueue;
}