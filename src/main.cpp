
#include <iostream>
#include <zmq.hpp>
#include <thread>
#include "consumer/consumer1.h"
#include "consumer/consumer2.h"
#include "producer/producer.h"

using namespace std;

void foo(int z) {
  for (int i = 0; i < z; i++) {
    cout << "Thread using function"
            " pointer as callable "<<i<<"\n";
  }
}

int main() {
  zmq::context_t context (1);
  zmq::socket_t publisher (context, ZMQ_PUB);
  publisher.bind("tcp://*:5556");
  publisher.bind("ipc://weather.ipc");

  cout << "Hello, World!" << std::endl;
  unsigned int c = std::thread::hardware_concurrency();
  std::cout << " number of cores: " << c << endl;;

  consumer2 consumer_2 = consumer2();
  std::thread t1(foo,10);
  std::thread t2(consumer_2);

  t2.join();
  t1.join();

//  thread t1(consumer1(), 2);
//  t1.join();
//
//  std::thread th1(foo,4);
//
//  th1.join();

  return 0;
}

