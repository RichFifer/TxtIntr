#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

void help() {
    cout << "Как использовать: ./calculator [-s или -d] [значение1] [значение2] [значение3] [значение4]" << endl;
    cout << "Первый флаг: -s - суммирование, -d - вычитание" << endl;
    cout << "Минимум 2 операнда, максимум 4" << endl;
    cout << "Пример: ./calculator -s 1 2 3" << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 6) {
        help();
        return 1;
    }

    int opt;
    string operation;

    // Обработка флагов с помощью getopt
    while ((opt = getopt(argc, argv, "sd")) != -1) {
        switch (opt) {
            case 's':
                operation = "-s";
                break;
            case 'd':
                operation = "-d";
                break;
            default:
                help();
                return 1;
        }
    }

    vector<double> values;
    for (int i = optind; i < argc; ++i) {
        values.push_back(atof(argv[i]));
    }

    if (values.size() < 3 || values.size() > 6) {
        help();
        return 1;
    }

    if (operation == "-s") {
        double sum = 0;
        for (double value : values) {
            sum += value;
        }
        cout << "Сумма: " << sum << endl;
    } else if (operation == "-d") {
        double result = values[0];
        for (size_t i = 1; i < values.size(); ++i) {
            result -= values[i];
        }
        cout << "Результат вычитания: " << result << endl;
    }

    return 0;
}
