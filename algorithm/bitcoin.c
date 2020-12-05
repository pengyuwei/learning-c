#include <math.h>
#include <stdio.h>

double AttackerSuccessProbability(double q, int z)
{
    double p = 1.0 - q;
    double lambda = z * (q / p);
    double sum = 1.0;
    int i, k;
    for (k = 0; k <= z; k++)
    {
        double poisson = exp(-lambda);
        for (i = 1; i <= k; i++)
            poisson *= lambda / i;
        sum -= poisson * (1 - pow(q / p, z - k));
    }
    return sum;
}

int main(int argc, char *argv[])
{
    for (double q = 0.1; q<=1; q+=0.1) {
        for (int z = 0; z <= 10; z++) {
            double ret = AttackerSuccessProbability(q, z);
            printf("q=%02f, z=%d, sum=%f\n", q, z, ret);
        }
    }

    return 0;
}