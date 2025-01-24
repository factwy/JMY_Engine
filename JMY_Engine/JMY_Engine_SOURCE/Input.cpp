#include "Input.h"

namespace jmy {
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initialize() {
		CreateKeys();
	}
	void Input::Update() {
		UpdateKeys();
	}

	void Input::CreateKeys() {
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::UpdateKeys() {
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
			UpdateKey(i);
	}
	void Input::UpdateKey(size_t i) {
		if (IsKeyDown(i))
			UpdateKeyDown(i);
		else
			UpdateKeyUp(i);
	}

	bool Input::IsKeyDown(size_t i) {
		return (GetAsyncKeyState(ASCII[i]) & 0x8000);
	}
	void Input::UpdateKeyDown(size_t i) {
		if (mKeys[i].bPressed == true)
			mKeys[i].state = eKeyState::Pressed;
		else
			mKeys[i].state = eKeyState::Down;
		mKeys[i].bPressed = true;
	}
	void Input::UpdateKeyUp(size_t i) {
		if (mKeys[i].bPressed == true)
			mKeys[i].state = eKeyState::Up;
		else
			mKeys[i].state = eKeyState::None;
		mKeys[i].bPressed = false;
	}

	bool Input::GetKeyDown(eKeyCode code) {
		return mKeys[(UINT)code].state == eKeyState::Down;
	}
	bool Input::GetKeyUp(eKeyCode code) {
		return mKeys[(UINT)code].state == eKeyState::Up;
	}
	bool Input::GetKey(eKeyCode code) {
		return mKeys[(UINT)code].state == eKeyState::Pressed;
	}
}