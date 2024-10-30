#include "main.h"

int main() {

    setlocale(LC_ALL, "Russian");
    wcout << (L"|| Практика №2 ||\n");
    wcout << ("=========================================\n");
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
    ex7();
    ex8();

    return 0;
}

void ex1() {
    wcout << L"Задание 1: Поиск ближайшей пары точек\n";

    vector<Point> points = {
        {2.1, 3.4}, {3.5, 5.1}, {1.3, 4.8},
        {6.3, 2.9}, {7.2, 6.1}, {4.8, 3.3}
    };
    wcout << L"Точки: " << endl;
    for (int i = 0; i < points.size(); i++) {
        cout << points[i].x << " " << points[i].y << "\n";
    }
    ClosestPairResult result = closestPair(points);
    wcout << L"Минимальное расстояние: " << result.distance << endl;
    wcout << L"Между точками: (" << result.point1.x << L", " << result.point1.y << L") и (" << result.point2.x << L", " << result.point2.y << L")" << endl;
}

void ex2() {
    wcout << L"\nЗадание 2: Умножение больших чисел (Алгоритм Карацубы)\n";

    string num1, num2;
    wcout << L"Введите первое число:";
    cin >> num1;
    wcout << L"Введите второе число:";
    cin >> num2;
    recursionCounter = 0;
    string result = karatsubaMultiply(num1, num2);
    wcout << L"Результат умножения: ";
    cout << result << endl;
    wcout << L"Количество рекурсивных вызовов: ";
    cout << recursionCounter << endl;
}

void ex3() {
    wcout << L"\nЗадание 3: Алгоритм нахождения медианы\n";

    vector<int> nums = {7, 3, 5, 1, 9, 4};
    wcout << L"Массив: ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    wcout << L"\nМедиана массива: " << findMedian(nums) << endl;
}

void ex4() {
    wcout << L"\nЗадание 4: Быстрый алгоритм возведения в степень\n";

    double a;
    int n;
    wcout << L"Введите число (a):";
    cin >> a;
    wcout << L"Введите степень (n):";
    cin >> n;
    wcout << L"Результат " << a << "^" << n << " = " << power(a, n) << endl;
}

void ex5() {
    wcout << L"\nЗадача 5: Алгоритм нахождения наибольшей общей подстроки (LCS)\n";

    string s1, s2;
    wcout << L"Введите первую строку:";
    cin >> s1;
    wcout << L"Введите вторую строку:";
    cin >> s2;
    string lcs = findLongestCommonSubstring(s1, s2);
    wcout << L"Наибольшая общая подстрока: ";
    cout << lcs << endl;
}

void ex6() {
    wcout << L"\nЗадача 6: Алгоритм вычисления выпуклой оболочки (Convex Hull)\n";

    int n;
    wcout << L"Введите количество точек:";
    cin >> n;
    vector<FeltPoint> points(n);
    wcout << L"Введите координаты точек (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<FeltPoint> hull = convexHull(points);
    wcout << L"Вершины выпуклой оболочки:\n";
    for (const FeltPoint& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

void ex7() {
    wcout << L"\nЗадача 7: Разделение массива на две группы с минимальной разницей сумм\n";

    int n;
    wcout << L"Введите количество элементов:";
    cin >> n;
    vector<int> nums(n);
    wcout << L"Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    auto [group1, group2] = partitionWithMinDifference(nums);
    int sum1 = accumulate(group1.begin(), group1.end(), 0);
    int sum2 = accumulate(group2.begin(), group2.end(), 0);
    int difference = abs(sum1 - sum2);
    wcout << L"Первая группа элементов: ";
    for (int num : group1) {
        cout << num << " ";
    }
    wcout << L"\nСумма первой группы: " << sum1 << endl;
    wcout << L"Вторая группа элементов: ";
    for (int num : group2) {
        cout << num << " ";
    }
    wcout << L"\nСумма второй группы: " << sum2 << endl;
    wcout << L"Минимальная разница между суммами: " << difference << endl;
}

void ex8() {
    wcout << L"\nЗадача 8: Алгоритм разделения массива на k групп с минимальной разницей сумм\n";

    int n, k;
    wcout << L"Введите количество элементов:";
    cin >> n;

    vector<int> nums(n);
    wcout << L"Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    wcout << L"Введите количество групп (k):";
    cin >> k;
    vector<Group> groups = partitionArray(nums, k);
    printResult(groups);
}
