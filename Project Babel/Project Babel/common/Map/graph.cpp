#include <common.hpp>



void Graph::Init(GLuint n)
{



	this->num_nodes = n;


	this->matrix = new GLint*[this->num_nodes];
	for (GLuint i = 0; i < this->num_nodes; i++)
		this->matrix[i] = new GLint[this->num_nodes];



	for (GLuint j = 0; j < this->num_nodes; j++)
	{


		for (GLuint i = 0; i < this->num_nodes; i++)


		{


			this->matrix[i][j] = 0;


		}



	}



	this->components = new GLint[this->num_nodes];


	this->num_compontents = 0;



}




void Graph::DepthSearch(GLboolean *visited, GLint node)
{


	for (GLuint i = 0; i < this->num_nodes; i++)
		if (visited[i] == 0 && matrix[node][i] == 1)
		{
		components[i] = this->num_compontents;
		visited[i] = 1;
		this->DepthSearch(visited, i);
		}


}



void Graph::ComputeComponents()
{

	GLboolean * visited = new GLboolean[this->num_nodes];
	for (GLuint i = 0; i < this->num_nodes; i++)
		visited[i] = 0;




	for (GLuint i = 0; i < this->num_nodes; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			components[i] = this->num_compontents;
			this->DepthSearch(visited,i);
			this->num_compontents++;
		}
	}


}