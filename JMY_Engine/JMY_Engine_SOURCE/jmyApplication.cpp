#include "jmyApplication.h"

namespace jmy
{
	Application::Application()
		: mHwnd(nullptr), mHdc(nullptr), mSpeed(0.0f),
		mX(0.0f), mY(0.0f) { }
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.01f;

		// 내가 오른쪽 키를 입력받았다면 x좌표가 플러스
		// 왼쪽 -> x 마이너스
		// 위아래는 y 플러스 마이너스

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));    // 파랑 브러쉬 생성
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // 파랑 브러쉬 선택 및 흰색 브러쉬(원본) 반환
		
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		SelectObject(mHdc, oldPen);
		
		Rectangle(mHdc, 10 + mX, 10 + mY, 20 + mX, 20 + mY);

		SelectObject(mHdc, oldBrush);    // 흰색 원본브러쉬로 선택
		DeleteObject(redPen);
		DeleteObject(brush);            // 파랑 브러쉬 삭제
	}
}