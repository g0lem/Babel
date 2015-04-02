#ifndef TURN_HPP
#define TURN_HPP




#define NO_ACTION -1
#define MOVING 0
#define ATTACKING 1



#define TIME_FOR_ACTION 0.10f



class ActionHandler
{


	GLfloat timer;
	GLint action;


public:


	inline ActionHandler(){ this->Init(); }
	inline void Init(){ this->timer = 0.0f; this->action = NO_ACTION; }
	inline void Start(){ this->timer = glfwGetTime(); }
	inline void Stop(){ this->timer = 0.0f; }
	inline GLboolean HasReachedLifetime(GLfloat life_time){ return glfwGetTime() - this->timer > life_time; }
	inline GLboolean IsStopped(){ return this->timer == 0.0f; }
	inline void SetAction(GLint action){ this->action = action; }
	inline GLint GetAction(){ return this->action; }



};






class TurnSystem
{



	GLfloat turns;



public:



	GLfloat GetTurns(){ return this->turns; }


	void ComputeAttack(GLfloat attack_speed);
	void ComputeMovement(GLfloat movement_speed);


	inline TurnSystem(){ this->Init(); }
	void Init();


	inline void Reset(){ this->turns = 0.0f; }
	inline void Advance(){ if (this->turns >= 1.0f)this->turns--; }
	inline void Add(GLfloat turns){ this->turns += turns; }
	inline void Update(TurnSystem * other){ if (this->turns > other->GetTurns())other->Add(this->turns - other->GetTurns()); }
	inline void Wait(){ this->turns++; }



};




#endif









