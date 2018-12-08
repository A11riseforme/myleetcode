#include <stdio.h>

int roman_char_to_num(char c)
{
    switch(c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(char* s) {
    int sum = roman_char_to_num(s[0]);
    for (int i = 1; s[i] != '\0'; i += 1) {
        int current_num = roman_char_to_num(s[i]);
        int previous_num = roman_char_to_num(s[i-1]);
        if (current_num > previous_num) {
            sum = sum - previous_num + (current_num - previous_num);
        } else {
            sum += current_num;
        }
    }
    return sum;
}

int main() {
    char roman[] = "MCMXCIV";
    int num = romanToInt(roman);
    printf("%d", num);
}
