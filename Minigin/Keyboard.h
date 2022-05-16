#pragma once
#include "ControllerButtons.h"
#include "Command.h"

namespace BTEngine {
	
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();
		void CheckPressed();
		void AddKeyboardMapping(KeyboardButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv);
	private:
		class KeyboardImpl;
		KeyboardImpl* m_pKeyboardImpl;
	};
}



