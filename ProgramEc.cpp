/*
 * ProgramEc.c
 *
 *  Created on: Feb 10, 2023
 *      Author: e971t520
 */

#include <iostream>
using namespace std;

int main(){
	FILE *text = fopen("input.txt", "r");
	if (text == NULL){
		printf("Error");
		return 1;
	}
	int dep[5][5];
	int prog[5][5];
	int i;
	int j;
	for (i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
	    	fscanf(text, "%d\n", &dep[j][i]);
		}

	}
	for (i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
	    	fscanf(text, "%d\n", &prog[j][i]);
		}

	}
	fclose(text);

	int depProg[5] = {-1,-1,-1,-1,-1};

	// loop to run, i 
	for(i = 0; i < 5; i++){
		int pri[5] = {-1,-1,-1,-1,-1};
		int fin = -1;

		// iterate through departments with no programmer
		for(int j = 0; j < 5; j ++){
			if (depProg[j] == -1){
				// check what lowest department number prefers 
				if (fin == -1){
					fin = dep[j][0];
					pri[j] = j + 1;
				}
				// check if other departments prefers that and put them in an array
				else if (dep[j][0] == fin){
					pri[j] = j + 1;
				}
			}
		}
		// check the programmers priority
		int y = 0;
		for(int num = 0; num < 5; num++){
			for(int k = 0; k < 5; k++){
				// assign the department to the programmer
				if(prog[fin - 1][num] == pri[k]){

					depProg[k] = fin;

					//cout << fin << endl;
					k = 5;
					num = 5;
				}
			}

		}

		// remove the programmer from each department preference array by creating a new array

		int newdep[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
		for(int k = 0; k < 5; k++){
			int x = 0;
			for(int p = 0; p < 5; p++){
				if (dep[k][p] != fin){
					newdep[k][x] = dep[k][p];
					x++;
				}
			}
		}


		// copy the array to the original array	
		for (int l = 0; l < 5; l++){
			for (int j = 0; j < 5; j++){
				dep[l][j] = newdep[l][j];
			}
		}
		
	}
	for(int i = 0; i < 5; i++){
		printf("Department %d will get Programmer %d\n", i + 1, depProg[i]);
	}
}