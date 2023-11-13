#include "NumberList.cpp"

int main(){
    NumberList list;

    list.appendNode(0);
    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);

    //list.displayList();

    list.positionRemove(2);

    //std::cout << "DEBUG:: Should insert in third position, should now read \"1 2 0 3 4 5\"" << std::endl;

    list.displayList();
}