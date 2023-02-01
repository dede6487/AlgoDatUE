#include<list>
#include<tuple>
#include<vector>
#include<map>

using namespace std;

template <class student> class Edge {
public:
	student st1;
	student st2;

	Edge(student st1_, student st2_) {
		st1 = st1_;
		st2 = st2_;
	}

	~Edge(){}
};

template <class student> class adjList {
private:
	list<int>* adj;
	vector<student> Vertices;
	map<student, int> StudentMap;

	int students;

	void dfsHelper(bool* visited, int vertexNum) {
		visited[vertexNum] = true;

		typename list<student>::iterator it;
		for (it = adj[vertexNum].begin(); it != adj[vertexNum].end(); it++) {
			int num = StudentMap[*it];
			if (!visited[num]) {
				dfsHelper(visited, num);
			}
		}
	}

public:
	adjList() {

	}
	~adjList() {

	}

	void Friends(int outNumber, list<Edge> outList) {
		bool* visited = new bool[students];
		int count = 0;
		map<student> needsEdge;

		for (int v = 0; v < students; v++) {
			visited[v] = false;
		}

		for (int v = 0; v < students; v++) {
			if (!visited[v]) {
				count++;
				needsEdge[count] = Vertices[v];
				dfsHelper(visited, v);
			}
		}

		if (count > 1) { // this means that there are more than 1 connected components
			outNumber = count - 1;
			typename map<student>::iterator it;
			for (it = needsEdge.begin(); it.next() != needsEdge.end(); it++) {
				Edge e(*it, *(it.next()));
				outList.push_back(e);
			}
			
		}
		else {
			outNumber = 0;
		}

	}

};


int main() {

}