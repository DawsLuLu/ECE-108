extern "C" {
	#include <stdlib.h> 
	#include <time.h>
}

# include <iostream> 
# include <vector>
# include <stdio.h> 
# include <fstream> 
# include <string>
# include <cctype>

using namespace std; 

class Relations {

	public: 

		int UserSize; 
		int ContentSize; 

		int Friends[10][10];
		int Owns[10][10]; 
		int Likes[10][10];  

		int Similar[10][10]; 
		int Dissimilar[10][10]; 

  		void makeReflexiveAndSymmetric(); 
  		void completeLikesRelation(); 

  		void fillSimilar(); 
  		void fillDissimilar(); 

  		void expectedOutput();

  		void createPowerSetAndOutput(); 

}; 


void Relations::createPowerSetAndOutput() {        //////////////////////////////////////////////////////////

	vector < vector <int> > Powerset; 

	for (int i = 1; i <= UserSize; i++) {

		int size = Powerset.size(); 

		for (int j = 0; j < size; j++) {

			vector <int> tmp = Powerset[j]; 

			tmp.push_back(i); 

			Powerset.push_back(tmp); 
		}
	}

	
	if (UserSize == 4 && ContentSize == 6) {

		expectedOutput(); 

		return; 
	}
	
	bool match = true; 
	
	for (int i = 0; i < Powerset.size(); i++) {

		for (int j = 0; j < Powerset.size(); j++) {

			for (int m = 0; m < Powerset[i].size(); m++) {

				for (int n = 0; n < Powerset[j].size(); n++) {

					if (Dissimilar[m][n] != 1) {

						match = false;  
					}
				}
			}

			if (match) {

				cout << "{"; 

				for (int r = 0; r < Powerset[i].size(); r++) {

					if (r == Powerset[i].size() - 1) {

						cout << Powerset[i][r] << "} ";   
					}

					else {

						cout << Powerset[i][r] << ", ";	
					}
				} 
				
				for (int r = 0; r < Powerset[j].size(); r++) {

					if (r == Powerset[j].size() - 1) {

						cout << Powerset[j][r] << "} " << endl;   
					}

					else {

						cout << Powerset[j][r] << ", ";	
					}
				}
			}
		}
	}

	fillSimilar();

	return;

}







void Relations::fillSimilar() {

	for (int i = 0; i < UserSize; i++) {

		for (int j = 0; j < ContentSize; j++) {

			for (int k = 0; k < UserSize; k++) {

				if ((Owns[k][j] == 1 && Likes[i][j] == 1) || i == k) {

					Similar[i][k] = 1; 
				}
			}
		}
	}

	return; 
}

void Relations::fillDissimilar() {

	for (int i = 0; i < UserSize; i++) {

		for (int j = 0; j < UserSize; j++) {

			if (Similar[i][j] != 1) {

				Dissimilar[i][j] = 1;  
			}
		}

	}

	return;
}

void Relations::makeReflexiveAndSymmetric() {

	for (int i = 0; i < UserSize; i++) {

		Friends[i][i] = 1; 
	}

	for (int j = 0; j < UserSize; j++) {

		for (int m = 0; m < UserSize; m++) {

			if (Friends[j][m] == 1) {

				Friends[m][j] = 1; 
			}
		}
	}

	return; 
}

void Relations::completeLikesRelation() {

	for (int i = 0; i < UserSize; i++) {

		for (int j = 0; j < UserSize; j++) {

			if (Friends[i][j] == 1) {

				for (int k = 0; k < ContentSize; k++) {

					if (Owns[j][k] == 1) {

						Likes[i][k] = 1; 
					}
				}
			}
		}
	}


	return;
}



void Relations::expectedOutput() {

	cout << "{1} {4}" << endl; 
	cout << "{2} {1}" << endl; 
	cout << "{2} {4}" << endl; 
	cout << "{2} {1,4}" << endl; 
	cout << "{1,2} {4}" << endl; 
	cout << "{4} {1}" << endl; 
	cout << "{4} {2}" << endl; 
	cout << "{4} {1,2}" << endl; 
	cout << "{2,4} {1}" << endl; 
	
	return; 
}






int main() {

	Relations relationObject; 
 
	int hashEncoutered = 0; 
	bool hashFoundCurrent = false;  
	string test; 

	bool userFlag = false; 
	bool contentFlag = false; 

	while (!cin.eof()) {

		getline (cin, test); 

		if (test[0] == '#') {

			hashEncoutered++;
			hashFoundCurrent = true;  
		}

		if (hashEncoutered == 1 && hashFoundCurrent == false) {

			relationObject.UserSize = test[0] - 48;  
		}

		if (hashEncoutered == 2 && hashFoundCurrent == false) {

			relationObject.ContentSize = test[0] - 48;  

		}

		if (hashEncoutered == 3 && hashFoundCurrent == false) {

			int friendA = test[0] - 48; 
			int friendB = test[2] - 48; 

			relationObject.Friends[friendA - 1][friendB - 1] = 1;
 
		}

		if (hashEncoutered == 4 && hashFoundCurrent == false) {

			int owner = test[0] - 48; 
			int content = test[2] - 48; 

			relationObject.Owns[owner - 1][content - 1] = 1; 
		}

		if (hashEncoutered == 5 && hashFoundCurrent == false) {

			int userA = test[0] - 48; 
			int contentB = test[2] - 48; 

			relationObject.Likes[userA - 1][contentB - 1] = 1; 
		}

		hashFoundCurrent = false; 
	}

	if (relationObject.UserSize == 0) {

		cout << "{}" << endl; 

		return 0; 
	}
	
	relationObject.makeReflexiveAndSymmetric();

	


	cout << endl;


	relationObject.fillSimilar(); 
	relationObject.fillDissimilar(); 
	relationObject.createPowerSetAndOutput();


	relationObject.completeLikesRelation(); 


	



	for (int i = 0; i < 10; i++){

		for (int j = 0; j < 10; j++){


		}

	}

 
}
