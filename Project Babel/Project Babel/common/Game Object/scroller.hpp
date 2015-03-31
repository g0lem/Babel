//Checked 1




#ifndef SCROLLER_HPP
#define SCROLLER_HPP





class Scroller
{



	glm::vec2 offset;


    glm::ivec2 begin_limit, end_limit;



public:



	inline Scroller(){ this->Init(); }


	inline ~Scroller(){ this->Clean(); }



	void Init();


	void Clean();



	void ComputeScreenLimits(Controller * ctrl, glm::ivec2 map_size, glm::vec2 tile_scale);




	inline glm::vec2 GetOffset(){ return this->offset; }



	inline void SetOffset(glm::vec2 offset){ this->offset = offset; }



	inline glm::ivec2 GetBeginLimit(){ return this->begin_limit; }



	inline glm::ivec2 GetEndLimit(){ return this->end_limit; }



};




#endif