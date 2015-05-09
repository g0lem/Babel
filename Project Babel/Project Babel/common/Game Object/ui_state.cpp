#include <common.hpp>






void UIState::Init()
{






	this->inter_handler = new UI_intersect();

	this->m_state = new MenuState();

	this->i_state = new InventoryState();

	this->p_state = new panel_state();

	this->s_state = new StoryState();

	this->spell_State = new SpellState();

	this->stat_state = new StatState();
}





void UIState::ProcessKeys(SoundManager *sm, Controller * ctrl)
{


	if (ctrl->GetKeyOnce(MENU_KEY))
	{
		this->m_state->SetState(!this->m_state->GetState());
		{
			sm->PlaySound(MENUPRESSBUTTON);
		}
	}
	

}





void UIState::ManageQuits()
{





}





void UIState::Update(SoundManager *sm, Controller * ctrl)
{


	this->ProcessKeys(sm, ctrl);


	this->ManageQuits();


}




