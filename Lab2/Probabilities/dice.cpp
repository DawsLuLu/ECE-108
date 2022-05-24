extern "C" {
	#include <stdlib.h>
	#include <time.h>
}

#include <iostream>

using namespace std;

int main() {

	srand((unsigned int)time(NULL));

	int x = 0; 
	int y = 0;
	int max = 99099;
	int min = 0;
	
	float result110 = 0;
	float result210 = 0;
	float result310 = 0;
	float result410 = 0;
	float result510 = 0;
	float result610 = 0;
	
	float result11k = 0;
	float result21k = 0;
	float result31k = 0;
	float result41k = 0;
	float result51k = 0;
	float result61k = 0;
	
	float result1100k = 0;
	float result2100k = 0;
	float result3100k = 0;
	float result4100k = 0;
	float result5100k = 0;
	float result6100k = 0;
	
	float resultlow100 = 0;
	float resulthigh100 = 0;
	float lowequalshigh100 = 0;

	float resulthigh10k = 0;
	float resultlow10k = 0;
	float lowequalshigh10k = 0;

	float result2D2 = 0;
	float result2D3 = 0;
	float result2D4 = 0;
	float result2D5 = 0;
	float result2D6 = 0;
	float result2D7 = 0;
	float result2D8 = 0;
	float result2D9 = 0;
	float result2D10 = 0;
	float result2D11 = 0;
	float result2D12 = 0;


	for (int i = 0; i < 10; i++) {
	    
	    x = 0;

		x = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		
		if (((x % 6) + 1) == 1) {
		    
		    result110++;
		    
		}
		
		if (((x % 6) + 1) == 2) {
		    
		    result210++;
		    
		}
		
		if (((x % 6) + 1) == 3) {
		    
		    result310++;
		    
		}
		
		if (((x % 6) + 1) == 4) {
		    
		    result410++;
		    
		}
		
		if (((x % 6) + 1) == 5) {
		    
		    result510++;
		    
		}
		
		if (((x % 6) + 1) == 6) {
		    
		    result610++;
		    
		}
		
	}
	
	cout << "10 rolls:" << endl << "1:" << result110 / 10 << endl << "2:" << result210 / 10 << endl << "3:" << result310 / 10 << endl << "4:" << result410 / 10 << endl << "5:" << result510 / 10 << endl << "6:" << result610 / 10 << endl << endl;

    	for (int i = 0; i < 1000; i++) {
	    
	    x = 0;

		x = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		
		if (((x % 6) + 1) == 1) {
		    
		    result11k++;
		    
		}
		
		if (((x % 6) + 1) == 2) {
		    
		    result21k++;
		    
		}
		
		if (((x % 6) + 1) == 3) {
		    
		    result31k++;
		    
		}
		
		if (((x % 6) + 1) == 4) {
		    
		    result41k++;
		    
		}
		
		if (((x % 6) + 1) == 5) {
		    
		    result51k++;
		    
		}
		
		if (((x % 6) + 1) == 6) {
		    
		    result61k++;
		    
		}
		
	}
	
	cout << "1000 rolls:" << endl << "1:" << result11k / 1000 << endl << "2:" << result21k / 1000 << endl << "3:" << result31k / 1000 << endl << "4:" << result41k / 1000 << endl << "5:" << result51k / 1000 << endl << "6:" << result61k / 1000 << endl << endl;

        for (int i = 0; i < 100000; i++) {
	    
	    x = 0;

		x = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		
		if (((x % 6) + 1) == 1) {
		    
		    result1100k++;
		    
		}
		
		if (((x % 6) + 1) == 2) {
		    
		    result2100k++;
		    
		}
		
		if (((x % 6) + 1) == 3) {
		    
		    result3100k++;
		    
		}
		
		if (((x % 6) + 1) == 4) {
		    
		    result4100k++;
		    
		}
		
		if (((x % 6) + 1) == 5) {
		    
		    result5100k++;
		    
		}
		
		if (((x % 6) + 1) == 6) {
		    
		    result6100k++;
		    
		}
		
	}
	
	cout << "100000 rolls:" << endl << "1:" << result1100k / 100000 << endl << "2:" << result2100k / 100000 << endl << "3:" << result3100k / 100000 << endl << "4:" << result4100k / 100000 << endl << "5:" << result5100k / 100000 << endl << "6:" << result6100k / 100000 << endl << endl;

for (int i = 0; i < 10000; i++){

	resultlow10k = 0;

	resulthigh10k = 0;

	for (int j = 0; j < 100; j++) {
			
			x = 0;

			x = min + rand() / (RAND_MAX / (max - min + 1) + 1);

			if (((x % 6) + 1) < 4) {

				resultlow10k++;

			}

			if (((x % 6) + 1) > 3) {

				resulthigh10k++;

			}	
	
		}

		if (resulthigh10k == resultlow10k) {

			lowequalshigh10k++;

		}	

}	

	cout << "10000 rolls:" << endl << "Low Equals High:" << lowequalshigh10k / 10000 << endl << endl;

	for (int i = 0; i < 10000; i++) {

		x = 0;
		y = 0;

		x = min + rand() / (RAND_MAX / (max - min + 1) + 1);

		y = min + rand() / (RAND_MAX / (max - min + 1) + 1);

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 2) {

			result2D2++;

		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 3) {

			result2D3++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 4) {

			result2D4++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 5) {

			result2D5++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 6) {

			result2D6++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 7) {

			result2D7++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 8) {

			result2D8++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 9) {

			result2D9++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 10) {

			result2D10++;
			
		}

		if ((((x % 6) + 1) + ((y % 6) + 1)) == 11) {

			result2D11++;
			
		}
		
		if ((((x % 6) + 1) + ((y % 6) + 1)) == 12) {

			result2D12++;
			
		}

	}

	cout << "2 dice, 10000 rolls:" << endl << "2:" << result2D2 / 10000 << endl<<"3:" <<  result2D3 / 10000 << endl<< "4:" << result2D4 / 10000 << endl<< "5:" << result2D5 / 10000 << endl
	<< "6:" << result2D6 / 10000 << endl<< "7:" << result2D7 / 10000 << endl<< "8:" << result2D8 / 10000 << endl<< "9:" << result2D9 / 10000 << endl<< "10:" << result2D10 / 10000 << endl
	<< "11:" << result2D11 / 10000 << endl<< "12:" << result2D12 / 10000 << endl;

}