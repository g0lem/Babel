#include <common.hpp>






void UIState::Init()
{




	this->char_panel = new CharPanState();



	this->inter_handler = new UI_intersect();

	this->p_state = new panel_state();
}





void UIState::ProcessKeys(Controller * ctrl)
{


	if (ctrl->GetKeyOnce(BACKPACK_KEY))
		this->char_panel->SetState(!this->char_panel->GetState());


}





void UIState::ManageQuits()
{




	if (this->GetCharPanState()->GetState() == NOT_ACTIVE)
	{
		if (this->GetCharPanState()->GetColID() != NOT_SET)
		{


			this->GetInterHandler()->GetInters()->erase(this->GetInterHandler()->GetInters()->begin() + this->GetCharPanState()->GetColID());
			this->GetCharPanState()->SetColID(NOT_SET);


		}
	}


}





void UIState::Update(Controller * ctrl)
{


	this->ProcessKeys(ctrl);


	this->ManageQuits();


}




