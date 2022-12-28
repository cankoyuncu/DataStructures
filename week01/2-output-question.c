// 06.10.2022

 
 #include <stdio.h>

 void calculate(int x){
 		printf("%d\n",x);
 		if(x<9)
 			calculate(x+1);
 		printf("%d\n",x);
}
 
 int main(){
 	
 	calculate(1);
 	
 }
