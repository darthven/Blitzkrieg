#include "darthvector.h"

int main() {

    DarthVector<int> vector(20);

    for(int i = 0; i < 15; i++) {
        vector.push(i);
        std::cout << vector.at(i) << std::endl;
    }
    std::cout << "Size: " << vector.size() << std::endl;
    vector.insert(0, 111);
    vector.insert(5, 222);
    vector.insert(vector.size(), 333);
    std::cout << "Size: " << vector.size() << std::endl;
    for(int i = 0; i < vector.size(); i++) {
        std::cout << vector.at(i) << std::endl;
    }
    return 0;
}
