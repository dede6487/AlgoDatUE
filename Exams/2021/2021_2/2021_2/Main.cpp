#include<vector>
#include<list>
#include<string>
#include<set>
#include<map>
#include<iostream>

using namespace std;

// assuming that we gat the data in a way that we can then store it in the following adjacency list:
// 

struct person {
	string name;
	int age;
};


class adjList {
private:
	vector<list<person>> adjacency;
	vector<person> Vertices;
	map<person, int> persToNum;
	int vertexNum;
public:
	adjList(int populationNum) {
		vertexNum = populationNum;
	}

	~adjList() {

	}

private:
	void dfsClanHelper(int vec_num, list<person>::iterator list_it, set<person> visited, int temp_population, string temp_elder, int temp_elderAge) {
		if (list_it != adjacency[vec_num].end()) {
			if (visited.find(*list_it) != visited.end()) {
				temp_population++;
				if ((*list_it).age > temp_elderAge) {
					temp_elderAge = (*list_it).age;
					temp_elder = (*list_it).name;
				}
				visited.insert(*list_it);
				dfsClanHelper(vec_num, list_it++, visited, temp_population, temp_elder, temp_elderAge);
			}
		}
	}

	//doesnt actually go through all vertices of a clan!!!!!!!!!!!!!!!
	
public:
	string mostNumerousClan() {
		//using depth first search over all clans
		list<person>::iterator list_it;
		vector<person>::iterator vec_it;
		set<person> visited;

		int population = 0;
		string elder = "";
		int elderAge = 0;

		int clans = 0;

		for (vec_it = Vertices.begin(); vec_it != Vertices.end(); vec_it++) {
			if (visited.find(*vec_it) != visited.end()) {
				clans++;

				int temp_population = 1;
				int temp_elderAge = (*vec_it).age;
				string temp_elder = (*vec_it).name;

				int vec_num = persToNum[(*vec_it)];
				list_it = adjacency[vec_num].begin();

				visited.insert(*vec_it);
				dfsClanHelper(vec_num, list_it, visited, temp_population, temp_elder, temp_elderAge);
			}
		}
		if (clans == 1) {
			cout << "it's just one clan!" << endl;
		}
		return elder;
	}
};

int main() {

}