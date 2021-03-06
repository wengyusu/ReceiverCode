/*******************************************************************************
 * Common definitions for parsing sample data.
 ******************************************************************************/
#ifndef __SAMPLE_DATA_HPP__
#define __SAMPLE_DATA_HPP__

#include <iostream>
#include <vector>
#include <string>

//Get the time in milliseconds
uint64_t msecTime();

struct uint128_t {
  uint64_t upper;
  uint64_t lower;

  //Default constructor
  uint128_t() = default;
  //Constructor that just takes in an unsigned integer.
  uint128_t(unsigned int val);
  uint128_t(const uint128_t& val);
  template <typename T>
  uint128_t& operator=(const T& val) {
    upper = 0;
    lower = val;
    return *this;
  }
} __attribute__((packed));


//Define an equality operator for the 128 bit type
bool operator==(const uint128_t& a, const uint128_t& b);

//Define a print operator for the 128 bit type
std::ostream& operator<<(std::ostream& os, const uint128_t& val);
std::istream& operator>>(std::istream& is, uint128_t& val);

//Define a binary & operator.
uint128_t operator&(const uint128_t& a, const uint128_t& b);

//Define a less than operator
bool operator<(const uint128_t& a, const uint128_t& b);

//To string functions for the 128 bit integer type
std::string to_string(uint128_t val);
std::u16string to_u16string(uint128_t val);

typedef uint128_t TransmitterID;
typedef uint128_t ReceiverID;
typedef int64_t Timestamp;

//Define a type for the FSM_TR byte and its masks.
typedef unsigned char FSM_TR;
enum FSM_MASK {fixed       = 0x00,
               semi_fixed  = 0x01,
               mobile      = 0x02};
enum TR_MASK { transmitter = 0x00,
               receiver    = 0x10};

//Sample data with details about a packet from a transmitter to a receiver.
struct SampleData {
  unsigned char physical_layer;
  TransmitterID tx_id;
  ReceiverID rx_id;
  Timestamp rx_timestamp;
  float rss;
  //TODO The FSM_TR field will be removed in the future.
  FSM_TR type;
  std::vector<unsigned char> sense_data;
  bool valid;
};

//Device position
struct DevicePosition {
  FSM_TR type;
  unsigned char physical_layer;
  TransmitterID device_id;
  float x;
  float y;
  float z;
  std::u16string region_uri;
  bool valid;
};

#endif


