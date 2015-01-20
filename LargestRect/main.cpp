//
//  main.cpp
//  LargestRect
//
//  Created by CKHuang on 1/20/15.
//  Copyright (c) 2015 CKHuang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void sortit(vector<int> v, int);

int main(int argc, const char * argv[]) {
    int input[] = {2,1,5,6,2,3};
    int size = sizeof(input)/sizeof(int);
    vector<int> ivec(input, input+size);
    int max=0, min=0;
    
    int i,j, height=0, width=1;
    int area=0;
//    sortit(ivec, size);
//    min = ivec[0];
    min =1;
    printf("%d\n", size);
    
    for (i=0; i < size; i++) {
        printf("i:%d\n", i);
        width =1;
        if(input[i] == min) {
            area = ivec[i] * size;
            printf("area1:%d max:%d\n", area, max);
        }
        else{
            height = ivec[i];
            int adj=i-1;
            while (adj>0) {
                if (ivec[adj] >= ivec[i]) {
                    width++;
                    adj--;
                }
                else
                    break;
            }
            adj = i+1;
            while (adj < size) {
                if (ivec[adj] >= ivec[i]) {
                    width++;
                    adj++;
                }
                else
                    break;
            }
            area = width * height;
            printf("area2:%d max:%d\n", area, max);
        }
        
        if (area > max) {
            max = area;
        }

    }
    printf("max:%d \n", max);
//    std::cout << "Hello, World!\n";
    cout <<  "\nHello, World!\n";
    return 0;
}

void sortit(vector<int>& p, const int size) {
    int i,j;
    int temp=0;
    
    for (i=0; i < size; i++) {
        for (j=0; j<size; j++) {
            if (p[i] < p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
