
#include <iostream>
#include <thread>
#include "subscriber/Subscriber1.h"
#include "subscriber/Subscriber2.h"
#include "publisher/Publisher.h"
#include <zmq.hpp>

using namespace std;

int main() {

  Publisher publisher;
  Subscriber2 subscriber_2;
  Subscriber1 subscriber_1;
  std::thread sub1Thread(subscriber_1);
  std::thread sub2Thread(subscriber_2);
  std::thread publisherThread(publisher);

  publisherThread.join();
  sub2Thread.join();
  sub1Thread.join();
  return 0;
}

