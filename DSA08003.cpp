#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<int> dq;
    int Q;
    std::cin >> Q;
    while (Q--) {
        std::string query;
        std::cin >> query;
        if (query == "PUSHFRONT") {
            int x;
            std::cin >> x;
            dq.push_front(x);
        }
        else if (query == "PRINTFRONT") {
            if (!dq.empty()) {
                std::cout << dq.front() << '\n';
            }
            else {
                std::cout << "NONE" << '\n';
            }
        }
        else if (query == "POPFRONT") {
            if (!dq.empty()) {
                dq.pop_front();
            }
        }
        else if (query == "PUSHBACK") {
            int x;
            std::cin >> x;
            dq.push_back(x);
        }
        else if (query == "PRINTBACK") {
            if (!dq.empty()) {
                std::cout << dq.back() << '\n';
            }
            else {
                std::cout << "NONE" << '\n';
            }
        }
        else if (query == "POPBACK") {
            if (!dq.empty()) {
                dq.pop_back();
            }
        }
    }
    return 0;
}
