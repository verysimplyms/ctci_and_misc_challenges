#include <vector>
#include <iostream>

class IntNode {
	public:
		IntNode() {  };
		IntNode(int theData, IntNode* theLink)
		: data(theData), link(theLink) {};
		IntNode* getLink() const { return link; }
		int getData() const { return data; }
		IntNode* getHead() const { return head; }
		void setData(int theData) { data = theData; }
		void setLink(IntNode* pointer) { link = pointer; }
		void setHead(IntNode* pointer) {head = pointer; }

	private:
		int data;
		IntNode *link = nullptr;
		IntNode *head;
};

typedef IntNode* IntNodePtr;

void headInsert(IntNodePtr& head, int theData) {
	head = new IntNode(theData, head);
}

void insertNode(IntNodePtr afterMe, int theData) {
	afterMe->setLink(new IntNode(theData, afterMe->getLink()));
}
void removeNode(IntNodePtr& node) {
    IntNodePtr nodePrior = node->getHead();
    while(nodePrior->getLink() != nullptr) {
        if(nodePrior->getLink() == node) {
            nodePrior->setLink(node->getLink());
            delete node;
            break;
        }
            nodePrior = nodePrior->getLink();
    }

    node = nodePrior;
}

int kthToLast(IntNodePtr& node, int kth) {
    int i = 0;
    IntNodePtr temp = node;
    while(temp->getLink() != nullptr) {
        temp = temp->getLink();
        i++;
    }

    for(int j = 0; j <= (i - kth); j++) {
        if(j == (i - kth)) {
            return node->getData();
        }

        if(node->getLink() == nullptr) {
            break;
        }

        node = node->getLink();
    }
}

int main() {
    IntNodePtr example = new IntNode;
	example->setData(-1);

	IntNodePtr head = example;
    example->setHead(head);

    for (int i = 0; i < 27; i++) {
        insertNode(example, i);
        example = example->getLink();
        example->setHead(head);
	}

	example = example->getHead();
    std::cout << "kth value: " << kthToLast(example, 21) << std::endl;
}
