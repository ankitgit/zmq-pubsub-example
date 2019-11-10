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

    try {

      std::cout << "Starting the Publisher" << "\n";;
      zmq::context_t context(1);
      zmq::socket_t publisher(context, ZMQ_PUB);
      publisher.bind("tcp://*:5563");

      int i = 0;

      while (i < 20) {
        i++;
        //  Send message to all subscribers
        zmq::message_t message(20);
        snprintf((char *) message.data(), 20,
                 "A Random message no %d for topic A", i);
        publisher.send("A", ZMQ_SNDMORE);
        publisher.send(message);

        snprintf((char *) message.data(), 20,
                 "Random message no %d for topic B", i);
        publisher.send("B", ZMQ_SNDMORE);
        publisher.send(message);

        std::cout << "sent some data: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
      }
    } catch (zmq::error_t &e) {
      std::cout << e.what();
    }

  }

};

#endif //ZMQ_PUBSUB_EXAMPLE_SRC_PRODUCER_PUBLISHER_H_
