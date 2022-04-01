#pragma once

namespace SDIZO
{
	enum class MenuMessageType
	{
		MainMenu,
		TestTypeMenu,
	};

	enum class TestsMessageType
	{
		ManualArrayTestMenu,
		ManualListTestMenu,
		ManuslHeapTestMenu,
		ManualTreeTestMenu,
		AutomaticArrayTestMenu,
		AutomaticListTestMenu,
		AutomaticHeapTestMenu,
		AutomaticTreeTestMenu,
		None
	};

	enum class Color
	{
		Red,
		Black
	};
}