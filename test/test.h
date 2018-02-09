/** 
 *  @file    test.h
 *  @author  Konstantin Kharlambov (darthven)
 *  @date    2/9/2018  
 *  @version 0.1 
 *  
 *  @brief DarthTest
 *
 *  @section DESCRIPTION
 *  
 *  This is custom implementation of unit-testing.
 *  
 */

#include <cstring>
#include <iostream>

class DarthTest {
    private:
        int tests_passed;
        int tests_failed;
    public:
        DarthTest();
        ~DarthTest();
        template<typename T>
        bool equal(const T expected, T actual, const std::string message);

        template<typename T>
        bool equalAddresses(T *expected, T *actual, const std::string message);

        template<typename T>
        bool equalValues(T *expected, T *actual, const int from_index, const int to_index, const std::string message);

};

DarthTest::DarthTest() {
    this->tests_passed = 0;
    this->tests_failed = 0;
}

DarthTest::~DarthTest() {
    std::cout << "Tests passed: " <<  this->tests_passed << std::endl
     << "Tests failed: " <<  this->tests_failed << std::endl;
}

/** 
  *   @brief Checks if expected value equals to actual.   
  *  
  *   @param  expected is value that must be returned from function 
  *   @param  actual is value that is got from function
  *   @param  message is error message if check is failed
  *   @return bool result of check
  */  
template<typename T>
bool DarthTest::equal(T expected, T actual, const std::string message) {
    if(expected == actual) {
        this->tests_passed++;
        return true;
    }
    this->tests_failed++;
    std::cout << message << std::endl;
    return false;
}
 
/** 
  *   @brief Checks if expected and actual values point to same address.   
  *  
  *   @param  expected is value that must be returned from function 
  *   @param  actual is value that is got from function
  *   @param  message is error message if check is failed
  *   @return bool result of check
  */  
template<typename T>
bool DarthTest::equalAddresses(T *expected, T *actual, const std::string message) {
    if(expected == actual) {
        this->tests_passed++;
        return true;
    }
    this->tests_failed++;
    std::cout << message << std::endl;
    return false;
}

/** 
  *   @brief Checks if expected values of array-based data structures equals to actual.   
  *  
  *   @param  expected is value that must be returned from function 
  *   @param  actual is value that is got from function
  *   @param  from_index is start position from which arrays' values will be compared
  *   @param  to_index is end position to which arrays' values will be compared
  *   @param  message is error message if check is failed
  *   @return bool result of check
  */    
template<typename T>
bool DarthTest::equalValues(T *expected, T *actual, const int from_index, const int to_index, const std::string message) {
    for(int i = from_index; i < to_index; i++) {
        if(*(expected + i) != *(actual + i)) {
            this->tests_failed++;
            std::cout << message << std::endl;            
            return false;            
        }
    }
    this->tests_passed++;
    return true;
}