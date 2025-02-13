#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

typedef char Str24[24];
typedef char Str9[9];
typedef char Str40[40];  

typedef struct FloatInfo {
  bool non_negative;
  int decimal;
  int int_of_fraction;
  int num_digits;
} FloatInfo;

FloatInfo FractionStrAnalysis(Str40 float_str) {
  FloatInfo ans = {true, 0, 0, 0};
  int output_num;
  int index = 0;
  double output_fraction;
  char answer[10] = {0};
  int non_zero_position;
  if (float_str[0] == '-') {
    ans.non_negative = false;
  }

  else {
    ans.non_negative = true;
  }

  int lens = strlen(float_str);
  int num = atoi(float_str);
  if (num < 0)
    num = num * -1;

  ans.decimal = num;
  for (int i = 0; i < lens; i++) {
    if (float_str[i] == '.') {
      index = i;
      break;
    }
  }
  if (index == 0)
    return ans;
  double num1 = atof(float_str);
  int count = 0;
  if (num1 < 0)
    num1 = num1 *-1.0;
  for (int i = index+1; i < lens; i++) {
    if (float_str[i] != '0') {
      answer[count] = float_str[i];
      count++;
    }
  }
  ans.num_digits = lens - index - 1;
  ans.int_of_fraction = atoi(answer);
  return ans;
}

void DecimalToBinary(int input_num, Str40 output_num) {
  int index;
  bool is_first = false;
  int count = 0;
  if (input_num == 0) {
    output_num[0]='0';
  }
  for (int i = 32; i >= 0; i--) {
    int value = pow(2, i);
    if (is_first && input_num / value == 1) {
      output_num[count] = '1';
      input_num = input_num % value;
      count++;
    }

    else if (is_first && input_num / value == 0) {
      output_num[count] = '0';
      input_num = input_num % value;
      count++;
    }

    else if (input_num / value == 1) {
      output_num[count] = '1';
      input_num = input_num % value;
      is_first = true;
      count++;
    }
  }

}

void FractionToBinary(int int_of_fraction, int num_digits, Str40 output_bin) {
  char ans[40] = {0};
  int count = 0;
  double num;
  bool is_first = false;
  num_digits = -num_digits;
  num = pow(10, num_digits) * int_of_fraction;
  for (int i = -1 ; i >= -32; i--) {
    if (num == 0) {
      break;
    }
    double value = pow(2, i);
    int num1 = num / value;
    if (num1 == 1) {
      ans[count] = '1';
      num = num - value;
      is_first = true;
      count++;
    }

    else {
      ans[count] = '0';
      count++;
    }
  }
  for (int i = 0; i < 10; i++) {
    output_bin[i] = ans[i];
  }
}


int FindMantissaExponent(Str40 input_decimal, Str40 input_fraction, 
    Str24 mantissa) {
  int lens1 = strlen(input_decimal);
  int lens2 = strlen(input_fraction);
  int sum = lens1+lens2;
  int index = 0;
  char ans[40];
  strcpy(ans, input_decimal);
  int count = 0;
  int count1 = 0;
  
  for (int i = lens1; i < 24; i++) {
    ans[i] = input_fraction[count];
    count++;
  }
  for (int i = 0; i < 24; i++) {
    if (ans[i] == '1') {
      index = i;
      break;
    }
  }
  for (int i = 0; i < 23; i++) {
    mantissa[i] = '0';
  }
  for (int i = index+1; i < sum; i++) {
    mantissa[count1] = ans[i];
    count1++;
  }
  return strlen(input_decimal) - index -1;
} 



void DecimalToExcess127(int exponent, Str9 excess127) {
  int num;
  num = exponent+127;
  int count = 0;
  for (int i = 32; i >= 8; i--) {
    int value = pow(2, i);
    if (num / value == 1) {
      num = num % value;
    }
  }
  for (int i = 0; i < 8; i++) {
    excess127[i] = '0';
  }
  for (int i = 7; i >= 0; i--) {
    int value = pow(2, i);
    if (num/value == 1) {
      num = num %value;
      excess127[count] = '1';
    }

    count++;
  }
}
int main() {

  Str40 input_string = "";
  bool is_positive = true;
  Str24 binary_mantissa = "";
  Str9 binary_excess127 = "";
  scanf("%s", input_string);
  
  Str40 output_Decimal = {0};
  Str40 output_Fraction = {0};
  float exponent = 0;
  FloatInfo data;
  data = FractionStrAnalysis(input_string);
  DecimalToBinary(data.decimal, output_Decimal);
  FractionToBinary(data.int_of_fraction, data.num_digits, output_Fraction);
  exponent = FindMantissaExponent(output_Decimal, output_Fraction,
      binary_mantissa);
  DecimalToExcess127(exponent, binary_excess127);
  is_positive = data.non_negative;
  if (data.decimal == 0 && data.int_of_fraction == 0) {
    printf("%c %s %s", is_positive ? '0' : '1',
        "00000000",
        "00000000000000000000000");
    return 0;
  }
  
  if ( is_positive ) 
    printf("0 %s %s", binary_excess127 ,  binary_mantissa);
  else
    printf("1 %s %s", binary_excess127 ,  binary_mantissa);

  return 0;
}