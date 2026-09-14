#include <iostream>
#include <vector>
using namespace std;
class PriceCalculator {
public:
    int calculatePrice(vector<int> prices) {
        int total = 0;
        for (int price : prices)
            total += price;
        return total;
    }
    int calculatePrice(int price, int quantity) {
        return price * quantity;
    }
};