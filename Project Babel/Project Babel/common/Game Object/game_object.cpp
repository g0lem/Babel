//Checked 1




#include <common.hpp>


void GameObject::Init()
{


	rebuild = false;
	this->m_scroller = new Scroller();
	this->c_map = new CollisionMap();
	this->m_misc = new Miscellaneous();
	this->m_list = new ItemList();
	this->t_system = new TurnSystem();
	this->ui_state = new UIState();
	this->p_state = new panel_state();
	this->e_loader = new EnemyLoader();
	this->t_object = new TextObject();
	this->f_list = new FontList();
	u_t =new  std::vector < untablet* > ;

}

void GameObject::Advance()
{
	rebuild = false;

	
	this->c_map = new CollisionMap();
	this->e_loader = new EnemyLoader();


	this->GetItemList()->ClearObjects();
	this->GetItemList()->ClearDroppedItems(); 

}


void GameObject::Clean()
{



	delete this->m_scroller;
	delete this->c_map;
	delete this->m_misc;
	delete this->m_list;
	delete this->t_system;
	delete this->ui_state;
	delete this->p_state;
	delete this->e_loader;


}