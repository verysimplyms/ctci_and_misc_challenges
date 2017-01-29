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


int main()
{
	IntNodePtr example = new IntNode;
	example->setData(-1);

	IntNodePtr head = example;
    example->setHead(head);

	for (int i = 0; i < 27; i++) {
        if(example->getData() % 5 == 0) {
            example->setData(2);
        }

        insertNode(example, i);
        example = example->getLink();
        example->setHead(head);
	}

	example = example->getHead();

	while(example->getLink() != nullptr) {
        std::cout << " " << example->getData();
        example = example->getLink();
	}

    example = example->getHead();
    //example = example->getLink();

    std::cout << "\n" << std::endl;
    for (int i = 0; i < 27; i++) {
            if(example->getLink() != nullptr) {
                if((example->getData()  == 2)) {
                    removeNode(example);
                }
                example = example->getLink();
            }
	}

	example = example->getHead();
	for (int i = 0; i < 27; i++) {
        if(example->getLink() != nullptr) {
            std::cout << example->getData() << std::endl;
            example = example->getLink();
        }
	}


    std::cout << "\n" << std::endl;
	example = example->getHead();

	std::cout << " Program finished" << std::endl;
    return 0;
}

