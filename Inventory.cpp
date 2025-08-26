#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Inventory
{
private:
    T* pItems_;
    int capacity_; // 인벤토리가 최대로 저장 할 수 있는 공간의 크기
    int size_;     // 현재 인벤토리에 저장된 아이템의 실제 개수

public:
    Inventory(int capacity_ = 10)
        : capacity_(capacity_ > 0 ? capacity_ : 1),
        size_(0),
        pItems_(nullptr)
    {
        pItems_ = new T[capacity_];
    };

    virtual ~Inventory()
    {
        delete[] pItems_;
        pItems_ = nullptr;
    };

    void printItemMenu()
    {
        cout << "===================" << endl;
        cout << " 1. 검 " << endl;
        cout << " 2. 포션 " << endl;
        cout << " 3. 아이템" << endl;
        cout << "===================" << endl;
    }

    void printMenu()
    {
        cout << "======================================" << endl;
        cout << " 1. 아이템 저장 " << endl;
        cout << " 2. 아이템 버리기 " << endl;
        cout << " 3. 아이템 개수 확인" << endl;
        cout << " 4. 인벤토리 최대 저장 용량 확인" << endl;
        cout << " 5. 모든 아이템 정보 확인" << endl;
        cout << " 6. 인벤토리 창 닫기" << endl;
        cout << "======================================" << endl;
    }

    void AddItem(const T& item)
    {
        if (size_ < capacity_)
        {
            pItems_[size_++] = item;
            cout << "* 현재 남은 공간은 " << capacity_ - size_ << " 칸 입니다." << endl;
        }
        else
        {
            cout << "인벤토리가 가득 찼습니다!" << endl;
        }
    }

    void RemoveLastItem()
    {
        if (size_ > 0)
        {
            cout << "* 마지막 아이템을 버렸습니다." << endl;
            size_--;
        }
        else
        {
            cout << "인벤토리가 비었습니다." << endl;
        }
    }

    void printAllItems() const
    {
        if (size_ > 0)
        {
            for (int i = 0; i < size_; i++)
            {
                pItems_[i].PrintInfo();
            }
        
        }
        else
        {
            cout << "(비어있음)" << endl;
        }
    }

    int GetSize() const 
    {
        return size_; 
    }
    int Getcapacity() const 
    {
        return capacity_; 
  
    }

};

struct Item //구조체 - 따로쓰고싶은거 묶어둠
{
    string name_;
    int price_;

    void PrintInfo() const
    {
        cout << "[아이템 이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
};


int main()
{
    int choice = 0;
    Inventory<Item> inv(10);
    int Itemchoice;

    cout << "인벤토리를 열었습니다. 무엇을 하시겠습니까?" << endl;

    while (choice != 6)
    {
        inv.printMenu();
        cout << "* 번호를 선택 해주세요." << endl;
        cin >> choice;

        if (choice == 1)
        {
            inv.printItemMenu();
            cout << "* 아이템을 선택 해주세요." << endl;
            cin >> Itemchoice;

            if (Itemchoice == 1)
            {
                cout << "* 검을 획득 했습니다." << endl;
                inv.AddItem({"검", 500});
            }
            else if (Itemchoice == 2)
            {
                cout << "* 포션을 획득 했습니다." << endl;
                inv.AddItem({"포션", 200});
            }
            else if (Itemchoice == 3)
            {
                cout << "* 아이템을 획득 했습니다." << endl;
                inv.AddItem({ "아이템", 100 });
            }
            else
            {
                cout << "* 번호를 다시 입력해주세요" << endl;
            }
        }
        else if (choice == 2)
        {
            inv.RemoveLastItem();
        }
        else if (choice == 3)
        {
            cout << "* 현재 아이템 개수는 " << inv.GetSize() << " 개 입니다." << endl;
        }
        else if (choice == 4)
        {
            cout << "* 인벤토리 최대 저장용량은 " << inv.Getcapacity() << " 입니다." << endl;
        }
        else if (choice == 5)
        {
            cout << "* 모든 아이템 정보를 확인 합니다." << endl;
            inv.printAllItems();
        }
        else if (choice == 6)
        {
            cout << "* 인벤토리창을 닫습니다." << endl;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 입력 해주세요." << endl;
        }
    }
}
