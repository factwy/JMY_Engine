#pragma once
#include "CommonInclude.h"

namespace jmy
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

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

