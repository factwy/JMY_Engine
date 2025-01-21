#include "jmyGameObject3.h"

namespace jmy
{
	GameObject3::GameObject3()
		: mX(0.0f), mY(0.0f) {}
	GameObject3::~GameObject3() {}

	void GameObject3::Update()
	{
		mX = (mX + 0.00001) * (-1.0002);
		mY = (mY + 0.00001) * (-1.0002);
	}
	void GameObject3::LateUpdate()
	{

	}
	void GameObject3::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));    // �Ķ� �귯�� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // �Ķ� �귯�� ���� �� ��� �귯��(����) ��ȯ

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		Ellipse(hdc, 100 + mX, 100 + mY, 200 - mX, 200 - mY);

		SelectObject(hdc, oldBrush);    // ��� �����귯���� ����
		DeleteObject(brush);            // �Ķ� �귯�� ����
	}

	void GameObject3::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
	float GameObject3::GetX() { return mX; }
	float GameObject3::GetY() { return mY; }
}