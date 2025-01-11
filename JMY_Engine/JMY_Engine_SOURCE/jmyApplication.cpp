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

		// ���� ������ Ű�� �Է¹޾Ҵٸ� x��ǥ�� �÷���
		// ���� -> x ���̳ʽ�
		// ���Ʒ��� y �÷��� ���̳ʽ�

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
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));    // �Ķ� �귯�� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // �Ķ� �귯�� ���� �� ��� �귯��(����) ��ȯ
		
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		SelectObject(mHdc, oldPen);
		
		Rectangle(mHdc, 10 + mX, 10 + mY, 20 + mX, 20 + mY);

		SelectObject(mHdc, oldBrush);    // ��� �����귯���� ����
		DeleteObject(redPen);
		DeleteObject(brush);            // �Ķ� �귯�� ����
	}
}