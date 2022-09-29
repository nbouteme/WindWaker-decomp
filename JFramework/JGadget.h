#pragma once

template <class P, class M>
unsigned my_offsetof(const M P::*member) {
	return (unsigned)&(reinterpret_cast<P *>(0)->*member);
}

template <class P, class M>
P *my_container_of_impl(M *ptr, const M P::*member) {
	return (P *)((char *)ptr - my_offsetof(member));
}

#define my_container_of(ptr, type, member) \
	my_container_of_impl(ptr, &type::member)

namespace JGadget {

	// doubly linked, circular
	struct TLinkListNode {
		TLinkListNode *next = nullptr;
		TLinkListNode *prev = nullptr;
	};

	struct TNodeLinkList {
		TLinkListNode head{&head, &head};
		int count = 0;
		struct iterator {
			TLinkListNode *node;
		};

		iterator Erase(TLinkListNode *param_3) {
			TLinkListNode *prevnode;
			TLinkListNode *nextNode;

			nextNode = param_3->next;
			prevnode = param_3->prev;
			nextNode->prev = prevnode;
			prevnode->next = nextNode;
			count--;
			return iterator{nextNode};
		}

		iterator Insert(iterator where, TLinkListNode *newel) {
			TLinkListNode *pTVar1;
			TLinkListNode *pTVar2;

			pTVar1 = where.node;
			pTVar2 = pTVar1->prev;
			newel->next = pTVar1;
			newel->prev = pTVar2;
			pTVar1->prev = newel;
			pTVar2->next = newel;
			count = count + 1;
			return iterator{newel};
		}

		iterator erase(iterator it) {
			TLinkListNode *node = it.node;
			TLinkListNode *next = node->next;
			iterator start{node};
			iterator end{next};
			return erase(start, end);
		}

		iterator erase(iterator start, iterator end) {
			TLinkListNode *startNode = start.node;
			TLinkListNode *endNode = end.node;
			while (startNode != endNode) {
				TLinkListNode *nextNode = startNode->next;
				Erase(startNode);
				startNode = nextNode;
			}
			return iterator{end.node};
		}

		// infinite loop if param_3 not in the list (as it is circular), this makes
		// checks in JUTConsoleManager useless
		iterator JGadget::TNodeLinkList::Find(TLinkListNode *param_3) {
			auto local_c = head.next;
			while (local_c && local_c != param_3) {
				local_c = local_c->next;
			}
			return iterator{local_c};
		}

		void splice(iterator myIt, TNodeLinkList *otherList, iterator otherIt) {
			iterator otherNode = otherIt;
			iterator otherNextNode{otherNode.node->next};

			if (myIt.node == otherIt.node) {
				return;
			}

			if (myIt.node != otherNextNode.node) {
				otherList->Erase(otherNode.node);
				Insert(myIt, otherNode.node);
			}
		}

		void JGadget::TNodeLinkList::Remove(TLinkListNode *node) {
			TNodeLinkList trashList;
			TLinkListNode *myNode = this->head.next;
			while (myNode != &this->head) {
				if (myNode == node) {
					TLinkListNode *next = myNode->next;
					trashList.splice(iterator{&trashList.head}, this, iterator{myNode});
					myNode = next;
				} else {
					myNode = myNode->next;
				}
			}
		}
	};
}
