#include<iostream>

using namespace std;
class queue {
public:
	int front;
	int rear;
	int* arr;
	int size = 3;

    int maxnodes = 5;
    int Matrix[5][5];
    bool visited[10];
    int numnodes = 5;

	queue(int size) {
		front, rear = -1;
		arr = new int[size];
	}
	void enqeue(int a) {
		if (rear == size - 1) {
			cout << " FULL ";
		}
		else {
			rear = +1;
			arr[rear] = a;
			cout << " " << arr[rear];
		}
	}
	int deqeue() {
		int x = -1;
		if (rear == front) {
			cout << " Empty ";
		}
		else {
			front += 1;
			x = arr[front];
			cout << " " << arr[front];
		}
		return x;
	}
	int peak() {
		if (front == rear) {
			return -1;
		}
		else {
			return arr[rear];
		}
	}
	bool empty() {
		if (front == rear) {
			return true;
		}
		else {
			return false;
		}
	}
    

    void  Graph() {
        for (int i = 0; i < maxnodes; i++) {
            for (int j = 0; j < maxnodes; j++) {
                Matrix[i][j] = 0;
            }
        }
    }
    void BFS(int startNode) {
        int size = 5;
        queue q(size);
       q.enqeue(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int currentNode = q.front;
           q.deqeue();

            cout << currentNode << " ";

            for (int i = 0; i < numnodes; i++) {
                if (Matrix[currentNode][i] == 1 && !visited[i]) {
                    q.enqeue(i);
                    visited[i] = true;
                }

            }
        }
    }

    void addEdge(int from, int to) {
        Matrix[from][to] = 1;
        Matrix[to][from] = 1;
    }
    void displayGraph() {
        for (int i = 0; i < numnodes; i++) {
            for (int j = 0; j < numnodes; j++) {
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};




    int main() {
        queue q(5);
        
        q.addEdge(0, 1);
        q.addEdge(1, 0);
        q.addEdge(1, 3);
        q.addEdge(3, 1);
        q.addEdge(2, 4);
        q.addEdge(3, 4);
        q.addEdge(4, 2);
        q.addEdge(4, 3);
        int startnode;
        cout << " ENTER THE THE ELEMENT OF GRAPH TO START: ";
        cin >> startnode;
        q.BFS(startnode);
        cout << endl;
       
}