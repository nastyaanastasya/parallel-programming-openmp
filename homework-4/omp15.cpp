#include <algorithm>
#include <iostream>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

    omp_set_dynamic(0);
    omp_set_num_threads(8);

    int left_border, right_border;
    cout << "Enter min and max values: ";
    cin >> left_border >> right_border;

    vector<int> result;
    #pragma omp parallel for
    for(int i = left_border; i <= right_border; i++) {
        if(i >= 2) {
            bool flag = true;
            #pragma omp parallel for
            for(int j = 2; j <= (int) sqrt(i); j++) {
                if (i % j == 0) {
                    flag = false;
                }
            }
            if (flag) {
                #pragma omp critical
                result.push_back(i);
            }
        }
    }

    sort(result.begin(), result.end());

    printf("Prime numbers: ");
    for(int num : result) {
        printf("%d ", num);
    }
    printf("\n");
}




// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <omp.h>
// #include <chrono>
// #include <windows.h>
// #include <valarray>

// const int EPS = 100;

// using namespace std;

// int main() {
//     srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
//     setlocale(LC_ALL, "ru_RU.UTF-8");
//     SetConsoleOutputCP(CP_UTF8);

//     cout << "Task15" << endl << endl;

//     int a, b;
//     cout << "Введите границы" << endl;
//     cin >> a >> b;

//     // Решето Эратосфена
//     bool used[b + 1];
//     vector<int> answer;
//     for (int i = 2; i <= b; ++i) {
//         if (!used[i]) {
//             if (i >= a) {
//                 answer.push_back(i);
//             }

// #pragma omp parallel for
//             for (int j = 2 * i; j <= b; j += i) {
//                 used[j] = true;
//             }
//         }
//     }

//     for (int x: answer) {
//         printf("%d ", x);
//     }
//     printf("\n");

//     // Тупой алгоритм
//     answer.clear();
//     #pragma omp parallel for
//     for (int i = a; i <= b; ++i) {
//         if (i >= 2) {
//             bool flag = true;
//             #pragma omp parallel for
//             for (int j = 2; j <= (int) sqrt(i); ++j) {
//                 if (i % j == 0) {
//                     flag = false;
//                 }
//             }
//             #pragma omp critical
//             if (flag) {
//                 answer.push_back(i);
//             }
//         }
//     }

//     sort(answer.begin(), answer.end());
//     for (int x: answer) {
//         printf("%d ", x);
//     }
//     printf("\n");
// }





// #include <iostream>
// #include <omp.h>
// #include <stdio.h>
// #include <math.h>
// #include <vector>
// #include <stdlib.h>
// #include <algorithm>

// #define NUM_THREADS 4

// static int compareFunc (const void * a, const void * b)
// {
//   return ( *(int*)a - *(int*)b );
// }

// using namespace std;


// int main() {
    
//     omp_set_dynamic(0); // not change number of threads when running
//     omp_set_num_threads(NUM_THREADS);
    
//     int start = 0;
    
//     int end = 0;
    
//     printf("Start: ");
//     cin >> start;
    
//     printf("End: ");
//     cin >> end;
        
//     vector<int> result;
    
//     bool isSimple = true;
//     int rightBound = 0;
//     #pragma omp parallel for private(isSimple, rightBound)
//     for (int i = start; i <= end; i++) {
//         isSimple = true;
//         rightBound = sqrt(i);
//         for (int j = 2; j <= rightBound; j++) {
//             if (i > 2) {
//                 if (i % j == 0) {
//                     isSimple = false;
//                     break;
//                 }
//             }
//         }
//         if (isSimple) {
//             #pragma omp critical
//             {
//                 result.insert(result.end(), i);
//             }
//         }
//     }

//     //SORT IT
//     sort (result.begin(), result.end());

//     for (int i = 0; i < result.size(); i++) {
//         printf("%d ", result[i]);
//     }

//     return 0;
// }
