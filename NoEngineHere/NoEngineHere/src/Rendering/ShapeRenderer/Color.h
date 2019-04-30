#pragma once
namespace noe{

	struct Color{
		static constexpr Color red(){ return Color(1, 0, 0); }
		static constexpr Color green(){ return Color(0, 1, 0); }
		static constexpr Color blue(){ return Color(0, 0, 1); }
		static constexpr Color black(){ return Color(0, 0, 0); }
		static constexpr Color white(){ return Color(1, 1, 1); }

		constexpr Color(float r, float g, float b, float a = 1)
			: r(r), g(g), b(b), a(a){
		}

		//defaults to white
		constexpr Color()
			: r(1), g(1), b(1), a(1){
		}


		float r;
		float g;
		float b;
		float a;
	};


}

