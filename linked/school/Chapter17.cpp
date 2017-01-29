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

void insert(IntNodePtr afterMe, int theData) {
	afterMe->setLink(new IntNode(theData, afterMe->getLink()));
}

int main()
{
	IntNodePtr example = new IntNode;
	example->setData(12);
	IntNodePtr head = example;
    example->setHead(head);

	for (int i = 1; i < 9; i++) {
        insert(example, i);
        example = example->getLink();
        example->setHead(head);
        std::cout << " " << example->getData();
	}

    std::cout << "\n" << std::endl;
	example = example->getHead();

    while (example->getLink() != nullptr) {
        std::cout << example->getLink() << std::endl;
        example = example->getLink();
    }

	std::cout << " Program finished" << std::endl;
    return 0;
}

