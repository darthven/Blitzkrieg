#include "../src/darthvector.h"
#include "test.h"

int main() {

    DarthVector<int> vector(20);

    DarthTest vector_test;

    int EXPECTED_VALUES[][25] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {111, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {111, 0, 1, 2, 3, 222, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {111, 0, 1, 2, 3, 222, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 333},
        {111, 0, 1, 2, 3, 222, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {0, 1, 2, 3, 222, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
    };

    const std::string SIZE_ERROR_MESSAGE =  "[Size] Wrong size of vector";
    const std::string VALUES_ERROR_MESSAGE =  "[Values] Wrong values of vector";
    const std::string ITEM_ERROR_MESSAGE =  "[Item] Wrong item's value of vector";
    const std::string INDEX_ERROR_MESSAGE =  "[Item] Wrong item's index of vector";
    
    for(int i = 0; i < 15; i++) {
        vector.push(i);
    }     
    vector_test.equal(15, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[0], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE);   
   
    vector.insert(0, 111);
    vector_test.equal(16, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[1], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE);  

    vector.insert(5, 222);
    vector_test.equal(17, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[2], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE); 
 
    vector.insert(vector.size() - 1, 333);
    vector_test.equal(18, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[3], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE); 
 
    int pop = vector.pop();
    vector_test.equal(333, pop, ITEM_ERROR_MESSAGE);
    vector_test.equal(17, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[4], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE);

    int shift = vector.shift();
    vector_test.equal(111, shift, ITEM_ERROR_MESSAGE);
    vector_test.equal(16, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[5], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE);
   
    vector.delete_(4);
    vector_test.equal(15, vector.size(), SIZE_ERROR_MESSAGE);
    vector_test.equalValues(EXPECTED_VALUES[6], vector.values(), 0, vector.size(), VALUES_ERROR_MESSAGE);

    vector_test.equal(12, vector.find(12), INDEX_ERROR_MESSAGE);
    vector_test.equal(-1, vector.find(333), INDEX_ERROR_MESSAGE);   

    return 0;
}
