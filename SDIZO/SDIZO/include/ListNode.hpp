#pragma once

namespace SDIZO
{
	template<typename T>
	struct ListNode
	{
		T value;
		ListNode* previous;
		ListNode* next;
		ListNode(T value, ListNode* previous, ListNode* next)
			: value(value), previous(previous), next(next) {}
	};
}