#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SEC_PER 0.1

double v_st;
double v_ed;
double v_max;
double a;
double distance;

double x1, x2, x3;

void putData() {
    printf("출발 속도를 입력하시오(m/s): ");
    scanf("%lf", &v_st);

    printf("도착 속도를 입력하시오(m/s): ");
    scanf("%lf", &v_ed);

    printf("최고 속도를 입력하시오(m/s): ");
    scanf("%lf", &v_max);

    printf("최고 가속도 & 감속도를 입력하시오(m/s): ");
    scanf("%lf", &a);

    printf("총 거리를 입력하시오(m/s): ");
    scanf("%lf", &distance);
}

void calculate_tri() {
    double t1 = (v_max - v_st) / a; // 속도 증가할 때 시간
    double t2 = (v_max - v_ed) / a; // 속도 감소할 때 시간

    double sec = 0; // 현재 시간
    double dist = 0; // 현재 거리

    double v_before = v_st;
    double v_after = v_st;

    printf("%.2lfsec : %.2lfm/s : %.2lfm\n", sec, v_after, dist);

    while (ceil(sec*10)/10 < t1 + t2) {
        sec += SEC_PER; // 시간 증가 +0.1초 단위

        // 속도 증가
        if (sec < t1) {
            v_after += (a * SEC_PER);
            x1 += SEC_PER;
        }
        // 속도 하락
        else {
            v_after = fabs(v_after - (a * SEC_PER));
            x2 += SEC_PER;
        }

        dist += ((v_before + v_after) * SEC_PER) / 2;
        v_before = v_after;

        printf("%.2lfsec : %.2lfm/s : %.2lfm\n", sec, v_after, dist);
    }
}

void calculate() {
    double v_before = v_st;
    double v_after = v_st;

    double sec = 0; // 현재 시간
    double dist = 0; // 현재 거리

    double t1 = (v_max - v_st) / a; // 속도 증가할 때 시간
    double t2 = (v_max - v_ed) / a; // 속도 감소할 때 시간
    double d1 = ((v_max + v_st) * t1) / 2;
    double d2 = ((v_max + v_ed) * t2) / 2;
    double t3 = ((distance - (d1 + d2)) / v_max); // 등속도할 때 시간

    printf("%.2lfsec : %.2lfm/s : %.2lfm\n", sec, v_after, dist);

    while (ceil(sec * 10) / 10 < t1 + t2 + t3) {
        sec += SEC_PER; // 시간 증가 +0.1초 단위

        // 상승
        if (sec < t1) {
            v_after += (a * SEC_PER);
            dist += ((v_before + v_after) * SEC_PER) / 2;
            x1 += SEC_PER;
        }
        // 등속
        else if (sec <= t1 + t3 && sec > t1) {
            v_before = v_max;
            dist += v_max * SEC_PER;
            x3 += SEC_PER;
        }
        // 정점을 찍고 속도 하락
        else {
            v_after = fabs(v_after - (a * SEC_PER));
            dist += ((v_before + v_after) * SEC_PER) / 2;
            x2 += SEC_PER;
        }

        printf("%.2lfsec : %.2lfm/s : %.2lfm\n", sec, v_after, dist);
        
        v_before = v_after;
    }
}

void solution() {

    // 삼각형인지 => 삼각형이었을 때 넓이보다 작거나 같으면 삼각형
    if ( (((v_max * v_max) * 2) - (v_st * v_st) - (v_ed * v_ed)) / (2 * a) >= distance ){
        double v_x = sqrt((2 * a * distance + (v_st * v_st) + (v_ed * v_ed)) / 2);

        // 최고속도 도달 못할 경우
        if (v_x < v_max)
            v_max = v_x;

        calculate_tri();
    }
    // 사다리꼴인지 => 삼각형이었을 때 넓이보다 크면 사다리꼴
    else {
        calculate();
    }

    printf("x1 = %.4lf, xm = %.4lf, x2 = %.4lf\n", x1, x3, x2);
}

int main() {
    putData();
    solution();
}