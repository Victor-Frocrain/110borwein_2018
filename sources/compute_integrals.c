/*
** EPITECH PROJECT, 2019
** compute_integrals
** File description:
** compute_integrals
*/

#include "borwein.h"

double compute_first(int n, double x)
{
    double result = 1;

    for (int k = 0; k <= n; k++)
        if (x != 0)
            result = result * (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
    return (result);
}

void compute_rect(int nb)
{
    double result = 0;
    double result1 = 0;

    for (double i = 0; i < 10000; i++)
        result += compute_first(nb, (i * 0.5 + 0.25));
    result *= 0.5;
    printf("Midpoint:\nI%d = %.10f\n", nb, result);
    result1 = result - (M_PI / 2);
    if (result1 < 0)
        result1 *= -1;
    printf("diff = %.10f\n", result1);
}

void compute_trap(int nb)
{
    double result = 0;
    double result2 = 0;

    for (double i = 1; i < 10000; i++) {
        result += compute_first(nb, (i * 0.5));
    }
    result = ((result * 2) + compute_first(nb, 0) + compute_first(nb, 5000)) * 0.25;
    printf("\nTrapezoidal:\nI%d = %.10f\n", nb, result);
    result2 = result - (M_PI / 2);
    if (result2 < 0)
        result2 *= -1;
    printf("diff = %.10f\n", result2);
}

void compute_simpson(int nb)
{
    double result = 0;
    double result1 = 0;

    for (double i = 1; i < 10000; i++) {
        result += compute_first(nb, (i * 0.5));
    }
    for (double i = 0; i < 10000; i++) {
        result1 += compute_first(nb, (i * 0.5) + 0.25);
    }
    result = ((result * 2) + (result1 * 4) + compute_first(nb, 0) + compute_first(nb, 5000)) * (5000.0 / 60000.0);
    printf("\nSimpson:\nI%d = %.10f\n", nb, result);
    result1 = result - (M_PI / 2);
    if (result1 < 0)
        result1 *= -1;
    printf("diff = %.10f\n", result1);
}

void compute_integrals(int nb)
{
    compute_rect(nb);
    compute_trap(nb);
    compute_simpson(nb);
}
