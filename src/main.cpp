
#include <iostream>
#include <thread>
#include "subscriber/Subscriber1.h"
#include "subscriber/Subscriber2.h"
#include "publisher/Publisher.h"
#include <zmq.hpp>

using namespace std;

int main() {


  cout << "Hello, World!" << std::endl;

  Publisher publisher;
  Subscriber2 subscriber_2;
  Subscriber1 subscriber_1;
  std::thread publisherThread(publisher);
  std::thread sub1Thread(subscriber_1);
  std::thread sub2Thread(subscriber_2);

//  std::this_thread::sleep_for(std::chrono::seconds(4));
  publisherThread.join();
  sub2Thread.join();
  sub1Thread.join();

//  thread t1(Consumer1(), 2);
//  t1.join();
//
//  std::thread th1(foo,4);
//
//  th1.join();

  return 0;
}

