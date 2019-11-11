//
// Created by ankit on 09.11.19.
//

#ifndef ZMQ_PUBSUB_EXAMPLE_SRC_CONSUMER_SUBSCRIBER1_H_
#define ZMQ_PUBSUB_EXAMPLE_SRC_CONSUMER_SUBSCRIBER1_H_

#include <zmq.hpp>
class Subscriber1 {

 public:
  Subscriber1() = default;
  void operator()() {
    std::cout << "Starting the Subscriber 1" << "\n";;
    zmq::context_t context(1);
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5563");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "B", 1);

    int i = 0;
    while (1) {
      i++;
      zmq::message_t update;
      subscriber.recv(&update);
      std::string iss(static_cast<char *>(update.data()));
      std::cout << "Message received at B : " << i << " : " << iss << "\n";
    }
  }
};

#endif //ZMQ_PUBSUB_EXAMPLE_SRC_CONSUMER_SUBSCRIBER1_H_
