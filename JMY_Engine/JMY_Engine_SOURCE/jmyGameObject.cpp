#include "jmyGameObject.h"

namespace jmy
{
	GameObject::GameObject()
		: mX(0.0f), mY(0.0f) {}
	GameObject::~GameObject() {}

	void GameObject::Update()
	{
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
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));    // 파랑 브러쉬 생성
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // 파랑 브러쉬 선택 및 흰색 브러쉬(원본) 반환
		
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		Rectangle(hdc, 10 + mX, 10 + mY, 20 + mX, 20 + mY);

		SelectObject(hdc, oldBrush);    // 흰색 원본브러쉬로 선택
		DeleteObject(brush);            // 파랑 브러쉬 삭제
	}

	void GameObject::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
	float GameObject::GetX() { return mX; }
	float GameObject::GetY() { return mY; }
}