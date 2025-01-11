#include "jmyGameObject2.h"

namespace jmy
{
	GameObject2::GameObject2()
		: mX(0.0f), mY(0.0f) {}
	GameObject2::~GameObject2() {}

	void GameObject2::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObject2::LateUpdate()
	{

	}
	void GameObject2::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));    // �Ķ� �귯�� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // �Ķ� �귯�� ���� �� ��� �귯��(����) ��ȯ

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		Ellipse(hdc, 10 + mX, 10 + mY, 20 + mX, 20 + mY);

		SelectObject(hdc, oldBrush);    // ��� �����귯���� ����
		DeleteObject(brush);            // �Ķ� �귯�� ����
	}

	void GameObject2::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
	float GameObject2::GetX() { return mX; }
	float GameObject2::GetY() { return mY; }
}