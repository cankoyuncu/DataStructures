//Write a function to add two complex numbers.

// 06.10.2022


 #include <stdio.h>
 
	int add(int a, int b){
		return a + b;
	}
	struct complex addcomplex(struct complex a, struct complex b){
		struct complex result;
		result.real = a.real + b.real;
		result.im = a.im + b.im;
		return result;
	};)
 	
 }
