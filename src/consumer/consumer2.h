//
// Created by ankit on 09.11.19.
//

#ifndef ZMQ_PUBSUB_EXAMPLE_SRC_CONSUMER_CONSUMER2_H_
#define ZMQ_PUBSUB_EXAMPLE_SRC_CONSUMER_CONSUMER2_H_

class consumer2 {

 public:
  consumer2()= default;
  void operator()(){
    std::cout << "consumer 2";
  }
};

#endif //ZMQ_PUBSUB_EXAMPLE_SRC_CONSUMER_CONSUMER2_H_
