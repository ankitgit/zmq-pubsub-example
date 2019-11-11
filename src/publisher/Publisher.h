//
// Created by ankit on 09.11.19.
//

#ifndef ZMQ_PUBSUB_EXAMPLE_SRC_PRODUCER_PUBLISHER_H_
#define ZMQ_PUBSUB_EXAMPLE_SRC_PRODUCER_PUBLISHER_H_

#include <zmq.hpp>

class Publisher {

 public:
  Publisher() = default;
  void operator()() {

    std::cout << "Starting the Publisher" << "\n";;
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5563");

    int i = 0;

    while (i < 20) {
      i++;
      //  Send message to all subscribers
      zmq::message_t messageA(70);
      snprintf((char *) messageA.data(), 70,
               "A Random message no %d for topic A\n", i);
      publisher.send("A", ZMQ_SNDMORE);
      publisher.send(messageA);

      zmq::message_t messageB(70);
      snprintf((char *) messageB.data(), 70,
               "B Random message no %d for topic B\n", i);
      publisher.send("B", ZMQ_SNDMORE);
      publisher.send(messageB);

      std::cout << "sent some data: " << i << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(2));
    }
  }

};

#endif //ZMQ_PUBSUB_EXAMPLE_SRC_PRODUCER_PUBLISHER_H_
