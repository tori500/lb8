#include <stdio.h>
#include <locale.h>
#include <tgmath.h>

void task1(void);
void task2(void);
void task3(void);
void task4(void);

int main() {
    setlocale(LC_ALL, "RUS");

    task1();
    task2();
    task3();
    task4();

    return 0;
}

// Задание 0 Печать символов
void task1(void) {
    int n, choice;
    char symbol1, symbol2;

    printf("Введите количество символов: ");

    if (scanf("%d", &n) != 1) {
        printf("Ошибка ввода!\n");
        return;
    }

    if (n <= 0) {
        printf("Количество должно быть больше нуля!\n");
        return;
    }

    printf("Выберите вариант:\n");
    printf("1 - Обычная печать символов\n");
    printf("2 - Плюс в начале и/или в конце\n");
    printf("3 - Две половины разными символами\n");
    printf("4 - Восклицательный знак после каждого символа\n");

    printf("Ваш выбор: ");

    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода!\n");
        return;
    }

    switch (choice) {

        // Обычная печать символов
        case 1:
            printf("Введите символ: ");
            scanf(" %c", &symbol1);

            for (int i = 1; i <= n; i++) {
                putchar(symbol1);
            }
            break;

        // Плюс в начале и/или в конце
        case 2: {
            int start, end;

            printf("Поставить + в начале? (1 - да, 0 - нет): ");
            scanf("%d", &start);

            printf("Поставить + в конце? (1 - да, 0 - нет): ");
            scanf("%d", &end);

            printf("Введите символ: ");
            scanf(" %c", &symbol1);

            if (start == 1) {
                putchar('+');
            }

            for (int i = 1; i <= n; i++) {
                putchar(symbol1);
            }

            if (end == 1) {
                putchar('+');
            }
            break;
        }

        // Две половины разными символами
        case 3:
            printf("Введите первый символ: ");
            scanf(" %c", &symbol1);

            printf("Введите второй символ: ");
            scanf(" %c", &symbol2);

            for (int i = 1; i <= n; i++) {
                if (i <= n / 2) {
                    putchar(symbol1);
                } else {
                    putchar(symbol2);
                }
            }
            break;

        // Восклицательный знак после каждого символа
        case 4:
            printf("Введите символ: ");
            scanf(" %c", &symbol1);

            for (int i = 1; i <= n; i++) {
                putchar(symbol1);
                putchar('!');
            }
            break;

        default:
            printf("Неверный вариант!\n");
    }

    printf("\n");
}

//задание 1
void task2(void) {
    int m, n;
    int k = 1;
    long long s = 0;

    printf("=== Задание 1 ===\n");
    printf("Введите m и n: ");

    if (scanf("%d%d", &m, &n) != 2) {
        printf("Ошибка ввода!\n");
        return;
    }

    // Суммирование от m до n в порядке убывания
    if (m >= n) {
        for (int i = m; i >= n; i--) {
            s += i;
            printf("Выполнено %d раз\n", k++);
        }
    } else {
        // Если m меньше n, суммирование в порядке возрастания
        for (int i = m; i <= n; i++) {
            s += i;
            printf("Выполнено %d раз\n", k++);
        }
    }

    printf("Результат: %lld\n", s);
}

// Задание 1А. Степени двойки
void task1A(void) {
    int n;

    printf("=== Задание 1А ===\n");
    printf("Введите максимальную степень n: ");

    if (scanf("%d", &n) != 1 || n < 0 || n > 1023) {
        printf("Ошибка! Введите число от 0 до 1023.\n");
        return;
    }

    printf("Степени двойки:\n");

    for (int i = 0; i <= n; i++) {
        double value = pow(2.0, i);

        printf("2^%-3d = %20.0f\n", i, value);
    }

    // Перевод результата в K = 1024
    double result = pow(2.0, n) / 1024.0;

    printf("Результат: %.1fK\n", result);
}

//задание 2
void task3(void) {
    setlocale(LC_ALL, "");

    double x, y, h;
    double a = 1.0;
    double b = 3.0;

    printf("Табулирование функции y = |e^x - 2| - x^2\n");
    printf("Интервал: [1; 3]\n");

    printf("Введите шаг табуляции: ");
    if (scanf("%lf", &h) != 1 || h <= 0) {
        printf("Ошибка! Шаг должен быть положительным числом.\n");
    }

    printf("\n");
    printf("-----------------------------\n");
    printf("|       x       |    f(x)   |\n");
    printf("-----------------------------\n");

    for (int i = 0; a + i * h <= b + 1e-9; i++) {
        x = a + i * h;

        y = fabs(exp(x) - 2) - x * x;

        printf("| %13.4f | %9.4f |\n", x, y);
    }

    printf("-----------------------------\n");
}

//домашнее задание 26 вариант (задание 3)
void task4(void) {
    setlocale(LC_ALL, "");

    int N, K;
    double S = 0;

    printf("Вычисление суммы S = 1^K + 2^K + ... + N^K\n");

    printf("Введите N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Ошибка! N должно быть положительным целым числом.\n");
    }

    printf("Введите K: ");
    if (scanf("%d", &K) != 1) {
        printf("Ошибка ввода K!\n");
    }

    for (int i = 1; i <= N; i++) {
        S += pow(i, K);
    }

    printf("Результат: S = %.6f\n", S);
}