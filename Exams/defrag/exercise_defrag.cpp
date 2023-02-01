#include"GraphMat.h"


void defrag() {
	int holeCount = 0
	for(int i = 1; i < counter; i++)
	{
		if (currVertices[i] == vertexNullValue) 
		{
			for (int j = i; j < counter; j++) //shifting vertices to fill hole and correct the map accordingly
			{
				vertices[j] = currVertices[j + 1];
				currVertices[j] = currVertices[j + 1];
				holeCount++;
			}
		}
	}
	counter -= holeCounter; //setting the counter to the appropriate new count
}