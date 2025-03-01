#include "jmyApplication.h"
#include "Input.h"
#include "Time.h"

namespace jmy
{
	Application::Application()
		: mHwnd(nullptr), mHdc(nullptr) { }
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0.0f, 0.0f);
		mPlayer2.SetPosition(200.0f, 200.0f);
		mPlayer3.SetPosition(100.0f, 100.0f);

		Input::Initialize();
		Time::Initailize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		mPlayer2.Update();
		//mPlayer3.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
		mPlayer2.Render(mHdc);
		mPlayer3.Render(mHdc);
	}
}