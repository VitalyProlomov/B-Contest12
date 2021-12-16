#include <iostream>
#include <algorithm>
#include <vector>

double findLeastPossibleSum(int numbers_amount) {
    auto *all_numbers = new std::vector<int>();

    if (numbers_amount == 1) {
        std::cin >> numbers_amount;
        return 0;
    }
    int input = 0;
    for (int i = 0; i < numbers_amount; ++i) {
        std::cin >> input;
        all_numbers->push_back(input);
    }

    std::sort(all_numbers->begin(), all_numbers->end());

    std::vector<int> *temp_vec;
    double final_sum = 0;
    while (all_numbers->size() != 1) {
        temp_vec = new std::vector<int>();
        int last_index = 0;
        for (int elem_index = 0; elem_index < all_numbers->size(); elem_index += 2) {
            // Needed to track the last element not added to the temporary vector.
            last_index = elem_index;
            if (all_numbers->size() < elem_index + 2) {
                break;
            }

            all_numbers->at(elem_index) += all_numbers->at(elem_index + 1);
            final_sum += all_numbers->at(elem_index) * static_cast<double>(0.05);
            temp_vec->push_back(all_numbers->at(elem_index));
        }

        if (last_index != 0) {
            for (int not_added = last_index; not_added < all_numbers->size(); ++not_added) {
                temp_vec->push_back(all_numbers->at(not_added));
            }
        }

        std::sort(temp_vec->begin(), temp_vec->end());

        all_numbers->clear();
        for (auto &el : *temp_vec) {
            all_numbers->push_back(el);
        }
        delete temp_vec;
    }
    delete all_numbers;
    return final_sum;
}
int main() {
    int numbers_amount;
    std::cin >> numbers_amount;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << findLeastPossibleSum(numbers_amount);

    return 0;
}
