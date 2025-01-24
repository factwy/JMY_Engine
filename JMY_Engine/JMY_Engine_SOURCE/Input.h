#pragma once
#include "CommonInclude.h"

namespace jmy {
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(size_t i);

		static bool GetKeyDown(eKeyCode code);
		static bool GetKeyUp(eKeyCode code);
		static bool GetKey(eKeyCode code);
		
		static bool IsKeyDown(size_t i);
		static void UpdateKeyDown(size_t i);
		static void UpdateKeyUp(size_t i);

	private:
		static std::vector<Key> mKeys;

	};
}

