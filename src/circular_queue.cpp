#include <iostream>
using namespace std;

namespace cq {
    
    const int LIMIT = 5;

    int _queue[LIMIT] = {0, 0, 0, 0, 0};
    int _top = 0;
    int _bottom = 0;

    int size() {
        int s = (LIMIT - _top + _bottom) % LIMIT;  
        return s;
    }

    bool is_queue_empty() {
        return _bottom == _top;
    }

    void enqueue(int v) {
        cout << "enqueue(" << v << ")" << endl;
        if(size() == LIMIT - 1) {
            cout << "Queue full " << size() << endl;
            exit(0);
        }
        _queue[_bottom] = v;
        _bottom = (_bottom + 1) % LIMIT;
        cout << "size: " << size() << endl;
    }

    void dequeue() {
        if(is_queue_empty()) {
            cout << "Queue empty" << _bottom << "/" << _top << endl;
            exit(0);
        }
        cout << "dequeue\n";
        _queue[_top] = 0;
        _top = (_top + 1) % LIMIT;
        cout << "size: " << size() << endl;
    }

    int first() {
        if(is_queue_empty()) {
            cout << "Queue empty" << _bottom << "/" << _top << endl;
            exit(0);
        }
        return _queue[_top];
    }

    void show() {
        for(int i = 0; i < LIMIT; i++) {
            cout << "(" << i << "): " << _queue[i] << endl;
        }
        if(is_queue_empty()) {
            cout << "Empty" << endl;
        }    
        cout << "top    : " << _top << endl;
        cout << "bottom : " << _bottom << endl << endl;
    }

    int run() {
        enqueue(1);
        show();

        enqueue(2);
        show();

        enqueue(3);
        show();

        enqueue(4);
        show();

        enqueue(5);
        show();

        enqueue(-1);
        show();

        enqueue(-2);
        show();

        enqueue(-3);
        show();

        enqueue(-4);
        show();

        enqueue(-5);
        show();
        
        return 0;
    }

}

int main() { return cq::run(); }
