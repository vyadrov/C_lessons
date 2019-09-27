#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {
    double mantissa, power, exp;
    int i, sign, esign;

    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (mantissa = 0.0; isdigit(s[i]); i++)
        mantissa = 10.0 * mantissa + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        mantissa = 10.0 * mantissa + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exp = 0.0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');
    exp = pow(10.0f, esign * exp);
    return sign * (mantissa / power) * exp;
}

int main(int argc, char *argv[]) {
    char source[]="99.45e-5";
    double out;
    out1 = atof(source);
    printf("%.10f\n", out);    
}