#ifndef GRAPH_HPP
#define GRAPH_HPP




class Graph
{



	GLint**matrix;



	GLuint num_nodes;



	GLint *components;



	GLuint num_compontents;



	void DepthSearch(GLboolean *visited, GLint node);


public:



	inline Graph(GLuint n){ this->Init(n); }



	void Init(GLuint n);



	inline void AddEdge(GLint a, GLint b){ this->matrix[a][b] = this->matrix[b][a] = 1; }



	inline GLboolean Connected(GLint a, GLint b){ return this->matrix[a][b]; }



	inline GLuint GetNumNodes(){ return this->num_nodes; }



	inline GLint * GetComponents(){ return this->components; }



	inline GLuint GetNumComponents(){ return this->num_compontents; }




	void ComputeComponents();



};




#endif