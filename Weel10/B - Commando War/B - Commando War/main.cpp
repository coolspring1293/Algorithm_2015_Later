//
//  main.cpp
//  B - Commando War
//
//  Created by Kieran Will on 12/3/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Commando {
public:
	int B, J;
	Commando(int b, int j) { B = b; J = j; }
};

bool cmp(Commando &a, Commando &b) {
	return a.J > b.J;
}
vector<Commando> V;
int N, _count = 1, B, J, start_time = 0, end_time = 0;
int main(int argc, const char * argv[]) {
    while (cin >> N and N != 0) {
		V.clear();
        for (int i = 0; i < N; ++ i) {
            cin >> B >> J;
			V.push_back(Commando(B, J));
        }
		sort(V.begin(), V.end(), cmp);
		start_time = end_time = 0;
		for (int i = 0; i < V.size(); ++ i) {
			start_time += V[i].B;
			if (end_time < V[i].J + start_time)
                end_time = V[i].J + start_time;
		}
        cout << "Case " << _count ++ << ": " << end_time << "\n";
    }
    return 0;
}


/*
 3
 2 5
 3 2
 2 1
 3
 3 3
 4 4
 5 5
 0
 
 */
