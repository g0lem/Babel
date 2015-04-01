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




	if (this->GetInventoryState()->GetState() == NOT_ACTIVE)
	{
		if (this->GetInventoryState()->GetColID() != NOT_SET)
		{


			this->GetInterHandler()->GetInters()->erase(this->GetInterHandler()->GetInters()->begin() + this->GetInventoryState()->GetColID());
			this->GetInventoryState()->setColID(NOT_SET);


		}
	}

	if (this->GetStoryState()->GetState() == NOT_ACTIVE)
	{
		if (this->GetStoryState()->GetColID() != NOT_SET)
		{


			this->GetInterHandler()->GetInters()->erase(this->GetInterHandler()->GetInters()->begin() + this->GetStoryState()->GetColID());
			this->GetStoryState()->setColID(NOT_SET);


		}
	}



}





void UIState::Update(Controller * ctrl)
{


	this->ProcessKeys(ctrl);


	this->ManageQuits();


}




