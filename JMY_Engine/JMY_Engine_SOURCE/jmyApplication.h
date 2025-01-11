#pragma once
#include "CommonInclude.h"
#include "jmyGameObject.h"
#include "jmyGameObject2.h"
#include "jmyGameObject3.h"

namespace jmy
{
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		GameObject mPlayer;
		GameObject2 mPlayer2;
		GameObject3 mPlayer3;
	};
}

