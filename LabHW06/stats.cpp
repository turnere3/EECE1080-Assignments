// Author: Eric Turner
// Source File: stats.cpp
// Description: Various array statistics

#include <cmath>

using namespace std;

int arrSum(int array[], unsigned length){
  int sum = 0;
  for (unsigned i = 0; i < length; i++){
    sum += array[i];
  }
 return sum;
}

double arrMean(int array[], unsigned length){
  double mean = 0;
  for (unsigned i = 0; i < length; i++){
    mean += array[i];
  }
  mean = mean / length;
 return mean;
}

int arrMin(int array[], unsigned length){
  int min = array[0];
  for (unsigned i = 0; i < length; i++){
    if (array[i] < min){
      min = array[i];
    }
  }
  return min;
}

int arrMax(int array[], unsigned length){
  int max = array[0];
  for (unsigned i = 0; i < length; i++){
    if (array[i] > max){
      max = array[i];
    }
  }
 return max;
}

double arrStdDev(int array[], unsigned length){
 return 0;
}

bool isPrime(int number){
  int count = 0;
  if (number == 0 || number == 1 || number < 0){
    return false;
  }else{
    for (int k = 2; k < sqrt(number) + 1; k++){
      if (number % k == 0){
        count++;
      }
    }
    if (count > 0){
      return false;
    }else{
	    return true;
	  }
  }
}

unsigned arrNumPrimes(int array[], unsigned length){
  int count = 0;
  for (unsigned i = 0; i < length; i++){
    if (isPrime(array[i]) == true){
      count += 1;
    }
  }
  return count;
}

unsigned arrSetSize(int array[], unsigned length){
  unsigned count = 0;
  for (unsigned i = 0; i < length; i++){
    unsigned check = 0;
    for (unsigned k = i + 1; k < length; k++){
      if (array[i] == array[k]){
        check = 1;
      }
    }
    if (check == 0){
      count += 1;
    }
  }
 return count;
}


unsigned arrNumCount(int array[], unsigned length, int num){
  int count = 0;
  for (unsigned i = 0; i < length; i++){
    if (array[i] == num){
      count += 1;
    }
  }
 return count;
}


// For HW

unsigned arrNumBetween(int array[], unsigned length, int low, int high){
  int count = 0;
  for (unsigned i = 0; i < length; i++){
    if (array[i] >= low && array[i] < high){
      count += 1;
    }
  }
 return count;
}

void arrReverse(int array[], unsigned length){
  int tempArray[length];
  for (unsigned i = 0; i < length; i++){
    tempArray[i] = array[length - i - 1];
  }
  for (unsigned j = 0; j < length; j++){
    array[j] = tempArray[j];
  }
 return;
}

int arrFind(int array[], unsigned length, int value, unsigned position = 0){
  for (unsigned i = position; i < length; i++){
    if (array[i] == value){
      position = i;
      return position;
    }
  }
  position = -1;
  return position;
}



