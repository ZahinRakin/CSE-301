#include <stdio.h>
#include <stdlib.h>

void ks(int*, int*, int, int);

int main(){
  int weight[] = {10, 20, 30};
  int benefit[] = {60, 100, 120};
  int maxWeight = 50;
  int size = sizeof(benefit)/sizeof(*benefit);
  ks(benefit, weight, maxWeight, size);
  return 0;
}

void ks(int* benefit, int* weight, int maxWeight, int size){
  double ratios[size];
  for(int i = 0; i < size; i++){
    ratios[i] = (double)benefit[i]/weight[i];
  }
  for(int i = 0; i < size - 1; i++){
    for(int j = i; j < size; j++){
      if(ratios[j] < ratios[j+1]){
        double tempRatio = ratios[j];
        ratios[j] = ratios[j+1];
        ratios[j+1] = tempRatio;
        
        int tempBenefit = benefit[j];
        benefit[j] = benefit[j+1];
        benefit[j+1] = tempBenefit;
        
        int tempWeight = weight[j];
        weight[j] = weight[j+1];
        weight[j+1] = tempWeight;
      }
    }
  }
  
  double currentBenefit = 0.0;
  int currentWeight = 0;
  printf("Weight[i]\tBenefit[i]\n");
  for(int i = 0; i < size; i++){
    if(currentWeight + weight[i] <= maxWeight){
      currentWeight += weight[i];
      currentBenefit += benefit[i];
      printf("%d\t\t%d\n",weight[i],benefit[i]);
    }
    else{ 
      double fraction = (double)(maxWeight - currentWeight)/maxWeight;
      currentBenefit += fraction*benefit[i];
      printf("%d\t\t%d\n",weight[i],benefit[i]);
    }
  }
  printf("Finally weight & total benefit:\n%d\t%.3f\n",maxWeight,currentBenefit);
}
