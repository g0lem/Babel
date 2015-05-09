
#include <common.hpp>

void FontManager::Init(GameObject * g_obj)
{
	this->BindCreate("data/shaders/text_vert.txt",
		"data/shaders/text_frag.txt");

	g_obj->GetFontList()->Load();
	this->fText = new FloatingText();
	this->p_text = new PanelText();

	this->UnbindCreate();
}



void FontManager::Clean()
{
	TextRender::Clean();
}



void FontManager::Render(Controller * ctrl, GameObject * g_obj, Tooltip *t_tip)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	this->SetColor(1.f, 1.f, 1.f);

	this->fText->Render(g_obj, this, ctrl);

	this->p_text->Render(ctrl, this, g_obj);

	if (g_obj->statrender == true)
	{
		if (g_obj->StatPositions->size() > 0){
			char *temp = new char[256], *ito = new char[256];

			strcpy(temp, "HP: ");
			_itoa(g_obj->playerStats->GetHp()->hp, ito, 10);
			strcat(temp, ito);
			strcat(temp, " / ");
			_itoa(g_obj->playerStats->GetHp()->max_hp, ito, 10);
			strcat(temp, ito);

			g_obj->StatPositions->at(0).text = temp;



			temp = new char[256];
			strcpy(temp, "XP: ");
			_itoa(g_obj->playerStats->GetXp()->xp, ito, 10);
			strcat(temp, ito);
			strcat(temp, " / ");
			_itoa(g_obj->playerStats->GetXp()->max_xp, ito, 10);
			strcat(temp, ito);

			g_obj->StatPositions->at(1).text = temp;

			temp = new char[256];
			strcpy(temp, "Level: ");
			_itoa(g_obj->playerStats->GetXp()->lvl, ito, 10);
			strcat(temp, ito);

			g_obj->StatPositions->at(2).text = temp;

			temp = new char[256];
			strcpy(temp, "Spell DMG: ");
			_itoa(g_obj->spelldamage, ito, 10);
			strcat(temp, ito);

			g_obj->StatPositions->at(3).text = temp;

			temp = new char[256];
			strcpy(temp, "Damage: ");
			_itoa(g_obj->playerStats->base_attack.x, ito, 10);
			strcat(temp, ito);
			g_obj->StatPositions->at(4).text = temp;

			temp = new char[256];
			strcpy(temp, "Armor: ");
			_itoa(g_obj->playerStats->base_armor, ito, 10);
			strcat(temp, ito);

			g_obj->StatPositions->at(5).text = temp;

			float start = 74;
			glm::vec2 fucklel = g_obj->statpos + glm::vec2(60, +40);
			g_obj->GetFontList()->GetFont()->Print("Stats", fucklel.x, ctrl->GetWindowHeight() - fucklel.y, 40);

			for (int i = 0; i < 6; i++)
			{


				g_obj->StatPositions->at(i).pos = g_obj->statpos + glm::vec2(45, (i * 24) + start);




				g_obj->GetFontList()->GetFont()->Print(g_obj->StatPositions->at(i).text, g_obj->StatPositions->at(i).pos.x, ctrl->GetWindowHeight() - g_obj->StatPositions->at(i).pos.y, 24);
			}
		}
	}
	

	this->SetColor(0, 0, 0);

	if (g_obj->cooldown > 0){
		char * temp = new char[256], *temp2 = new char[256];
		strcpy(temp, "CD: ");
		_itoa(g_obj->cooldown, temp2, 10);
		strcat(temp, temp2);
		g_obj->GetFontList()->GetFont()->Print(temp, g_obj->spellPOS.x, g_obj->spellPOS.y + 9, 12);
	}
	this->SetColor(0.f, 0.f, 0.f);
	if (t_tip->GetTooltips()->at(t_tip->GetRenderingIndex())->renderstring == true)
		t_tip->RenderText(g_obj, this, ctrl);

	this->UnbindRun();


}