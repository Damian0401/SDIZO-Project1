#pragma once

namespace DS
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