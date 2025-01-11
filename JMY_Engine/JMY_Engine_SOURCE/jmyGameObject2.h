#pragma once
#include "CommonInclude.h"

namespace jmy
{
	class GameObject2
	{
	public:
		GameObject2();
		~GameObject2();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y);
		float GetX();
		float GetY();
	private:
		float mX;
		float mY;
	};
}

class GameObject2
{
};

