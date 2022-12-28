// Copyright Kaitlyn Ip 2022
//
// Created by Kaitlyn Ip
// Created in December 2022
// A program calculates the average mark

#include <iomanip>
#include <iostream>
#include <list>

float findAverageMark(std::list<int> list) {
    // Calculates the average of a list

    int sum = 0;
    float average = 0;

    for (int num : list) {
        sum += num;
    }
    average = static_cast<float>(sum) / list.size();

    return average;
}

int main() {
    // Gets marks, puts the marks in a list and calls the average function

    int markInt;
    float markAverage;
    std::string markText;
    std::list<int> markList;

    std::cout << "Please enter 1 mark at a time. Enter -1 to end.";
    std::cout << std::endl;
    while (true) {
        try {
            std::cout << "What is your mark? (as %): ";
            std::cin >> markText;
            markInt = stoi(markText);
            if (markInt >= 0 && markInt <= 100) {
                markList.push_back(markInt);
            } else if (markInt > 100) {
                std::cout << std::endl;
                std::cout << "That is not a valid input.";
                std::cout << std::endl;
            } else {
                break;
            }
        } catch (std::invalid_argument) {
            std::cout << "That is not a valid input. Try again.";
            std::cout << std::endl;
        }
    }
    markAverage = findAverageMark(markList);
    std::cout << std::endl;
    std::cout << "Your average is: ";
    std::cout << markAverage << std::setprecision(2) << "%.";

    std::cout << std::endl;
    std::cout << "\nDone." << std::endl;
}
