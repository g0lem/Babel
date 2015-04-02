#include <common.hpp>






void UIState::Init()
{






	this->inter_handler = new UI_intersect();

	this->m_state = new MenuState();

	this->i_state = new InventoryState();

	this->p_state = new panel_state();

	this->s_state = new StoryState();
}





void UIState::ProcessKeys(Controller * ctrl)
{


	if (ctrl->GetKeyOnce(MENU_KEY))
		this->m_state->SetState(!this->m_state->GetState());
	

}





void UIState::ManageQuits()
{





}





void UIState::Update(Controller * ctrl)
{


	this->ProcessKeys(ctrl);


	this->ManageQuits();


}




