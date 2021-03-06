#include "cvrp.h"
#include <random>

using namespace std;

int main(int argc, char *argv[]){
	
	
	if(argc == 1){
					
	}else{
		string path(argv[1]);
		double alpha;
		CVRP problem;
		
		problem.load_solomon_instance(path);

		string a(argv[2]), s(argv[6]), gran(argv[4]);
		int seed = stoi(s);
		clock_t begin = clock();
		Solution* S = problem.GRA(stoi(a), stoi(string(argv[3])), stod(gran), atoi(argv[5]), seed);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << S->funcVal << "," << S->nVehi << "," << S->alpha << "," << seed << "," << elapsed_secs;
		
	}
}
