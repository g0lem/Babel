#include <common.hpp>


void Map::FirstTunnelPass()
{


	GLuint min_room_distance = 15;



	for (GLuint i = 1; i < rooms->size(); i++)
	{


		GLfloat min_distance = this->tilemap->GetSize().x*this->tilemap->GetSize().y;
		GLuint k = 0;


		for (GLuint j = 1; j < rooms->size(); j++)
		{

			if (i != j && !m_graph->Connected(i, j))
				if (min_distance > glm::distance(glm::vec2(rooms[0][i]->GetInternalCenter()), glm::vec2(rooms[0][j]->GetInternalCenter()))
					&& min_distance > min_room_distance)
				{


				min_distance = glm::distance(glm::vec2(rooms[0][i]->GetInternalCenter()), glm::vec2(rooms[0][j]->GetInternalCenter()));
				k = j;


				}




		}



		this->AddTunnel(rooms[0][i]->GetInternalCenter(), rooms[0][k]->GetInternalCenter());
		m_graph->AddEdge(i, k);


	}




}



void Map::SecondTunnelPass()
{


	m_graph->ComputeComponents();

	GLuint selected = 0;

	GLuint max_rooms = 0;


	GLint *room_values = new GLint[m_graph->GetNumComponents()];


	for (GLuint i = 0; i < m_graph->GetNumComponents(); i++)
		room_values[i] = 0;



	for (GLuint i = 0; i < m_graph->GetNumNodes(); i++)
	{


		room_values[m_graph->GetComponents()[i]]++;



	}


	for (GLuint i = 0; i < m_graph->GetNumComponents(); i++)
	{


		if (room_values[i] > max_rooms)
		{

			max_rooms = room_values[i];


			selected = i;


		}


	}



	GLuint first_node_selected = 0;




	for (GLuint i = 0; i < m_graph->GetNumComponents(); i++)
	{




		if (i == selected)

		{


			for (GLuint j = 0; j < m_graph->GetNumNodes(); j++)

			{


				if (i == m_graph->GetComponents()[j])
				{


					first_node_selected = j;
					break;

				}


			}



		}



	}



	for (GLuint i = 0; i < m_graph->GetNumComponents(); i++)
	{


		GLuint first_node = 0;


		if (i != selected)

		{


			for (GLuint j = 0; j < m_graph->GetNumNodes(); j++)

			{


				if (i == m_graph->GetComponents()[j])
				{


					first_node = j;
					break;

				}


			}



			this->AddTunnel(rooms[0][first_node_selected]->GetInternalCenter(), rooms[0][first_node]->GetInternalCenter());


		}



	}




}

